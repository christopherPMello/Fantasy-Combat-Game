/*********************************************************************
 ** Description: This is the Queue header for the Queue class
 *********************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "QueueNode.hpp"
class Queue{
private:
    std:: shared_ptr<QueueNode> head;
    std:: shared_ptr<Character> fighter;
public:
    Queue();
    void chooseFighter(int);
    void addCharacter(std:: string);
    void deleteFront();
    void printQue();
    void deleteList();
    void nullFighter();
    void moveHead();
    std:: shared_ptr<Character> getFront();
    void addChar(std:: string, std:: shared_ptr<Character>);
    std:: string getName();
};
#endif
