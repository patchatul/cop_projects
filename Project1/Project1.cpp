/*
COP4530 Project 1 Circularly Linked List
Our project is about implementing a circularly linked list in Boba drink order.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "CircularLinkedList.h"
#include "LinkedList.h"
using namespace std;

//Node class in Node.h
//Linked list class and template in LinkedList.h for the boba menu
//Circularly linked list class and template in CircularLinkedList.h for add-ons 

//class for the boba drink menu 
class BobaDrink {
    //private data types for the boba drink from being changed outside the class
    private:
        string name;
        double price;

    //public data types for the boba drink to be accessed outside the class
    public:
        //constructor for the boba drink with a name and price
        BobaDrink(string nameInput, double priceInput){
            name = nameInput;
            price = priceInput;
        }
        //getter for the name of the boba drink
        string getName(){ 
            return name; 
        }
        //getter for the price of the boba drink
        double getPrice(){
            return price;
        }
        //getter for printing the boba drink
        void display(){
            cout << name << ", $" << fixed << setprecision(2)<< price << endl;
        }
};

//class for Add-on ingredients, return name and price similar to Boba Menu structure
class Addon{
    private:
        string name;
        double price;
    public:
        Addon(string nameInput, double priceInput){
            name = nameInput;
            price = priceInput;
        }
        string getName(){ 
            return name; 
        }
        double getPrice(){
            return price;
        }
        void display(){
            cout << name << ", $" << price << endl;
        }

};

//print boba drink menu list
void printBobaMenu(const LinkedList<BobaDrink> & bobaMenu) {
    cout << "BOBA MENU" << endl;
    bobaMenu.display();
};
//print add-on on that boba drink order
void printAddonMenu(const CircularLinkedList<Addon> & addonMenu) {
    cout << "ADD-ONS" << endl;
    addonMenu.display();
};




// main function to run the program
int main(){
    // Create normal singly linked list
    LinkedList<BobaDrink> bobaMenu;


    // Add Boba drinks to the singly linked list
    bobaMenu.add(BobaDrink("Milk Tea", 5.00));
    bobaMenu.add(BobaDrink("Green Tea", 5.20));
    bobaMenu.add(BobaDrink("Oolong Milk Tea", 5.80));
    bobaMenu.add(BobaDrink("Matcha Latte", 6.00));
    bobaMenu.add(BobaDrink("Thai Tea", 6.30));
    bobaMenu.add(BobaDrink("Brown Sugar Milk Tea", 6.70));

    //Create the add-ons to boba order as a circular linked list
    CircularLinkedList<Addon> addonMenu;

    //add add-ons to the circular linked list   
    addonMenu.add(Addon("Oreo Crumble", 0.70));
    addonMenu.add(Addon("Mango Jelly", 0.70));
    addonMenu.add(Addon("Custard Pudding", 0.80));
    addonMenu.add(Addon("Crystal Boba", 1.00));
    addonMenu.add(Addon("Lychee Popping Boba", 1.00));

    cout << "Welcome to the Boba Cafe! Make Your Boba Order!" << endl;
    //print the singly linked lists of Boba menu
    printBobaMenu(bobaMenu);
    //print the circularly linked lists of add-ons to the boba order
    printAddonMenu(addonMenu);

    return 0;
}