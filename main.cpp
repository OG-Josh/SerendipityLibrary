// -------------------------------------------------------------------------------
// File Name - main.cpp
// Project Name - Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
// Creator's name and email: Joshua Yang, joshuayang0324@gmail.com
// Course - Section : CS 1B
// Creation Date: 10/13/18
// Date of Last Modificataion: 12/15/18
// -------------------------------------------------------------------------------
// Purpose of this program: Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
// Algorithm
// - Step 1: Prompts user to either  run the cashier module, inventory database module or the reports module
// - Step 2: Prompts user to either purchase a book, complete the order or cancel the order
// - Step 3: Prompts user to search for the book to purchase and asks how many books the user wants to buy
// - Step 4: Prompts user to either add a book, lookup a book, edit a book or delete a book
// - Step 5: Prompts user to seach for the book to lookup, edit, add or delete
// - Step 6: Prompts user to display either inventory listing, inventory wholesale value, inventory retail value
//   		 list by quantity, age or cost
// - Step 7: Prompts user to quit the program
// -------------------------------------------------------------------------------
// -								Data Dictionary
// - CONSTANTS
// -
// - NAME				DATA TYPE				VALUE
// - -----------------  ----------------------  --------------
// - MAX_SIZE			int						0
// -
// - VARIABLES
// -
// - NAME				DATA TYPE				INITIAL VALUE
// - -----------------  ----------------------  --------------
// - *head				nodeType				NULL
// - *tail				nodeType				NULL
// - bookCount			int						0
// - choice				int						0
// - tf					bool					false
// - *temp				nodetype				NULL
// - s1					string					-
// - s2					string					-
// - s3					string					-
// - s4					string					-
// - s5					string					-
// - i6					int						-
// - d7					double					-
// - d8					double					-
// --------------------------------------------------------------------------------

#include <iostream>
#include "mainmenu.h"
#include "windows.h"

    
int main ()
{
    BookData book[20];
    
	nodeType *head;
	nodeType *tail;
	
	nodeCartType *cHead;
	nodeCartType *cTail;
	
	head = NULL;
	tail = NULL;
	
	cHead = NULL;
	cTail = NULL;
	
	int bookCount = 0;
	int choice = 0;
	
	bool tf = false;
	
	rData(head, tail, bookCount);
	
	while (choice != 4)
	{
		do
		{
		system("cls");
		cout << " ========================================================================================= " << endl;
		cout << "                    ************************************************                       " << endl;
		cout << "                    *           Serenditity Menu                   *                       " << endl;
		cout << "                    *        1 - Cashier Module                    *                       " << endl;
		cout << "                    *        2 - Inventory Database Module         *                       " << endl;
		cout << "                    *        3 - Report Module                     *                       " << endl;
		cout << "                    *        4 - Exit                              *                       " << endl;
		cout << "                    ************************************************                       " << endl;
		cout << " ========================================================================================= " << endl;
		cout << "                             Enter choice (1-4): ";
			cin >> choice;
			
			if (choice >= 1 && choice < 5) 
				tf = true;
			else 
			{
				cout <<"invalid choice" << endl;
				cout << system("PAUSE") << endl;
				cout << system("CLS") << endl;
			}
		}while(!tf);
		
		switch(choice)
		{
			case 1:
				cout <<"You selected Cashier Module." << endl;
				system("CLS");
				cashier(head , tail, cHead, cTail);
				break;
			case 2: 
				cout <<"You selected Inventory Database Module." << endl;
				system("CLS");
				invmenu (head,tail,bookCount);
				system("CLS");
				break;
			case 3:
				cout <<"You selected Report Module." << endl;
				system("CLS");
				reports(head,tail,bookCount);
				break;	
		}
	}
	wData(head, tail);
	return 0;
}

void wData(nodeType*head, nodeType *tail)
{
    nodeType *temp;
    ofstream outFile;
    
    temp = head;
    
    outFile.open("database-2.txt");
    
    while(temp != NULL)
    {
        outFile << temp->book->getTitle() << endl;
		outFile << temp->book->getISBN() << endl;
		outFile << temp->book->getAuthor() << endl;
		outFile << temp->book->getPub() << endl;
		outFile << temp->book->getDateAdded() << endl;
		outFile << temp->book->getQty() << endl;
		outFile << temp->book->getWholesale() << endl;
		outFile << temp->book->getRetail() << endl;
        
        temp = temp->next;
    }
    
    outFile.close();
}

void rData(nodeType *&head, nodeType *&tail, int &bookCount)
{
	nodeType *temp;
	temp = NULL;
	
	string s1;
	string s2;
	string s3;
	string s4;
	string s5;
	
	s1="BLANK";
	s2="BLANK";
	s3="BLANK";
	s4="BLANK";
	s5="BLANK";
	
	int i6;
	i6 = 0;
	
	double d7;
	double d8;
	d7=0.0;
	d8=0.0;
	
	ifstream inFile;
	inFile.open("database-2.txt");
	while(getline(inFile, s1))
	{
		getline(inFile, s2);
		getline(inFile, s3);
		getline(inFile, s4);
		getline(inFile, s5);
		
		inFile >> i6;
		inFile >> d7;
		inFile >> d8;
		inFile.ignore(9999, '\n');
		
		temp = new nodeType;
		
		temp->book = new BookData;
		temp->book->setTitle(s1);
		temp->book->setISBN(s2);
		temp->book->setAuthor(s3);
		temp->book->setPub(s4);
		temp->book->setDateAdded(s5);
		temp->book->setQty(i6);
		temp->book->setWholesale(d7);
		temp->book->setRetail(d8);
		
		bookCount++;
		
		if(head == NULL && tail == NULL)
		{
			head = temp;
			tail = temp;
		}
		else 
		{
			tail->next = temp;
			tail = temp;
		}
		temp = NULL;
		tail->next = NULL;
	}
	inFile.close();
	
}
