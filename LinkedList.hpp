// -*- C++ -*-
/**
 * @author Dalton Yoder
 * @file LinkedList.hpp
 * @desc Implementation of the LinkedList class.
 * @date 24 January 2020
 * @note Rewritten/Updated from my own LinkedList from EECS 268.
 */
/**
 * CONSTRUCTORS/DECONSTRUCTOR
 */
template <typename T>
LinkedList<T>::LinkedList() {
  m_front = nullptr;
  m_length = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& orig) {
  m_length = orig.m_length;
  Node<T>* temp1 = orig.m_front; //temp1 will give next node.
  T value = temp1->getValue();
  m_front = new Node<T>(value);
  Node<T>* temp2 = m_front;          //temp2 will keep things in order.
  while(temp1!=nullptr) {
    temp1 = orig.m_front->getNext();
    temp2->setNext(temp1);
    temp2 = temp2->getNext();
  }
}

template <typename T>
LinkedList<T>::~LinkedList() {
  clear();
}

/**
 * OPERATOR OVERLOADING
 */
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& orig) {
  this->clear();  //enpty out what we want to make equal to orig.
  m_length = orig.m_length;
  Node<T>* temp1 = orig.m_front; //temp1 will give next node.
  T value = temp1->getValue();
  m_front = new Node<T>(value);
  Node<T>* temp2 = m_front;          //temp2 will keep things in order.
  while(temp1!=nullptr) {
    temp1 = orig.m_front->getNext();
    temp2->setNext(temp1);
    temp2 = temp2->getNext();
  }
  return *this;
}

/**
 * MEMBER FUNCTIONS
 */
template <typename T>
bool LinkedList<T>::isEmpty() const {
  if(m_front==nullptr) return true;
  else return false;
}

template <typename T>
int LinkedList<T>::getLength() const { return m_length; }

template <typename T>
void LinkedList<T>::insert(int position, T entry) throw (std::runtime_error) {
  //validate position
  if((position >= 1) && (position <= m_length+1)) {
    if((m_length == 0) || (position == 1)) {        //new list or front of list
      addFront(entry);
    } else if (position == m_length + 1) {          //end of the list
      addBack(entry);
    } else {                                        //anywhere else in the list
      Node<T>* newNode = new Node<T>(entry);
      Node<T>* prevNode = m_front;
      Node<T>* postNode = prevNode->getNext();
      //locate the before/after nodes.
      for(int i = 2 ; i < position ; i++) { //+2 for location of postNode.
        prevNode = prevNode->getNext();
        postNode = postNode->getNext();
      }
      //Now that we are here, insert our new node.
      newNode->setNext(postNode);
      prevNode->setNext(newNode);
      m_length++;
    }
  } else {
    throw std::runtime_error("Invalid position for insertion!\n");
  }
}

template <typename T>
void LinkedList<T>::remove(int position) throw (std::runtime_error) {
  //validate position
  if((position >= 1) && (position <= m_length)) {
    if((position == 1) && (m_length == 1)) { //removing only item in list.
      delete m_front;
      m_front = nullptr;
      m_length--;
    } else if(position == 1) {               //removing first item.
      removeFront();
    } else if(position == m_length) {        //removing last item.
      removeBack();
    } else {                                 //removing any other item.
      Node<T>* temp1 = m_front;
      Node<T>* temp2;
      //temp1 will be the node we want gone, temp2 will store the previous node.
      for (int i = 1 ; i < position ; i++) {
        temp2 = temp1;
        temp1 = temp1->getNext();
      }
      Node<T>* next = temp1->getNext();
      temp2->setNext(next);
      delete temp1;
      m_length--;
    }
  } else {
    throw std::runtime_error("Invalid position for removal!\n");
  }
}

template <typename T>
void LinkedList<T>::clear() {
 while(!isEmpty()) remove(m_length);
}

template <typename T>
T LinkedList<T>::getEntry(int position) const throw (std::runtime_error) {
  if((position >= 1) && (position <= m_length)) {
    Node<T>* temp = m_front;
    //finding the position desired
    for(int i = 1 ; i < position ; i++) {
      temp = temp->getNext();
    }
    return temp->getValue();
  } else {
    throw std::runtime_error("Invalid position for getEntry!\n");
  }
}

template <typename T>
void LinkedList<T>::replace(int position, T entry) throw (std::runtime_error) {
  if((position >= 1) && (position <= m_length)) {
    Node<T>* temp = m_front;
    for(int i = 1 ; i < position ; i++) {
      temp = temp->getNext();
    }
    temp->setValue(entry);
  } else {
    throw std::runtime_error("Invalid position for replacement!\n");
  }
}

template <typename T>
void LinkedList<T>::addFront(T entry) {
  if(m_length == 0) {
    m_front = new Node<T>(entry);
    m_length++;
  } else {
    Node<T>* temp = new Node<T>(entry);
    temp -> setNext(m_front);
    m_front = temp;
    m_length++;
  }
}

template <typename T>
void LinkedList<T>::removeFront() throw (std::runtime_error) {
  if(m_front != nullptr) {
    Node<T>* temp = m_front->getNext();
    delete m_front;
    m_front = temp;
    m_length--;
  } else {
    throw std::runtime_error("Cannot removeFront from empty list!\n");
  }
}

template <typename T>
void LinkedList<T>::addBack(T entry) {
  if(m_length == 0) {
    addFront(entry);
  } else {
    Node<T>* temp = m_front;
    Node<T>* newNode = new Node<T>(entry);
    //traverses until the end of the list.
    while(temp->getNext()!= nullptr) {
      temp = temp->getNext();
    }
    temp-> setNext(newNode);
    m_length++;
  }
}

template <typename T>
void LinkedList<T>::removeBack() throw (std::runtime_error) {
  if(m_front != nullptr) {
    if(m_length == 1) {
      removeFront();
    } else {
      Node<T>* temp1 = m_front;
      Node<T>* temp2 = m_front->getNext();
      while(temp2->getNext() != nullptr) {
        temp1 = temp1->getNext();
        temp2 = temp2->getNext();
      }
      delete temp2;
      temp1->setNext(nullptr);
      m_length--;
    }
  } else {
    throw std::runtime_error("Cannot removeBack from empty list!\n");
  }
}
