#ifndef TRAIL_HPP
#define TRAIL_HPP

#include "Arc.hpp"
#include <vector>
#include <iostream>

#define EMPTY_TRAIL 0

class Trail{ 
    public: 
        Trail(vector<Arc*> list);
        void print();
        int size(); 
        int getHead();
        int getTail(); 
        int getNumberOfTrails(); 
        int coveredBy(int index); 
        void changeTail(int new_tail);
        void changeHead(int new_head); 
        vector <Arc*> getArcs(); 
        void changeCover(int new_cover, int arc_index); 
        vector <Trail> split(int capacity); 
        int subtrailSize(); 
        void numberOfTrailsCorrection(); 
    private: 
        vector<Arc*> arcs; 
        int head; 
        int tail; 
        int number_of_trails; 
};

#endif