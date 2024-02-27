/*
	Name: Alec Him
	Assignment: CS 482 - HW 2
	Description: AI 15-puzzle solver with 3 provided IS using A* Search Algorithm
*/

// Libraries
#include "astarsolver.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

int main(){
	State goal(intArr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0});
	Neighbors n;
	intArr puzzle;
	std::string choice = "Backwards";

	if(choice == "Spiral"){
		std::cout << "Solving Spiral...\n";
		puzzle = {1, 2, 3, 4, 12, 13, 14, 5, 11, 0, 15, 6, 10, 9, 8, 7};
	} else if(choice == "Backwards"){
		std::cout << "Solving Backwards...\n";
		puzzle = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	} else {
		std::cout << "Solving Simple...\n";
		puzzle = {1, 2, 0, 3, 6, 7, 11, 4, 5, 9, 12, 8, 13, 10, 14, 15};
	}

    State start(puzzle);
	start.display();
    
	nodePtr node;
	AStarSolver solve(start, goal);
	while (!solve.isSolved()){
		node = solve.getNextNode();
		solve.expandNode(node, n);
	}

	// Gets the nodes for the solution
	nodeList solution;
	do{
		solution.push_back(node);
		node = node->getParent();
	} while(node != NULL);

	// Display Outputs
    solve.displayTotalNodes();
	std::cout << " - Length of Solution Path: " << solution.size() - 1 << "\n";
	int actions;
	std::cout << " - Solution Path from IS to GS: \n| ";
	for(int i = solution.size() - 1; i >= 0; i--){
		std::string out = actionToString(solution[i]->getAction());
		actions++;
		if(!(out == "")){
			std::cout << out;
		}
		if(i != 0 && i != solution.size() - 1 && (actions % 10) != 0){
			std::cout  << " -> ";
		} 
		if((actions % 10) == 0 && i != 0){
			std::cout << "\n| -> ";
		}
	}
	std::cout << "\n";

	return 0;
}