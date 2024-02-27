#include "astarsolver.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

/* =====
 * State Class Implementation
 * ===== */
State::State(const intArr& arr){
    arr.size() == _arrSize * _arrSize;
    _state = arr;
}

State::State(const State& st){
    _arrSize = st._arrSize;
    _state = st._state;
}

bool operator==(const State& st1, const State& st2){
	return (st1._state == st2._state);
}

int State::findBlankIndex() const{
    for(int i = 0; i < _state.size(); i++){
        if(_state[i] == 0){
            return i;
        }
    }
    return (int)_state.size();
}

void State::swap(int i0, int i1){
    int tmp = _state[i1];
    _state[i1] = _state[i0];
    _state[i0] = tmp;
}

const intArr& State::getArray() const{
    return _state;
}

int State::getArrSize() const{
	return _arrSize;
}

void State::display(){
    std::cout << "=====================" << std::endl;
    for(int i = 0; i < _arrSize; i++){
        std::cout << "| ";
        for(int j = 0; j < _arrSize; j++){
            int index = i * _arrSize + j;
            if(_state[index] == 0){
                std::cout << "[]" << " | ";
            } else if(_state[index] < 10){
                std::cout << " " << _state[index] << " | ";
            } else {
                std::cout << _state[index] << " | ";
            }
        }
        if(i != 3){
            std::cout << "\n---------------------\n";
        }
    }
    std::cout << "\n=====================" << std::endl;
}

/* =====
 * Neighbors Class Implementation
 * ===== */
Neighbors::Neighbors(){
    mapEdge.insert(std::make_pair(0, std::vector<int>{1, 4}));
    mapEdge.insert(std::make_pair(1, std::vector<int>{0, 2, 5}));
    mapEdge.insert(std::make_pair(2, std::vector<int>{1, 3, 6}));
    mapEdge.insert(std::make_pair(3, std::vector<int>{2, 7}));

    mapEdge.insert(std::make_pair(4, std::vector<int>{0, 5, 8}));
    mapEdge.insert(std::make_pair(5, std::vector<int>{1, 4, 6, 9}));
    mapEdge.insert(std::make_pair(6, std::vector<int>{2, 5, 7, 10}));
    mapEdge.insert(std::make_pair(7, std::vector<int>{3, 6, 11}));

    mapEdge.insert(std::make_pair(8, std::vector<int>{4, 9, 12}));
    mapEdge.insert(std::make_pair(9, std::vector<int>{5, 8, 10, 13}));
    mapEdge.insert(std::make_pair(10, std::vector<int>{6, 9, 11, 14}));
    mapEdge.insert(std::make_pair(11, std::vector<int>{7, 10, 15}));

    mapEdge.insert(std::make_pair(12, std::vector<int>{8, 13}));
    mapEdge.insert(std::make_pair(13, std::vector<int>{9, 12, 14}));
    mapEdge.insert(std::make_pair(14, std::vector<int>{10, 13, 15}));
    mapEdge.insert(std::make_pair(15, std::vector<int>{11, 14}));
}

const std::vector<int>& Neighbors::getNeighbors(int i) const{
    std::map<int, std::vector<int>>::const_iterator itr(mapEdge.find(i));
    if(itr != mapEdge.end()){
        return itr->second;
    }
    static std::vector<int> pass;
    return pass;
}

/* =====
 * Node Class Implementation
 * ===== */
Node::Node(const State& state, nodePtr parent, Action action, int depth) : _state(state){
    _depth = depth;
    _action = action;
    _parent = parent;
}

nodePtr Node::getParent(){
    return _parent;
}

const State& Node::getState(){
    return _state;
}

int Node::getDepth() const{
    return _depth;
}

Action Node::getAction() const{
    return _action;
}

/* =====
 * A* Solver Class Implementation
 * ===== */
bool AStarSolver::Compare::operator()(const nodePtr& n1, const nodePtr& n2) const{
    const State& state1 = n1->getState();
    int cost1 = computeWeightedCost(state1, n1->getDepth());
    const State& state2 = n2->getState();
    int cost2 = computeWeightedCost(state2, n2->getDepth());
    return cost1 < cost2;
}

int AStarSolver::Compare::h1Cost(const State& st) const{
	int cost = 0;
	const intArr& state = st.getArray();
	for(int i = 0; i < state.size(); i++){
		if(state[i] == 0){
			continue;
		}
		if(state[i] != i + 1){
			cost += 1;
		}
	}
	return cost;
}

int AStarSolver::Compare::h2Cost(const State& st) const{
	int cost = 0;
	const intArr& state = st.getArray();
	int arrSize = st.getArrSize();
	for(int i = 0; i < state.size(); i++){
		int v = state[i];
		if(v == 0){
			continue;
		}
		int gx = (v - 1) % arrSize;
		int gy = (v - 1) / arrSize;

		int x = i % arrSize;
		int y = i / arrSize;

		int h2cost = abs(x - gx) + abs(y - gy);
		cost += h2cost;
	}
	return cost;
}

int AStarSolver::Compare::h3Cost(const State& st) const{
    int cost = 0;
    const intArr& state = st.getArray();
    int arrSize = st.getArrSize();
    for(int i = 0; i < state.size(); i++){
        int v = state[i];
        if(v == 0){
            continue;
        }
        int gx = (v - 1) % arrSize;
        int gy = (v - 1) / arrSize;

        int x = i % arrSize;
        int y = i / arrSize;

        int h2cost = abs(x - gx) + abs(y - gy);
        // Check blocked tiles in the same row
        for(int j = i + 1; j < state.size(); j++){
            int nv = state[j];
            if(nv == 0){
                continue;
            }
            int nx = j % arrSize;
            int ny = j / arrSize; 
            if(nx == x && nv < v && ny < y){
                cost += 2;
            }
        }
        // Check blocked tiles in the same col
        for(int j = i + arrSize; j < state.size(); j += arrSize){
            int nv = state[j];
            if(nv == 0){
                continue;
            }
            int nx = j % arrSize;
            int ny = j / arrSize; 
            if(ny == y && nv < v && nx < x){
                cost += 2;
            }
        }
        cost += h2cost;
    }
    return cost;
}

int AStarSolver::Compare::h4Cost(const State& st) const{
    int cost = 0;
    const intArr& state = st.getArray();
    int arrSize = st.getArrSize();
    for(int i = 0; i < state.size(); i++){
        int v = state[i];
        if(v == 0){
            continue;
        }
        int gx = (v - 1) % arrSize;
        int gy = (v - 1) / arrSize;
        
        int x = i % arrSize;
        int y = i / arrSize;

        int h2cost = abs(x - gx) + abs(y - gy);
        cost = std::max(cost, h2cost);

    }
    return cost;
}

// Weighted A*
int AStarSolver::Compare::computeWeightedCost(const State& state, int depth) const{
    double wH1 = 0.7;
    double wH2 = 1.0;
    double wH3 = 1.3;
    double wH4 = 0.9;

    int h1 = h1Cost(state);
    int h2 = h2Cost(state);
    int h3 = h3Cost(state);
    int h4 = h4Cost(state);

    double weightedCost = (wH1 * h1) + (wH2 * h2) + (wH3 * h3) + (wH4 * h4); 

    return weightedCost + depth;
}

AStarSolver::AStarSolver(const State& start, const State& goal) : _goal(goal), _solved(false){
    nodePtr root(new Node(start, 0, Action::None, 0));
    _openlist.push_back(root);
}

bool AStarSolver::isInClosed(const State& state, const nodeList& values){
    for(int i = 0; i < values.size(); i++){
        if(state == values[i]->getState()){
            return true;
        }
    }
    return false;
}

bool AStarSolver::isSolved() const{
    return _solved;
}

nodePtr AStarSolver::getNextNode(){
    // If the open list is empty, return
    if(_openlist.empty()){
        return 0;
    }
    nodePtr current;
    // Finds the minimum f value in the open list using A Star
    nodeList::iterator current_itr(std::min_element(_openlist.begin(), _openlist.end(), Compare()));

    // If current node is at the end of open list, return
    if(current_itr == _openlist.end()){
        return 0;
    }
    // Copies the value to a shared pointer
    current = *current_itr;

    // Erases current_itr from the open list
    _openlist.erase(current_itr);
    _closedlist.push_back(current);

    return current;
}

void AStarSolver::expandNode(nodePtr current, const Neighbors& map){
    if(current->getState() == _goal){
        _solved = true;
        return;
    }

    // Gets the index of 0 and the neighbors of the index
    int blankIndex = current->getState().findBlankIndex();
    const intArr& neighbors = map.getNeighbors(blankIndex);

    // Loops through neighbors and creates new Nodes based on if its in the closed list
    for(int i = 0; i < neighbors.size(); i++){
        int next = neighbors[i];
        State state = current->getState();
        state.swap(blankIndex, next);

        if(!isInClosed(state, _closedlist)){
            Action action;
            if(next == blankIndex + 1){
                action = Action::Right;
            } else if(next == blankIndex - 1){
                action = Action::Left;
            } else if(next == blankIndex + 4){
                action = Action::Down;
            } else if(next == blankIndex - 4){
                action = Action::Up;
            }
            nodePtr n(new Node(state, current, action, current->getDepth() + 1));
            _openlist.push_back(n);
        }
    }
}

void AStarSolver::displayTotalNodes(){
    std::cout << " - Total Nodes Generated: " << _openlist.size() + _closedlist.size() << std::endl;
}

std::string actionToString(Action action){
	switch(action){
		case Action::Up:
			return "Up";
		case Action::Down:
			return "Down";
		case Action::Left:
			return "Left";
		case Action::Right:
			return "Right";
		default:
			break;
	}
	return "";
}