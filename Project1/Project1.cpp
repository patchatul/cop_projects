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
            cout << std::left << setw(20) << name << " $" << fixed << setprecision(2)<< price << endl;
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
            cout << std::left << setw(20) << name << " $" << fixed << setprecision(2)<< price << endl;
        }

};

//print boba drink menu list
void printBobaMenu(const LinkedList<BobaDrink> & bobaMenu) {
    cout << "======== BOBA MENU ========" << endl;
    bobaMenu.display();
    cout << "===========================" <<endl;
};


//print add-on on that boba drink order
void printAddonMenu(const CircularLinkedList<Addon> & addonMenu) {
    cout << "====== ADD-ONS MENU =======" << endl;
    addonMenu.display();
    cout << "===========================" <<endl;
};



//UserReceipt class: this is the users reciept for the data of the items name and price to be stored 

class UserReceipt{
    private:
        string itemName;
        double price;
    public:
        //constructor
        UserReceipt(string userItem, double userPrice){
            itemName = userItem;
            price = userPrice;
        }

        void display(){
            cout << std::left << setw(20) << itemName << " $" << fixed <<setprecision(2) << price <<endl;
        }
};


//Order class: this is used to store what the user orders so that the final reciept can be printed out
class Order{
    private:
        //this will be the users receipt (receipt is a linkedlist)
        LinkedList<UserReceipt> receipt;
        //this will store the final price of the users drink after modifications are added
        double finalPrice;

    public: 
        //Constructor
        Order(){
            finalPrice = 0.0;
        }

        //This method is to ask the user for the drink name and add to their receipt and the price to finalPrice
        void addDrink(const LinkedList<BobaDrink> & bobaMenu){

            //Get the users choice of boba drink
            string bobaName;

            cout << "Enter the name of your drink: ";

            getline(cin, bobaName);

            //Check that the user entered the correct name for their drink
            Node <BobaDrink>* drink = bobaMenu.findByName(bobaName);

            //Loop if a nullptr (meaning drink name was not found) is returned until the correct name is entered
            while (drink == nullptr){
                cout << "You have entered an invalid option. Please enter a drink from the menu: ";

                getline(cin, bobaName);

                //Check that the user entered the correct name for their drink
                drink = bobaMenu.findByName(bobaName);
            }

            //Save the order name and price to the receipt by adding to the linked list
            receipt.add(UserReceipt(drink->data.getName(), drink->data.getPrice()));

            //add the price to the final price
            finalPrice += drink->data.getPrice();
        }


        // Function to apply add-on modifications to user order
        void applyModification(const CircularLinkedList<Addon>& addonMenu) {

            string addonName; // Hold user input 'add-on' name
            string answer; // Hold user input for if they want to have add-ons or not

            do{

                cout << "Would you like to add an add-on? (yes/no): "; // Ask use if they want add-on
                getline(cin, answer);

                //Convert answer to lowercase as the case does not matter
                for(char &c : answer){
                    c = tolower(c);
                }
                
                // If the user inputs any answer that is not yes or no keep asking 
                while(answer != "yes" && answer != "no"){
                    cout << "Please enter yes or no only: ";
                    getline(cin, answer);

                    for(char &c : answer){
                        c = tolower(c);
                    }
                }

                // If the user inputs no, there will be no add-ons added
                if(answer == "no") {
                    break;
                }

                cout<<"Enter an add-on: "; // Ask user to eneter add-on name
                getline(cin, addonName);

                Node<Addon>* selectAddon = addonMenu.findByName(addonName); // Stores a pointer to node containg the selected add-on

                //Loop if a nullptr (meaning add-on name was not found) is returned until the correct name is entered
                while(selectAddon == nullptr) {
                    cout << "Invalid add-on. Try again: ";
                    getline(cin, addonName); // Prompt user to re-enter name
                    selectAddon = addonMenu.findByName(addonName);
                }


                //Save the add-on name and price to the receipt by adding to the linked list
                receipt.add(UserReceipt(selectAddon->data.getName(), selectAddon->data.getPrice()));


                //add the price to the final price
                finalPrice += selectAddon->data.getPrice();

            }while(answer == "yes");
        }


        //Print the reciept of the users
        void printReceipt() const{
            cout << endl;
            cout << "========= RECIEPT =========" <<endl;
            receipt.display();
            cout << "===========================" <<endl;
            cout<< "Total $" << fixed <<setprecision(2) << finalPrice <<endl;
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
    
    //Start output in the terminal
    cout << "===============================================" <<endl;
    cout << "Welcome to the Boba Cafe! Make Your Boba Order!" << endl;
    cout << "===============================================" <<endl;

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

    cout << endl;

    // Ask user if add-ons wants to be applied to order
    order.applyModification(addonMenu);
    
    cout << endl;

    //print out the final receipt
    order.printReceipt();

    return 0;
}