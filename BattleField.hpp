/*********************************************************************
 ** Description: This is the BattleField header for the BattleField class
 *********************************************************************/
#ifndef BATTLEFIELD_HPP
#define BATTLEFIELD_HPP
#include "GamePlay.hpp"
class BattleField{
private:
    std:: shared_ptr<Queue> P1;
    std:: shared_ptr<Queue> P2;
    std:: shared_ptr<Queue> Loser;
    Menu menu;
    int points1;
    int points2;
public:
    BattleField();
    void initalize(Menu& menu);
    void fight();
    void results();
    void loserBracket();
    void currentFighters();
    void display();
    void points();
};
#endif
