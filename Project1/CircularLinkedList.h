/*
A class for the circular linked list data structure fro add-on to the boba order.
*/

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;     // First node
    Node<T>* tail;     // Last node
    int size;          // Number of nodes

public:
    // Constructor for the circular linked list
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Destructor prevents memory leaks
    ~CircularLinkedList() {
        clear();
    }

    // Check whether the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    // Return number of items
    int getSize() const {
        return size;
    }

    // Add a new item to the end of the circular list
    void add(T value) {
        // Create a new node
        Node<T>* newNode = new Node<T>(value);

        // If the list is empty
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;// Node points back to itself
        }
        else {
            newNode->next = head;// New node points to the first node
            tail->next = newNode;// Old last node points to new node
            tail = newNode;// New node becomes the last node
        }
        size++;
    }

    // Display every item in the circular list
    void display() const {
        // Check for empty list
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node<T>* current = head;
        // Continue until we return to the head
        do {
            current->data.display();
            current = current->next;
        } while (current != head);
    }

    // Find an item using its name
    Node<T>* findByName(string name) const {

        //Empty list means nothing to find
        if (isEmpty()) {
            return nullptr;
        }
        Node<T>* current = head;
        //Traverse the circular list
        do {
            // Compare current item's name
            if (current->data.getName() == name) {
                return current;
            }
            current = current->next;
        } while (current != head);
        return nullptr;// Item was not found
    }

    // Remove an item by name
    bool removeByName(string name) {

        // Nothing to remove
        if (isEmpty()) {
            return false;
        }

        Node<T>* current = head;
        Node<T>* previous = tail;

        do {
            // Check if current node is the item
            if (current->data.getName() == name) {
                // Only one node exists
                if (current == head && current == tail) {
                    head = nullptr;
                    tail = nullptr;
                }
                // Removing the first node
                else if (current == head) {
                    head = head->next;
                    tail->next = head;
                }
                // Removing any other node
                else {
                    previous->next = current->next;
                    // Update tail if needed
                    if (current == tail) {
                        tail = previous;
                    }
                }
                delete current;
                size--;
                return true;
            }
            previous = current;
            current = current->next;
        } while (current != head);
        return false;
    }

    // Delete every node
    void clear() {
        if (head == nullptr) {
            return;
        }
        Node<T>* current = head->next;
        // Delete all nodes except head
        while (current != head) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        // Delete head
        delete head;

        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};

#endif