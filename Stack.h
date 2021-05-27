// -*- C++ -*-
/****************************************************
 * @author Dalton Yoder
 * @file Stack.h
 * @desc A Stack using LinkedLists.
 * @date 27 May 2021
 * @note Stacks are LIFO structures.
 ***************************************************/

#ifndef STACK_
#define STACK_

#include "LinkedList.h"

template<typename T>
class Stack {
    private:
        LinkedList<T>* m_stack;
    public:
    /*********************************
     *  CONSTRUCTORS/DECONSTRUCTOR
     ********************************/

        /* @brief An empty Stack is made. */
        Stack();

        /* @pre A stack exists.
         * @post A new copy is made. */
        Stack(const Stack& orig);

        /* @brief Stack is deleted after use, memory freed. */
        ~Stack();
    
    /*********************************
     *  OPERATOR OVERLOADING
     ********************************/

        /* @brief Assignment function overloading. */
        Stack& operator=(const Stack& orig);
    
    /*********************************
     *  MEMBER FUNCTIONS
     ********************************/

        /* @brief Insert a value at the top of the stack.
         * @param entry Value to be stored in the stack. */
        void push(T entry);

        /* @brief Remove a value from the top of the stack.
         * @throw runtime_error if list is empty. */
        void pop() throw (std::runtime_error);

        /* @brief Obtain the value from the top of the stack.
         * @return the object from the top. */
        T peek() const;

};
#include "Stack.hpp"
#endif