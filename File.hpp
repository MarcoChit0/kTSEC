#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream> 
#include <vector>
#include <string> 
#include <sstream>
#include "Set.hpp"

#define SRC_POS 0
#define DST_POS 1

vector <Arc*> read_arc_file(string file_name); 
bool isNumber(const string& str);
vector <Trail> read_trail_file(string file_name, vector <Arc*>list_of_pointers);
vector<string> tokenize(string line);
#endif