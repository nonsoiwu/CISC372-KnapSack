/**
 * File: main.cpp
 * Authors: Korey Mitchell, Matt Grossman, and Nonso Iwu
 * Course: CISC372
 * Instructor: Sunita Chandrasekaran
 * Created on November 29, 2019
 */

#include "../Item.hpp"
#include "../Knapsack.hpp"
#include "time.h"
using namespace std;

int main(int argc, char const *argv[])
{
    
    int* weights;       //Weight of items
    int* values;        //Values of items
    int W;              //Max capacity
    int n;              //Number of items
    int i, j;           //iterators
    ItemList *it;       //ItemList

    scanf("%d", &n);                            //Read number of items
	weights = (int*)malloc((n+1)*sizeof(int));
	values = (int*)malloc((n+1)*sizeof(int));

	//Read weights and corresponding values for 'n' items
	for(i=1;i<=n;i++)
		scanf("%d", &weights[i]);
	for(i=1;i<=n;i++)
		scanf("%d", &values[i]);
	//Read Max. Weight Capacity of Knapsack

    //printf("weight %d\n", &weights[i]);
    //printf("values %d\n", &values[i]);
    printf("Naive:\n");
    printf("Items: %d\n", n);
	scanf("%d", &W);
    printf("Capacity: %d\n", W);

    it = new ItemList();
    Item *item;

    //Fill weights and values
    for (size_t i = 0; i < n; i++)
    {
        item = new Item("",  weights[i], values[i]);
        it->addItem(*item);
    }

    Knapsack ks = Knapsack();
    ks.solve(it, W);
    free(weights);
	free(values);
    return 0;
}
