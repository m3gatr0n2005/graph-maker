#include "graphLayer.h"

#include <SFML/Graphics/CircleShape.hpp>


GraphLayer::GraphLayer(const std::string& name)
	: Layer(name)
{

}

void GraphLayer::onAttach()
{

}

void GraphLayer::onDetach()
{

}

void GraphLayer::onUpdate(sf::Time frameTime)
{

}

void GraphLayer::onRender(std::shared_ptr<sf::RenderWindow> window, const RenderZone& zone)
{
	sf::CircleShape circle(200, 30);
	circle.setFillColor({ 153, 204, 255 });

	circle.setPosition(zone.getCenter());	// !remember: sfml position is top left corner of the shape(not center)

	circle.setScale(1, zone.width / zone.height);

	window->draw(circle);
}

void GraphLayer::onEvent(const sf::Event& event)
{

}
