#ifndef H_STACK
#define H_STACK

template <typename T>
struct StackElem {
  T elem;
  struct StackElem* next;
};

template <typename T>
class Stack
{
public:
  Stack() : first(NULL), length(0) {}
  ~Stack() {
    while(first != NULL)
    {
      struct StackElem* current = first;
      first = first->next;
      delete current;
    }
  }
  void push(T elem) {
    ++length;
    struct StackElem* newElem = new struct StackElem;
    newElem->next = first;
    newElem->elem = elem;
    first = newElem;
  }
  T pop() {
    --length;
    struct StackElem* current = first;
    T elem = current->elem;
    first = current->next;
    delete current;
    return elem;
  }
  bool empty() const {return first==NULL;}
  uint8_t size() const {return length;}
private:
  struct StackELem* first;
  uint8_t length;
};

#endif