COMPILER=g++
DEXEC=dynamic
NEXEC=naive
DYNAMIC=./Dynamic/main.cpp
NAIVE=./Naive/main.cpp
SOURCES=Knapsack.cpp Item.cpp

all:
	@make clean;
	@make build;

build:
	$(COMPILER) -g $(DYNAMIC) $(SOURCES) -o $(DEXEC)
	$(COMPILER) -g $(NAIVE) $(SOURCES) -o $(NEXEC)

clean:
	rm -rf $(DEXEC).exe
	rm -rf $(NEXEC).exe