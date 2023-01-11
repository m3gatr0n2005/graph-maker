#include "inputLayer.h"

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


InputLayer::InputLayer(const std::string& name)
	: Layer(name)
{

}

void InputLayer::onAttach()
{

}

void InputLayer::onDetach()
{

}

void InputLayer::onUpdate(sf::Time frameTime)
{

}

void InputLayer::onRender(std::shared_ptr<sf::RenderWindow> window, const RenderZone& zone)
{
	sf::VertexArray triangle(sf::Triangles, 3);

	sf::Vector2f zoneCenter = zone.getCenter();

	triangle[0].position = sf::Vector2f(zone.width * 0.15f, zoneCenter.y * 1.3f);
	triangle[1].position = sf::Vector2f(zoneCenter.x, zoneCenter.y * 0.5f);
	triangle[2].position = sf::Vector2f(zone.width * 0.85f, zoneCenter.y * 1.3f);

	triangle[0].color = { 240, 40, 50 };
	triangle[1].color = { 50, 40, 240 };
	triangle[2].color = { 40, 240, 50 };

	window->draw(triangle);

	sf::RectangleShape line({ 1, zone.height });
	line.move({ zone.width, 0 });
	line.setFillColor(sf::Color::Black);
	//line.rotate(45);
	window->draw(line);
}

void InputLayer::onEvent(const sf::Event& event)
{

}
