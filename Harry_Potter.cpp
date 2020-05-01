#include "Harry_Potter.hpp"
//Harry Potter destructor
Harry_Potter:: Harry_Potter(){
    Armor = 0;
    Strength = 10;
    baseStrength = 10;
    attackRoll = 2;
    defenseRoll = 2;
    type = "Harry Potter";
}
//
//Overriden attack function
int Harry_Potter:: attack(){
    //Calls random function
    Attack = 0;
    Attack = randomAttack();
    return Attack;
}
//
//Overriden defense function
int Harry_Potter:: defense(){
    //Calls random function
    Defense = 0;
    Defense = randomDefense();
    return Defense;
}
//Specifc attack function for Blue Men
//
int Harry_Potter::randomAttack(){
    srand( static_cast<unsigned int>(time(NULL)));
    return (rand() %(6) + 1);
}
//Specifc defense function for Blue Men
//
int Harry_Potter::randomDefense(){
    srand( static_cast<unsigned int>(time(NULL)));
    return (rand() %(6) + 1);
}
