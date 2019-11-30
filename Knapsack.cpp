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

void Knapsack::solve2(ItemList *itemlist, int capacity){
    int K[itemlist->size+1][capacity+1];
    Item *temp = itemlist->first;

    for (size_t i = 0; i <= itemlist->size; i++)
    {
        for (size_t j = 0; j <= capacity; j++)
        {
            if(i==0 || j==0){
                K[i][j] = 0;
            }else if(temp->weight <= j){
                K[i][j] = max(temp->value + K[i-1][j - temp->weight], K[i-1][j]);
            }else{
                K[i][j] = K[i-1][j];
            }
        }

        if(i != 0){
            temp = temp->next;
        }
    }
    
    cout << K[itemlist->size][capacity];
    return;
}
