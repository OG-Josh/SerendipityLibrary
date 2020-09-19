// -------------------------------------------------------------------------------
// File Name - invmenu.cpp
// Project Name - Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
// Creator's name and email: Joshua Yang, joshuayang0324@gmail.com
// Course - Section : CS 1B
// Creation Date: 10/13/18
// Date of Last Modificataion: 12/15/18
// -------------------------------------------------------------------------------
// Purpose of this program: Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------

#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
#include "windows.h"

using namespace std;

void invmenu (nodeType *& head, nodeType *& tail, int &bookCount)
{
	
	int choice = 0;
	bool tf = false;
	int ind = -1;
	
	while (choice != 5) 
	{
		
		do
		{
			
		cout << "=========Serendity Booksellers==========\n";
		cout << "==========Inventory Database============\n";
		cout << "       (1) Look up a Book          \n";
		cout << "       (2) Add a Book              \n";
		cout << "       (3) Edit a Book's Record    \n";
		cout << "       (4) Delete a Book           \n";
		cout << "       (5) Return to Main Menu     \n";
		cout << "        Enter choice (1-5):        \n";
			
			cout << "Enter your choice from (1 - 5): ";
			cin >> choice;
			if (choice >= 1 && choice < 6) 
			{
				tf = true;
			}
			else 
			{
				cout <<"Invalid choice, please re-enter a valid choice" << endl;
				cout << system("PAUSE") << endl;
				cout << system("CLS") << endl;
			}
		}while(!tf);
		
		switch(choice)
		{
			case 1:
				LookUpBook(head, tail, bookCount);
				cout << endl;
				system("PAUSE");
				break;
			case 2:
				addBook(head, tail, bookCount);
				cout << endl;
				break;
			case 3:
				editBook(head,tail,bookCount);
				cout << endl;
				break;
			case 4:
				deleteBook(head,tail,bookCount);
				break;
		}
		cout << system("CLS") << endl;
	}
}



void addBook (nodeType *& head, nodeType *& tail, int &bookCount)
{
    nodeType *temp;
	temp = NULL;
	int choice = -1;
	
	string s1;
	s1 = "BLANK";
	string s2;
	s2 = "BLANK";
	string s3;
	s3 = "BLANK";
	string s4;
	s4 = "BLANK";
	string s5;
	s5 = "BLANK";
	
    
    int i6;
    i6 = 0;
    
	double d7;
	d7 = 0.0;
	double d8;
	d8 = 0.0;
	
	bool ex = false;
	bool sv = false;
	cin.ignore(1000, '\n');
	
	do
	{
		cout <<"***********************************************************************" << endl;
		cout <<"*                      SERENDIPITY BOOKSELLERS                        *" << endl;
		cout <<"*                             ADD BOOK                                *" << endl;
		cout <<"*       DATABASE SIZE: 20 " <<" CURRENT BOOKCOUNT: " << setw(4) << bookCount <<"*" << endl;
		
		cout <<"* <1> Enter the Title----------------> "  << s1 << endl;
		cout <<"* <2> Enter the ISBN-----------------> "  << s2 << endl;
		cout <<"* <3> Enter Author-------------------> "  << s3 << endl;
		cout <<"* <4> Enter Publisher----------------> "  << s4 << endl;
		cout <<"* <5> Enter the date added-----------> "  << s5 << endl;
		cout <<"* <6> Enter the quantity on hand-----> "  << i6 << endl;
		cout <<"* <7> Enter the Wholesale price------> $" << d7 << endl;
		cout <<"* <8> Enter the retail price---------> $" << d8 << endl;
		cout <<"* <9> Save and Exit" << endl;
		cout <<"* <10> Exit" << endl << endl;
		
		cout << "Enter a Choice: ";
		if(!(cin >> choice))
		{
			cin.clear();
			choice = -1;
		}
	  
		cin.ignore(1000, '\n');
		
		switch(choice)
		{
		case 1 : 
			cout << "Enter Book Title: ";
			getline(cin, s1);
			break;
		case 2 : 
			cout << "Enter ISBN: ";
			getline(cin, s2);
			break;
		case 3 : 
			cout << "Enter Author: ";
			getline(cin, s3);
			break;
		case 4 : 
			cout << "Enter Publisher: ";
			getline(cin, s4);
			break;
		case 5 : 
			cout << "Enter Date Added: ";
			getline(cin, s5);
			break;
		case 6 : 
			cout << "Enter Quantity on Hand: ";
			cin >> i6;
			break;
		case 7 : 
			cout << "Enter Wholesale Price: $";
			cin >> d7;
			break;
		case 8 : 
			cout << "Enter Retail Price: $";
			cin >> d8;
			break;
		case 9 : 
			ex = true;
			sv = true;
			break;
		case 10: 
			ex = true;
			break;
		default: 
			cout << "Re-enter choice" << endl;
			system("PAUSE");
			break;
		}
		system("CLS");
	}while(!ex);
	
	if(sv)
	{
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
	
}

void LookUpBook(nodeType *&head, nodeType *&tail, int & bookCount)
{
	nodeType *temp;
	temp = head;
	char choice;
	bool dc;
	string searchTitle;
	
	cin.ignore();
	
	cout << "=== BOOK LOOK UP ===" << endl;
	cout << "SEARCH: ";
	getline(cin, searchTitle);
	
	while(temp!=NULL){
	
		if(search(temp->book->getTitle(), searchTitle))
		{
			do
			{
				cout << "RESULT: " << temp->book->getTitle() << endl;
				dc = false;
				cout << "View this book? (Y/N): ";
				cin >> choice;
				if (toupper(choice) == 'N')
				{
					dc = true;
				}
				else if(toupper(choice) == 'Y')
				{
					dc = true;
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
			}while(!dc);
		}
		
		else if(search(temp->book->getISBN(), searchTitle))
		{
			do
			{
				cout << "RESULT: " << temp->book->getISBN() << endl;
				dc = false;
				cout << "View this book? (Y/N): ";
				cin >> choice;
				if (toupper(choice) == 'N')
				{
					dc = true;
				}
				else if(toupper(choice) == 'Y')
				{
					dc = true;
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
			}while(!dc);
			
		}
		if(toupper(choice) == 'Y')
		{
			break;
		}
		
		temp = temp->next;
	}
	
}

void editBook(nodeType *&head, nodeType *& tail, int bookCount)
{
	nodeType *temp;
	temp = head;
	
    int choice = 0;
    int count = 0;
    int i6;
    
    double d7;
    double d8;
    
    string searchTitle;
	string s1;
	string s2;
	string s3;
	string s4;
	string s5;
	
	char found;
    bool ex = false;
	
	cin.ignore();
	
	cout << "=== BOOK LOOK UP ===" << endl;
	cout << "SEARCH: ";
	getline(cin, searchTitle);
	
	
	
	while (temp != NULL && !exit){
		
		if(search(temp->book->getTitle(), searchTitle))
		{
			cout << "RESULT: " << temp->book->getTitle() << endl;
			cout << "View this book? (Y/N): ";
			cin.get(found);
			cin.ignore(1000, '\n');
			if (toupper(found) == 'Y')
			{
				ex = true;
				count++;
			}
		}
		else
			temp = temp->next;
	}
	
	ex = false;
	
	if (count != 0)
	{
        do
        {
            cout <<"***********************************************************************" << endl;
            cout <<"*                      SERENDIPITY BOOKSELLERS                        *" << endl;
            cout <<"*                             ADD BOOK                                *" << endl;
            cout <<"*       DATABASE SIZE: 20 " <<" CURRENT BOOKCOUNT: " << setw(4) << bookCount <<"*" << endl;
            
            cout <<"<1> Enter the Title----------------> "  << temp->book->getTitle() << endl;
            cout <<"<2> Enter the ISBN-----------------> "  << temp->book->getISBN() << endl;
            cout <<"<3> Enter Author-------------------> "  << temp->book->getAuthor() << endl;
            cout <<"<4> Enter Publisher----------------> "  << temp->book->getPub() << endl;
            cout <<"<5> Enter the date added-----------> "  << temp->book->getDateAdded() << endl;
            cout <<"<6> Enter the quantity on hand-----> "  << temp->book->getQty() << endl;
            cout <<"<7> Enter the Wholesale price------> $" << temp->book->getWholesale() << endl;
            cout <<"<8> Enter the retail price---------> $" << temp->book->getRetail() << endl;
            cout <<"<9> Exit" << endl;
            
            cout << "Enter a Choice: ";
            if(!(cin >> choice))
            {
                cin.clear();
                choice = -1;
            }
          
            cin.ignore(1000, '\n');
            
            switch(choice)
            {
            case 1 : 
				cout << "Enter Book Title: ";
                getline(cin,s1);
				temp->book->setTitle(s1);
                break;
            case 2 : 
				cout << "Enter ISBN: ";
                getline(cin, s2);
				temp->book->setISBN(s2);
                break;
            case 3 : 
				cout << "Enter Author: ";
                getline(cin, s3);
				temp->book->setAuthor(s3);
                break;
            case 4 : 
				cout << "Enter Publisher: ";
                getline(cin, s4);
				temp->book->setPub(s4);
                break;
            case 5 : 
				cout << "Enter Date Added: ";
                getline(cin, s5);
				temp->book->setDateAdded(s5);
                break;
            case 6 : 
				cout << "Enter Quantity on Hand: ";
                cin >> i6;
				temp->book->setQty(i6);
                break;
            case 7 : 
				cout << "Enter Wholesale Price: $";
                cin >> d7;
				temp->book->setWholesale(d7);
                break;
            case 8 : 
				cout << "Enter Retail Price: $";
                cin >> d8;
				temp->book->setRetail(d8);
                break;
            case 9 : 
				ex = true;
                break;
            default: 
				cout << "*** Enter Valid Option ***" << endl;
                system("PAUSE");
                break;
            }
        }while(!ex);
    }
	else
	{
		cout <<"No book found" << endl;
        system("PAUSE");
	}
}

void deleteBook(nodeType *&head, nodeType *&tail, int &bookCount)
{
	nodeType *temp;
	temp = head;
	
	int count = 0;
	int choice = 0;
	
	char found;
	char confirm;
	
	string searchTitle;
	
	bool ex = false;
	bool ft = false;

	cin.ignore();
	
	cout << "Enter the title of the book to delete: ";
	getline(cin, searchTitle);
	
	while (temp != NULL && !ex)
	{
		
		if(ft)
		{
			if(search(temp->book->getTitle(), searchTitle))
			{
				cout << "RESULT: " << temp->book->getTitle() << endl;
				cout << "View this book? (Y/N): ";
				cin.get(found);
				cin.ignore(1000, '\n');
				if (toupper(found) == 'Y')
				{
					ex = true;
					count++;
				}
			}
			
			ft = true;
		}
		else
		{
			if(search(temp->next->book->getTitle(), searchTitle))
			{
				cout << "RESULT: " << temp->next->book->getTitle() << endl;
				cout << "View this book?(Y/N): ";
				cin.get(found);
				cin.ignore(1000, '\n');
				if (toupper(found) == 'Y')
				{
					ex = true;
					count++;
				}
				else
					temp = temp->next;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
    
    if (count != 0)
    {
        bookInfo(*(temp->book));
		
        cout << "Delete book?\n";
		cin.get(confirm);
        cin.ignore(1000, '\n');

		if (toupper(confirm) == 'Y')
		{
			nodeType *found = temp->next;
			temp->next = found->next;
			found->next = NULL;
			delete found->book;
			delete found;
			bookCount--;
		}
	}
    else
    {
        cout <<"Book was not found" << endl;
    }
}

void cartAddBook(nodeCartType *&head, nodeCartType *&tail, nodeType *& temp)
{
    if(head == NULL && tail == NULL)
    {
        head = new nodeCartType;
        head->next = NULL;
        head->node = new nodeType;
        head->node->next = NULL;
        head->node->book = new BookData;
        
        tail = head;
    }
    else
    {
        tail->next = new nodeCartType;
        tail = tail->next;
        tail->next = NULL;
        tail->node = new nodeType;
        tail->node->next = NULL;
        tail->node->book = new BookData;
    }
}

bool search(string bookTitle, string searchTitle)
{
	
	transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::tolower);
	transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);
	if (bookTitle == searchTitle)
		return true;
	else if (bookTitle.find(searchTitle) != string::npos)
		return true;
	return false;
}
