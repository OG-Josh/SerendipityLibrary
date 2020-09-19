// -------------------------------------------------------------------------------
// File Name - bookdata.h
// Project Name - Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
// Creator's name and email: Joshua Yang, joshuayang0324@gmail.com
// Course - Section : CS 1B
// Creation Date: 10/13/18
// Date of Last Modificataion: 12/15/18
// -------------------------------------------------------------------------------
// Purpose of this program: Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iostream>
#include <string>

using namespace std;

class BookData
{
	private:
		string title;
		string isbn;
		string author;
		string publisher;
		string dateAdded;
		
		int quantity;
		
		double wholesale;
		double retail;     
		
	public:
	 	
		~BookData();
		BookData ();
		BookData (string, string, string, string, string, int, double, double);
		   
		   
		void setTitle(string);
		string getTitle() const;
		
		void setISBN(string);
		string getISBN() const;
		
		void setAuthor(string);
		string getAuthor() const;
		
		void setPub(string);
		string getPub() const;
		
		void setDateAdded(string);
		string getDateAdded() const;
		
		void setQty(int);
		int getQty() const;
		
		void setWholesale(double);
		double getWholesale() const;
		
		void setRetail(double);
		double getRetail() const;
};


#endif
