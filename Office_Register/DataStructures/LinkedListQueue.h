#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H

#include "Queue.h"
#include "DLList.h"

template <typename E>

class LinkedListQueue : public Queue<E> {
    private:
        DLList<E> myQueue;        

    public:
        LinkedListQueue();
        ~LinkedListQueue();
        void clear();
        void enqueue(const E& item);
        E dequeue();
        E frontValue();
        int length();
};

template <typename E>
LinkedListQueue<E>::LinkedListQueue() { }

template <typename E>
LinkedListQueue<E>::~LinkedListQueue() { }

template <typename E>
void LinkedListQueue<E>::clear() {
    while(!myQueue.isEmpty()) {
        myQueue.removeFront();
    }
}

template <typename E>
void LinkedListQueue<E>::enqueue(const E& item) {
    myQueue.insertBack(item);
}

template <typename E>
E LinkedListQueue<E>::dequeue() {
    return myQueue.removeFront();
}

template <typename E>
E LinkedListQueue<E>::frontValue() {
    return myQueue.peekFront();
}


template <typename E>
int LinkedListQueue<E>::length() {
    return myQueue.length();
}
#endif
