COMPILER=g++
EXEC=main
SOURCES=main.cpp Knapsack.cpp Item.cpp

all:
	@make clean;
	@make build;

build:
	$(COMPILER) -g $(SOURCES) -o $(EXEC)

run:
	./$(EXEC).exe

clean:
	rm -rf $(EXEC).exe