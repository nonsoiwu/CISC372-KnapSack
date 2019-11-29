/**
 * File: main.cpp
 * Authors: Korey Mitchell, Matt Grossman, and Nonso Iwu
 * Course: CISC372
 * Instructor: Sunita Chandrasekaran
 * Created on November 29, 2019
 */

#include "Item.hpp"
#include "Knapsack.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    ItemList i = createMock1();
    Knapsack ks = Knapsack();
    i.show();
    ks.solve(&i, 10);
    return 0;
}
