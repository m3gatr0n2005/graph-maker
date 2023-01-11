#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <string>


struct RenderZone
{
	sf::Vector2f topLeft;
	float width;
	float height;

	sf::Vector2f getCenter() const
	{
		sf::Vector2f zoneCenter;
		zoneCenter.x = topLeft.x + width / 2;
		zoneCenter.y = topLeft.y + height / 2;

		return zoneCenter;
	}
};


class Layer
{
public:
	Layer(const std::string& name = "")
		: _name(name) {}

	virtual void onAttach() {};
	virtual void onDetach() {};

	virtual void onUpdate(sf::Time frameTime) {};
	virtual void onRender(std::shared_ptr<sf::RenderWindow> window, const RenderZone& zone) {};
	virtual void onEvent(const sf::Event& event) {};

	const std::string& getName() { return _name; };

protected:
	std::string _name;
};
