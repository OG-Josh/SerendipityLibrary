// -------------------------------------------------------------------------------
// File Name - mainmenu.h
// Project Name - Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
// Creator's name and email: Joshua Yang, joshuayang0324@gmail.com
// Course - Section : CS 1B
// Creation Date: 10/13/18
// Date of Last Modificataion: 12/15/18
// -------------------------------------------------------------------------------
// Purpose of this program: Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------

#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
#include "bookdata.h"

using namespace std;


struct nodeType
{
	BookData *book;
	nodeType *next;
};

struct nodeCartType
{
	nodeType *node;
	nodeCartType *next;
	int amount;
};

void rData(nodeType *&head, nodeType *&tail, int &bookCount);
void wData(nodeType*head, nodeType *tail);
void cashier(nodeType *&, nodeType *&,nodeCartType*&, nodeCartType*&);
void invmenu (nodeType *&head, nodeType *&tail, int &bookCount);
void reports (nodeType *&head, nodeType *&tail, int bookCount);

#endif
