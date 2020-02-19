#pragma once
#ifndef __DICE1__
#define __DICE1__
#include"DisplayObject.h"
#include "Config.h"
#include <SDL_hints.h>

class Dice1: public DisplayObject
{
public:
	Dice1(std::string imagePath = "../Assets/textures/1.png",
		std::string name = "Dice1",
		GameObjectType type = DICE1,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.1f), bool isCentered = false);
	~Dice1();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};
#endif /*Defiend(__DICE1__)*/