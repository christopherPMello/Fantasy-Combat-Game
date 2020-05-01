/*********************************************************************
 ** Description: This is the Blue Men header file for the Blue Men class
 *********************************************************************/
#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP
#include "Character.hpp"
class Blue_Men : public Character{
public:
    Blue_Men();
    int randomAttack() override;
    int randomDefense() override;
    int attack() override;
    int defense() override;
};
#endif
