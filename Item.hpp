/**
 * File: Item.hpp
 * Authors: Korey Mitchell, Matt Grossman, and Nonso Iwu
 * Course: CISC372
 * Instructor: Sunita Chandrasekaran
 * Created on November 29, 2019
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

#ifndef ITEM_HPP
#define ITEM_HPP

/**
 * Item (or Object) for the KnapSack to hold
 */
class Item{
    friend class ItemList;
    string name;    //Optional name to identify an item
    int weight;     //Associated weights of an item
    int value;      //Associated values of an item
    Item *prev;     //previous item in list
    Item *next;     //next item in list

    public:
        Item();                         //Constructor
        Item(string n, int w, int v);   //Constructor sets name, weight, and value to n, w, v respectively
};

/**
 * Acts as a list for classes of 'Item'
 */
class ItemList{
    Item *first;    //Address to the first item in list
    Item *last;     //Address to the last item in list
    int size;       //Size of list

    public:
        ItemList();             //Constructor
        void addItem(Item &i);  //Adds Item to list
};

#endif /* ITEM_HPP */