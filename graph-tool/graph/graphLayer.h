#pragma once

#include "Core/layer.h"


class GraphLayer : public Layer
{
public:
	GraphLayer(const std::string& name);

	virtual void onAttach() override;
	virtual void onDetach() override;

	virtual void onUpdate(sf::Time frameTime) override;
	virtual void onRender(std::shared_ptr<sf::RenderWindow> window, const RenderZone& zone) override;
	virtual void onEvent(const sf::Event& event) override;
};
