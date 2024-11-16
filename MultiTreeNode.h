#ifndef MULTITREENODE_H
#define MULTITREENODE_H

#include "NodeRecord.h"
#include <list>
#include <memory>
#include <iostream> // Include the necessary header for cout

template <typename T>
class MultiTreeNode
{
private:
    NodeRecord<T> *record;
    list<MultiTreeNode<T> *> children;

public:
    list<MultiTreeNode<T> *> &getChildren() { return children; }
    string getKey() const { return record->getKey(); };
    NodeRecord<T> *getRecord() const { return record; };
    void print() const { cout << record->getKey(); };
    MultiTreeNode(NodeRecord<T> *record) : record(record) {};

    bool addChild(NodeRecord<T> *newRecord);
    bool removeChild(const T &key);
    ~MultiTreeNode(); // whyyyyyyy is this at the bottom, shame oh you, shame on your family
};
// Implementation

template <typename T>
bool MultiTreeNode<T>::addChild(NodeRecord<T> *childToAdd)
{
    if (record->canHaveChildren())
    {
        MultiTreeNode<T> *newChild = new MultiTreeNode(childToAdd);
        children.push_back(newChild);
        return true;
    }
    return false;
    // not sure how to comment this, seems pretty face value given the context?
    // if it can have kids, give it a kid
    // if not, then false
}

template <typename T>
bool MultiTreeNode<T>::removeChild(const T &keyToDelete)
{
    // not sure if we are allowed to do #include <algorithm> so i gotta do it this way (which is ew)
    // again, auto since we don't necessarily know the type (some type of pointer)
    // starting at the beginning of the list until the end
    for (auto iterator = children.begin(); iterator != children.end(); ++iterator)
    {
        // dereference the pointer, get the key,
        if ((*iterator)->getKey() == keyToDelete)
        {
            // store the problem child (hi) somewhere to fully kill it
            MultiTreeNode<T> *child = *iterator;
            children.erase(iterator); // list syntax moment,
            // use the built in method to remove it from the LIST
            // call the destructor on the child's address (it is now homeless)
            delete child;
            // mission acomplished
            return true;
        }
    }
    // could not find it, didn't delete anything
    return false;
}

// the get functions, print, and constructor are all simple one line functions,
// implemented them with decleration

// template <typename T>
// MultiTreeNode<T>::MultiTreeNode(NodeRecord<T> *record) : record(record) {}
// template <typename T>
// NodeRecord<T> *MultiTreeNode<T>::getRecord() const
// {
//     // TODO: complete
//     return record;
//     // TODO: figure out what needs to be completed?
// }
// template <typename T>
// string MultiTreeNode<T>::getKey() const
// {
//     return record->getKey();
// }
// template <typename T>
// void MultiTreeNode<T>::print() const
// {
//     cout << record->getKey() << endl;
// }

// having this at the bottom bothers me immensely
// the correct order is constructor, parameter constructor, destructor, copy, other methods
// destructor on bottom is a sin
template <typename T>
MultiTreeNode<T>::~MultiTreeNode()
{
    // i hate this syntax
    // for each element in children, which we will name child
    // kill the child
    // this will kill all the children
    for (auto child : children)
    {
        delete child;
    }
}
// will this method be recursive if it tries deleting a child of type MultiTreeNode?

#endif // MULTITREENODE_H