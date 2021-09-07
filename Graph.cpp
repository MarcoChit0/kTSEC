#include "Graph.hpp"

using namespace std; 

Graph::Graph(vector<Arc*> arcs){
    this->Arcs = arcs;
}

vector<Arc*> Graph::GetArcs()
{
    return this->Arcs; 
}