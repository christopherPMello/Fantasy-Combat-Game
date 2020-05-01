/*********************************************************************
 ** Description: This is the Vampire header file for the Vampire class
 *********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Character.hpp"
class Barbarian : public Character{
    public:
    Barbarian();
    int randomAttack() override;
    int randomDefense() override;
    int attack() override;
    int defense() override;
};
#endif


