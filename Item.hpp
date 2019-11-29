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

/**
 * Item (or Object) for the KnapSack to hold
 */

class Item{
    string name;    //Optional name to identify an item
    int weight;     //Associated weights of an item
    int value;      //Associated values of an item

    public:
        Item(string n, int w, int v); //Constructor sets name, weight, and value to n, w, v respectively
};

/**
 * Acts as a list for classes of 'Item'
 */
class ItemNode{
    Item *i;            //Address to the item this node references
    ItemNode *next;     //Address to the next item in list

    public:
        ItemNode();         //Constructor
        ItemNode(Item &i);  //Constructor; takes the address of an Item class
};