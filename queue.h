#ifndef H_QUEUE
#define H_QUEUE

template <typename T>
struct QueueElem {
  T elem;
  struct QueueElem* next;
};

template <typename T>
class Queue
{
public:
  Queue() : first(NULL), last(NULL), length(0) {}
  ~Queue() {
    while(first != NULL)
    {
      struct QueueElem* current = first;
      first = first->next;
      delete current;
    }
  }
  void push(T elem) {
    ++length;
    struct QueueElem* newElem = new struct QueueElem;
    newElem->next = NULL;
    newElem->elem = elem;
    last->next = newElem;
    last = newElem;
  }
  T pop() {
    --length;
    struct QueueElem* current = first;
    T elem = current->elem;
    first = current->next;
    delete current;
    return elem;
  }
  bool empty() const {return first==NULL;}
  uint8_t size() const {return length;}
private:
  struct QueueELem* first;
  struct QueueELem* last;
  uint8_t length;
};

#endif