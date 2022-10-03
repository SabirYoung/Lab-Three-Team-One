//  file name -- book.cpp
//  This file contains the implementations of the member function of
//  Book class.

//  ========================= header files =======================
#include <iostream>
#include <string>
#include <cstring>
#include "book.h"

//  ======================= symbolic constrantes =================
const int MIN = 1;
const int MAX = 7;
const int DECIMAL = 2;

//  ======================= namespaces used ======================
using namespace std;

// ======================== function prototypes ==================

void displayMenu();
void getChoice(int&);
void takeAction(int, Book&);


int main(){//beginning of int main

    Book book1("915934560213", "The lord of the rings", "J. R. R. Tolkien", 1178);

    int choice;

    do
   {
      displayMenu();
      getChoice(choice);
      takeAction(choice, book1);
   } while (choice != MAX);

   return 0;

}// end of main


void displayMenu()
// this funciton displays the main menu of the program
{
    cout << "*********************************" << endl;
    cout << "Test book driver" << endl;
    cout << "1.  Acquire Book button" << endl;
    cout << "2.  Press Read button" << endl;
    cout << "3.  Press Jump button" << endl;
    cout << "4.  Press Backup button" << endl;
    cout << "5.  Press Return Book button" << endl;
    cout << "6.  Display book state" << endl;
    cout << "7.  Exit" << endl;
    cout << "please enter your choice: ";
}// end of the main menu

void getChoice(int &option)
//this function asks the user to input a choice based on the menu options.
//if the user inputs a value that is out of bounds, the function will ask them
//to reenter the value. this will continue until the user inputs a value that
//is int he bounds.
{
   do
   {
      cin >> option;
      if (option < MIN || option > MAX)
      {
         cout << "The choice: "
              << option
              << " is out of bounds of the given range a values ."
              << endl;
         cout << "Please enter the value agine ";
      }
   } while (option < MIN || option > MAX);
}// end of function getChoice

void takeAction(int choice, Book &book1)
{
    int newBookStatus;
    char newBookType;
    int addPages;
    int subPages;
    float amtPaid;

    switch(choice)
    //switch statment to do the required action based on the
    //choice of the user.
    {
        case 1: cout << endl << "Option 1 was selected... " << endl;
                cout << "Please enter book status(R/r for recreational, A/a for academic, N/n-neither): ";
                cin >> newBookStatus;
                cout << "Please enter book type(1- purchased, 2-rented, 3-neither of these): ";
                cin >> newBookType;
                cout << "Please enter amount paid for book: ";
                cin >> amtPaid;
                book1.acquireBook(newBookType, newBookStatus, amtPaid);
                cout << endl;
                break;

        case 2: cout << "option 2 was selected... " << endl;
                cout << "Page read!" << endl;
                book1.readPage();
                cout << endl;
                break;

        case 3: cout << "option 3 was selected... " << endl;
                cout << "please enter the number of pages you want to go forward: ";
                cin >> addPages;
                book1.jumpPages(addPages);
                cout << "You went forward by " << addPages << " number of pages!" << endl;
                cout << endl;
                break;

        case 4: cout << endl << "option 4 was selected... " << endl;
                cout << "please enter the number of pages you want to go backwards: ";
                cin >> subPages;
                book1.backup(subPages);
                cout << "You went backwards by " << subPages << " number of pages!" << endl;
                cout << endl;
                break;

        case 5: cout << endl << "option 5 was selected... " << endl;
                book1.returnBook();
                cout << "you have returned to book. ";
                cout << endl;
                break;

        case 6: cout << "option 6 was selected "<< endl;
                cout << "the state of the book will now be displayed:" << endl << endl;
                cout << "**************************************************" << endl;
                cout << "The Book title is: " << book1.getISBN() << endl;
                cout << "The Book type is: " << book1.getBookType() << endl;
                cout << "The Book Status is: " << book1.getBookStatus() << endl;
                cout << "The number of pages of the book is: " << book1.getPages() << endl;
                cout << "The current page of the book is: " << book1.getCurrentPage() << endl;
                cout << endl;
                break;

        default:
                break;




    }
}

/*void createNewBook(string varName, string ISBN, string bookTitle, string author, int numPages)
{
   Book varName(ISBN, bookTitle, author, numPages);
}
*/