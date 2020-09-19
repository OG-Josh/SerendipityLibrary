// -------------------------------------------------------------------------------
// File Name - invmenu.h
// Project Name - Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
// Creator's name and email: Joshua Yang, joshuayang0324@gmail.com
// Course - Section : CS 1B
// Creation Date: 10/13/18
// Date of Last Modificataion: 12/15/18
// -------------------------------------------------------------------------------
// Purpose of this program: Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------

#ifndef INVMENU_H
#define INVMENU_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <algorithm>

#include "bookdata.h"
#include "mainmenu.h"

using namespace std;

bool search(string bookTitle, string searchTitle);

void LookUpBook(nodeType *&, nodeType *&, int &bookCount);

void addBook (nodeType *&, nodeType *&, int &bookCount);

void editBook(nodeType *&, nodeType *&, int bookCount);

void deleteBook(nodeType *&, nodeType *&, int &bookCount);

void cartAddBook (nodeCartType *&, nodeCartType *&, nodeType *& );

#endif
