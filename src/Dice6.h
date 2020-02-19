#pragma once
#ifndef __DICE6__
#define __DICE6__

#include"DisplayObject.h"
#include "Config.h"
#include <SDL_hints.h>

class Dice6 : public DisplayObject
{
public:
	Dice6(std::string imagePath = "../Assets/textures/5.png",
		std::string name = "Dice6",
		GameObjectType type = DICE6,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.1f), bool isCentered = false);
	~Dice6();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};

#endif/*Defined(__DICE6__)*/