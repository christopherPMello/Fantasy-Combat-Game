/*********************************************************************
 ** Description: This is the GamePlay class that serves as the general flow for the game.
                 This class is in charge of creating, retreiving information in reagrd to
                 character attacks and qualities, and accounting for the specific stength of each
                 character in battle
 *********************************************************************/
#include "GamePlay.hpp"
//Initalizes the main variables in the game
//
void GamePlay:: initalize(std::shared_ptr<Character> ch1, std::shared_ptr<Character> ch2){
    fighter1 = ch1;
    fighter2 = ch2;
    counter = potterLife1 = potterLife2 = ag = again = statusOne = statusTwo = 0;
}
//This functions serves as the general game flow and is in charge of the character accounting
//
void GamePlay:: gameFlow(){
//Initalized variables
    roll1 = 0;
    roll2 = 0;
    bool charm = true;
    bool turn = true;
    bool medusaWins = true;
//creates main while loop for entire game flow
    while(turn == true){
    if(turn == true){
//Determines if fighter 1 can attack due to vampires charm abilities
    vamp2(charm);
    if(charm == true){
//Gives fighter 1 the amount of rolls as determined in their class
    for(int i = 0; i < (fighter1->getAttackRoles()); i++){
    int temp = 0;
    temp = rollDieAttack(fighter1);
    roll1 += temp;
                }
//Checks if fighter 1 is medusa because of her glare attack imediate win
    if(fighter1->getType() == "Medusa")
    medusaWin(roll1, medusaWins, ag);
//Used to break out of the gameFlow function and return to ask user if they would like to play agin
        if(ag == 1)
            return;
            }
        }
    if(turn == true){
    if(medusaWins == true){
    if(charm == true){
//Gives fighter 1 the amount of rolls as determined in their class
    for(int i = 0; i < (fighter2->getDefenseRoles()); i++){
    int temp = 0;
    temp = rollDieDefense(fighter2);
    roll2 += temp;
    }
                }
           }
        }
        Check(charm, turn, medusaWins);
        if(ag == 1)
            return;
//Determines if fighter 1 can attack due to vampires charm abilities
            vamp1(charm);
            if(charm == true){
//Gives fighter 1 the amount of rolls as determined in their class
            for(int i = 0; i < (fighter2->getAttackRoles()); i++){
                int temp = 0;
                temp = rollDieAttack(fighter2);
                roll2 += temp;
                }
//Checks if fighter 1 is medusa because of her glare attack imediate win
                if(fighter2->getType() == "Medusa")
                medusaWin(roll2, medusaWins, ag);
                if(ag == 1)
                    return;
            }
        }
        if(turn == true){
            if(charm == true){
            if(medusaWins == true){
    //Gives fighter 1 the amount of rolls as determined in their class
            for(int i = 0; i < (fighter1->getDefenseRoles()); i++){
                int temp = 0;
                temp = rollDieDefense(fighter1);
                roll1 += temp;
                }
                }
            }
        }
    Check(charm, turn, medusaWins);
    if(ag == 1)
        return;
}
//Functions Check
//
void GamePlay:: Check(bool& charm, bool& turn, bool& medusaWins){
    //Checking function for all potential characters in the battle
    if(charm == true){
        if(counter % 2 == 0){
            playerCheck(turn, 1);
            blue();
            potter();
            results1();
            health(ag);
            //Used to break out of the gameFlow function and return to ask user if they would like to play agin
            if(ag == 1)
                return;
        }
        //Checking function for all potential characters in the battle
        else{
            playerCheck(turn, 2);
            blue();
            potter();
            results2();
            health(ag);
            if(ag == 1)
                return;
        }
    }
    medusaWins = true;
    counter++;
    roll1 = 0;
    roll2 = 0;
}
//Calculates the players strengths and attack/defense
//
bool GamePlay:: playerCheck(bool& turn, int strike){
    int defense = 0, attack = 0;
    damage = 0;
//Depending on which player attacks we calculate the strengths
    if(strike == 1){
    defense += roll2;
    defense += fighter2->getArmor();
    attack += roll1;
        if(attack > defense){
    damage = attack - defense;
    fighter2->setStrength(fighter2->getStrength() - damage);
        }
    }
    if(fighter2->getStrength() <= 0){
        return false;
    }
//Depending on which player attacks we calculate the strengths
    if(strike == 2){
        defense += roll1;
        defense += fighter1->getArmor();
        attack += roll2;
        if(attack > defense){
            damage = attack - defense;
            fighter1->setStrength(fighter1->getStrength() - damage);
        }
    }
    if(fighter1->getStrength() <= 0){
        return false;
    }
    else
        return true;
}
//After each succession of attack and defense, we present the following information
//
void GamePlay::results1(){
    int strength;
    if(fighter2->getStrength() <= 0)
        strength = 0;
    else
        strength = fighter2->getStrength();
}
//After each succession of attack and defense, we present the following information
//
void GamePlay::results2(){
    int strength;
    if(fighter1->getStrength() <= 0)
        strength = 0;
    else
        strength = fighter1->getStrength();
}
//Calcuates if each player is still alive
//
void GamePlay::health(int& again){
//Calculates players health and makes sure they are both above 0
    if(fighter1->getStrength() <= 0){
    statusTwo = 1;
    again = 1;
    }
//Calculates players health and makes sure they are both above 0
    else if(fighter2->getStrength() <= 0){
    statusOne = 1;
    again = 1;
    }
}
//Specific function for harry potter to recalulate his health upon death
//
void GamePlay:: potter(){
    if((fighter1->getType() == "Harry Potter") && (potterLife1 == 0) && (fighter1->getStrength() <= 0)){
        fighter1->setStrength(20);
        potterLife1 += 1;
    }
    if((fighter2->getType() == "Harry Potter") && (potterLife2 == 0) && (fighter2->getStrength() <= 0)){
        fighter2->setStrength(20);
        potterLife2 += 1;
    }
}
//Specific function for vampire to determine if that fighter used charm or not
//
void GamePlay:: vamp1(bool& hit){
    if((fighter1->getType() == "Vampire") && randomVamp() == 1){
    hit = false;
    }
    else
        hit = true;
}
//Specific function for vampire to determine if that fighter used charm or not
//
void GamePlay:: vamp2(bool& hit){
    if((fighter2->getType() == "Vampire") && randomVamp() == 1){
        hit = false;
    }
    else
        hit = true;
}
//Recalculates the defense roll ability depending on the blue men health
//
void GamePlay:: blue(){
    if((fighter1->getStrength() <= 8) && (fighter1->getType() == "Blue Men"))
        fighter1->setDefenseRoll(2);
    if((fighter1->getStrength() <= 4) && (fighter1->getType() == "Blue Men"))
        fighter1->setDefenseRoll(1);
    
    if((fighter2->getStrength() <= 8) && (fighter2->getType() == "Blue Men"))
        fighter2->setDefenseRoll(2);
    if((fighter2->getStrength() <= 4) && (fighter2->getType() == "Blue Men"))
        fighter2->setDefenseRoll(1);
}
//This function is specifically for the special case of is medusa kills harry potter on his first life
//
void GamePlay:: medusaWin(int x, bool& win, int& again){
//Calculates if game is over depending on harry potters life count
    if((fighter1->getType() == "Medusa") && (x == 12)&& (fighter2-> getType() == "Harry Potter") && (potterLife2 == 1)){
        std:: cout << "Fighter 1 Wins!" << std:: endl;
        statusOne = 1;
        again = 1;
    }
//Calculates if game is over depending on harry potters life count
    if((fighter1->getType() == "Medusa") && (x == 12) && (fighter2-> getType() != "Harry Potter")){
        std:: cout << "Fighter 1 Wins!" << std:: endl;
        statusOne = 1;
        again = 1;
    }
//Calculates if game is over depending on harry potters life count
    if((fighter1->getType() == "Medusa") && (x == 12)&& (fighter2-> getType() == "Harry Potter") && (potterLife2 == 0)){
        fighter2->setStrength(20 + x);
        potterLife2 += 1;
        win = false;
    }
//Calculates if game is over depending on harry potters life count
    if((fighter2->getType() == "Medusa") && (x == 12)&& (fighter1-> getType() == "Harry Potter") && (potterLife1 == 1)){
        std:: cout << "Fighter 2 Wins!" << std:: endl;
        statusTwo = 1;
        again = 1;
    }
//Calculates if game is over depending on harry potters life count
    if((fighter2->getType() == "Medusa") && (x == 12) && (fighter1-> getType() != "Harry Potter")){
        std:: cout << "Fighter 2 Wins!" << std:: endl;
        statusTwo = 1;
        again = 1;
    }
//Calculates if game is over depending on harry potters life count
    if((fighter2->getType() == "Medusa") && (x == 12)&& (fighter1-> getType() == "Harry Potter") && (potterLife1 == 0)){
        fighter1->setStrength(20 + x);
        potterLife1 += 1;
        win = false;
    }
}
//Returns either 1 or 2 for the vampire charm ability
//
int GamePlay:: randomVamp(){
    srand( static_cast<unsigned int>(time(NULL)));
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    return (rand() %(2) + 1);
}
//Retreives the attack from each character
//
int GamePlay:: rollDieAttack(std:: shared_ptr<Character>& fighter){
    return fighter->randomAttack();
}
int GamePlay:: rollDieDefense(std:: shared_ptr<Character>& fighter){
    return fighter->randomDefense();
}
//Deletes all character info to avoid memory leaks and to set up game if user wants to play again
//
bool GamePlay:: getAg(){
    return ag;
}
int GamePlay:: getAgain2(){
    return statusTwo;
}
int GamePlay:: getAgain1(){
    return statusOne;
}
