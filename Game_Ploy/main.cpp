#include <iostream>
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"
#include <vector>
#include<time.h>
#include<stdio.h>
#include <string.h>
#include <utility>
#include <string>
#include <sstream>

using namespace std;
static const float VIEW_HEIGHT = 1080.0f;
static const float VIEW_WIDTH = 1920.0f;

void Showtexet(int x, int y, int num, int size, sf::RenderWindow& window, sf::Font* font)
{
    sf::Text text;
    text.setFont(*font);
    text.setPosition(x, y);
    string str;
    stringstream ss;
    ss << num;
    ss >> str;
    text.setString(str);
    text.setFillColor(sf::Color::Magenta);
    text.setCharacterSize(size);
    window.draw(text);
}

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_WIDTH);
}

int main()
{
    int Score = 0, TimeCandy = 0, TimeEnemy = 0, TimeCookie = 0;
    float SumTime = 0.0f,MainTime = 120.0f;
    int R1 = 0,R2 = 0;
    sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Game's Ploy", sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
    //sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1020, 1080));
    sf::Texture playerTexture;
        playerTexture.loadFromFile("Pic/main.png");
    sf::Texture Candy_pic;
        Candy_pic.loadFromFile("Pic/Candy.png");
    sf::Texture Choco;
        Choco.loadFromFile("Pic/Chocolate.png");
    sf::Texture Pumpkin_pic;
        Pumpkin_pic.loadFromFile("Pic/Pumpkin1.png");
    sf::Texture Cookie_pic;
        Cookie_pic.loadFromFile("Pic/Cookie.png");
    sf::Texture Bg;
        Bg.loadFromFile("Pic/Bg.jpg");
    sf::Texture st;
        st.loadFromFile("Pic/state.jpg");
    sf::Texture Spider_pic;
        Spider_pic.loadFromFile("Pic/Spider.png");
    sf::Font Font;
        Font.loadFromFile("Font/Dog.ttf");

   
    Player player(&playerTexture, sf::Vector2u(20, 3), 0.075f, 400.0f,200.0f);
    
    std::vector<Platform> platforms,Item,Enemy,Candy,Pumpkin,Cookie;
    Platform Background(&Bg, sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT) / 2.0f);
    Platform state(&st, sf::Vector2f(VIEW_WIDTH, 400), sf::Vector2f(VIEW_WIDTH/2.0f, VIEW_HEIGHT+20));
    
    srand(time(NULL));
    float deltaTime = 0.0f;
    sf::Clock clock;
  
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;
        
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();
 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

        }

        SumTime += deltaTime;
        if(SumTime >= 0.7f)
        { 
            R1 = rand() % 850 + 100;
            MainTime-=0.5f;
            if (MainTime < 0) MainTime = 0;
            TimeCandy++;
            TimeEnemy++;
            TimeCookie++;
            int x = rand() % 5;
            if(x==0)
                Item.push_back(Platform(&Choco, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(R1, -100.0f)));
            else if (x == 1 && TimeEnemy >= 2)
            {
                Enemy.push_back(Platform(&Spider_pic, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(R1, -100.0f)));
                TimeEnemy -= 2;
            }
                
            else if (x == 2 && TimeEnemy >= 2)
            {
                Pumpkin.push_back(Platform(&Pumpkin_pic, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(R1, -100.0f)));
                TimeEnemy -= 2;
            }
              
            else if (x == 3 && TimeCandy >= 20)
            {
                TimeCandy -= 20;
                Candy.push_back(Platform(&Candy_pic, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(R1, -100.0f)));
            }

            else if (x == 4 && TimeCookie >= 30)
            {
                TimeCookie -= 30;
                Cookie.push_back(Platform(&Cookie_pic, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(R1, -100.0f)));
            }

            else Item.push_back(Platform(&Choco, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(R1, -100.0f)));


            R1 = rand() % 850 + 1000;
            TimeCandy++;
            TimeEnemy++;
            TimeCookie++;
            x = rand() % 5;
            if (x == 0)
                Item.push_back(Platform(&Choco, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(R1, -100.0f)));
            else if (x == 1 && TimeEnemy >= 2)
            {
                Enemy.push_back(Platform(&Spider_pic, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(R1, -100.0f)));
                TimeEnemy -= 2;
            }

            else if (x == 2 && TimeEnemy >= 2)
            {
                Pumpkin.push_back(Platform(&Pumpkin_pic, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(R1, -100.0f)));
                TimeEnemy -= 2;
            }

            else if (x == 3 && TimeCandy >= 20)
            {
                TimeCandy -= 20;
                Candy.push_back(Platform(&Candy_pic, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(R1, -100.0f)));
            }

            else if (x == 4 && TimeCookie >= 30)
            {
                TimeCookie -= 30;
                Cookie.push_back(Platform(&Cookie_pic, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(R1, -100.0f)));
            }

            else Item.push_back(Platform(&Choco, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(R1, -100.0f)));
            SumTime -= 0.7f;
        }
        
        //Update
        player.Update(deltaTime);

         for (Platform& S : Item)
            S.update(deltaTime);

         for (Platform& S : Enemy)
             S.update(deltaTime);

         for (Platform& S : Candy)
             S.update(deltaTime);

         for (Platform& S : Pumpkin)
             S.update(deltaTime);

         for (Platform& S : Cookie)
             S.update(deltaTime);

        //ชน && +- Score
        Collider playerCollision = player.GetCollider();
        sf::Vector2f direction;

        for (Platform& S : Item)
            if (S.GetCollider().CheckCollider(playerCollision))
            {
                S.body.setPosition(S.body.getPosition().x,1800.0f );
                Score+=2; 
            }
        
        for (Platform& S : Candy)
            if (S.GetCollider().CheckCollider(playerCollision))
            {
                S.body.setPosition(S.body.getPosition().x, 1800.0f);
                Score+=20;
              
            }

        for (Platform& S : Enemy)
            if (S.GetCollider().CheckCollider(playerCollision))
            {
                S.body.setPosition(S.body.getPosition().x, 1800.0f);
                
                Score -= 5;
                if (Score < 0) Score = 0;
                MainTime -= 2.5f;
            }

        for (Platform& S : Pumpkin)
            if (S.GetCollider().CheckCollider(playerCollision))
            {
                S.body.setPosition(S.body.getPosition().x, 1800.0f);
                if (Score < 0) Score = 0;
                Score -= 10;
                if (Score < 0) Score = 0;
                MainTime -= 2.5f;
                if (MainTime < 0) MainTime = 0;
            }

        for (Platform& S : Cookie)
            if (S.GetCollider().CheckCollider(playerCollision))
            {
                S.body.setPosition(S.body.getPosition().x, 1800.0f);
                MainTime += 10.0f;
            }
                
 
        if (state.GetCollider().CheckCollider(playerCollision, direction, 1.0f))
            player.OnCollosion(direction);

        //delete
        while (!Item.empty() && (Item.front().body.getPosition().y > 1080.0f))
            Item.erase(Item.begin());

        while (!Enemy.empty() && (Enemy.front().body.getPosition().y > 1080.0f))
            Enemy.erase(Enemy.begin());

        while (!Pumpkin.empty() && (Pumpkin.front().body.getPosition().y > 1080.0f))
            Pumpkin.erase(Pumpkin.begin());

        while (!Candy.empty() && (Candy.front().body.getPosition().y > 1080.0f))
            Candy.erase(Candy.begin());

        while (!Cookie.empty() && (Cookie.front().body.getPosition().y > 1080.0f))
            Cookie.erase(Cookie.begin());

        //Draw
        window.clear(sf::Color(150,150,150));
      
        Background.Draw(window);

        for (Platform& S : Item)
            S.Draw(window);
        for (Platform& S : Enemy)
            S.Draw(window);
        for (Platform& S : Candy)
            S.Draw(window);
        for (Platform& S : Pumpkin)
            S.Draw(window);
        for (Platform& S : Cookie)
            S.Draw(window);
        state.Draw(window);
        player.Draw(window);

        //Text
        Showtexet(200, 100, Score, 100, window, &Font);
        Showtexet(1500, 100, MainTime, 100, window, &Font);
        window.display();
    }
    return 0;
}





