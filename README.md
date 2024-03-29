# CISC372 Parallel Computing- Knapsack Problem
## Authors:
* Nonso Iwu
* Korey Mitchell
* Matt Grossman

## How to Build:
There are three executables that need to be built:\
```naive.exe```<br>
```dynamic.exe```<br>
```parallel.exe ```

To build ```naive.exe``` and ```dynamic.exe```, use the following commands (from outermost folder):
```
cd ./Serial
make build
```

To build ```parallel.exe```, use the following commands (from outermost folder):
```
cd ./Parellel
make build
```

## How to Run:
```./naive.exe```\
```./dynamic.exe```\
```./parallel.exe```\
for the naive, dynamic, and parallel programs respectively.

These programs will prompt you for console input for items for the knapsack problem.\
Each will ask for:
* Number of Item(s)
* Item weight(s)
* Item values(s)
* Capacity of Knapsack

So I problem with 3 item of weights 5, 10, 15 and corresponding values 11, 22, 33 with a knapsack capacity of 5 would require the inputs:\
```3```   &ensp;&ensp;Number of Items\
```5```   &ensp;&ensp;Weight of Item \#1\
```10```  &ensp;&ensp;Weight of Item \#2\
```15```  &ensp;&ensp;Weight of Item \#3\
```11```  &ensp;&ensp;Value of Item \#1\
```22```  &ensp;&ensp;Value of Item \#2\
```33```  &ensp;&ensp;Value of Item \#3\
```5```   &ensp;&ensp;Capacity of Knapsack

## How to Generate Sample Inputs:
We predicted that this would become inconvenient after a while, so we created a random sample generator.

Here are the commands for building a sample input with size of 5 (from outermost folder):
```
cd ./Generator
gcc -g generate.cpp -o gen
./gen 5
```

This will create a file named "sample5.txt"
You can now use this file to test the previously built programs!

For example (from outermost folder):\
```./Serial/dynamic.exe < ./Generator/sample5.txt``` 
