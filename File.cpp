#include "File.hpp"
vector <Arc> read_arc_file(string file_name){
    ifstream my_file(file_name);
    if(my_file.is_open()){
        string line; 
        vector <string> tokens; 
        vector <Arc> list_of_arcs; 
        while(getline(my_file,line) && line.length()>0){
                tokens = tokenize(line); 
                if(isNumber(tokens.at(SRC_POS)) && isNumber(tokens.at(DST_POS))){
                    Vertex src(stoi(tokens.at(SRC_POS))); 
                    Vertex dst(stoi(tokens.at(DST_POS))); 
                    Arc new_arc(src, dst); 
                    list_of_arcs.push_back(new_arc); 
            }
        }
        return list_of_arcs; 
    }
    else{
       cout<<" read_arc_file -- error -- could not open input file"<<endl; 
       exit(EXIT_FAILURE);         
    }
}

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void make_list_of_pointers(vector <Arc> list_of_arcs, vector <Arc*> *list){
    vector <Arc*> list_of_pointers; 
    for(int i=0; i<list_of_arcs.size(); i++){
        list_of_pointers.push_back(&list_of_arcs.at(i));
    }
    *list = list_of_pointers;
}

vector<string> tokenize(string line) {

    vector <string> tokens;
    stringstream check1(line);
      
    string intermediate;

    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }

    return tokens;
}

vector <Trail> read_trail_file(string file_name, vector <Arc*>list_of_pointers){
    ifstream my_file(file_name);
    if(my_file.is_open()){
        string line; 
        vector <string> tokens; 
        vector <Arc> list_of_arcs; 
        vector <Arc*> aux; 
        vector <Trail> list_of_trails; 
        while(getline(my_file,line)){
                if(line.length()>0){
                    tokens = tokenize(line);
                    if(isNumber(tokens.at(SRC_POS)) && isNumber(tokens.at(DST_POS))){
                        Vertex src(stoi(tokens.at(SRC_POS))); 
                        Vertex dst(stoi(tokens.at(DST_POS))); 
                        Arc new_arc(src, dst); 
                        list_of_arcs.push_back(new_arc);
                        }                
                }
                else{
                    for(int i=0; i<list_of_arcs.size();i++){
                        bool found = false; 
                        for(int j=0; j<list_of_pointers.size();j++){
                            if( (list_of_arcs.at(i).getFst() == list_of_pointers.at(j)->getFst())
                            && (list_of_arcs.at(i).getSnd() == list_of_pointers.at(j)->getSnd())
                            && !found){
                                aux.push_back(list_of_pointers.at(j)); 
                                found = true; 
                            }
                        }
                    }
                    Trail new_trail(aux); 
                    list_of_trails.push_back(new_trail); 
                    aux.erase(aux.begin(), aux.begin() + aux.size()); 
                    list_of_arcs.erase(list_of_arcs.begin(), list_of_arcs.begin() +list_of_arcs.size()); 
                }
        }
        return list_of_trails; 
    }
    else{
       cout<<" read_trail_file -- error -- could not open input file"<<endl; 
       exit(EXIT_FAILURE);         
    }
}