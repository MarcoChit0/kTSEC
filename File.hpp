#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream> 
#include <vector>
#include <string> 
#include <sstream>
#include <iomanip>
#include "Set.hpp"

#define SRC_POS 0
#define DST_POS 1


vector <Arc*> ReadArcFile(string file_name); 
bool IsNumber(const string& str);
vector <Trail> ReadTrailFile(string file_name, vector <Arc*>list_of_pointers);
vector<string> Tokenize(string line);
void WriteTrailFile(string file_name, Set output_set);
#endif