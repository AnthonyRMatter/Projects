#ifndef ALIST_H
#define ALIST_H 

#include "List.h"

template <typename E>
class Alist : public List<E> {

    private:
        int maxSize; // maximum size of the list
        int listSize; // number of elements in the list right now
        int curr; // position of the current element
        E* listArray;

    public:
        Alist(int size);
        ~Alist();

        void clear();
        void insert(E item);
        void append(E item);
        E remove();
        void moveToStart();
        void moveToEnd();
        void prev();
        void next();
        int length();
        int currPos();
        void moveToPos(int pos);
        E getValue();
};

template <typename E>
Alist<E>::Alist(int size) {
    maxSize = size;
    listSize = 0;
    curr = 0;
    listArray = new E[maxSize];
}

template <typename E>
Alist<E>::~Alist() {
    delete[] listArray;
}

template <typename E>
void Alist<E>::clear() {
    delete[] listArray;
    listSize = curr = 0;
    listArray = new E[maxSize];
}

template <typename E>
void Alist<E>::insert(E item) {

    // if the size of the list has reached its max possible size, do nothing because
    // we dont have enough space to insert another value
    if (listSize >= maxSize) {
        return; 
    }

    // Go over this loop in paper, this shifts over the array to make room for the new value that
    // will be inserted
    for (int i = listSize; i > curr ; i--) {
        listArray[i] = listArray[i - 1];
    }

    listArray[curr] = item;
    listSize++;
}

template <typename E>
void Alist<E>::append(E item) {

    if (listSize >= maxSize) // Reached max possible size
        return;
    
    listArray[listSize++] = item; // append new item to the end of the list

}

template <typename E>
E Alist<E>::remove() {
    E item = listArray[curr];

    for (int i = curr; i < listSize - 1; i++) {
       listArray[i] = listArray[i+1];
    }

    listSize--;
    return item;
}

template <typename E>
void Alist<E>::moveToStart() {
    curr = 0;
}

template <typename E>
void Alist<E>::moveToEnd() {
    curr = listSize;
}

template <typename E>
void Alist<E>::prev() {
    if(curr !=0) {    
        curr--;
    }
}

template <typename E>
void Alist<E>::next() {
    if(curr < listSize) {
        curr++;
    }
}

template <typename E>
int Alist<E>::length() {
    return listSize;
}

template <typename E>
int Alist<E>::currPos() {
    return curr;
}

template <typename E>
void Alist<E>::moveToPos(int pos) {
    if(pos >= 0 && pos <= listSize) {
        curr = pos;
    }
}

template <typename E>
E Alist<E>::getValue(){
    // bounds is already checked for by properly implementing moveToPos(), prev(), next(). Anything involving movin curr pos
    return listArray[curr];
}

#endif