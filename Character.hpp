/*********************************************************************
 ** Description: This is the Character header file for the Character class
 *********************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <chrono>
#include <thread>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
class Character{
protected:
int Attack, Defense, Armor, Strength, attackRoll, defenseRoll;
    std:: string type;
    int baseStrength;
public:
    virtual ~Character();
    virtual int attack() = 0;
    virtual int defense() = 0;
    virtual int randomAttack() = 0;
    virtual int randomDefense() = 0;
    void recovery();
//Get Functions
    int getAttack();
    int getDefence();
    int getArmor();
    int getStrength();
    int getAttackRoles();
    int getDefenseRoles();
    std:: string getType();
//Set Functions
    void setAttack(int);
    void setDefence(int);
    void setArmor(int);
    void setStrength(int);
    void setDefenseRoll(int);
};
#endif
