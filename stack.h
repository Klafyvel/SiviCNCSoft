#ifndef H_STACK
#define H_STACK

#include "communication.h"

#define MAX_STACK_SIZE 40

template <typename T>
class Stack
{
public:
  Stack() : first(0), length(0) {}
  ~Stack() {}

  void push(T elem) {
    dinfo("Pushing stack.");
    if (this->length >= MAX_STACK_SIZE) {
      constError("stack overflow.");
    }

    ++this->length;

    uint8_t newElemAdd = (this->first + 1) % MAX_STACK_SIZE;

    this->elements[newElemAdd] = elem;
    this->first = newElemAdd;
  };
  T pop() {
    if (this->length <= 0) {
      constError("stack empty.");
    }

    uint8_t elemAdd = this->first;
    this->first = (this->first - 1) % MAX_STACK_SIZE;

    --this->length;

    return this->elements[elemAdd];
  };
  void peek() {
    return this->elements[this->first];
  };
  bool empty() const {return this->length <= 0;};
  uint8_t size() const {return this->length;};
private:
  T elements[MAX_STACK_SIZE];
  uint8_t length;
  uint8_t first;
};

#endif