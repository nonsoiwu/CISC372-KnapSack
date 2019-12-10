/**
 * File: Knapsack.cpp
 * Authors: Korey Mitchell, Matt Grossman, and Nonso Iwu
 * Course: CISC372
 * Instructor: Sunita Chandrasekaran
 * Created on November 29, 2019
 */

#include "Knapsack.hpp"

void Knapsack::solve(ItemList *itemlist, int capacity){
    clock_t begin = clock();
    int r = solveR(itemlist->last, capacity);
    clock_t end = clock();

	printf("Optimal value= %d\n", r);
	double timer = 0.0 + (double)(end-begin)/CLOCKS_PER_SEC;
	printf("Execution Time: %fs", timer);
}

int Knapsack::solveR(Item *i, int capacity){
    int result = 0, tmp1, tmp2;

    if(i == NULL){
        result = 0;
    }else if(i->weight > capacity){
        result = solveR(i->prev, capacity); 
    }else{
        tmp1 = solveR(i->prev, capacity);
        tmp2 = i->value + solveR(i->prev, capacity - i->weight);
        result = max(tmp1, tmp2);
    }

    return result;
}

void Knapsack::solve2(ItemList *itemlist, int capacity){
    clock_t begin = clock();
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
    clock_t end = clock();
    cout << "Optimal Value" << K[itemlist->size][capacity] << "\n";
    double timer = 0.0 + (double)(end-begin)/CLOCKS_PER_SEC;
	printf("Execution Time: %fs", timer);

    return;
}
