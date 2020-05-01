/*********************************************************************
 ** Description: This is the QueueNode header for the QueueNode class
 *********************************************************************/
#ifndef QueueNode_hpp
#define QueueNode_hpp
#include <memory>
#include "Character.hpp"
#include "Menu.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
class QueueNode{
public:
    QueueNode();
    std:: shared_ptr<QueueNode> next;
    std:: shared_ptr<Character> self;
    std:: string name;
};
#endif
