#ifndef SET_HPP
#define SET_HPP

#include "Trail.hpp"
#include <iostream>
#include <vector>

using namespace std; 

class Set{     
    private: 
        vector<Trail> trails; 
    public: 
        /*
            name        :   Set
            input       :   new_set (vector of trails)
            function    :   creates a new Set
        */
        Set(vector<Trail> new_set);
        /*
            name        :   print
            function    :   print all trails on terminal 
        */
        void print();
        /*
            name        :   sort
            function    :   sort trails in ascending order by the length of each Trail, 
                            and, in case of ties, in descending order by the sum of the number of trails covering the arcs of each Trail 
        */    
        void sort(); 
        /*
            name        :   size
            function    :   return vector of trails' size
            output      :   trails size
        */        
        int  size(); 
        /*
            name        :   getTrailSize
            input       :   index (int)
            function    :   return size of Trail at index
            output      :   Trail at index -> size 
        */        
        int  getTrailSize(int index); 
        /*
            name        :   getTrailTail
            input       :   index (int)
            function    :   return tail from Trail at index
            output      :   Trail at index -> tail 
        */        
        int  getTrailTail(int index); 
        /*
            name        :   getTrailHead
            input       :   index (int)
            function    :   return head from Trail at index
            output      :   Trail at index -> head 
        */        
        int  getTrailHead(int index); 
        /*
            name        :   getTrailArcs
            input       :   index (int)
            function    :   return list of Arcs from Trail at index
            output      :   Trail at index -> list of Arcs 
        */
        vector <Arc*> getTrailArcs(int index); 
        /*
            name        :   getTrail
            input       :   index (int)
            function    :   return a Trail at index
            output      :   Trail at index 
        */
        Trail getTrail(int index); 
        /*
            name        :   coveredBy
            input       :   arc_index (int), trail_index (int)
            function    :   return Arc at arc_index from Trail at trail_index 
            output      :   Trail at trail_index -> Arc at arc_index -> coveredBy
        */        
        int  coveredBy(int trail_index, int arc_index); 
        /*
            name        :   changeTrailTail
            input       :   arc_index (int), trail_index (int)
            function    :   update tail from Trail at trail_index
        */        
        void changeTrailTail(int trail_index, int new_tail); 
        /*
            name        :   deleteTrail
            input       :   index (int)
            function    :   remove Trail at index from Trail list 
        */        
        void deleteTrail(int index); 
        /*
            name        :   addTrail
            input       :   t (Trail)
            function    :   add Trail t to Trail list
        */        
        void addTrail(Trail t); 
        /*
            name        :   changeCover
            input       :   arc_index (int), trail_index (int), new_cover (int)
            function    :   update Arc coveredBy field to new_cover
                            Set -> Trail at trail_index -> Arc at arc_index -> coveredBy = new_cover
        */        
        void changeCover(int new_cover, int arc_index, int trail_index); 
        /*
            name        :   changeTrailHead
            input       :   trail_index (int), new_head (int)
            function    :   update head from Trail at trail_index
        */        
        void changeTrailHead(int trail_index, int new_head); 
        /*
            name        :   split
            input       :   capacity (int)
            function    :   call split from Trails to all Trails from list of Trails 
            output      :   list of Trails, whose size is at most capacity 
        */        
        vector <Trail> split(int capacity);
        /*
            name        :   subtrailSize
            input       :   trail_index (int)
            function    :   return size of subtrail at trail_index
            output      :   Set -> Trail at trail_index -> (head - tail)
        */        
        int  subtrailSize(int trail_index); 
        /*
            name        :   numberOfTrailsCorrection
            function    :   call numberOfTrailsCorrection from trails to all Trails from list of Trails
        */        
        void numberOfTrailsCorrection(); 
};

#endif