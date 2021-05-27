// -*- C++ -*-
/****************************************************
 * @author Dalton Yoder
 * @file Stack.hpp
 * @desc A Stack using LinkedLists.
 * @date 27 May 2021
 ***************************************************/
/*********************************
 *  CONSTRUCTORS/DECONSTRUCTOR
 ********************************/

/* @brief An empty Stack is made. */
template <typename T>
Stack<T>::Stack() {
    m_stack = new LinkedList<T>();
}

/* @pre A stack exists.
 * @post A new deep copy is made. */
template <typename T>
Stack<T>::Stack(const Stack& orig) {
    this->m_stack = orig.m_stack;
}

/* @brief Stack is deleted after use, memory freed. */
template <typename T>
Stack<T>::~Stack() {
    delete m_stack;
}

/*********************************
 *  OPERATOR OVERLOADING
 ********************************/

/* @brief Assignment function overloading. */
template <typename T>
Stack& Stack<T>::operator=(const Stack& orig) {
    m_stack = orig.m_stack; //Can just use LinkedList's overloaded function.
}

/*********************************
 *  MEMBER FUNCTIONS
 ********************************/

/* @brief Insert a value at the top of the stack.
 * @param entry Value to be stored in the stack. */
template <typename T>
void Stack<T>::push(T entry) {
    //Just add to the front. We will assume the front is the "top" of the stack.
    m_stack->addFront(entry);
}

/* @brief Remove a value from the top of the stack.
 * @throw runtime_error if list is empty. */
template <typename T>
void Stack<T>::pop() throw (std::runtime_error) {
    //If the stack isn't empty, continue...
    if(!m_stack->isEmpty()) {
        m_stack->removeFront();
        /* Note: remove(1) could have worked as well.
         * However as I am running with front as my "top", this
         * makes more sense. */
    } else { //else throw an error.
        throw std::runtime_error("Pop invalid, stack is empty!\n");
    }
}

/* @brief Obtain the value from the top of the stack.
 * @return the object from the top. 
 * @throw runtime_error if list is empty. */
template <typename T>
T Stack<T>::peek() const throw (std::runtime_error) {
    //If the stack isn't empty, continue...
    if(!m_stack->isEmpty()) {
        return m_stack->getEntry(1);
    } else { //else throw an error.
        throw std::runtime_error("Peek invalid, stack is empty!\n");
    }
}