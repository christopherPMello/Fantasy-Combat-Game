/*********************************************************************
 ** Description: This is the Character class that contains the get and set functions
                 for the rest of the characters who derive form this base class
 *********************************************************************/
#include "Character.hpp"
Character:: ~Character(){
}
//Recovery functions for characters
void Character:: recovery(){
    float roll;
    srand( static_cast<unsigned int>(time(NULL)));
    roll = ((rand() %(5) + 1) / 10);
    if((getStrength() * (1 + roll)) < baseStrength)
    setStrength((getStrength() * (1 + roll)));
    else
        setStrength(baseStrength);
}
//Get Functions
int Character:: getAttack(){
    return Attack;
}
int Character:: getDefence(){
    return Defense;
}
int Character:: getArmor(){
    return Armor;
}
int Character::getAttackRoles(){
    return attackRoll;
}
int Character::getDefenseRoles(){
    return defenseRoll;
}
std:: string Character:: getType(){
    return type;
}
int Character:: getStrength(){
    return Strength;
}
//Set functions
void Character::setAttack(int x){
    Attack = x;
}
void Character::setDefence(int x){
    Defense = x;
}
void Character::setArmor(int x){
    Armor = x;
}
void Character::setStrength(int x){
    Strength = x;
}
void Character::setDefenseRoll(int x){
    defenseRoll = x;
}
