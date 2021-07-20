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
        /*
            name        :   Arc
            input       :   Vertex, Vertex 
            function    :   creates an Arc obj
        */ 
        Arc(Vertex first_vertex, Vertex last_vertex);
        /*
            name        :   addTrail
            function    :   add +1 to number_of_trails field 
        */ 
        void addTrail();
        /*
            name        :   print
            function    :   print on terminal this Arc 
        */
        void print();
        /*
            name        :   getNumberOfTrails
            output      :   number_of_trails
        */
        int getNumberOfTrails();
        /*
            name        :   coveredBy
            output      :   cover_trail
        */
        int coveredBy(); 
        /*
            name        :   changeCover
            input       :   int 
            function    :   this Arc is covered now by int new cover 
        */
        void changeCover(int new_cover); 

        int getFst(); 

        int getSnd(); 

        Vertex getFstVertex(); 
        Vertex getSndVertex(); 

        void changeFstVertex(Vertex new_fst_vertex);
        void changeSndVertex(Vertex new_snd_vertex);
};

#endif