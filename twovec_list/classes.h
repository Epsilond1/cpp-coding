//
// Created by Marx on 06.04.2017.

#include <iostream>

class Stack {
private:
    struct Node {
        int current;
        Node *next;
    };

    Node *head;
    size_t size;

public:
    Stack() {
      head=NULL;
      size = 0;
    }

    ~Stack() {
      delete head;
    };

    void push(int element);
    void top();
    void pop();
    size_t len();
};

void Stack::push(int element) {
  Node *slot = new Node;
  slot->current = element;
  slot->next = head;
  head = slot;
  size += 1;
}

void Stack::pop() {
  if (head != NULL) {
    head = head->next;
    size -= 1;
  }
  else {
    delete head;
    std :: cout << "Stack is empty!";
  }
}

void Stack::top() {
  if (head != NULL) {
    std :: cout << head->current << " ";
  }
  else {
    delete head;
    std :: cout << "Stack is empty!";
  }
}

size_t Stack::len() {
  return size;
}