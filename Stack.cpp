#include "Queue.h"
#include "LinkedListQueue.h"
#include "VectorQueue.h"
#include "QueueImplementation.h"
#include <stdexcept>
#include <iostream>

Queue::Queue(QueueContainer container)
    : _containerType(container)
{
    switch (container)
    {
        case QueueContainer::List:
        {
            _pimpl = static_cast<IQueueImplementation*>(new LinkedList());
            break;
        }
        case QueueContainer::Vector: 
        {
            _pimpl = static_cast<IQueueImplementation*>(new Vector());
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Queue::Queue(const ValueType* valueArray, const size_t arraySize, QueueContainer container) 
    : _containerType(container)
{
    switch (container)
    {
        case QueueContainer::List:
        {
            _pimpl = static_cast<IQueueImplementation*>(new LinkedList());

            for (int i = 0; i < arraySize; i++)
            {
                _pimpl->push(valueArray[i]);
            }

            break;
        }
        case QueueContainer::Vector:
        {
            _pimpl = static_cast<IQueueImplementation*>(new Vector(valueArray, arraySize)); 
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Queue::Queue(const Queue& copyQueue)
{
   
    switch (copyQueue._containerType)
    {
        case QueueContainer::List: 
        {
            _pimpl = static_cast<IQueueImplementation*>(new LinkedList(*(static_cast<LinkedList*>(copyQueue._pimpl))));
            this->_containerType = QueueContainer::List;
            break;
        }
        case QueueContainer::Vector:
        {
            _pimpl = static_cast<IQueueImplementation*>(new Vector(*(static_cast<Vector*>(copyQueue._pimpl))));
            this->_containerType = QueueContainer::Vector;
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Queue& Queue::operator=(const Queue& copyQueue)
{
    switch (copyQueue._containerType)
    {
        case QueueContainer::List: {
            if (this == &copyQueue)
            {
                return *this;
            }
            delete this->_pimpl;
            _pimpl = static_cast<IQueueImplementation*>(new LinkedList(*(static_cast<LinkedList*>(copyQueue._pimpl))));
            this->_containerType = QueueContainer::List;
            return *this;
            break;
        }

        case QueueContainer::Vector: {
            if (this == &copyQueue)
            {
                return *this; 
            }
            delete this->_pimpl;
            _pimpl = static_cast<IQueueImplementation*>(new Vector(*(static_cast<Vector*>(copyQueue._pimpl))));
            this->_containerType = QueueContainer::Vector;
            return *this;
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Queue::Queue(Queue&& moveQueue) noexcept
{
    switch (moveQueue._containerType)
    {
        case QueueContainer::List: {
            this->_pimpl = moveQueue._pimpl;
            moveQueue._pimpl = nullptr;
            this->_containerType = QueueContainer::List;
            break;
        }
        case QueueContainer::Vector: {
            this->_pimpl = moveQueue._pimpl;
            moveQueue._pimpl = nullptr;
            this->_containerType = QueueContainer::Vector;
            break;
        }

        default: 
        {
        }
    }
}

Queue& Queue::operator=(Queue&& moveQueue) noexcept
{
    switch (moveQueue._containerType)
    {
        case QueueContainer::List: 
        {   
            if (this == &moveQueue)
            {
                return *this;
            }
            delete this->_pimpl;
            this->_pimpl = moveQueue._pimpl;
            moveQueue._pimpl = nullptr;
            this->_containerType = QueueContainer::List;
            return *this;
            break;
        }
        case QueueContainer::Vector: 
        {
            if (this == &moveQueue)
            {
                return *this;
            }
            delete this->_pimpl;
            this->_pimpl = moveQueue._pimpl;
            moveQueue._pimpl = nullptr;
            this->_containerType = QueueContainer::Vector;
            return *this;
            break;
        }

        default:
        {
            return *this;
        }
    }    
}


Queue::~Queue()
{
    delete _pimpl; 
}

void Queue::push(const ValueType& value)
{
    // можно, т.к. push определен в интерфейсе
    _pimpl->push(value);
}

void Queue::pop()
{
    _pimpl->pop();
}

const ValueType& Queue::top() const
{
    return _pimpl->top();
}

bool Queue::isEmpty() const
{
    return _pimpl->isEmpty();
}

size_t Queue::size() const
{
    return _pimpl->size();
}

