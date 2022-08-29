#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <Windows.h>
namespace mySG 
{
	class Ñharacter :public sf::Drawable, public sf::Transformable
	{
	public:
		Ñharacter();
		//Ñharacter(std::vector<sf::Sprite> vec);
		//Ñharacter(const Ñharacter hero);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void setIdle(std::vector<sf::Sprite> i);
		void setIdleTexture(std::vector<sf::Texture> it);
		void setRunTexture(std::vector<sf::Texture> it);
		void createHero();
		void nextPos();
		void setScale(float s);
		void move(float x, float y);
		void setAction(int a);
		int getAction();
		void setRotate(int r);
		sf::Vector2f getPosition();
	private:
		std::vector<sf::Sprite> idle;
		std::vector<sf::Texture> idleTexture;
		std::vector<sf::Sprite> run;
		//std::vector<sf::Sprite> &actions;
		std::vector<sf::Texture> runTexture;
		int pos;
		int action;
		int posCount;
		float scale;
		sf::Vector2f position;
		int rotate;
	};
};
