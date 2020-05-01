/*********************************************************************
 ** Description: This is the Barbarian class that inherits from the Barbarian class with
 their own specific characteristics
 *********************************************************************/
#include "Barbarian.hpp"
//Barbarian constructor
//
Barbarian:: Barbarian(){
    Armor = 0;
    Strength = 12;
    baseStrength = 12;
    attackRoll = 2;
    defenseRoll = 2;
    type = "Barbarian";
}
//
//Overriden attack function
int Barbarian:: attack(){
//Calls random function
    Attack = 0;
    Attack = randomAttack();
    return Attack;
    }
//
//Overriden defense function
int Barbarian:: defense(){
    //Calls random function
    Defense = 0;
    Defense = randomDefense();
    return Defense;
}
//Specifc attack function for vampire
//
int Barbarian::randomAttack(){
    srand( static_cast<unsigned int>(time(NULL)));
    return (rand() %(6) + 1);
}
//Specifc defense function for vampire
//
int Barbarian::randomDefense(){
    srand( static_cast<unsigned int>(time(NULL)));
    return (rand() %(6) + 1);
}
