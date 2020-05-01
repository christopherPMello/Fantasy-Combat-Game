/*********************************************************************
 ** Description: This is the Queue data structure that holds the character
                 for each team as well as the loser pile.
 *********************************************************************/
#include "Queue.hpp"
//Creates a QueueNode and sets the self and next to nullptr
//
Queue:: Queue(){
    head = std:: make_shared<QueueNode>();
    head->self = nullptr;
    head->next = nullptr;
}
//Creates the object depending on the user inputted request and sets
//the fighter pointer looking to that object
void Queue:: chooseFighter(int character){
    if (character == 1)
        fighter = std:: make_shared<Vampire>();
    else if(character == 2)
        fighter = std:: make_shared<Barbarian>();
    else if(character == 3)
        fighter = std:: make_shared<Blue_Men>();
    else if(character == 4)
        fighter = std:: make_shared<Medusa>();
    else if(character == 5)
        fighter = std:: make_shared<Harry_Potter>();
}
//Adds the character currently created into the queueNode list and
//adds the name of the player as per user request
void Queue:: addCharacter(std:: string name){
    if(head->self == nullptr){
        head->self = fighter;
        head->name = name;
    }
    else{
        std:: shared_ptr<QueueNode> que = std::make_shared<QueueNode>();
        que->self = fighter;
        que->name = name;
        que->next = head;
        head = que;
    }
}
//This function is specifically for the loser brakcet. We do not create a new
//objects, simply pass the object to the loser queue
void Queue:: addChar(std:: string name, std:: shared_ptr<Character> fight){
    if(head->self == nullptr){
        head->self = fight;
        head->name = name;
    }
    else{
        std:: shared_ptr<QueueNode> que = std::make_shared<QueueNode>();
        que->self = fight;
        que->name = name;
        que->next = head;
        head = que;
    }
}
//Removes the front of the queue after fighter dies
//
void Queue:: deleteFront(){
    if(head == nullptr)
        return;
    if(head->next == nullptr){
        head = nullptr;
    }
    else{
        std:: shared_ptr<QueueNode> q;
        q = head;
        q = q->next;
        head = q;
    }
}
//Returns the first character in the queueu
//
std:: shared_ptr<Character> Queue:: getFront(){
    if(head == nullptr)
        return nullptr;
    else
        return head->self;
}
//Displays the contents of the entire que
//
void Queue:: printQue(){
    std:: shared_ptr<QueueNode> q;
    q = head;
    if(head == nullptr)
        return;
    else
    do{
        std:: cout << q->name << std:: endl;
        q = q->next;
        }
        while(q != nullptr);
}
//Sets the fighter variable to null for next created fighter
//
void Queue:: nullFighter(){
    fighter = nullptr;
}
//Moves the head character from the front to the back of the queue
//
void Queue:: moveHead(){
    if(head == nullptr)
        return;
    else if(head->next == nullptr)
    head->self->recovery();
    else
    {
    std:: shared_ptr<QueueNode> q = std::make_shared<QueueNode>();
    std:: shared_ptr<QueueNode> que = std::make_shared<QueueNode>();
    q = head;
    que = head;
    head = head->next;
    
    while(q->next != nullptr)
    q = q->next;
    q->next = que;
    que->next = nullptr;
    }
}
//Get function
std:: string Queue:: getName(){
return head->name;
}
