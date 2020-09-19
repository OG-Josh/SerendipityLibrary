// -------------------------------------------------------------------------------
// File Name - cashier.h
// Project Name - Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
// Creator's name and email: Joshua Yang, joshuayang0324@gmail.com
// Course - Section : CS 1B
// Creation Date: 10/13/18
// Date of Last Modificataion: 12/15/18
// -------------------------------------------------------------------------------
// Purpose of this program: Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------

#include "cashier.h"
#include "mainmenu.h"
#include "invmenu.h"
#include <iostream>
#include "windows.h"

using namespace std;

void cashier(nodeType *&head, nodeType *&tail, nodeCartType *&cHead, nodeCartType *&cTail)
{
    cHead = NULL;
    cTail = NULL;
    
	nodeType *temp;
	nodeCartType *tempC;
	temp = NULL;
	
	char view;
	
	int choice = 0;
	int cSize = 0;
	int qty = 0;
	int bookC = 0;
	
	double subtotal = 0;
	double tax = 0;
	
	bool tf = false;
	bool ex = false;
	bool fd = false;
	
	string searchTitle;
    
    do
	{
        tf = false;
        do
		{
            tf = false;
        	cout <<"*************************************************************" << endl;
            cout <<"*                  SERENDIPITY BOOKSELLERS                  *" << endl;
            cout <<"*                       INVENTORY MENU                      *" << endl;
            cout <<"*                                                           *" << endl;
            cout <<"*  <1> Purchase Book                                        *" << endl;
            cout <<"*  <2> Complete Order                                       *" << endl;
            cout <<"*  <3> Cancel Transaction                                   *" << endl;
            cout <<"*************************************************************" << endl;
            
            cout << "Enter your choice from (1 - 3): ";
            cin >> choice;
            cin.ignore(9999, '\n');
            
            if (choice >= 1 && choice <= 3) 
			{
                tf = true;
            }
            else 
			{
                cout << "Choice is invalid" << endl;
                cout << "Please enter a number beteween 1 and 3";
                system("PAUSE");
                system("CLS");
            }
        }while(!tf);
    
        if(choice == 1)
        {
        	system("CLS");
            fd = false;
            
			temp = head;
            cout <<"**************************************************************************" << endl;
            cout <<"*                           SERENDIPITY BOOKSELLERS                      *" << endl;
            cout <<"*                               CASHIER MODULE                           *" << endl;
            cout <<"*#  Qty   ISBN              Title                                 Price  *" << endl;
            cout <<"*________________________________________________________________________*" << endl;
            
            cout <<"Enter Book" << endl;
            cout <<"SEARCH: ";
            getline(cin, searchTitle);
            cout << "Searching" << endl;
			
            while(temp!=NULL && !fd)
			{
				if(search(temp->book->getTitle(), searchTitle))
				{
					cout << "RESULT: " << temp->book->getTitle() << endl;
					cout << "View this book? (Y/N): ";
					cin.get(view);
					cin.ignore(9999, '\n');
					
					if(toupper(view) == 'Y')
					{
						fd = true;
						cout <<"<1> Title--------------------> "  << temp->book->getTitle() << endl;
						cout <<"<2> ISBN---------------------> "  << temp->book->getISBN() << endl;
						cout <<"<3> Author-------------------> "  << temp->book->getAuthor() << endl;
						cout <<"<4> Publisher----------------> "  << temp->book->getPub() << endl;
						cout <<"<5> Date added---------------> "  << temp->book->getDateAdded() << endl;
						cout <<"<6> Quantity on hand---------> "  << temp->book->getQty() << endl;
						cout <<"<7> Wholesale price----------> $" << temp->book->getWholesale() << endl;
						cout <<"<8> Retail price-------------> $" << temp->book->getRetail() << endl;
						system("PAUSE");
						
					}
					else 
					{
						temp = temp->next;
					}
				}
                else 
                {
                    temp = temp->next;
                }
			}

            if(fd)
            {
                do{
                    tf = false;
                    cout << endl;
                    cout <<"How many would you like to purchase? ";
                    cin >> qty;
                    cin.ignore(9999, '\n');
                    
                    
                    if(qty <= temp->book->getQty()) 
					{
                        tf = true;
                    }
                    else {
                        cout <<"Not enough books, please enter a new quantity" << endl;
                        cout << system("PAUSE") << endl;
                    }
                }while(!tf);
                
                cartAddBook (cHead, cTail, temp);
                
                cTail->node->book->setTitle (temp->book->getTitle());
                cTail->node->book->setISBN (temp->book->getISBN());
                cTail->node->book->setAuthor (temp->book->getAuthor());
                cTail->node->book->setPub (temp->book->getPub());
                cTail->node->book->setDateAdded (temp->book->getDateAdded());
                cTail->node->book->setQty (qty);
                cTail->node->book->setWholesale (temp->book->getWholesale());
                cTail->node->book->setRetail (temp->book->getRetail());
                temp->book->setQty (temp->book->getQty() - qty);
            }
            else
            {
                cout << "Book not found" << endl;
            }
        }
        else if(choice == 2)
        {
        	system("CLS");
            if(cHead != NULL && cTail != NULL)
            {
                ex = true;
                fd = false;
                
                cout << endl;
                cout <<"************************************************************************" << endl;
            	cout <<"*                        SERENDIPITY BOOKSELLERS                       *" << endl;
            	cout <<"*                            CASHIER MODULE                            *" << endl;
                cout <<"*Qty   ISBN             Title                         Price     Total  *"<<endl;
                cout <<"*______________________________________________________________________*" << endl;
                tempC = cHead;
                while(tempC != NULL)
                {
                    cout << left << setw(6) << tempC->node->book->getQty() << setw(17) << tempC->node->book->getISBN() << setw(29) << tempC->node->book->getTitle().substr(0,27) << fixed << setprecision(2) << "$ " << setw(9) << tempC->node->book->getRetail() << "$ " << setw(4) << fixed <<	setprecision(2) << (tempC->node->book->getRetail() * tempC->node->book->getQty());
                    cout << endl;
                    
                    subtotal += tempC->node->book->getRetail() * qty;
                    tempC = tempC->next;
                }
                tax = subtotal * 0.06;
                cout << setw(60) <<"                       Subtotal:" << "$ " << showpoint << fixed << setw(5) << setprecision(2) << subtotal << endl;
                cout << setw(60) <<"                       Tax:" << right <<"$ " << showpoint << fixed << setw(5) << setprecision(2) << tax << endl;
                cout << left << setw(60) <<"                       Total:" << "$ " << showpoint << fixed << setw(5) << setprecision(2) << (subtotal + tax) << endl;
                cout << endl;
                cout <<"Thank You For Shopping with us!" << endl;
                cout << endl;
            }
        }
        else
        {
            ex = true;
        }
        
        system("PAUSE");
        system("CLS");
        
    }while(!ex);
}


