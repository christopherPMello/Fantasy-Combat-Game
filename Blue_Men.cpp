/*********************************************************************
 ** Description: This is the Blue Men class that inherits from the Blue Men class with
 their own specific characteristics
 *********************************************************************/
#include "Blue_Men.hpp"
//Blue Men constructor
//
Blue_Men:: Blue_Men(){
    Armor = 3;
    Strength = 12;
    baseStrength = 12;
    attackRoll = 2;
    defenseRoll = 3;
    type = "Blue Men";
}
//
//Overriden attack function
int Blue_Men:: attack(){
    //Calls random function
    Attack = 0;
    Attack = randomAttack();
    return Attack;
}
//
//Overriden Defense function
int Blue_Men:: defense(){
    //Calls random function
    Defense = 0;
    Defense = randomDefense();
    return Defense;
}
//Specifc attack function for Blue Men
//
int Blue_Men::randomAttack(){
    srand( static_cast<unsigned int>(time(NULL)));
    return (rand() %(10) + 1);
}
//Specifc attack function for Blue Men
//
int Blue_Men::randomDefense(){
    srand( static_cast<unsigned int>(time(NULL)));
    return (rand() %(6) + 1);
}
