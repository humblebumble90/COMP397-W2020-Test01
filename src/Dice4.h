#pragma once
#ifndef __DICE4__
#define __DICE4__

#include"DisplayObject.h"
#include "Config.h"
#include <SDL_hints.h>

class Dice4 : public DisplayObject
{
public:
	Dice4(std::string imagePath = "../Assets/textures/4.png",
		std::string name = "Dice4",
		GameObjectType type = DICE4,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.1f), bool isCentered = false);
	~Dice4();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};
#endif /*Defined(__DICE4__)*/