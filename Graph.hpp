#ifndef GRAPH_HPP 
#define GRAPH_HPP 

#include <vector>
#include "Arc.hpp"
using namespace std; 

class Graph{ 
    public:
        Graph(vector <Arc*> lis_of_arcs);
        void print(); 
        
    private: 
        vector <vector<Arc*>> arcs; 
        vector <Vertex> vertex; 
};


#endif