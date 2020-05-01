/*********************************************************************
 ** Author:      Christopher Mello
 ** Date:        November 18, 2018
 ** Description: This program is an extension of the fight combat game.
                 The same rules apply for the comabt as defined witin
                 the character class and gamePlay classes however, there
                 is now a tournament. The user is allowed the ability to
                 choose the amount of characters per team and the type of
                 character they would like to have fight on their team. After
                 each fight, the game will display the queues of containing the
                 fighters in both teams as well as the loser queue. The game will
                 end when there are no more fighter left to battle for one team. 
 *********************************************************************/
#include <iostream>
#include "BattleField.hpp"
int main(){
    int t = 0;
//Creates menu object and obtains user information about which character they want
    Menu menu;
    menu.opening(t);
    menu.character_Descritption();
//will always interate at least once
    while(t == 1){
//clears all current member variables in the menu class
    menu.restart();
    menu.getNumOfCharacters();
//loops depending on the number of characters
    for(int i = 0; i < menu.getNumOfCharacters2();i++){
//Obtains character information
    menu.start_game();
    menu.nameOfFighters1();
    menu.start_game2();
    menu.nameOfFighters2();
    }
//conducts tournament
    BattleField b;
    b.initalize(menu);
    b.fight();
    t = menu.again();
    }
    return 0;
}
