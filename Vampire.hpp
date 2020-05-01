/*********************************************************************
 ** Description: This is the Vampire header file for the Vampire class
 *********************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"
class Vampire : public Character{
public:
    Vampire();
    int randomAttack() override;
    int randomDefense() override;
    int attack() override;
    int defense() override;
};
#endif
