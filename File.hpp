#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream> 
#include <vector>
#include <regex> 
#include <string> 
#include "Set.hpp"

#define IGNORE_LINES 0
#define SRC_POS 0
#define DST_POS 1
using namespace std; 


Set Read(string file_name);
Set file_format_0(string file_name); 
void Write(string file_name, Set s);
vector<string> tokenize(string line);
bool isNumber(const string& str);
vector <Arc*> sort_list_of_arcs_by_first_vertex(vector <Arc*> lis_of_arcs); 
vector <Arc*> sort_list_of_arcs_by_second_vertex(vector <Arc*> lis_of_arcs); 
vector <Arc*> remove_duplicate_elements(vector <Arc*> list_of_arc);



#endif