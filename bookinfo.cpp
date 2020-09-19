// -------------------------------------------------------------------------------
// File Name - bookinfo.cpp
// Project Name - Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
// Creator's name and email: Joshua Yang, joshuayang0324@gmail.com
// Course - Section : CS 1B
// Creation Date: 10/13/18
// Date of Last Modificataion: 12/15/18
// -------------------------------------------------------------------------------
// Purpose of this program: Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------

#include "bookinfo.h"
#include <iostream>
#include "windows.h"

using namespace std;

void bookInfo(BookData book)
{
	cout << "                  Serendipity BookSellers\n";
	cout << "                    Book Information\n\n";
	cout << "\tTitle--------------------> " << book.getTitle() << endl;
	cout << "\tISBN---------------------> " << book.getISBN() << endl;
	cout << "\tAuthor-------------------> " << book.getAuthor() << endl;
	cout << "\tPublisher----------------> " << book.getPub () << endl;
	cout << "\tDate Added---------------> " << book.getDateAdded() << endl;
	cout << "\tQuantity-On-Hand---------> " << book.getQty() << endl;
	cout << "\tWholesale Cost----------->$" << book.getWholesale() << endl;
	cout << "\tRetail Price------------->$" << book.getRetail() << endl;
}
