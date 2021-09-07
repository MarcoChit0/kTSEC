#ifndef TRAIL_HPP
#define TRAIL_HPP

#include "Arc.hpp"
#include <vector>
#include <iostream>

// CONSTANTS:
#define EMPTY_TRAIL 0

class Trail{ 
        private: 
        vector<Arc*> Arcs; 
        int Head; 
        int Tail; 
        int NumberOfTrails; 
        
        public: 
        /*
            name        :   Trail
            input       :   list of Arcs
            function    :   create Trail object 
        */
        Trail(vector<Arc*> list);
        /*
            name        :   Print
            function    :   print on terminal all arcs from this Trail 
        */        
        void Print();
        /*
            name        :   Size
            function    :   return Trail size
            output      :   size from list of Arcs 
        */        
        int Size(); 
        /*
            name        :   GetHead
            function    :   return Trail head pointer
            output      :   head 
        */        
        int GetHead();
        /*
            name        :   GetTail
            function    :   return Trail tail pointer
            output      :   tail 
        */        
        int GetTail(); 
        /*
            name        :   GetNumberOfTrails
            function    :   return the sum of all arcs number of trails from the list o Arcs 
            output      :   number of trails 
        */        
        int GetNumberOfTrails(); 
        /*
            name        :   CoveredBy
            input       :   index (int)
            function    :   return coveredBy field from Arc at index position 
            output      :   list of Arcs at index -> coveredBy  
        */        
        int CoveredBy(int index); 
        /*
            name        :   SetTail
            input       :   new_tail (int)
            function    :   update currrent tail to new_tail 
        */        
        void SetTail(int new_tail);
        /*
            name        :   SetHead
            input       :   new_head (int)
            function    :   update current head to new_head
        */        
        void SetHead(int new_head); 
        /*
            name        :   GetArcs
            function    :   return list of Arcs 
            output      :   arcs 
        */        
        vector <Arc*> GetArcs(); 
        /*
            name        :   SetCover
            input       :   new_cover (int), arc_index (int)
            function    :   update cover from Arc into list of Arcs at arc_index to new_cover 
        */        
        void SetCover(int new_cover, int arc_index); 
        /*
            name        :   Split
            input       :   capactity (int)
            function    :   split the Trail's list of Arcs into lists of size at most capacity  
            output      :   list containing all lists of size at most capacity 
        */        
        vector <Trail> Split(int capacity); 
        /*
            name        :   SubtrailSize
            function    :   if there is a subtrail, return its size
            output      :   tail - head
        */        
        int SubtrailSize(); 
        /*
            name        :   NumberOfTrailsCorrection
            function    :   update number of trails field
        */        
        void NumberOfTrailsCorrection(); 
        /*
            name        :   GetArc
            input       :   arc_index
            output      :   Arc*
            function    :   return a pointer to Arc at arc_index
        */
        Arc* GetArc(int arc_index); 
};

#endif