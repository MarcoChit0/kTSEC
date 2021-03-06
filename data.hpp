#ifndef DATA_HPP
#define DATA_HPP

#include "Vertex.hpp"
#include "Arc.hpp"
#include "Trail.hpp"
#include "Set.hpp"
#include "File.hpp"

#include <iostream>
#include <vector> 
#include <utility>

using namespace std;  

Set AlgorithmForNEMO( Set trails, int capacity);

// if a is subtrail of b 
//      then return true 
//      else return false
bool IsSubtrail(vector <Arc*> a, vector <Arc*> b);

#endif