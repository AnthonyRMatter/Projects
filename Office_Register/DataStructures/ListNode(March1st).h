// List node for a singly linked list

template <typename E>
class ListNode{
public:
  E element; // value of this node
  ListNode* next; // pointer to the next node in the list
//  ListNode* prev; // This is the only implementation for a doubly linked list
  ListNode(E elemVal, ListNode* nextVal = nullptr){
    element = elemVal;
    next = nextVal;
  }

  ListNode(ListNode* nextVal = nullptr){
    next = nextVal;
  }
};
