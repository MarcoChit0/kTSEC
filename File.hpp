#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream> 
#include <vector>
#include <string> 
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h> 
#include <chrono>
#include "Set.hpp"
#include "Graph.hpp"

#define SRC_POS 0
#define DST_POS 1

Trail GenerateRandomTrail(Graph graph);
vector <Arc*> ReadArcFile(string file_name); 
void CreateRandomTrailsFile(string file_name, vector<Arc*> arcs, int how_many_trails);
bool IsNumber(const string& str);
vector <Trail> ReadTrailFile(string file_name, vector <Arc*>list_of_pointers);
vector<string> Tokenize(string line);
void WriteTrailFile(string file_name, Set output_set);
#endif