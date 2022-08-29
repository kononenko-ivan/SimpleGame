#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <Windows.h>

class Level:public sf::Drawable, public sf::Transformable
{
public:
	Level();
	Level(sf::Vector2u sz);
	Level(int xSz,int ySz);
	void setSize(sf::Vector2u sz);
	sf::Vector2u getSize();
	void setTiles(std::vector<sf::Sprite> t);
	std::vector<sf::Sprite> getTiles();
	void setTilesTexture(std::vector<sf::Texture> t);
	std::vector<sf::Texture> getTilesTexture();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void move(float x, float y);
	void createLevel();
	float getScale();
	sf::Vector2f getFrontPos();
	sf::Vector2f getBackPos();
private:
	sf::Vector2u size;
	std::vector<sf::Sprite> tiles;
	std::vector<sf::Texture> tiles_texture;
	float scale;
};

