/*
A class for the node data structure to be used in LinkedList.h and CircularLinkedList.h.
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
    public:
        T data; //store the actual data of the node
        Node<T>* next; //pointer to the next node

        // Put dataInput directly into data
        Node(T dataInput) : data(dataInput), next(nullptr) {
    }
};

#endif // NODE_H