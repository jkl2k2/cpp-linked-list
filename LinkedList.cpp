/*
* Title: Project 2 - Recursive Linked List
* Abstract: Implements a linked list using recursive methods.
* Author: Joshua Lomelin
* Email: jlomelin@csumb.edu
* Estimate: 2 hours
* Date: 12/6/2021
*/

/**
This is base code for Project 2 for CST238 Fall 2020
This file DOES need to be modified and handed in
ONLY RECURSION can be used; any iteration will result
in a zero for the assignment
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;
/**
* Implement these functions IN ORDER
*/

// implement these two first
bool Node::hasNext() const {
  if (myNext == nullptr) {
    return false;
  } else {
    return true;
  }
}

bool LinkedList::empty() const {
  if (myFirst == nullptr) {
    return true;
  } else {
    return false;
  }
}

// then these two
void Node::display() const {
  cout << myData << " ";

  if (hasNext()) {
    myNext->display();
  }
}

void LinkedList::display() const {
  if (empty()) {
    cout << "Empty!" << endl;
  } else {
    myFirst->display();
  }
}

// then these two
// only append if this is the last node
// otherwise, recurse
void Node::append(int data) {
  cout << "Entered Node::append()" << endl;
  if (!hasNext()) {
    cout << "Appending" << endl;
    setNext(new Node(data));
  } else {
    cout << "Recursing" << endl;
    myNext->append(data);
  }
}

void LinkedList::append(int data) {
  cout << "Entered LinkedList::append()" << endl;
  if (empty()) {
    cout << "Linked list is empty, setting myFirst" << endl;
    myFirst = new Node(data);
  } else {
    cout << "Calling append on myFirst" << endl;
    myFirst->append(data);
  }
}

// then these two
bool Node::search(int data) const {
  if (!hasNext() && myData != data) {
    return false;
  } else if (myData == data) {
    return true;
  } else {
    return myNext->search(data);
  }
}

bool LinkedList::search(int data) const {
  if(empty()) {
    return false;
  } else {
    return myFirst->search(data);
  }
}

// then these two
bool Node::insertAfter(int oldData, int newData) {
  if (!hasNext() && myData != oldData) {
    return false;
  } else if (myData == oldData) {
    // Store old next
    Node * oldNext = getNext();

    // Make new node
    Node * newNode = new Node(newData);

    // Replace this current node's next with the new one
    setNext(newNode);

    // Set the new node's next to the old one, stitching the linked list back together
    newNode->setNext(oldNext);

    return true;
  } else {
    return myNext->insertAfter(oldData, newData);
  }
}

bool LinkedList::insertAfter(int oldData, int newData) {
  if(empty()) {
    return false;
  } else {
    return myFirst->insertAfter(oldData, newData);
  }
}

// then these two
bool Node::removeNext(int data) {
  if (!myNext->hasNext() && myNext->getData() != data) {
    return false;
  } else if (myNext->getData() == data) {
    // Store to-be-deleted's next Node
    Node * nextAfter = myNext->getNext();

    // Delete the next node (the one with the target data)
    delete myNext;

    // Set the current node's next to nextAfter, putting the linked list back together
    setNext(nextAfter);

    return true;
  } else {
    return removeNext(data);
  }
}

bool LinkedList::remove(int data) {
  if (empty()) {
    return false;
  } else if (myFirst->getData() == data) {
    delete myFirst;
    myFirst = nullptr;
    return true;
  } else {
    return myFirst->removeNext(data);
  }
}

// then these two
Node::~Node() {
  delete myNext;
}

LinkedList::~LinkedList() {
  delete myFirst;
}

// then these two
Node::Node(const Node & source) {
  myData = source.myData;
  myNext = source.myNext;
}

LinkedList::LinkedList(const LinkedList & source) {
  if (source.empty()) {
    return;
  } else {
    myFirst = source.myFirst;

    
  }
}

// then this one
LinkedList &LinkedList::operator=(const LinkedList & source) {
    return * this;
}

/**
* Implement the functions above, shouldn't need to change anything below,
but look at this for good examples!
*/

Node::Node(int data) {
    myData = data;
}

void Node::setNext(Node * next) {
    myNext = next;
}

LinkedList::LinkedList() {
    myFirst = nullptr; 
}

