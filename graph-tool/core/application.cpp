#include "application.h"

#include "inputHandle/inputLayer.h"
#include "graph/graphLayer.h"

#include <iostream>


Application::Application(const ApplicationDescription& desc)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

	_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(desc.windowWidth, desc.windowHeight), desc.name, sf::Style::Default, settings);
	_window->setFramerateLimit(desc.FPS);

    _clearColor = desc.clearColor;

    auto windowSize = _window->getSize();

    RenderZone zone;
    zone.topLeft = { 0, 0 };
    zone.width = windowSize.x * _windowDivider;
    zone.height = (float)windowSize.y;

    _layerStack.push_back({ new InputLayer("InputLayer"), zone});

    zone.topLeft = { zone.width, 0 };
    zone.width = windowSize.x * (1 - _windowDivider);
    zone.height = (float)windowSize.y;

    _layerStack.push_back({ new GraphLayer("GraphLayer"), zone });

    for (auto layerDesc : _layerStack)
        layerDesc.layer->onAttach();
}

void Application::run()
{
    sf::Clock clock;
    sf::Time start, end, frameTime;

    bool render = true;

    while (_window->isOpen())
    {
        clock.restart();
        start = clock.getElapsedTime();
       
        sf::Event event;

        while (_window->pollEvent(event))
        {
            onEvent(event);

            if (_closed)
                break;

            for (auto layerDesc : _layerStack)
                layerDesc.layer->onEvent(event);

            render = true;
        }

        if (_closed)
            break;

        end = clock.getElapsedTime();
        frameTime = end - start;

        for (auto layerDesc : _layerStack)
            layerDesc.layer->onUpdate(frameTime);

        if (render)
            onRender();

        _window->display();

        render = false;
    }
}

void Application::onEvent(const sf::Event& event)
{
    if (event.type == sf::Event::Closed)
    {
        exit();
    }

    if (event.type == sf::Event::Resized)   // TODO: probably mistake in zones
    {
        RenderZone zone;        // TODO: make more customizable(dont use indexes)
        zone.topLeft = { 0, 0 };
        zone.width = event.size.width * _windowDivider;
        zone.height = event.size.height;

        _layerStack[0].renderZone = zone;

        zone.topLeft = { zone.width, 0 };       
        zone.width = event.size.width * (1 - _windowDivider);
        zone.height = event.size.height;

        _layerStack[1].renderZone = zone;

        std::cout << "Width: " << event.size.width << "\n";     
        std::cout << "Height: " << event.size.height << "\n\n";
    }
}

void Application::onRender()
{
    _window->clear(_clearColor);

    for (auto layerDesc : _layerStack)
        layerDesc.layer->onRender(_window, layerDesc.renderZone);
}

void Application::exit()
{
    for (auto layerDesc : _layerStack)
        layerDesc.layer->onDetach();

    for (auto layerDesc : _layerStack)
        delete layerDesc.layer;

    _window->close();

    _closed = true;
}
