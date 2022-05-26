#include "Queue.h"
#include <iostream>
#include <utility>
#include <typeinfo>
#include "LinkedListQueue.h"
#include "VectorQueue.h"

int main()
{
    Queue test(QueueContainer::Vector);
    test.push(3);
    test.push(4);
    std::cout << test.top() << std::endl;
    test.pop();
    std::cout << test.top() << " " << test.size() << std::endl;

    return 0;
}

