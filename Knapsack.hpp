/**
 * File: Knapsack.hpp
 * Authors: Korey Mitchell, Matt Grossman, and Nonso Iwu
 * Course: CISC372
 * Instructor: Sunita Chandrasekaran
 * Created on November 29, 2019
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Item.hpp"
using namespace std;

#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

/**
 * Functions for the knapsack problem
 */

class Knapsack{
    public:
        void solve(ItemList *itemlist, int capacity); //1 function that solves the knapsack problem
        int solveR(Item *n, int capacity);  //Recursive method O(2^n)

        void solve2(ItemList *itemlist, int capacity); //Dynamic Programming method O(n*Capacity)
};

#endif /* KNAPSACK_HPP */