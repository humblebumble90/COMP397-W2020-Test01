#pragma once
#ifndef __DICE2__
#define __DICE2__
#include"DisplayObject.h"
#include "Config.h"
#include <SDL_hints.h>

class Dice2 : public DisplayObject
{
public:
	Dice2(std::string imagePath = "../Assets/textures/2.png",
		std::string name = "Dice2",
		GameObjectType type = DICE2,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.1f), bool isCentered = false);
	~Dice2();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};
#endif /*Defined(__DICE2__)*/