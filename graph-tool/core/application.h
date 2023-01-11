#pragma once

#include "layer.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>
#include <memory>


struct ApplicationDescription
{
	std::string name;
	uint32_t windowWidth = 1600;
	uint32_t windowHeight = 900;
	uint32_t FPS = 60;
	sf::Color clearColor;
};

struct LayerDescription
{
	Layer* layer;
	RenderZone renderZone;
};


class Application
{
public:
	Application(const ApplicationDescription& desc = ApplicationDescription());

	void run();
	void exit();

private:
	void onEvent(const sf::Event& event);
	void onRender(); // Note that onRender calls only when event occured(not every frame)

private:
	std::vector<LayerDescription> _layerStack;
	std::shared_ptr<sf::RenderWindow> _window;
	bool _closed = false;
	sf::Color _clearColor;

	const float _windowDivider = 0.25f;
};
