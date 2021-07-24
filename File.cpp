#include "File.hpp"
/*
vector <Trail> Read(string file_name){ 
   ifstream my_file(file_name); 
   if(my_file.is_open()){
        vector <Arc> list_of_arcs; 
        vector <Arc*> list_of_pointers; 
        string line; 
        vector <string> tokens; 
        while(getline(my_file, line) && line.length()>0){
            tokens = tokenize(line);
            if(isNumber(tokens.at(SRC_POS)) && isNumber(tokens.at(DST_POS))){
                Vertex src(stoi(tokens.at(SRC_POS))); 
                Vertex dst(stoi(tokens.at(DST_POS))); 
                Arc new_arc(src, dst); 
                list_of_arcs.push_back(new_arc); 
            }
        }   
        for(int i=0; i<list_of_arcs.size();i++){
            list_of_pointers.push_back(&list_of_arcs.at(i)); 
        }
        vector <Arc*> aux; 
        vector <Trail> list_of_trails; 
        while(getline(my_file,line)){
            if(line.length()>0){
                tokens = tokenize(line);
                if(isNumber(tokens.at(SRC_POS)) && isNumber(tokens.at(DST_POS))){
                    Vertex src(stoi(tokens.at(SRC_POS))); 
                    Vertex dst(stoi(tokens.at(DST_POS))); 
                    bool found=0;
                    for(int i=0; i<list_of_pointers.size() && !found;i++){
                        if( (src.getNumber() == list_of_pointers.at(i)->getFst())&&
                            (dst.getNumber() == list_of_pointers.at(i)->getSnd())){
                                found = true; 
                                aux.push_back(list_of_pointers.at(i)); 
                            }
                    }
                }
            }
            else{
                Trail new_trail(aux); 
                aux.erase(aux.begin(), aux.begin()+aux.size()); 
                list_of_trails.push_back(new_trail); 
            }
        }
        Trail new_trail(aux); 
        aux.erase(aux.begin(), aux.begin()+aux.size()); 
        list_of_trails.push_back(new_trail); 
        return list_of_trails;
   }
   else{
       cout<<"Read -- error -- could not open input file"<<endl; 
       exit(EXIT_FAILURE); 
   }
}


void Write(string file_name, Set s){
    ofstream my_file(file_name); 
    if(my_file.is_open()){
        for(int i=0; i<s.size();i++){
            for(int j=0;j<s.getTrail(i).size();j++){
                my_file<< s.getTrail(i).getArc(j)->getFst() <<" "<<s.getTrail(i).getArc(j)->getSnd()<<endl;  
            }
            my_file<<endl;
        }
    }
    else{
        cout<<"Write -- error -- could not open output file"<<endl; 
        exit(EXIT_FAILURE);
    }
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

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

vector <Arc*> sort_list_of_arcs_by_first_vertex(vector <Arc*> list){ 
    int i, j;

    for (i = 1; i < list.size(); i++)
    {
        Arc* key = list.at(i); 
        j = i - 1;

        while (j >= 0 && list.at(j)->getFst() > key->getFst())
        {
            list.at(j+1) = list.at(j);
            j = j - 1;
        }
        list.at(j+1) = key;
        
    }

    return sort_list_of_arcs_by_second_vertex(list); 
}

vector <Arc*> sort_list_of_arcs_by_second_vertex(vector <Arc*> list){
        int i, j;

    for (i = 1; i < list.size(); i++)
    {
        Arc* key = list.at(i); 
        j = i - 1;

        while (j >= 0 && list.at(j)->getSnd() > key->getSnd() && list.at(j)->getFst() == key->getFst())
        {
            list.at(j+1) = list.at(j);
            j = j - 1;
        }
        list.at(j+1) = key;
        
    }
    return list; 
}
*/

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

vector <Arc*> make_list_of_pointers(vector <Arc> list_of_arcs){
    vector <Arc*> list_of_pointers; 
    for(int i=0; i<list_of_arcs.size(); i++){
        cout << "arc: "<< list_of_arcs.at(i).getFst() <<" "<< list_of_arcs.at(i).getFst(); 
        cout << "   &: "<< &list_of_arcs.at(i)<<endl; 
        list_of_pointers.push_back(&list_of_arcs.at(i));
    }
    return list_of_pointers; 
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