/*********************************************************************
 ** Description: This is the GamePlay header file for the GamePlay class
 *********************************************************************/
#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
#include <chrono>
#include <thread>
#include "Queue.hpp"
class GamePlay{
private:
    int statusOne, statusTwo;
    int roll1, roll2, key, ag, again;
    int damage, counter;
    int potterLife1, potterLife2;
    std:: shared_ptr<Character> fighter1;
    std:: shared_ptr<Character> fighter2;
public:
    void initalize(std::shared_ptr<Character> ch1, std::shared_ptr<Character> ch2);
    void chooseFighter();
    void gameFlow();
    int rollDieAttack(std::shared_ptr<Character>&);
    int rollDieDefense(std::shared_ptr<Character>&);
    bool playerCheck(bool&, int);
    void results1();
    void results2();
    void health(int&);
    void potter();
    void vamp1(bool&);
    void vamp2(bool&);
    int randomVamp();
    void blue();
    void medusaWin(int, bool&, int&);
    void Check(bool&, bool&, bool&);
    
    bool getAg();
    int getAgain1();
    int getAgain2();
};
#endif
