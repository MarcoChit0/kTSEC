#ifndef ARC_HPP
#define ARC_HPP

#include <iostream>
#include "Vertex.hpp"
using namespace std;

#define NO_COVER -1

class Arc {
    private:
        Vertex arc_first_vertex;
        Vertex arc_last_vertex;      
        int number_of_trails; 
        int cover_trail;

    public: 
        Arc(Vertex first_vertex, Vertex last_vertex);
        void addTrail();
        void print();
        int getNumberOfTrails();
        int coveredBy(); 
        void changeCover(int new_cover); 
};

#endif