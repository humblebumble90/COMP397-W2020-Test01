#pragma once
#ifndef __DICE3__
#define __DICE3__

#include"DisplayObject.h"
#include "Config.h"
#include <SDL_hints.h>

class Dice3 : public DisplayObject
{
public:
	Dice3(std::string imagePath = "../Assets/textures/3.png",
		std::string name = "Dice3",
		GameObjectType type = DICE3,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.1f), bool isCentered = false);
	~Dice3();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};
#endif /*Defined(__DICE3__)*/