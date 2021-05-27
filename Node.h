// -*- C++ -*-
/**
 * @author Dalton Yoder
 * @file Node.h
 * @desc Node class for future use.
 * @date 24 January 2020
 */
#ifndef NODE_
#define NODE_

template <typename T>
class Node {
  private:
    T m_value;
    Node<T>* m_next;
  public:
    Node(T value);
    T getValue() const;
    void setValue(T value);
    Node<T>* getNext() const;
    void setNext(Node<T>* next);
};
#include "Node.hpp"
#endif
