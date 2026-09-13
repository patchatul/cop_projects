/*
A normal signly linked list for Boba menu list.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {

private:
    Node<T>* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }
    // Add item to the end of the list
    void add(T value) {
        Node<T>* newNode = new Node<T>(value);
        // If list is empty
        if (head == nullptr) {
            head = newNode;
            return;
        }
        // Find the last node
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;// Add new node to the end
    }

    // Display the list
    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            current->data.display();
            current = current->next;
        }
    }
};

#endif