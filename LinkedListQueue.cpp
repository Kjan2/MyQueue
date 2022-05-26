#include "LinkedListQueue.h"
#include <iostream>


LinkedList::LinkedList(const LinkedList& copyList)
{
    //this->_head = nullptr;

    if (copyList._head == nullptr)
    {
        return;
    }

    Node* node = copyList._head;

    while (node)
    {
        this->push(node->value);
        node = node->next;
    } 
}


LinkedList& LinkedList::operator=(const LinkedList& copyList)
{
    this->_head = nullptr;

    if (copyList._head == nullptr)
    {
        return *this;
    }

    Node* node = copyList._head;

    while (node)
    {
        this->push(node->value);
        node = node->next;
    } 
    return *this;
}

LinkedList::LinkedList(LinkedList&& moveList)
{
    this->_head = moveList._head;
    moveList._head = nullptr;
}

LinkedList& LinkedList::operator=(LinkedList&& moveList)
{

    this->_head = moveList._head;
    moveList._head = nullptr;

    return *this;
}


LinkedList::~LinkedList()
{
    Node* nodeDelete = _head;
    while(nodeDelete != nullptr)
    {
        Node* next = nodeDelete->next;
        delete nodeDelete;
        nodeDelete = next;
    }
    _head = nullptr;
}


LinkedList::Node::Node(Value val, Node* nextNode) : value(val), next(nextNode)
{

}

LinkedList::Iterator::Iterator(Node* node) : _node(node) 
{

}

LinkedList::Iterator::~Iterator()
{

}

LinkedList::Iterator& LinkedList::Iterator::operator++()
{
    _node = _node->next;
    return *this;
}

LinkedList::Node& LinkedList::Iterator::operator*()
{
    return *_node;
}

const LinkedList::Node& LinkedList::Iterator::operator*() const
{
    return *_node;
}

LinkedList::Node*  LinkedList::Iterator::operator->()
{
    return _node;
}

const LinkedList::Node* LinkedList::Iterator::operator->() const
{
    return _node;
}

void LinkedList::push(const Value& value)
{
    if (_head == nullptr)
    {
        _head = new Node(value, nullptr);
        return;
    }

    Node* node = new Node(value, nullptr);
    
    Node* temp = _head;
    _head = node;
    node->next = temp;
}

void LinkedList::pop()
{
    if (_head == nullptr)
    {
        throw size();
    }
    

    Node* curr = _head;

    if((curr == _head) && (curr->next == nullptr))
    {
        delete _head;
        _head = nullptr;
        return;
    }
    
    while(curr->next->next)
    {
        curr = curr->next;
    }

    
    delete curr->next;

    curr->next = nullptr;
}

void LinkedList::print(Node* node)
{
    if (node == nullptr)
    {
        std::cout << "null";
        return;
    }
    std::cout << node->value <<"->";
    print(node->next);
}

void LinkedList::print()
{
    this->print(_head);
}

const Value& LinkedList::top() const
{
    if (!_head)
    {
        throw size();
    }
    
    Node* node = _head;
    while(node->next)
    {
        node = node->next;
    }
    return node->value;
}

bool LinkedList::isEmpty() const
{
    if(_head == nullptr)
    {
        return 1;
    }

    return 0;
}

size_t LinkedList::size() const
{
    if (!_head)   
    {
        return 0;
    }

    int i = 1;

    Node* node = _head;
    while(node->next)
    {
        node = node->next;
        i++;
    }
    return i;
}
