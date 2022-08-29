#include "Ñharacter.h"
namespace mySG
{
	Ñharacter::Ñharacter() {
		sf::Vector2f winSize(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
		pos = 0;
		posCount = 0;
		position.x = 100;
		position.y = (winSize.y / 15) * 13;
		rotate = 1;
		//idle.push_back(sf::Sprite());
		//actions = idle;
		action = 0;
	}
	//Ñharacter::Ñharacter(const Ñharacter hero) {
	//	//this.
	//}
	void Ñharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		//for (auto i : idle) {
		if (action == 0)
			target.draw(idle[pos/10], states);
		else if (action == 1)
			target.draw(run[pos / 10], states);
		//}
	}
	void Ñharacter::setIdle(std::vector<sf::Sprite> i) {
		idle.swap(i);
	}
	void Ñharacter::setIdleTexture(std::vector<sf::Texture> it) {
		idleTexture.swap(it);
	}
	void Ñharacter::setRunTexture(std::vector<sf::Texture> it) {
		runTexture.swap(it);
	}
	void Ñharacter::createHero() {
		for (int i = 0; i < idleTexture.size();i++) {
			sf::Sprite idleSprite;
			idleSprite.setTexture(idleTexture[i]);
			idleSprite.setPosition(position);
			idleSprite.setScale(scale,scale);
			idle.push_back(idleSprite);
		}
		posCount = idle.size();
		for (int i = 0; i < runTexture.size(); i++) {
			sf::Sprite runSprite;
			runSprite.setTexture(runTexture[i]);
			runSprite.setPosition(position);
			runSprite.setScale(scale, scale);
			run.push_back(runSprite);
		}
	}

	void Ñharacter::nextPos() {
		pos++;
		if (pos == posCount*10)
			pos = 0;
	}
	void Ñharacter::setScale(float s) {

		scale = (s*128)/439;
	}
	int Ñharacter::getAction() {
		return action;
	}
	sf::Vector2f Ñharacter::getPosition() {
		return position;
	}
	void Ñharacter::setAction(int a) {
		if (action != a) {
			action = a;
			pos = 0;
		}
		//if (action == 0)
		//	actions = idle;
		//else if (action == 1)
		//	actions = run;
	}
	void Ñharacter::setRotate(int r) {
		if (rotate != r) {
			rotate = r;
			//pos = 0;
			for (int i = 0; i < idle.size(); i++) {
				idle[i].setScale(idle[i].getScale().x*(-1), idle[i].getScale().y);
			}
			for (int i = 0; i < run.size(); i++) {
				run[i].setScale(run[i].getScale().x * (-1), run[i].getScale().y);
			}
			move(50*rotate*(-1), 0);
		}
		
	}
	void Ñharacter::move(float x, float y) {
		if ((x > 0 && (position.x <= GetSystemMetrics(SM_CXSCREEN)-50)) || (x < 0 && (position.x >= 50)) || x == 0) {
			position.x += x;
			for (int i = 0; i < idle.size(); i++) {
				idle[i].move(x, y);
			}
			for (int i = 0; i < run.size(); i++) {
				run[i].move(x, y);
			}
		}
	}
};