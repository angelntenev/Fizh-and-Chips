// manager.cpp

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "manager.h"
#include "game.h"
#include "fish.h"
#include "background.h"

using namespace std;
using namespace sf;


//Temp audio



//Generate crosshair

bool noHunger = true;






const Keyboard::Key controls[11] =
{
    Keyboard::Num0,
    Keyboard::Num1, Keyboard::Num2,
    Keyboard::Num3, Keyboard::Num4,
    Keyboard::Num5, Keyboard::Num6,
    Keyboard::Num7, Keyboard::Num8,
    Keyboard::Num9, Keyboard::Space
};





Manager::Manager() : chipsScore(300)
{
    font.loadFromFile("res/SupermercadoOne-Regular.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setString(std::to_string(chipsScore));
    scoreText.setPosition(Vector2f(screenWidth - 100, 40));
    Fish* BossEnemy = new Fish();
    BossEnemy->setBossEnemySprite();
    setTarget();
    BossEnemy->setSpeed(0.1);
    setupDashboard();
   // bossEnemy.push_back(BossEnemy);



}



void Manager::Update(float& dt)
{
    crosshair->Update(dt);

    checkForReset();

    if (inactiveTimer < 0)
    {
        inactiveBoss = true;
    }
    else
    {
        inactiveTimer -= dt;
    }

    if (noHunger == true)
    {
        bossTime -= dt;
    }

    scoreText.setString(std::to_string(chipsScore));
    if (Keyboard::isKeyPressed(controls[1]))
    {
        if (buyTimer >= 0.2)
        {
            if ((chipsScore - decorationPrice) >= 0)
            {
                Fish* fish = new Fish();
                fishes.push_back(fish);
                addChips(-100);
                scoreText.setString(std::to_string(chipsScore));
            }
            buyTimer = 0;
        }
    }
    scoreText.setString(std::to_string(chipsScore));
    if (Keyboard::isKeyPressed(controls[3]))
    {
        if (buyTimer >= 0.2)
        {
            int count = 0;
            for (auto& _decorations : background->decorations)
            {
                if (_decorations.active == false)
                {
                    if ((chipsScore - decorationPrice) >= 0)
                    {
                        _decorations.active = true;
                        addChips(-decorationPrice);
                        scoreText.setString(std::to_string(chipsScore));
                        decorationPrice = decorationPrice + (decorationPrice/2);
                        break;
                    }
                }
            }
            
            buyTimer = 0;
        }
    }
    scoreText.setString(std::to_string(chipsScore));
    if (Keyboard::isKeyPressed(controls[2]))
    {
        if (buyTimer >= 0.2)
        {
            if ((chipsScore - 500) >= 0)
            {
                Fish* shark = new Fish();
                shark->setOrigin(Vector2f(64.f, 32.f));
                shark->setSharkSprite();
                sharks.push_back(shark);
                addChips(-500);
                scoreText.setString(std::to_string(chipsScore));
            }
            buyTimer = 0;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::M))
    {
        if (buyTimer >= 0.2)
        {
            addChips(1000);
            buyTimer = 0;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        pause = true;
    }
    buyTimer += dt;
    // bossTime += dt;

    //boss spawner

    if (bossTime < 0 && BossEnemy->bossActive == false)
    {
        Fish* BossEnemy = new Fish();
        bossEnemy.push_back(BossEnemy);
        BossEnemy->setHealth(100);
        BossEnemy->setBossEnemySprite();
        BossEnemy->bossActive = true;
        bossTime = 120;
        noHunger = false;
    }






    if (Keyboard::isKeyPressed(controls[10]))
    {
        if (feedTimer >= 0.15)
        {
            if (bossEnemy.size() > 0)
            {
                feedTimer = 0;
                Anim* _bullet = new Anim(crosshair->getPosition());
                bullets.push_back(_bullet);
            }
            else
            {
                feedTimer = 0;
                Consumable* food = new Consumable(false, crosshair->getPosition(), 64, 0, 0);
                foodObjects.push_back(food);
            }

        }
    }
    feedTimer += dt;



    for (auto& fish : fishes)
    {

        if (fish->getCoinCounter() < 0 && fish->getSizeGrowth() > 0)
        {
            if (fish->getSizeGrowth() == 2)
            {
                fish->resetCoinCounter();
                Consumable* coin = new Consumable(true, fish->reachPosition(), 96, 0, 20);
                currencyObjects.push_back(coin);
            }
            else if (fish->getSizeGrowth() == 1)
            {
                fish->resetCoinCounter();
                Consumable* coin = new Consumable(true, fish->reachPosition(), 96, 0, 10);
                currencyObjects.push_back(coin);
            }
        }
        if (fish->isHungry == false)
        {
            fish->Update(dt);
        }
        else
        {
            
            if (fish->getHungerTimer() < 5)
            {
                if (fish->getHungerTimer() < 0)
                {
                    fish->setHungryFish();


                }
                if (foodObjects.size() > 0)
                {
                    moveToClosestPoint(*fish);
                }
                for (int i = foodObjects.size() - 1; i >= 0; i--)
                {
                    if (fish->getMouth().getGlobalBounds().findIntersection(foodObjects[i]->getGlobalBounds()))
                    {

                        if (fish->isHungry == true)
                        {
                            fish->fishReset();
                            fish->resetHungerTimer();
                            fish->giveXP();
                            fish->setFullFish();
                            delete foodObjects[i];
                            foodObjects.erase(foodObjects.begin() + i);
                            fish->playGulp();
                        }

                        if (fish->getXP() > 40)
                        {
                            if (fish->getXP() > 100)
                            {
                                fish->Grow2();
                                fish->setSizeGrowth(2);
                            }
                            else
                            {
                                fish->Grow1();
                                fish->setSizeGrowth(1);
                            }

                        }



                    }
                }
            }
            if (fish->getHungerTimer() < -10)
            {
                fish->setDeadFish();
            }
            if (fish->getHungerTimer() < -15)
            {
                fish->_fordeletion = true;
            }
            fish->Update(dt);
        }
    }


    //Shark update
    for (auto& shark : sharks)
    {


        if (shark->getCoinCounter() < 0)
        {
            shark->resetCoinCounter();
            Consumable* coin = new Consumable(true, shark->reachPosition(), 96, 0, 50);
            currencyObjects.push_back(coin);
        }
        if (shark->isHungry == false)
        {
            shark->Update(dt);
        }
        else
        {
            if (shark->getHungerTimer() < 5)
            {
                if (shark->getHungerTimer() < 0)
                {
                    //setHungryShark
                    shark->setHungryShark();
                }
                if (fishes.size() > 0)
                {
                    moveToClosestFish(*shark);
                }
                for (int i = fishes.size() - 1; i >= 0; i--)
                {
                    if (shark->getMouth().getGlobalBounds().findIntersection(fishes[i]->getGlobalBounds()))
                    {

                        if (shark->isHungry == true)
                        {
                            shark->fishReset();
                            shark->resetHungerTimer();
                            //fish->setFullFish();
                            delete fishes[i];
                            fishes.erase(fishes.begin() + i);
                            shark->playGulp();
                            shark->setSharkNotHungry();
                        }

                    }
                }
            }
            if (shark->getHungerTimer() < -10)
            {
                shark->setDeadShark();
            }
            if (shark->getHungerTimer() < -15)
            {
                shark->_fordeletion = true;
            }
            shark->Update(dt);
        }
    }


    //Updates Boss
    for (auto& BossEnemy : bossEnemy)
    {

        if (BossEnemy->bossActive == true)
        {
            BossEnemy->Update(dt);
        }

        for (int i = bullets.size() - 1; i >= 0; i--)
        {
            if (bullets[i]->getGlobalBounds().findIntersection(BossEnemy->getGlobalBounds()) && bullets[i]->getHit() == false)
            {
                bullets[i]->setHit(true);
                BossEnemy->drainHealth(5);
                inactiveTimer = 2;
                inactiveBoss = false;
                chipsScore += 300;
            }
        }

        //if boss is not hurt by shots, eat fish
        if (inactiveBoss == true)
        {
            for (int i = fishes.size() - 1; i >= 0; i--)
            {
                if (BossEnemy->getGlobalBounds().findIntersection(fishes[i]->getGlobalBounds()))
                {
                    BossEnemy->playGulp();
                    fishes[i]->_fordeletion = true;
                }
            }

            for (int s = sharks.size() - 1; s >= 0; s--)
            {
                if (BossEnemy->getGlobalBounds().findIntersection(sharks[s]->getGlobalBounds()))
                {

                    BossEnemy->playGulp();
                    sharks[s]->_fordeletion = true;

                }
            }
        }

        if (BossEnemy->getHealth() <= 0)
        {
            BossEnemy->_fordeletion = true;
        }

    }






    for (auto& bullet : bullets)
    {
        bullet->Update(dt);
    }

    for (int i = foodObjects.size() - 1; i >= 0; i--)
    {
        foodObjects[i]->Update(dt);
        if (foodObjects[i]->_fordeletion)
        {
            delete foodObjects[i];
            foodObjects.erase(foodObjects.begin() + i);
        }
    }

    for (int i = currencyObjects.size() - 1; i >= 0; i--)
    {
        currencyObjects[i]->Update(dt);
        if (currencyObjects[i]->_fordeletion)
        {
            delete currencyObjects[i];
            currencyObjects.erase(currencyObjects.begin() + i);
        }
        else if (crosshair->getGlobalBounds().findIntersection(currencyObjects[i]->getGlobalBounds()))
        {
            addChips(currencyObjects[i]->getValue());
            delete currencyObjects[i];
            currencyObjects.erase(currencyObjects.begin() + i);
        }
    }

    for (int i = fishes.size() - 1; i >= 0; i--)
    {
        if (fishes[i]->_fordeletion == true)
        {
            delete fishes[i];
            fishes.erase(fishes.begin() + i);
        }
    }

    for (int i = sharks.size() - 1; i >= 0; i--)
    {
        if (sharks[i]->_fordeletion == true)
        {
            delete sharks[i];
            sharks.erase(sharks.begin() + i);
        }
    }

    for (int i = bossEnemy.size() - 1; i >= 0; i--)
    {
        if (bossEnemy[i]->_fordeletion == true)
        {
            delete bossEnemy[i];
            bossEnemy.erase(bossEnemy.begin() + i);
            noHunger = true;
            BossEnemy->bossActive = false;
        }
    }


    for (int i = bullets.size() - 1; i >= 0; i--)
    {
        if (bullets[i]->_fordeletion == true)
        {
            delete bullets[i];
            bullets.erase(bullets.begin() + i);
        }
    }

    for (int i = foodObjects.size() - 1; i >= 0; i--)
    {
        if (foodObjects[i]->_fordeletion == true)
        {
            delete foodObjects[i];
            foodObjects.erase(foodObjects.begin() + i);
        }
    }

    for (int i = currencyObjects.size() - 1; i >= 0; i--)
    {
        if (currencyObjects[i]->_fordeletion == true)
        {
            delete currencyObjects[i];
            currencyObjects.erase(currencyObjects.begin() + i);
        }
    }
}


void Manager::changeScore(int a)
{
    chipsScore -= a;
    scoreText.setString(std::to_string(chipsScore));
}

sf::Text Manager::getText()
{
    return Manager::scoreText;
}

std::vector<Fish*> Manager::getFish()
{
    return fishes;
}

float Manager::closestPoint(Vector2f obj1, Vector2f obj2)
{
    float sum1 = obj1.x + obj1.y;
    float sum2 = obj2.x + obj2.y;
    if (sum1 > sum2)
    {
        return sum1 - sum2;
    }
    else
    {
        return sum2 - sum1;
    }
}

void Manager::moveToClosestPoint(Fish& fish)
{
    float smallestDiff = 2401;
    for (int i = 0; i < foodObjects.size(); i++)
    {
        
        if (smallestDiff > Manager::closestPoint(fish.reachPosition(), foodObjects[i]->reachPosition()))
        {
            fish.destination = foodObjects[i]->reachPosition();
            smallestDiff = Manager::closestPoint(fish.reachPosition(), foodObjects[i]->reachPosition());
        }
    }
    fish.startPoint = fish.reachPosition();
    fish.setBothDirection();
}

void Manager::moveToClosestFish(Fish& fish)
{
    float smallestDiff = 2401;
    for (int i = 0; i < fishes.size(); i++)
    {

        if (smallestDiff > Manager::closestPoint(fish.reachPosition(), fishes[i]->reachPosition()))
        {
            fish.destination = fishes[i]->reachPosition();
            smallestDiff = Manager::closestPoint(fish.reachPosition(), fishes[i]->reachPosition());
        }
    }
    fish.startPoint = fish.reachPosition();
    fish.setBothDirection();

}


void Manager::moveToClosestShark(Fish& shark)
{
    float smallestDiff = 2401;
    for (int i = 0; i < sharks.size(); i++)
    {

        if (smallestDiff > Manager::closestPoint(shark.reachPosition(), sharks[i]->reachPosition()))
        {
            shark.destination = sharks[i]->reachPosition();
            smallestDiff = Manager::closestPoint(shark.reachPosition(), sharks[i]->reachPosition());
         
        }
    }
    shark.startPoint = shark.reachPosition();
    shark.setBothDirection();
   
    
    
}

void Manager::Render(RenderWindow& window)
{
   window.draw(*background);
   window.draw(dashboard);
   
    for (const auto _decorations : background->decorations)
    {
        if (_decorations.active == true)
        {
            window.draw(_decorations);
        }
        
    }

    for (const auto fish : fishes)
    {
        window.draw(*fish);
        window.draw(fish->getMouth());
    }
    for (const auto shark : sharks)
    {
        window.draw(*shark);
        window.draw(shark->getMouth());
    }

    for (const auto BossEnemy : bossEnemy)
    {
        window.draw(*BossEnemy);
        window.draw(BossEnemy->getMouth());
    }
    for (const auto bullet : bullets)
    {
        window.draw(*bullet);
    }
    window.draw(crossTarget);
    window.draw(*crosshair);
    window.draw(scoreText);
    //window.draw(*fish);
    for (const auto& consumable : foodObjects)
    {
        window.draw(*consumable);
    }
    for (auto& coin : currencyObjects)
    {
        window.draw(*coin);
    }



}

int Manager::getChips()
{
    return chipsScore;
}

void Manager::setChips(int chips)
{
    Manager::chipsScore = chips;
}

void Manager::addChips(int chips)
{
    Manager::chipsScore += chips;
}

void Manager::setTarget()
{
    crossTarget.setTextureRect(IntRect(Vector2(0, 0), Vector2(64, 64)));
    crossTarget.setOrigin(Vector2f(32.f, 32.f));
    crossTarget.setTexture(target);
    crossTarget.setPosition(Vector2f(-100.f, -100.f));
}

void Manager::putTargetAway()
{
    crossTarget.setPosition(Vector2f(-100.f, -100.f));
}

void Manager::placeTarget(Vector2f loc)
{
    crossTarget.setPosition(loc);
}

void Manager::checkForReset()
{
    if (reset == true)
    {
        for (auto& s : sharks)
        {
            s->_fordeletion = true;
        }
        for (auto& s : fishes)
        {
            s->_fordeletion = true;
        }
        for (auto& s : bossEnemy)
        {
            s->_fordeletion = true;
        }
        for (auto& s : background->decorations)
        {
            s.setActive(false);
        }
        for (auto& s : foodObjects)
        {
            s->_fordeletion = true;
        }
        for (auto& s : foodObjects)
        {
            s->_fordeletion = true;
        }
        for (auto& s : currencyObjects)
        {
            s->_fordeletion = true;
        }
        chipsScore = 300;
    }
    reset = false;
}

void Manager::setupDashboard()
{
    dashboard.setTexture(dashBoard);
    dashboard.setTextureRect(IntRect(Vector2(0, 0), Vector2(1600, 80)));
    dashboard.setPosition(Vector2f(0, 0));
}