/**
 * File: Knapsack.cpp
 * Authors: Korey Mitchell, Matt Grossman, and Nonso Iwu
 * Course: CISC372
 * Instructor: Sunita Chandrasekaran
 * Created on November 29, 2019
 */

#include "Knapsack.hpp"

void Knapsack::solve(ItemList *itemlist, int capacity){
    ItemList *dummy = new ItemList();
    cout << solveR(dummy, itemlist->last, capacity);
}

int Knapsack::solveR(ItemList *itemlist, Item *i, int capacity){
    int result = 0, tmp1, tmp2;

    if(i == NULL){
        result = 0;
    }else if(i->weight > capacity){
        result = solveR(itemlist, i->prev, capacity); 
    }else{
        tmp1 = solveR(itemlist, i->prev, capacity);
        tmp2 = i->value + solveR(itemlist, i->prev, capacity - i->weight);
        result = max(tmp1, tmp2);
    }

    return result;
    //If we are at the last index
        //return 0???
    //else if weight of item is more than capacity:
        //result = solveR(n-1, capacity)
    //else:
        //tmp1 = KS(n-1, C)
        //tmp2 = value of item + KS(n-1, capacit - weight of )
}
