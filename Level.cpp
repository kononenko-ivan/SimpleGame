#include "Level.h"

Level::Level() {
	setSize(sf::Vector2u(0, 0));
}
Level::Level(sf::Vector2u sz) {
	setSize(sz);
}

Level::Level(int xSz, int ySz) {
	setSize(sf::Vector2u(xSz, ySz));
}

void Level::setSize(sf::Vector2u sz) {
	size.x = sz.x;
	size.y = sz.y;
}
sf::Vector2u Level::getSize() {
	return size;
}

void Level::setTiles(std::vector<sf::Sprite> t) {
	tiles.swap(t);
}
std::vector<sf::Sprite> Level::getTiles() {
	return tiles;
}

void Level::setTilesTexture(std::vector<sf::Texture> t) {
	tiles_texture.swap(t);
}
std::vector<sf::Texture> Level::getTilesTexture() {
	return tiles_texture;
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto i : tiles) {
		target.draw(i, states);
	}
}

void Level::move(float x, float y) {
	if((x < 0 && !(tiles.back().getPosition().x<= GetSystemMetrics(SM_CXSCREEN)))|| (x > 0 && !(tiles.front().getPosition().x == 0)))
	for (int i = 0; i < tiles.size(); i++) {
		tiles[i].move(x, y);
	}
}

void Level::createLevel() {
	sf::Vector2f winSize(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	sf::Sprite block1;
	scale = (winSize.y / 15) / 128;
	block1.setScale(scale, scale);
	//sf::Texture text = tiles[0].data();
	//for(auto iter : tiles)
	block1.setTexture(tiles_texture[0]);
	block1.setPosition(scale * 128 * 0, scale * 128 * (getSize().y - 1));
	tiles.push_back(block1);
	block1.setTexture(tiles_texture[1]);
	for (int i = 1; i < getSize().x - 1; i++) {
		block1.setPosition(scale * 128 * i, scale * 128 * (getSize().y - 1));
		tiles.push_back(block1);
	}
	block1.setTexture(tiles_texture[2]);
	block1.setPosition(scale * 128 * (getSize().x - 1), scale * 128 * (getSize().y - 1));
	tiles.push_back(block1);
}

float Level::getScale() {
	return scale;
}

sf::Vector2f Level::getFrontPos() {
	return tiles.front().getPosition();
}
sf::Vector2f Level::getBackPos() {
	return tiles.back().getPosition();
}