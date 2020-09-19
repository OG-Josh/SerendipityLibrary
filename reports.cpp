// -------------------------------------------------------------------------------
// File Name - reports.cpp
// Project Name - Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
// Creator's name and email: Joshua Yang, joshuayang0324@gmail.com
// Course - Section : CS 1B
// Creation Date: 10/13/18
// Date of Last Modificataion: 12/15/18
// -------------------------------------------------------------------------------
// Purpose of this program: Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------

#include <iostream>
#include "reports.h"
#include "mainmenu.h"
#include "windows.h"

void reports (nodeType *&head, nodeType*&tail, int bookCount)
{
	int choice = 0;
	bool vl = false;
	
	while (choice != 7)
	{
		do
		{
		
    		cout << "************************************************************************" << endl;
			cout << "*                          Serendipity Booksellers                     *" << endl;
			cout << "*                                 Reports                              *" << endl;
			cout << "*1. Inventory Listing.                                                 *" << endl;
			cout << "*2. Inventory Wholesale Value.                                         *" << endl;
			cout << "*3. Inventory Retail Value.                                            *" << endl;
			cout << "*4. Listing by Quantity.                                               *" << endl;
			cout << "*5. Listing by Cost.                                                   *" << endl;
			cout << "*6. Listing by Age.                                                    *" << endl;
			cout << "*7. Return to Main Menu.                                               *" << endl;
			cout << "*                                                                      *" << endl;
			cout << "************************************************************************" << endl << endl;
			cout << "Enter your choice from (1 - 7): ";
			cin >> choice;
			if (choice >= 1 && choice < 8) 
				vl = true;
			else 
			{
				cout <<"choice is invalid" << endl;
				cout << system("PAUSE") << endl;
				cout << system("CLS") << endl;
			}
		}while(!vl);
	
		switch(choice)
		{
			case 1:
				repListing(head, tail, bookCount);
				cout << endl;
				system("PAUSE");
				break;
			case 2:
				repWholesale(head, tail, bookCount);
				cout << endl;
				system("PAUSE");
				break;
			case 3:
				repRetail(head, tail, bookCount);
				cout << endl;
				system("PAUSE");
				break;
			case 4:
				repQty(head, tail, bookCount);
				cout << endl;
				system("PAUSE");
				break;
			case 5:
				repCost(head, tail, bookCount);
				cout << endl;
				system("PAUSE");
				break;
			case 6:
				repAge(head, tail, bookCount);
				cout << endl;
				system("PAUSE");
				break;
		}
	
	system("CLS");
	
	}
}

void selectionSort(nodeType *& head, nodeType *&tail, int sortType)
 {
	nodeType* location;
	nodeType* smallestNode;
	string book1;
	string book2;
	BookData* temp;

	nodeType* currNode = head;
	while (currNode != NULL)
	{
		smallestNode = currNode;
		location = currNode->next;
		while (location != NULL)
		{
			switch (sortType)
			{
			case 1:
				if (location->book->getQty() > smallestNode->book->getQty())
				{
					smallestNode = location;
				}
				break;
			case 3:
				book1 = location->book->getDateAdded();
				book2 = smallestNode->book->getDateAdded();
				if (book1.substr(6, 4) > book2.substr(6, 4))
				{
					smallestNode = location;
				}
				else if (book1.substr(6, 4) == book2.substr(6, 4))
				{
					if (book1.substr(0, 2) > book2.substr(0, 2))
					{
						smallestNode = location;
					}
					else if (book1.substr(0, 2) == book2.substr(0, 2))
					{
						if (book1.substr(3, 2) > book2.substr(3, 2))
						{
							smallestNode = location;
						}
					}
				}
				break;
			case 2:
				if (location->book->getRetail() > smallestNode->book->getRetail())
				{
					smallestNode = location;
				}
				break;
			}

			location = location->next;
		}
		if (smallestNode != location)
		{
			temp = currNode->book;
			currNode->book = smallestNode->book;
			smallestNode->book = temp;
		}
		currNode = currNode->next;
	}
 }


void repListing(nodeType *&head, nodeType *&tail, int bookCount)
{	
	nodeType *temp;
	int counter = 0;
	cout << "*************************************************************************************************************************" << endl;
	cout << "*                                           SERENDIPITY BOOKSELLERS                                                     *" << endl;
	cout << "*                                               REPORT LISTING                                                          *" << endl;
	cout << "*					          PAGE: 1 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"                   *" << endl;
	cout << "* TITLE                          ISBN     AUTHOR        PUBLISHER    DATE ADDED    QTY      WHOLESALE COST RETAIL COST  *" << endl;
	cout << "* --------------------------------------------------------------------------------------------------------------------  *" << endl;
	temp = head;
	while(temp != NULL)
	{
		if(counter == 11)
		{
			system("PAUSE");
			system("CLS");
			counter = 0;
			cout << "*************************************************************************************************************************" << endl;
			cout << "*                                           SERENDIPITY BOOKSELLERS                                                     *" << endl;
			cout << "*                                               REPORT LISTING                                                          *" << endl;
			cout << "*			          PAGE: 1 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"             *" << endl;
			cout << "* TITLE                          ISBN     AUTHOR        PUBLISHER    DATE ADDED QTY      WHOLESALE COST RETAIL COST  *"<<endl;
			cout << "* -----------------------------------------------------------------------------------------------------------------  *" << endl;
		}
		cout << "* " << left << setw(27) << temp->book->getTitle().substr(0, 26) << right << setw(15) << temp->book->getISBN() << " " << left << setw(15) << temp->book->getAuthor().substr(0,14) << left << setw(12) << temp->book->getPub().substr(0, 11) << right << setw(11) << temp->book->getDateAdded() << setw(9) << temp->book->getQty() << " $" << fixed << setprecision(2) << setw(13) << temp->book->getWholesale() <<" $" << fixed << setprecision(2) <<setw(11) << temp->book->getRetail() <<" *" << endl;
		counter++;
		temp = temp->next;
	}
}
 
void repWholesale(nodeType *&head, nodeType *&tail, int bookCount)
{
	nodeType *temp;
	int counter = 0;
	double subtotal = 0;
	system("CLS");
	cout << "**************************************************************************************************************" << endl;
	cout << "*                                      SERENDIPITY BOOKSELLERS                                               *" << endl;
	cout << "*                                      REPORT WHOLESALE LISTING                                              *" << endl;
	cout << "*					          PAGE: 1 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"             *" << endl;
	cout << "* TITLE                                                   ISBN                 QTY         WHOLESALE COST *" << endl;
	cout << "* --------------------------------------------------------------------------------------------------------*" << endl;
	temp = head;
	while(temp != NULL)
	{
		if(counter == 11)
		{
			system("PAUSE");
			system("CLS");
			counter = 0;
			cout << "**************************************************************************************************************" << endl;
			cout << "*                                      SERENDIPITY BOOKSELLERS                                               *" << endl;
			cout << "*                                      REPORT WHOLESALE LISTING                                              *" << endl;
			cout << "*			          PAGE: 2 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"             *" << endl;
			cout << "* TITLE                                                   ISBN                 QTY         WHOLESALE COST *" << endl;
			cout << "* --------------------------------------------------------------------------------------------------------*" << endl;
		}
		cout << "* " << left << setw(55) << temp->book->getTitle().substr(0, 45) << setw(20) << temp->book->getISBN() << " " << right << setw(9) << temp->book->getQty() << "    $" << fixed << setprecision(2) <<setw(13) << temp->book->getWholesale() <<" *" << endl;
			counter++;
			subtotal += (temp->book->getWholesale() * temp->book->getQty());
			temp = temp->next;
	}
	cout << endl;
	cout <<"The total wholesale value: $ " << fixed << setprecision(2) << subtotal << "." << endl;
}


 
void repRetail(nodeType *& head, nodeType *&tail, int bookCount)
{
	nodeType *temp;
	int counter = 0;
	double subttl = 0;
	system("CLS");
	cout << "**************************************************************************************************************" << endl;
	cout << "*                                      SERENDIPITY BOOKSELLERS                                               *" << endl;
	cout << "*                                       REPORT RETAIL LISTING                                                *" << endl;
	cout << "*   				         PAGE: 1 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"             *" << endl;
	cout << "* TITLE                                                   ISBN                 QTY         RETAIL COST    *" << endl;
	cout << "* --------------------------------------------------------------------------------------------------------*" << endl;
	temp = head;
	while(temp!=NULL)
	{
		if(counter == 11)
		{
			system("pause");
			system("cls");
			counter = 0;
			cout << "**************************************************************************************************************" << endl;
			cout << "*                                      SERENDIPITY BOOKSELLERS                                               *" << endl;
			cout << "*                                      REPORT RETAIL LISTING                                                 *" << endl;
			cout << "*       			               PAGE: 1 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"             *" << endl;
			cout << "* TITLE                                                   ISBN                 QTY         RETAIL COST    *" << endl;
			cout << "* --------------------------------------------------------------------------------------------------------*" << endl;
		}
		cout << "* " << left << setw(55) << temp->book->getTitle().substr(0, 45) << setw(20) << temp->book->getISBN() << " " << right << setw(9) << temp->book->getQty() << "    $" << fixed << setprecision(2) << setw(13) << temp->book->getRetail() <<" *" << endl;
			counter++;
			subttl += (temp->book->getRetail() * temp->book->getQty());
			temp = temp->next;
	}
	cout <<"The total wholesale value: $ " << fixed << setprecision(2) << subttl << "." << endl;
}


void repQty(nodeType *& head, nodeType *&tail, int bookCount)
{
	
	nodeType *temp;
	selectionSort(head, tail, 1);
	int counter = 0;
	system("CLS");
	cout << "**********************************************************************************************************" << endl;
	cout << "*                                      SERENDIPITY BOOKSELLERS                                            *" << endl;
	cout << "*                                      REPORT QUANTITY LISTING                                            *" << endl;
	cout << "*				              PAGE: 1 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"    *" << endl;
	cout << "* TITLE                                                                              ISBN             QTY *" << endl;
	cout << "* --------------------------------------------------------------------------------------------------------*" << endl;
	temp = head;
	while(temp!=NULL)
	{
		if(counter == 11)
		{
			system("PAUSE");
			system("CLS");
			counter = 0;
			cout << "**********************************************************************************************************" << endl;
			cout << "*                                      SERENDIPITY BOOKSELLERS                                            *" << endl;
			cout << "*                                      REPORT QUANTITY LISTING                                            *" << endl;
			cout << "*				              PAGE: 2 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"    *" << endl;
			cout << "* TITLE                                                                              ISBN             QTY *" << endl;
			cout << "* --------------------------------------------------------------------------------------------------------*" << endl;
		}
		cout << "* " << left << setw(79) << temp->book->getTitle().substr(0, 76) << right << setw(15) << temp->book->getISBN() << " " << right << setw(8) << temp->book->getQty() <<" *"<< endl;
			counter++;
			temp = temp->next;
	}
}

 void repCost(nodeType *&head, nodeType *&tail, int bookCount) 
 {
	nodeType *temp;
	selectionSort(head, tail, 2);
	int counter = 0;
	system("CLS");
	cout << "**************************************************************************************************************" << endl;
	cout << "*                                      SERENDIPITY BOOKSELLERS                                               *" << endl;
	cout << "*                                        REPORT COST LISTING                                                 *" << endl;
	cout << "*					      PAGE: 1 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"       *" << endl;
	cout << "* TITLE                                                   ISBN                 QTY          WHOLESALE COST   *" << endl;
	cout << "* --------------------------------------------------------------------------------------------------------*" << endl;
	temp = head;
	while(temp!=NULL)
	{
		if(counter == 11)
		{
			system("PAUSE");
			system("CLS");
			counter = 0;
			cout << "**************************************************************************************************************" << endl;
			cout << "*                                      SERENDIPITY BOOKSELLERS                                               *" << endl;
			cout << "*                                        REPORT COST LISTING                                                 *" << endl;
			cout << "*				   PAGE: 2 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"                   *" << endl;
			cout << "* TITLE                                                   ISBN                 QTY         WHOLESALE COST    *" << endl;
			cout << "* -----------------------------------------------------------------------------------------------------------*" << endl;
		}
		cout << "* " << left << setw(55) << temp->book->getTitle().substr(0, 45) << setw(20) << temp->book->getISBN() << " " << right << setw(9) << temp->book->getQty() << "     " << fixed << setprecision(2) << setw(13) << temp->book->getWholesale() <<" *" << endl;
			counter++;
			temp = temp->next;
	}
}

void repAge(nodeType *&head, nodeType *&tail, int bookCount) 
{
	nodeType *temp;
	selectionSort(head, tail, 3);
	int counter = 0;
	system("CLS");
	cout << "**************************************************************************************************************" << endl;
	cout << "*                                      SERENDIPITY BOOKSELLERS                                               *" << endl;
	cout << "*                                        REPORT Age  LISTING                                                 *" << endl;
	cout << "*     						  PAGE: 1 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"   *" << endl;
	cout << "* TITLE                                                   ISBN                   QTY             Date        *" << endl;
	cout << "* -----------------------------------------------------------------------------------------------------------*" << endl;
	temp = head;
	while(temp!=NULL)
	{
		if(counter == 11)
		{
			system("PAUSE");
			system("CLS");
			counter = 0;
			cout << "**************************************************************************************************************" << endl;
			cout << "*                                      SERENDIPITY BOOKSELLERS                                               *" << endl;
			cout << "*                                        REPORT Age Listing                                                  *" << endl;
			cout << "*				             PAGE: 2 OF 2             DATABASE SIZE: 20 BOOKCOUNT: " << bookCount <<"        *" << endl;
			cout << "* TITLE                                                 ISBN                     QTY             Date        *" << endl;
			cout << "* -----------------------------------------------------------------------------------------------------------*" << endl;
		}
		cout << "* " << left << setw(55) << temp->book->getTitle().substr(0, 45) << setw(20) << temp->book->getISBN() << " " << right << setw(9) << temp->book->getQty() << "     " << fixed << setprecision(2) << setw(13) << temp->book->getDateAdded() <<" " << endl;
			counter++;
			temp = temp->next;
	}
}


 
