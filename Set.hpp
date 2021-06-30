#ifndef SET_HPP
#define SET_HPP

#include "Trail.hpp"
#include <iostream>
#include <vector>

using namespace std; 

class Set{ 
    public: 
        Set(vector<Trail> new_set);
        void print();
        void sort(); 
        int  size(); 
        int  getTrailSize(int index); 
        int  getTrailTail(int index); 
        int  getTrailHead(int index); 
        vector <Arc*> getTrailArcs(int index); 
        Trail getTrail(int index); 
        int  coveredBy(int index_trail, int index_arc); 
        void changeTrailTail(int trail_index, int new_tail); 
        void deleteTrail(int index); 
        void addTrail(Trail t); 
        void changeCover(int new_cover, int arc_index, int trail_index); 
        void changeTrailHead(int trail_index, int new_head); 
        vector <Trail> split(int capacity);
        int  subtrailSize(int trail_index); 
        void numberOfTrailsCorrection(); 
    private: 
        vector<Trail> trails;  
};

#endif