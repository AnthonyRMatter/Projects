#ifndef SLLIST_H
#define SLLIST_H

#include "List.h"
#include "ListNode.h"

template <typename E>
class SLList : public List<E> {
private:
  ListNode<E>* head; // pointer to list header
  ListNode<E>* tail; // pointer to list tail
  ListNode<E>* curr; // access to the current element
  int cnt; // count of elements (length/size of list)
public:
  SLList();
  ~SLList();

  void clear();

  // insert element at current location
  // @param item: element to be inserted
  void insert(E item);

  // append element at the end of the list
  // @param item: element to be inserted
  void append(E item);

  // remove and return the current element
  // @return the element that was removed
  E remove();

  // set the current position to the start of the list
  void moveToStart();

  // set the current position to the end of the list
  void moveToEnd();

  // move the current position one step to the left. No change if at beginning
  void prev();

  // move the current position one step to the right. No change if at end
  void next();

  // return the number of elements in the list
  int length();

  // return the position of the current element
  int currPos();

  // set current position
  // @param pos: the position to make current
  void moveToPos(int pos);

  // return the current element
  E getValue();

};

// O(N), need to iterate through the list to de-allocate each node
// Destructor
template <typename E>
SLList<E>::~SLList(){
  while(head!=nullptr){
    curr = head;
    head = head->next;
    delete curr;
  }
} 

// O(1)
// Constructor
template <typename E>
SLList<E>::SLList(){
  curr = tail = head = new ListNode<E>;
  cnt = 0;
} 

// O(N), need to iterate through list to de-allocate, clear, each node
template <typename E>
void SLList<E>::clear(){
  while(head!=nullptr){
    curr = head;
    head = head->next;
    delete curr;
  }
  curr = tail = head = new ListNode<E>;
  cnt = 0;
}

// O(1), since we are only re-directing the next pointer
// insert element at current location
// @param item: element to be inserted
template <typename E>
void SLList<E>::insert(E item){
  ListNode<E>* temp;
  temp = new ListNode<E>(item,curr->next); // creating a pointer with item to be insterted with the next pointer of the curr position
  curr->next = temp;
  //curr-> = new ListNode<E>(item,curr->next);
  if(tail == curr)
    tail = curr->next;
  cnt++;
}

// O(1), since we are only adding to the end of the list, tail
// append element at the end of the list
// @param item: element to be inserted
template <typename E>
void SLList<E>::append(E item){
  ListNode<E>* temp;
  temp = new ListNode<E>(item,nullptr);
  tail->next = temp;
  tail = tail->next;
  //tail = tail->next = new ListNode<E>(item,nullptr);
  cnt++;
}

// O(1), we only need to redirect the curr->next pointers
// after removing the curr->next object and returning its element
// @return the element that was removed
template <typename E>
E SLList<E>::remove(){

  // list is empty, thus return a null value of the data type
  if(curr->next == nullptr){ 
    E value = E();
    return value;
  }

  E item = curr->next->element; // create an item variable to store and return later
  ListNode<E>* temp = curr->next;
  if(tail == curr->next) // if the next element of curr is the tail
    tail = curr;         // the new tail will be the curr element
  curr->next = curr->next->next;
  delete temp;
  cnt--;
  return item;
}

// O(1)
// set the current position to the start of the list
template <typename E>
void SLList<E>::moveToStart(){
  curr = head;
}

// O(1)
// set the current position to the end of the list
template <typename E>
void SLList<E>::moveToEnd(){
  curr = tail;
}

// O(N), worst case if we are at the end of the list and have to traverse for its previous position
// move the current position one step to the left. No change if at beginning
template <typename E>
void SLList<E>::prev(){
  if(curr == head) // list is empty, there isnt 
    return;
  ListNode<E>* temp = head;
  while(temp->next != curr)
    temp = temp->next;
  curr = temp;
}

// O(1)
// move the current position one step to the right. No change if at end
template <typename E>
void SLList<E>::next(){
  if(curr != tail)
    curr = curr->next;
}

// O(1)
// return the number of elements in the list
template <typename E>
int SLList<E>::length(){
  return cnt;
}

// O(N), needs to traverse the list to count which position its at
// return the position of the current element
template <typename E>
int SLList<E>::currPos(){
  ListNode<E>* temp = head;
  int i; // will act as the counter, pos
  for(i=0;curr != temp;i++)
    temp = temp->next;
  return i;
}

// O(N), since we have to traverse through the list and change the curr position
// set current position
// @param pos: the position to make current
template <typename E>
void SLList<E>::moveToPos(int pos){
  curr = head;
  for(int i=0;i<pos;i++)
    curr = curr->next;
}

// O(1)
// return the current element
template <typename E>
E SLList<E>::getValue(){
  if(curr->next == nullptr){
    E value = E();
    return value;
  }
  return curr->next->element;
}

#endif