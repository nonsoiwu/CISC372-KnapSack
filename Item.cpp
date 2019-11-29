/**
 * File: Item.cpp
 * Authors: Korey Mitchell, Matt Grossman, and Nonso Iwu
 * Source: CISC372
 * Instructor: Sunita Chandrasekaran
 * Created on November 29, 2019
 */

#include "Item.hpp"

//ITEM

Item::Item(){
    name = "";
    weight = 0;
    value = 0;
    next = NULL;
    prev = NULL;
}

Item::Item(string n, int w, int v){
    name = n;
    weight = w;
    value = v;
    next = NULL;
    prev = NULL;
}

//ITEM LIST

ItemList::ItemList(){
    first = NULL;
    last = NULL;
    size = 0;
}

void ItemList::addItem(Item &item){
    if (size == 0){
        first = &item;
        last = &item;
    }else{
        last->next = &item;
        last = &item;
    }
    size += 1;
}

void ItemList::show(){
    cout << "Size: " << size;
    Item *temp = first; 
    while(temp != NULL)
    {
        cout << temp->name << ": weight=" << temp->weight << ", value=" << temp->value << "\n";
        temp = temp->next;
    }
}

//FUNCTIONS

ItemList createMock1(){
    ItemList *il = new ItemList();
    Item *apple = new Item("apple", 1,1);
    Item *orange = new Item("orange", 2,2);
    Item *lemon = new Item("lemon", 3,3); 
    il->addItem(*apple);
    il->addItem(*orange);
    il->addItem(*lemon);
    return *il;
}