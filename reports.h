// -------------------------------------------------------------------------------
// File Name - reports.h
// Project Name - Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------
// Creator's name and email: Joshua Yang, joshuayang0324@gmail.com
// Course - Section : CS 1B
// Creation Date: 10/13/18
// Date of Last Modificataion: 12/15/18
// -------------------------------------------------------------------------------
// Purpose of this program: Serendipity Menu Program [FINAL]
// -------------------------------------------------------------------------------

#ifndef REPORTS_H
#define REPORTS_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "bookdata.h"
#include "mainmenu.h"

using namespace std;

void repListing (nodeType *&head, nodeType *&tail, int bookCount);
void repWholesale (nodeType *&head, nodeType *&tail, int bookCount);
void repRetail (nodeType *&head, nodeType *&tail, int bookCount);
void repQty (nodeType *&head, nodeType *&tail, int bookCount);
void repCost (nodeType *&head, nodeType *&tail, int bookCount);
void repAge (nodeType *&head, nodeType *&tail, int bookCount);
void selectionSort(nodeType *&head, nodeType *&tail, int sortType);

#endif
