/*********************************************************************
 ** Description: This is the Vampire class that inherits from the Character class with
                 their own specific characteristics
 *********************************************************************/
#include "Vampire.hpp"
//Vampire constructor
//
Vampire:: Vampire(){
    Armor = 1;
    Strength = 18;
    baseStrength = 18;
    attackRoll = 1;
    defenseRoll = 1;
    type = "Vampire";
}
//
//Overriden attack function
int Vampire:: attack(){
    //Calls random function
    Attack = 0;
    Attack = randomAttack();
    return Attack;
}
//
//Overriden defense function 
int Vampire:: defense(){
    //Calls random function
    Defense = 0;
    Defense = randomDefense();
    return Defense;
}
//Specifc attack function for vampire
//
int Vampire::randomAttack(){
    srand( static_cast<unsigned int>(time(NULL)));
    return (rand() %(12) + 1);
}
//Specifc defense function for vampire
//
int Vampire::randomDefense(){
    srand( static_cast<unsigned int>(time(NULL)));
    return (rand() %(6) + 1);
}
