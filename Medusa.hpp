/*********************************************************************
 ** Description: This is the Medusa header file for the Medusa class
 *********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Character.hpp"
class Medusa : public Character{
public:
    Medusa();
    int randomAttack() override;
    int randomDefense() override;
    int attack() override;
    int defense() override;
};
#endif
