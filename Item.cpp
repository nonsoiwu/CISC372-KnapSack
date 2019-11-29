/**
 * File: Item.cpp
 * Authors: Korey Mitchell, Matt Grossman, and Nonso Iwu
 * Source: CISC372
 * Instructor: Sunita Chandrasekaran
 * Created on November 29, 2019
 */

#include "Item.hpp"

Item::Item(){
    name = "";
    weight = 0;
    value = 0;
}

Item::Item(string n, int w, int v){
    name = n;
    weight = w;
    value = v;
}

ItemNode::ItemNode(){
    i = NULL;
    next = NULL;
}

ItemNode::ItemNode(Item *it){
    i = it;
    next = NULL;
}