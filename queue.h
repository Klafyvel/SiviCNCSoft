#ifndef H_QUEUE
#define H_QUEUE


#include "communication.h"

#define MAX_QUEUE_SIZE 64

template <typename T>
class Queue
{
public:
  Queue() : first(0), last(0), length(0) {}
  ~Queue() {}
  void push(T elem) {
    dinfo("Pushing queue");

    if(this->length >= MAX_QUEUE_SIZE)
      constError("queue overflow.");

    ++this->length;

    uint8_t newElemAdd = this->last;
    this->elements[newElemAdd] = elem;
    this->last = (newElemAdd-1)% MAX_QUEUE_SIZE;
  }
  T pop() {
    if (this->length <= 0)
      constError("queue empty.");

    uint8_t elemAdd = this->first;
    this->first = (this->first - 1)%MAX_QUEUE_SIZE;

    --this->length;

    return this->elements[elemAdd];
  }

  T peek() {
    return this->elements[this->first];
  }
  bool empty() const {return this->length==0;}
  uint8_t size() const {return this->length;}
private:
  T elements[MAX_QUEUE_SIZE];
  uint8_t first;
  uint8_t last;
  uint8_t length;
};

#endif