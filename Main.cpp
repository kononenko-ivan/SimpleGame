#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Level.h"
#include "Ñharacter.h"
void createCharacter(mySG::Ñharacter* hero) {
    std::vector<sf::Sprite> idle;
    std::vector<sf::Texture>heroTexture;
    std::string iter[] = { "0","1","2","3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9"};
    for (int i = 0; i < 10; i++) {
        std::string file = "png/Idle__00";
        sf::Texture tex;

        file += iter[i];
        file += ".png";

        if (!tex.loadFromFile(file)) {
            std::cout << "Error load " << i + 1 << std::endl;
        }
        heroTexture.push_back(tex);
        
        
    }
    hero->setIdleTexture(heroTexture);
    heroTexture.clear();
    for (int i = 0; i < 10; i++) {
        std::string file = "png/Run__00";
        sf::Texture tex;

        file += iter[i];
        file += ".png";

        if (!tex.loadFromFile(file)) {
            std::cout << "Error load " << i + 1 << std::endl;
        }
        heroTexture.push_back(tex);


    }
    hero->setRunTexture(heroTexture);
    //hero
}
void createLevel(Level *lvl) {
    sf::Vector2f winSize(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
    std::vector<sf::Sprite> tilesLevel;
    std::vector<sf::Texture> tiles;
    std::string iter[] = { "1","2","3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10","11","12","13","14","15","16","17","18" };
    for (int i = 0; i < 18; i++) {
        std::string file = "png/Tiles/";
        sf::Texture tex;
        
        file += iter[i];
        file += ".png";
        
        if (!tex.loadFromFile(file)) {
            std::cout << "Error load " << i + 1 << std::endl;
        }
        tiles.push_back(tex);
    }
    //sf::Sprite block1;
    //float scale = (winSize.y / 15) / 128;
    //block1.setScale(scale,scale);
    ////sf::Texture text = tiles[0].data();
    ////for(auto iter : tiles)
    //block1.setTexture(tiles[0]);
    //block1.setPosition(scale * 128 * 0, scale * 128 * (lvl->getSize().y - 1));
    //tilesLevel.push_back(block1);
    //block1.setTexture(tiles[1]);
    //for (int i = 1; i < lvl->getSize().x-1; i++) {
    //    block1.setPosition(scale * 128*i, scale * 128 * (lvl->getSize().y - 1));
    //    tilesLevel.push_back(block1);
    //}
    //block1.setTexture(tiles[2]);
    //block1.setPosition(scale * 128 * (lvl->getSize().x - 1), scale * 128 * (lvl->getSize().y - 1));
    //tilesLevel.push_back(block1);
    //lvl->setTiles(tilesLevel);
    lvl->setTilesTexture(tiles);
}

int main()
{
    sf::Vector2f winSize(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
    
    sf::RenderWindow window(sf::VideoMode(winSize.x, winSize.y), "Tilemap"/*, sf::Style::Fullscreen*/);
    
    sf::Texture bgTexture;
    bgTexture.loadFromFile("png/BG/BG.png");
    sf::Sprite bgSprite(bgTexture);
    
    bgSprite.setPosition(bgSprite.getOrigin());
    
    float xScale = winSize.x /1000.f, yScale = winSize.y /750.f;
    bgSprite.setScale(xScale,yScale);
    Level level1(30, 15);
    

    std::vector<sf::Texture> tiles;
    createLevel(&level1);
    mySG::Ñharacter ninja;
    std::vector<sf::Texture> hero_Idle;
    createCharacter(&ninja);
    sf::Sprite test;
   // test.setTexture(hero_Idle.front());
    level1.createLevel();
    ninja.setScale(level1.getScale());
    ninja.createHero();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                else if (event.key.code == sf::Keyboard::Left) {
                    ninja.setRotate(-1);
                    ninja.setAction(1);
                    if (ninja.getPosition().x <= winSize.x/2 && level1.getFrontPos().x != 0)
                        level1.move(5, 0);
                    else
                        ninja.move(-5, 0);
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    ninja.setRotate(1);
                    ninja.setAction(1);
                    if (ninja.getPosition().x >= winSize.x / 2 && !(level1.getBackPos().x <= winSize.x/*-(128*level1.getScale())*/))
                        level1.move(-5, 0);
                    else
                        ninja.move(5, 0);
                    
                }
                else if (event.key.code == sf::Keyboard::Up) {
                    ninja.move(0, -25);
                    //std::cout << "Up" << std::endl;
                }
                
            }
            else
                ninja.setAction(0);
            

        }
        window.clear();
        window.draw(bgSprite);
        window.draw(level1);
        window.draw(ninja);
        window.display();
        ninja.nextPos();
    }

    return 0;
}