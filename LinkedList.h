// -*- C++ -*-
/**
 * @author Dalton Yoder
 * @file LinkedList.h
 * @desc LinkedList class for future use.
 * @date 24 January 2020
 * @note Rewritten/Updated from my own LinkedList from EECS 268.
 */
#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "Node.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class LinkedList {
  private:
    Node<T>* m_front;
    int m_length;
  public:
/**
 * CONSTRUCTORS/DECONSTRUCTOR
 */
    /* @brief An empty list is created. */
    LinkedList();
    /* @pre List exists.
     * @post New deep copy of list is made. */
    LinkedList(const LinkedList& orig);
    /* @brief List is deleted after use. Memory freed. */
    ~LinkedList();
/**
 * OPERATOR OVERLOADING
 */
    /* @brief Making one list equal to the other. */
    LinkedList& operator=(const LinkedList& orig);
/**
 * MEMBER FUNCTIONS
 */
    /* @brief return true if list is empty. */
    bool isEmpty() const;
    /* @brief returns the length of the list as an integer. */
    int getLength() const;
    /* @brief insert value into the list at a set position.
     * @param position Location where value is to be stored. 1 <= position <= m_length+1
     * @param entry Value to be stored.
     * @throw runtime_error if position is invalid. */
    void insert(int position, T entry) throw (std::runtime_error);
    /* @brief remove value at said position.
     * @param position Location to remove value.
     * @throw runtime_error if position is invalid. */
    void remove(int position) throw (std::runtime_error);
    /* @brief list is cleared of values. */
    void clear();
    /* @brief returns the value at the desired position.
     * @param position location where we desire to know the value.
     * @throw runtime_error if position is invalid. */
    T getEntry(int position) const throw (std::runtime_error);
    /* @brief replace the value at a given position in the list.
     * @param position Location where value is to be stored.
     * @param entry New value we want to add in that place.
     * @throw runtime_error if position is invalid. */
    void replace(int position, T entry) throw (std::runtime_error);
    /* @brief add a value to the front of the list.
     * @param entry Value we want to add to the list. */
    void addFront(T entry);
    /* @brief removes the first value in the list.
     * @throw runtime_error if list is empty. */
    void removeFront() throw (std::runtime_error);
    /* @brief add a value to the back of the list.
     * @param entry Value we want to add to the list. */
    void addBack(T entry);
    /* @brief removes the last value in the list.
     * @throw runtime_error if list is empty. */
    void removeBack() throw (std::runtime_error);
};
#include "LinkedList.hpp"
#endif
