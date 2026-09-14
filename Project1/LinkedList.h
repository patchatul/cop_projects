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

    //Find an item using its name
    Node<T>* findByName(string name) const {

        Node<T>* current = head;
        //Traverse the linked list

        while (current != nullptr){

            //Save both values in a string to be converted to lowercase as case doesnt matter but spelling does 
            string menuName = current -> data.getName();
            string userInputName = name;

            for(char &c : menuName){
                c = tolower(c);
            }
            for(char &c : userInputName){
                c = tolower(c);
            }

            //now compare both to check if the user input value is on the menu
            if(menuName == userInputName){
                return current;
            }

            //move on to the next one if not found yet
            current = current -> next;
        }
        return nullptr;// Item was not found
    }
};

#endif