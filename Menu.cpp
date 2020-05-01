/*********************************************************************
 ** Description: This is the Menu class that obtains user information about character choice and
                 willingness to play the game simulatiion
 *********************************************************************/
#include "Menu.hpp"
#include <cstdlib>
//Begining function to determine if user wants to play the game
//
void Menu:: opening(int& start){
    std:: cout << "Would you like to play the Fantasy Combat Game?" << std:: endl;
    std:: cout << "1) Yes" << std:: endl;
    std:: cout << "2) No" << std:: endl;
    std:: cin >> start;
    integerCheck12(start);
    
    if(start == 2)
        exit(0);
}
//Begining function to inform user about the qualities of each character
//
void Menu:: character_Descritption(){
    std:: cout << "~Vampire Description~" << std:: endl;
    std:: cout << "Description: Suave, debonair, but vicious and surprisingly resilient" << std:: endl;
    std:: cout << "Attack: 1 die roll up to 12 attack" << std:: endl;
    std:: cout << "Defense: 1 die roll up to 6 defense" << std:: endl;
    std:: cout << "Armor: 1 armor" << std:: endl;
    std:: cout << "Strength: 18" << std:: endl;
    std:: cout << "Special Power: Charm: Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their opponent does not actually attack them" << std:: endl;
    std:: cout << std:: endl;
    
    std:: cout << "~Barbarian Description~" << std:: endl;
    std:: cout << "Description: Think Conan or Hercules from the movies. Big sword, big muscles, bare torso" << std:: endl;
    std:: cout << "Attack: 2 dice rolls up to 6 attack each" << std:: endl;
    std:: cout << "Defense: 2 dice rolls up to 6 defense each" << std:: endl;
    std:: cout << "Armor: 0 armor" << std:: endl;
    std:: cout << "Strength: 12" << std:: endl;
    std:: cout << "Special Power: No special power" << std:: endl;
    std:: cout << std:: endl;
    
    std:: cout << "~Blue Men Description~" << std:: endl;
    std:: cout << "Description: They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies’ armor or clothing." << std:: endl;
    std:: cout << "Attack: 2 dice rolls up to 10 attack each" << std:: endl;
    std:: cout << "Defense: 3 dice rolls up to 6 defense each" << std:: endl;
    std:: cout << "Armor: 3 armor" << std:: endl;
    std:: cout << "Strength: 12" << std:: endl;
    std:: cout << "Special Power: Mob: Blue Men are actually a swarm of small individuals. For every 4 points of damage, they lose one defense die. For example, if they have a strength of 8, they would have 2d6 for defense." << std:: endl;
    std:: cout << std:: endl;
   
    std:: cout << "~Medusa Description~" << std:: endl;
    std:: cout << "Description: Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!" << std:: endl;
    std:: cout << "Attack: 2 dice rolls up to 6 attack each" << std:: endl;
    std:: cout << "Defense: 1 die roll up to 6 defense each" << std:: endl;
    std:: cout << "Armor: 3 armor" << std:: endl;
    std:: cout << "Strength: 8" << std:: endl;
    std:: cout << "Special Power: Glare: If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter on his first life, then Harry Potter comes back to life." << std:: endl;
    std:: cout << std:: endl;
    
    std:: cout << "~Harry Potter Description~" << std:: endl;
    std:: cout << "Description: Harry Potter is a wizard." << std:: endl;
    std:: cout << "Attack: 2 dice rolls up to 6 attack each" << std:: endl;
    std:: cout << "Defense: 2 dice rolls up to 6 defense each" << std:: endl;
    std:: cout << "Armor: 0 armor" << std:: endl;
    std:: cout << "Strength: 10/20" << std:: endl;
    std:: cout << "Special Power: Hogwarts: If Harry Potter's strength reaches 0 or below, he immediately recovers and his total strength becomes 20. If he were to die again, then he’s dead." << std:: endl;
    std:: cout << std:: endl;
    
    std:: cout << "~Extra Notes~" << std:: endl;
    std:: cout << "If Medusa uses “glare” on Harry Potter on his first life, then Harry Potter comes back to life after using “hogwarts" << std:: endl;
    std:: cout << "If the Vampire’s “charm” ability activates when Medusa uses “glare”, the Vampire’s charm trumps Medusa’s glare" << std:: endl;
    std:: cout << std:: endl;
}
//Obtains info on what characters they would like to have battle for team 1
//
void Menu:: start_game(){
    std:: cout << "Please choose a character to fight for team 1" << std:: endl;
    std:: cout << "1) Vampire" << std:: endl;
    std:: cout << "2) Barbarian" << std:: endl;
    std:: cout << "3) Blue Men" << std:: endl;
    std:: cout << "4) Medusa" << std:: endl;
    std:: cout << "5) Harry Potter" << std:: endl;
    std:: cin >> character1;
    integerCheckCh(character1);
    vecNum1.push_back(character1);
    std:: cout << std:: endl;

}
//Obtains info on what characters they would like to have battle for team 2
//
void Menu:: start_game2(){
    std:: cout << "Please choose a character to fight for team 2" << std:: endl;
    std:: cout << "1) Vampire" << std:: endl;
    std:: cout << "2) Barbarian" << std:: endl;
    std:: cout << "3) Blue Men" << std:: endl;
    std:: cout << "4) Medusa" << std:: endl;
    std:: cout << "5) Harry Potter" << std:: endl;
    std:: cin >> character2;
    integerCheckCh(character2);
    vecNum2.push_back(character2);
    std:: cout << std:: endl;
}
//Standard integer checking function
//
void Menu:: integerCheck(int& var){
    while(!var || var <= 0){
    std:: cout << "Please enter a valid number" << std:: endl;
    std:: cin.clear();
    std:: cin.ignore();
    std:: cin >> var;
    }
}
//Integer Checking function for a two option choice
//
void Menu:: integerCheck12(int& var){
    integerCheck(var);
    while(var != 1 && var != 2){
        std:: cout << "please enter a valid number option" << std:: endl;
        std:: cin.clear();
        std:: cin.ignore();
        std:: cin >> var;
        integerCheck(var);
    }
}
//Integer check for which characters the user wants to choose
//
void Menu:: integerCheckCh(int& var){
    integerCheck(var);
    while(var != 1 && var != 2 && var != 3 && var != 4 && var != 5){
        std:: cout << "please enter a valid number option" << std:: endl;
        std:: cin.clear();
        std:: cin.ignore();
        std:: cin >> var;
        integerCheck(var);
    }
}
//Play again function
//
int Menu:: again(){
    int again;
    std:: cout << "Would you like to play again?" << std:: endl;
    std:: cout << "1) Yes" << std:: endl;
    std:: cout << "2) No" << std:: endl;
    std:: cin.clear();
    std:: cin >> again;
    integerCheck12(again);
    return again;
}
//Obtains the number of characters per team
//
void Menu:: getNumOfCharacters(){
    std:: cout << "How many fighters would you like per team?" << std:: endl;
    std:: cin >> numOfCharacters;
}
//Obtains the name of each fighter and enters that information into a vector for
//team 1
void Menu:: nameOfFighters1(){
    std:: string name;
    std:: cout << "What is that fighters name? " << std:: endl;
    std:: cin.clear();
    std:: cin.ignore();
    getline(std:: cin, name);
    vecString1.push_back(name);
}
//Obtains the name of each fighter and enters that information into a vector
//for team 2
void Menu:: nameOfFighters2(){
    std:: string name;
    std:: cout << "What is that fighters name? " << std:: endl;
    std:: cin.clear();
    std:: cin.ignore();
    getline(std:: cin, name);
    vecString2.push_back(name);
}
//Initalizes the characters to zero
//
void Menu::characterInital(){
    character1 = 0;
    character2 = 0;
}
//Clears all the member variables if user chooses to play the game again
//
void Menu:: restart(){
    vecString1.clear();
    vecString2.clear();
    vecNum1.clear();
    vecNum2.clear();
}
//Get functions
//
const std:: vector<int>& Menu:: getCharacter1(){
    return vecNum1;
}
const std:: vector<int>& Menu:: getCharacter2(){
    return vecNum2;
}
std:: vector<std:: string>& Menu:: getString1(){
    return vecString1;
}
std:: vector<std:: string>& Menu:: getString2(){
    return vecString2;
}
int Menu:: getNumOfCharacters2(){
    return numOfCharacters;
}
