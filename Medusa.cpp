#include "Medusa.hpp"
//Medusa constructor
//
Medusa:: Medusa(){
    Armor = 3;
    Strength = 8;
    baseStrength = 8;
    attackRoll = 2;
    defenseRoll = 1;
    type = "Medusa";
}
//
//Overriden attack function
int Medusa:: attack(){
    //Calls random function
    Attack = 0;
    Attack = randomAttack();
    return Attack;
}
//
//Overriden defense function
int Medusa:: defense(){
    //Calls random function
    Defense = 0;
    Defense = randomDefense();
    return Defense;
}
//Specifc attack function for Blue Men
//
int Medusa::randomAttack(){
    srand( static_cast<unsigned int>(time(NULL)));
    return (rand() %(6) + 1);
}
//Specifc defense function for Blue Men
//
int Medusa::randomDefense(){
    srand( static_cast<unsigned int>(time(NULL)));
    return (rand() %(6) + 1);
}
