/*
COP4530 Project 1 Circularly Linked List
Our project is about implementing a circularly linked list in Boba drink order.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
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


//Order class- this is used to store what the user orders so that the final reciept can be printed out

class Order{
    private:
        //this will store the drink name and any modifications
        vector <string> itemsOrdered;

        //this will store the price of each thing that was ordered
        vector <double> prices;

        //this will store the final price of the users drink
        double finalPrice;

    public: 
        //Constructor
        Order(){
            finalPrice = 0.0;
        }

        void addDrink(const LinkedList<BobaDrink> & bobaMenu){

            //Get the users choice of boba drink
            string bobaName;

            cout << "Enter the name of your drink: ";

            getline(cin, bobaName);

            //Check that the user entered the correct name for their drink
            Node <BobaDrink>* drink = bobaMenu.findByName(bobaName);

            //Loop if a nullptr is returned until the correct name is entered
            while (drink == nullptr){
                cout << "You have entered an invalid option. Please entere a drink from the menu: ";

                getline(cin, bobaName);

                //Check that the user entered the correct name for their drink
                drink = bobaMenu.findByName(bobaName);
            }

            //Save the order name and prices in the vectors
            itemsOrdered.push_back(drink -> data.getName());
            prices.push_back(drink -> data.getPrice());

            //add the price to the final price
            finalPrice += drink->data.getPrice();
        }


        //print the reciept of the users
        void printReciept() const{
            cout << endl;
            cout << "========= RECIEPT =========" <<endl;

            //loop through the items ordered to print them out 
            // the size of itemsOrdered is the same size of prices
            for(int i = 0; i < itemsOrdered.size(); i++){

                //print the price to have a fixed number of only 2 decimals 
                cout << itemsOrdered[i] << " - $" << fixed <<setprecision(2) << prices[i] <<endl;
            }

            cout << "===========================" <<endl;

            cout<< "Total $: " << fixed <<setprecision(2) << finalPrice <<endl;

            cout << "===========================" <<endl;


        }

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
    cout << endl;

    //Create the user order object 
    Order order;

    //get their drink order
    order.addDrink(bobaMenu);
    
    cout << endl;

    //print the circularly linked lists of add-ons to the boba order
    printAddonMenu(addonMenu);


    //print out the final reciept
    order.printReciept();

    return 0;
}