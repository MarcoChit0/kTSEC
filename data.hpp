#ifndef DATA_HPP
#define DATA_HPP

#include "Vertex.hpp"
#include "Arc.hpp"
#include "Trail.hpp"
#include "Set.hpp"

#include <iostream>
#include <vector> 
#include <utility>

using namespace std;  

class Graph{ 
    public:
        Graph(vector <Arc*> arcs, vector <Vertex*> vertex);
        void print(); 
    private: 
        vector <vector<Arc*>> arcs; 
        vector <Vertex*> vertex; 
}; 

Set algorithm_for_NEMO(vector <Arc *> arcs, Set trails, int capacity);

// if a is subtrail of b 
//      then return true 
//      else return false
bool isSubtrail(vector <Arc*> a, vector <Arc*> b);

#endif