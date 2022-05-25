#pragma once
// Уровень абстракции
// клиентский код подключает именно этот хедер
#include <stdio.h>
// тип значений в стеке
using ValueType = double;

// на основе какого контейнера работает стек
enum class QueueContainer {
    Vector = 0,
    List,
    // можно дополнять другими контейнерами
};

// декларация интерфейса реализации
class IQueueImplementation;

class Queue
{
public:
    // Большая пятерка
    Queue(QueueContainer container = QueueContainer::Vector);
    // элементы массива последовательно подкладываются в стек
    Queue(const ValueType* valueArray, const size_t arraySize, 
          QueueContainer container = QueueContainer::Vector);

    explicit Queue(const Queue& copyQueue);
    Queue& operator=(const Queue& copyQueue);

    // Здесь как обычно
    Queue(Queue&& moveQueue) noexcept;
    Queue& operator=(Queue&& moveQueue) noexcept;

    ~Queue();

    // добавление в начало
    void push(const ValueType& value);
    // удаление с хвоста
    void pop();
    // посмотреть элемент в хвосте
    const ValueType& top() const;
    // проверка на пустоту
    bool isEmpty() const;
    // размер 
    size_t size() const;

private:
    // указатель на имплементацию (уровень реализации)
    IQueueImplementation* _pimpl = nullptr;
    // тип контейнера, наверняка понадобится
    QueueContainer _containerType;
};

