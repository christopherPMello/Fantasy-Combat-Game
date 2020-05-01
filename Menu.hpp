/*********************************************************************
 ** Description: This is the Menu header file for the Menu class
 *********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <vector>
class Menu{
private:
    int character1, character2, play_again;
    int numOfCharacters;
    std:: vector<std:: string> vecString1;
    std:: vector<std:: string> vecString2;
    std:: vector<int>vecNum1;
    std:: vector<int>vecNum2;
public:
    void opening(int& start);
    void character_Descritption();
    void Display();
    void results(int);
    int  again();
    void integerCheck(int&);
    void integerCheckCh(int&);
    void integerCheck12(int& var);
    const std:: vector<int>&  getCharacter1();
    const std:: vector<int>&  getCharacter2();
    std:: vector<std:: string>& getString1();
    std:: vector<std:: string>& getString2();
    void characterInital();
    
    void start_game();
    void start_game2();
    void getNumOfCharacters();
    int getNumOfCharacters2();
    void nameOfFighters1();
    void nameOfFighters2();
    void restart();
};
#endif
