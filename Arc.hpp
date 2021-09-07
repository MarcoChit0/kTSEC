#ifndef ARC_HPP
#define ARC_HPP

#include <iostream>
#include "Vertex.hpp"
using namespace std;

// CONSTANTS:
#define NO_COVER -1

class Arc {
    private:
        Vertex Source;
        Vertex Destiny;      
        int NumberOfTrails; 
        int CoverTrail;

    public:
        /*
            name        :   Arc
            input       :   Vertex, Vertex 
            function    :   creates an Arc obj
        */ 
        Arc(Vertex source, Vertex destiny);
        /*
            name        :   AddTrail
            function    :   add +1 to number_of_trails field 
        */ 
        void AddTrail();
        /*
            name        :   Print
            function    :   print on terminal this Arc 
        */
        void Print();
        /*
            name        :   GetNumberOfTrails
            output      :   number_of_trails
        */
        int GetNumberOfTrails();
        /*
            name        :   CoveredBy
            output      :   cover_trail
        */
        int CoveredBy(); 
        /*
            name        :   SetCover
            input       :   int 
            function    :   this Arc is covered now by int new cover 
        */
        void SetCover(int new_cover); 
        /*
            name        :   GetSourceValue
            output      :   Source vertex value 
        */
        int GetSourceValue(); 
        /*
            name        :   GetDestinyValue
            output      :   Destiny vertex value
        */
        int GetDestinyValue(); 
        /*
            name        :   GetSource
            output      :   Source vertex
        */
        Vertex GetSource(); 
        /*
            name        :   GetDestiny
            output      :   Destiny Vertex
        */
        Vertex GetDestiny(); 
        /*
            name        :   SetSource
            input       :   Vertex
            function    :   change source vertex to input vertex
        */
        void SetSource(Vertex new_src_vertex);
        /*
            name        :   SetDestiny
            input       :   Vertex
            function    :   change destiny vertex to input vertex
        */
        void SetDestiny(Vertex new_dst_vertex);
};

#endif