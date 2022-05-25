#pragma once
#include "QueueImplementation.h"
using Value = double;
class LinkedList : public IQueueImplementation
{
public:

    
    struct Node
    {
        Node(Value val, Node* nextNode);
        Value value;
        Node* next;
    };


    class Iterator
    {
    private:
        Node* _node;
    public:
        explicit Iterator(Node* node);
        Iterator() = default;
        ~Iterator();

        Iterator& operator++();
        Node& operator*();
        const Node& operator*() const;
        Node* operator->();
        const Node* operator->() const;
    };

    LinkedList() = default;

    LinkedList(const LinkedList& copyList);
    LinkedList& operator=(const LinkedList& copyList);

    LinkedList(LinkedList&& moveList);
    LinkedList& operator=(LinkedList&& moveList);

    ~LinkedList();

    void print(Node* node);
    void print();
    
    void push(const Value& value);
    void pop();

    const Value& top() const;

    bool isEmpty() const;

    size_t size() const;
private:
    Node* _head = nullptr;
};
