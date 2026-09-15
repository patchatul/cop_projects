/*
A normal signly linked list for Boba menu list.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include <cctype>
using namespace std;

template <typename T>
class LinkedList {

private:
    Node<T>* head;
    int size;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
        size = 0;
    }
    // Destructor prevents memory leaks 
    ~LinkedList() { 
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
        size++; //increase number of nodes
    }

    // Display the list
    void display() const {
        // Check if list is empty 
        if (isEmpty()) { 
        cout << "There is no Boba menu." << endl; 
        return; 
    }
        Node<T>* current = head;
        while (current != nullptr) {
            current->data.display();
            current = current->next;
        }
    }

    //Find an item using its name
    Node<T>* findByName(string name) const {
        // Nothing to search if list is empty 
        if (isEmpty()) { 
            return nullptr; 
        }

        Node<T>* current = head;
        //Traverse the linked list

        while (current != nullptr){

            //Save both values in a string to be converted to lowercase as case doesnt matter but spelling does 
            string menuName = current -> data.getName();
            string userInputName = name;

            // Convert menu name to lowercase
            for(char &c : menuName){
                c = tolower(c);
            }
            for(char &c : userInputName){
                c = tolower(c);
            }

            //compare both to check if the user input value is on the menu
            if(menuName == userInputName){
                return current;
            }

            //move on to the next one if not found yet
            current = current -> next;
        }
        return nullptr;// Item was not found
    }
    // Remove an item by name 
    bool removeByName(string name) { 
        // Nothing to remove 
        if (isEmpty()) { 
            return false; 
        } 
        Node<T>* current = head; 
        Node<T>* previous = nullptr; 
        // Traverse the list 
        while (current != nullptr) { 

            // Copy names for case-insensitive comparison 
            string menuName = current->data.getName(); 
            string userInputName = name; 

            // Convert menu name to lowercase 
            for (char &c : menuName) { 
                c = tolower(c);
            }
            // Convert user input to lowercase 
            for (char &c : userInputName) { 
                c = tolower(c);
            }
            // Found the item 
            if (menuName == userInputName) { 
                // Removing the first node 
                if (current == head) { 
                    head = head->next; 
                } else { 
                    // Skip the node being removed 
                    previous->next = current->next; 
                } 
                // Free the memory 
                delete current; 
                // Decrease number of nodes 
                size--; 
                return true; 
            } 
            // Move forward 
            previous = current; 
            current = current->next; 
        } 
        // Item was not found 
        return false; 
    } 
    // Delete every node in the list 
    void clear() { 
        // Nothing to clear 
        if (head == nullptr) { 
            return; 
        } 
        Node<T>* current = head; 
        // Delete every node 
        while (current != nullptr) { 
            Node<T>* nextNode = current->next; 
            delete current; current = nextNode; 
        } 
        // Reset the list 
        head = nullptr; 
        size = 0; 
    }
};

#endif;