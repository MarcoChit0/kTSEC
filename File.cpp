#include "File.hpp"
vector <Arc*> ReadArcFile(string file_name){
    ifstream my_file(file_name);
    if(my_file.is_open()){
        string line; 
        vector <string> tokens; 
        vector <Arc*> list_of_arcs; 
        while(getline(my_file,line) && line.length()>0){
                tokens = Tokenize(line); 
                if(IsNumber(tokens.at(SRC_POS)) && IsNumber(tokens.at(DST_POS))){
                    Vertex src(stoi(tokens.at(SRC_POS))); 
                    Vertex dst(stoi(tokens.at(DST_POS))); 
                    Arc* new_arc = new Arc(src,dst); 
                    list_of_arcs.push_back(new_arc); 
            }
        }
        return list_of_arcs; 
    }
    else{
       cout<<" ReadArcFile -- error -- could not open input file"<<endl; 
       exit(EXIT_FAILURE);         
    }
}

bool IsNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

vector<string> Tokenize(string line) {

    vector <string> tokens;
    stringstream check1(line);
      
    string intermediate;

    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }

    return tokens;
}

vector <Trail> ReadTrailFile(string file_name, vector <Arc*>list_of_pointers){
    ifstream my_file(file_name);
    if(my_file.is_open()){
        string line; 
        vector <string> tokens; 
        vector <Arc> list_of_arcs; 
        vector <Arc*> aux; 
        vector <Trail> list_of_trails; 
        Trail new_trail({});
        while(getline(my_file,line)){
                if(line.length()>0){
                    tokens = Tokenize(line);
                    if(IsNumber(tokens.at(SRC_POS)) && IsNumber(tokens.at(DST_POS))){
                        Vertex src(stoi(tokens.at(SRC_POS))); 
                        Vertex dst(stoi(tokens.at(DST_POS))); 
                        Arc new_arc(src, dst); 
                        list_of_arcs.push_back(new_arc);
                        }                
                }
                else{
                    for(int i=0; i<list_of_arcs.size();i++){
                        bool found = false; 
                        for(int j=0; j<list_of_pointers.size()&& !found;j++){
                            if( (list_of_arcs.at(i).GetSourceValue() == list_of_pointers.at(j)->GetSourceValue())
                            && (list_of_arcs.at(i).GetDestinyValue() == list_of_pointers.at(j)->GetDestinyValue())){
                                aux.push_back(list_of_pointers.at(j)); 
                                found = true; 
                            }
                        }
                    }
                    new_trail = Trail(aux); 
                    list_of_trails.push_back(new_trail); 
                    aux.erase(aux.begin(), aux.begin() + aux.size()); 
                    list_of_arcs.erase(list_of_arcs.begin(), list_of_arcs.begin() +list_of_arcs.size()); 
                }
        }
        for(int i=0; i<list_of_arcs.size();i++){
            bool found = false; 
            for(int j=0; j<list_of_pointers.size()&& !found;j++){
                if( (list_of_arcs.at(i).GetSourceValue() == list_of_pointers.at(j)->GetSourceValue())
                    && (list_of_arcs.at(i).GetDestinyValue() == list_of_pointers.at(j)->GetDestinyValue())){
                    aux.push_back(list_of_pointers.at(j)); 
                    found = true; 
                }
            }
        }
        if(!aux.empty()){
            new_trail = Trail(aux);
            list_of_trails.push_back(new_trail); 
            aux.erase(aux.begin(), aux.begin() + aux.size()); 
            list_of_arcs.erase(list_of_arcs.begin(), list_of_arcs.begin() +list_of_arcs.size());             
        }
        my_file.close();
        return list_of_trails; 
    }
    else{
       cout<<" ReadTrailFile -- error -- could not open input file"<<endl; 
       exit(EXIT_FAILURE);         
    }
}


void WriteTrailFile(string file_name, Set output_set)
{
    ofstream my_file(file_name); 
    if(my_file.is_open())
    {
        for(int i=0; i< output_set.Size(); i++){
            for(int j =0; j< output_set.GetTrail(i).Size(); j++){
                my_file<<"  "<< output_set.GetTrail(i).GetArc(j)->GetSourceValue()<<right<< setw(4) << output_set.GetTrail(i).GetArc(j)->GetDestinyValue()<<endl;
            }
            my_file<<endl;
        }
        my_file.close();
    }
    else
    {
        cout<<" WriteTrailFile -- error -- could not open output file"<<endl; 
        exit(EXIT_FAILURE);         
    }
    
}