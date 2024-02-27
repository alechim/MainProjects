#ifndef ASTARSOLVER_H
#define ASTARSOLVER_H

#include <map>
#include <vector>
#include <memory>

// Class Prototypes
class State;
class Neighbors;
class Node;
class AStarSolver;
enum class Action {None, Up, Down, Left, Right};

// Typedef Declarators
typedef std::vector<int> intArr;
typedef std::shared_ptr<Node> nodePtr;
typedef std::vector<nodePtr> nodeList;

// Contains the Puzzle within a 1D int vector
class State {
	private:
		intArr _state;
		int _arrSize = 4;
	public:
		// Constructor
		State(const intArr& arr);
        // Copy constructor
		State(const State& st);
        friend bool operator == (const State& st1, const State& st2);
        // findBlankIndex: Finds the index where 0 is located
		int findBlankIndex() const;
        // swap: Swaps the values of the state based on passed indexes
		void swap(int i0, int i1);
        // Getters and Setters
		const intArr& getArray() const;
        int getArrSize() const;
        void display();
};

// Contains the map of Neighbors for 15-Puzzle
class Neighbors{
	public:
		std::map<int, std::vector<int>> mapEdge;
        // Constructor
        Neighbors();
        // Looks for the neighbors of the passed index
        const std::vector<int>& getNeighbors(int i) const;
};

// Contains the state, parent, depth, and action
class Node{
	private:
		State _state;
		nodePtr _parent;
		int _depth;
		Action _action;
	public:
		// Constructor
		Node(const State& state, nodePtr parent, Action action, int depth = 0);
        // Getters and Setters
		nodePtr getParent();
        const State& getState();
        int getDepth() const;
        Action getAction() const;
};

class AStarSolver{
	private:
		class Compare{
			public:
				// Compare costs between two nodes
                bool operator()(const nodePtr& n1, const nodePtr& n2) const;
                // Heuristic Functions
                int h1Cost(const State& st) const;
                int h2Cost(const State& st) const;
                int h3Cost(const State& st) const;
                int h4Cost(const State& st) const;
                // Weighted A*
                int computeWeightedCost(const State& state, int depth) const;
        };
        nodeList _openlist;
		nodeList _closedlist;
		const State& _goal;
		bool _solved;
    public:
        // Constructor
		AStarSolver(const State& start, const State& goal);
        bool isInClosed(const State& state, const nodeList& values);
        bool isSolved() const;
        // getNextNode: Returns next node in the search.
		nodePtr getNextNode();
        // expandNode: expands the graph by looking into the Neighbors for the given node.
		void expandNode(nodePtr current, const Neighbors& map);
        // displayTotalNodes: display the nodes generated (open + closed sets)
		void displayTotalNodes();
};

// actionToString: converts Action to string to use for output
std::string actionToString(Action action);

#endif /* ASTARSOLVER_H */