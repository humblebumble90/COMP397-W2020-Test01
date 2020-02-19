#include "Dice2.h"
#include "TextureManager.h"
#include "Game.h"

Dice2::Dice2(std::string imagePath, std::string name, GameObjectType type, glm::vec2 position, bool isCentered)
	: m_name(name), m_isCentered(isCentered), m_alpha(255)
{
	TheTextureManager::Instance()->load(imagePath,
		m_name, TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);
	setType(type);
}

Dice2::~Dice2()
{
}

void Dice2::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
	TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}
void Dice2::update()
{
}

void Dice2::clean()
{
	TheTextureManager::Instance()->removeTexture(m_name);
}
