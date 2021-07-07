#ifndef TRAIL_HPP
#define TRAIL_HPP

#include "Arc.hpp"
#include <vector>
#include <iostream>

#define EMPTY_TRAIL 0

class Trail{ 
        private: 
        vector<Arc*> arcs; 
        int head; 
        int tail; 
        int number_of_trails; 
        
        public: 
        /*
            name        :   Trail
            input       :   list of Arcs
            function    :   create Trail object from that list of Arcs 
        */
        Trail(vector<Arc*> list);
        /*
            name        :   print
            function    :   print on terminal all arcs from this Trail 
        */        
        void print();
        /*
            name        :   size
            function    :   return Trail size
            output      :   size from list of Arcs 
        */        
        int size(); 
        /*
            name        :   getHead
            function    :   return Trail head pointer
            output      :   head 
        */        
        int getHead();
        /*
            name        :   getTail
            function    :   return Trail tail pointer
            output      :   tail 
        */        
        int getTail(); 
        /*
            name        :   getNumberOfTrails
            function    :   return the sum of all arcs number of trails from the list o Arcs 
            output      :   number of trails 
        */        
        int getNumberOfTrails(); 
        /*
            name        :   coveredBy
            input       :   index (int)
            function    :   return coveredBy field from Arc at index position 
            output      :   list of Arcs at index -> coveredBy  
        */        
        int coveredBy(int index); 
        /*
            name        :   changeTail
            input       :   new_tail (int)
            function    :   update currrent tail to new_tail 
        */        
        void changeTail(int new_tail);
        /*
            name        :   changeHead
            input       :   new_head (int)
            function    :   update current head to new_head
        */        
        void changeHead(int new_head); 
        /*
            name        :   getArcs
            function    :   return list of Arcs 
            output      :   arcs 
        */        
        vector <Arc*> getArcs(); 
        /*
            name        :   changeCover
            input       :   new_cover (int), arc_index (int)
            function    :   update cover from Arc into list of Arcs at arc_index to new_cover 
        */        
        void changeCover(int new_cover, int arc_index); 
        /*
            name        :   split
            input       :   capactity (int)
            function    :   split the Trail's list of Arcs into lists of size at most capacity  
            output      :   list containing all lists of size at most capacity 
        */        
        vector <Trail> split(int capacity); 
        /*
            name        :   subtrailSize
            function    :   if there is a subtrail, return its size
            output      :   tail - head
        */        
        int subtrailSize(); 
        /*
            name        :   numberOfTrailsCorrection
            function    :   update number of trails field
        */        
        void numberOfTrailsCorrection(); 

};

#endif