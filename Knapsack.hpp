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
 * Knapsack class for the knapsack problem
 */

class Knapsack{
    ItemNode *items;
    int capacity;   //Capacity number s

    public:
        Knapsack();         //Constructor
        Knapsack(int c);    //Constructor. capacity attribute is set to c
};


void solve(); //1 function that solves the knapsack problem

#endif /* KNAPSACK_HPP */