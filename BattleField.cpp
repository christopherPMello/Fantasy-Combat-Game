/*********************************************************************
 ** Description: This is the BattleField class that holds the primary
                 tournament style for each game
 *********************************************************************/
#include "BattleField.hpp"
//Creates queues for the member variables within BattleField
//
BattleField:: BattleField(){
    P1 = std:: make_shared<Queue>();
    P2 = std:: make_shared<Queue>();
    Loser = std:: make_shared<Queue>();
    points1 = 0;
    points2 = 0;
}
//Transports information obtained from the menu class and creates characters
//in BattleField
void BattleField:: initalize(Menu& menu){
    this->menu = menu;
//passes in the information gained from menu into BattleField vectors
    std:: vector<int> vecNum1 = menu.getCharacter1();
    std:: vector<std:: string> vecString1 = menu.getString1();
    std:: vector<int> vecNum2 = menu.getCharacter2();
    std:: vector<std:: string> vecString2 = menu.getString2();
    for(int i = 0; i < vecNum1.size(); i++){
//Creates a fighter and adds the name to that fighter object
        P1->chooseFighter(vecNum1.at(i));
        P1->addCharacter(vecString1.at(i));
        P2->chooseFighter(vecNum2.at(i));
        P2->addCharacter(vecString2.at(i));
    }
}
//The overall gameflow function that keeps track of each movement within the
//tournament
void BattleField:: fight(){
    while(P1->getFront() != nullptr || P1->getFront() != nullptr){
    GamePlay g;
    g.initalize(P1->getFront(), P2->getFront());
    std:: cout << "Fight is commencing!" << std:: endl;
    g.gameFlow();

//If player number 1 wins, we display the following information and
//increment points1 variable by 2. The player 2 que is lessened by 1 player and
//added to the back of the loser que. The player 1 character who won is placed
//in the back of the que.
    if(g.getAgain1() == 1){
        std:: cout << std:: endl;
        std:: cout << "Oh Wow! Two Points for Team 1!" << std:: endl;
        points1 += 2;
        display();
        Loser->addChar(P2->getName(), P2->getFront());
        loserBracket();
//restores damaged player
        P1->getFront()->recovery();
        P1->moveHead();
        P2->deleteFront();
        currentFighters();
        if(P2->getFront() == nullptr)
            break;
//lefts intentionally for breaking up tournaments into sections
        //std:: cout << "Press any key to continue!" << std:: endl;
        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
//If player number 2 wins, we display the following information and
//increment points2 variable by 2. The player 1 que is lessened by 1 player and
//added to the back of the loser que. The player 2 character who won is placed
//in the back of the que.
    else if(g.getAgain2() == 1){
        std:: cout << std:: endl;
        std:: cout << "Oh Wow! Two Points for Team 2!" << std:: endl;
        points2 += 2;
        display();
        Loser->addChar(P1->getName(), P1->getFront());
        loserBracket();
//restores damaged player
        P2->getFront()->recovery();
        P2->moveHead();
        P1->deleteFront();
        currentFighters();
        if(P1->getFront() == nullptr)
            break;
//lefts intentionally for breaking up tournaments into sections
        //std:: cout << "Press any key to continue!" << std:: endl;
        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
//If the game is over, we display which team won
//
    if(P1->getFront() == nullptr)
        std:: cout << std:: endl << "Team 2 is the winner! " << std:: endl << std:: endl;
    if(P2->getFront() == nullptr)
        std:: cout << std:: endl<< "Team 1 is the winner! " << std:: endl << std:: endl;
    points();
}
//Displays the information within the loser bracket
//
void BattleField:: loserBracket(){
    std:: cout << "Losers Bracket:" << std:: endl;
    Loser->printQue();
    std:: cout << std:: endl;
}
//Displays the ending stance for characters within each team
//
void BattleField:: currentFighters(){
    std:: cout << "Team 1 Remaining: " << std:: endl;
    P1->printQue();
    std:: cout << std:: endl;
    std:: cout << "Team 2 Remaining: " << std:: endl;
    P2->printQue();
}
//Displays the ending result after each fight
//
void BattleField:: display (){
    std:: cout << "*****************************************" << std:: endl;
    std:: cout << "Team one fighter: " << P1->getFront()->getType() << ", Formally known as " << P1->getName() << std:: endl;
    std:: cout << "Team two fighter: " << P2->getFront()->getType() << ", Formally known as " << P2->getName() << std:: endl;
    points();
    std:: cout << "*****************************************" << std:: endl;
}
//Dislays the number of points for each team
//
void BattleField:: points(){
    std:: cout << "Team 1 has: " << points1 << " points" << std:: endl;
    std:: cout << "Team 2 has: " << points2 << " points" << std:: endl;
}
