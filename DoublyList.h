#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>

using namespace std;

class Node {
public:
    Node() : data(0), nextLink(NULL), previousLink(NULL) { }

    Node(int theData, Node *previous, Node *next)
            : data(theData), nextLink(next), previousLink(previous) { }

    Node *getNext() const { return nextLink; }

    Node *getPrev() const { return previousLink; }

    int getData() const { return data; }

    void setData(int theData) { data = theData; }

    void setNext(Node *pointer) { nextLink = pointer; }

    void setPrev(Node *pointer) { previousLink = pointer; }

    ~Node() { }

private:
    int data;
    Node *nextLink;
    Node *previousLink;
};


class DoublyList {
public:
    // constructor
    DoublyList();

    // printForward
    void printForward() const;

    // printBackwards
    void printBackwards() const;

    // insertFront
    void insertFront(int newData);

    void pushTop(int newData); // stack test
    void popTop();             // stack test;
    // insertBack
    void insertBack(int newData);

    // search
    bool search(int key) const;

    // deleteNode
    void deleteNode(int deleteData);

    // sum
    int sum() const;

    // front
    int front() const;

    // back
    int back() const;

    // copyToList
    void copyToList(DoublyList &otherList) const;

    // moveKeyNodeToFirst
    void moveKeyNodeToFirst(int key);

    // destroyList
    void destroyList();

    // destructor
    ~DoublyList();

private:
    Node *first;    // pointer to the first node on the list
    Node *last;     // pointer to the last node on the list
    int count;      // number of nodes in the list
};

#endif