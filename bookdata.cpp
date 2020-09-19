// -------------------------------------------------------------------------------
// File Name - bookdata.cpp
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
#include "bookdata.h"
#include "windows.h"

using namespace std;

BookData::~BookData()
{
}

BookData::BookData()
{
	setTitle("BLANK");
	setISBN("BLANK");
	setAuthor("BLANK");
	setPub("BLANK");
	setDateAdded("BLANK");
	setQty(0);
	setWholesale(0);
	setRetail(0);
}

BookData::BookData(string newTitle, string newISBN, string newAuthor, string newPublisher, string newDateAdded, int newQuantity, double newWholesale, double newRetail)
{
	setTitle(newTitle);
	setISBN(newISBN);
	setAuthor(newAuthor);
	setPub(newPublisher);
	setDateAdded(newDateAdded);
	setQty(newQuantity);
	setWholesale(newWholesale);
	setRetail(newRetail);
}

void BookData::setTitle(string newTitle)
{
	title = newTitle;
}
	
void BookData::setISBN(string newISBN)
{
	isbn = newISBN;
}

void BookData::setAuthor(string newAuthor)
{
	author = newAuthor;
}

void BookData::setPub(string newPublisher)
{
	publisher = newPublisher;
}

void BookData::setDateAdded(string newDateAdded)
{
	dateAdded = newDateAdded;
}

void BookData::setQty(int newQuantity)
{
	quantity = newQuantity;
}

void BookData::setWholesale(double newWholesale)
{
	wholesale = newWholesale;
}

void BookData::setRetail(double newRetail)
{
	retail = newRetail;
}

string BookData::getTitle() const
{
	return title;
}

string BookData::getISBN() const
{
	return isbn;
}

string BookData::getAuthor() const
{
	return author;
}

string BookData::getPub() const
{
	return publisher;
}

string BookData::getDateAdded() const
{
	return dateAdded;
}

int BookData::getQty() const
{
	return quantity;
}

double BookData::getWholesale() const
{
	return wholesale;
}

double BookData::getRetail() const
{
	return retail;
}

