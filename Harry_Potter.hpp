/*********************************************************************
 ** Description: This is the Harry Potter header file for the Harry Potter class
 *********************************************************************/
#ifndef HAPPY_POTTER_HPP
#define HAPPY_POTTER_HPP
#include "Character.hpp"
class Harry_Potter : public Character{
public:
    Harry_Potter();
    int randomAttack() override;
    int randomDefense() override;
    int attack() override;
    int defense() override;
};
#endif
