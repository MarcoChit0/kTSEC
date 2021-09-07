#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Arc.hpp"
#include <vector>

class Graph{
    private: 
        vector<Arc*> Arcs;

    public:
        Graph(vector<Arc*> arcs);
        vector<Arc*> GetArcs();
};
#endif

