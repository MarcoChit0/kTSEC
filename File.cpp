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
    // DEBUG:
    // cout << "set to be writen: "<<endl;
    // output_set.Print();
    // cout<<endl;
    ofstream my_file(file_name); 
    if(my_file.is_open())
    {
        for(int i=0; i< output_set.Size(); i++){
            for(int j =0; j< output_set.GetTrail(i).Size(); j++){
                my_file<< output_set.GetTrail(i).GetArc(j)->GetSourceValue()<<" "<< output_set.GetTrail(i).GetArc(j)->GetDestinyValue()<<endl;
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

Trail GenerateRandomTrail(Graph graph)
{
    Trail randomTrail({});
    if(graph.GetAdjacencyList().size()>0){
        int randomIndex = (rand() % graph.GetAdjacencyList().size()); 
        int randomExit = 0;
        vector <Vertex> randomVertices; 
        Vertex randomVertex;
        bool stop = false;
        do
        {
            randomVertex = graph.GetAdjacencyListUnitAt(randomIndex).GetVertex();
            randomVertices.push_back(randomVertex);
            BFSNodeList bfsList = graph.BFS(randomVertex);
            if(bfsList.GetNodeList().size() <= 1)
            {
                // no children case:
                stop = true;
            }
            else{
                vector<BFSNode> children = bfsList.GetChildrenByParent(bfsList.GetNodeList().at(0));
                if(children.size() > 0)
                {
                    bool isVertexFromRandomVertices = false;
                    do{
                        isVertexFromRandomVertices = false;
                        randomIndex = rand() % (children.size() + randomExit) + 0;  // generate a random number    
                        randomExit += (rand() % 4) -1;  // change the random exit factor     
                        if(randomExit < 0)
                        {
                            randomExit = 0; // random exit factor cannot be less than 0
                        }                        
                        if(randomIndex < children.size())
                        {
                            for(int i=0; i< randomVertices.size(); i++)
                            {
                                if(children.at(randomIndex).GetVertex().GetNumber() == randomVertices.at(i).GetNumber()){
                                    isVertexFromRandomVertices = true;
                                }
                            }
                            randomIndex = graph.GetIndexFromVertex(children.at(randomIndex).GetVertex());   // get index from vertex in the graph
                        }   
                        else
                        {
                            // random exit case:
                            isVertexFromRandomVertices = false;
                            stop = true;
                        }
                    }while(isVertexFromRandomVertices);
                }
                else
                {
                    // no children case:
                    stop = true;
                }
            }
        }while(!stop);
        if(randomVertices.size()>= 2)
        {
            // transform all vertex list in a trail
            vector<Arc*> listOfArcs; 
            for(int i= 0; i< (randomVertices.size()-1); i++){
                listOfArcs.push_back(graph.GetAdjacencyListUnitBy(randomVertices.at(i), randomVertices.at(i+1)));
            }
            randomTrail = Trail(listOfArcs);
        }
    }
    return randomTrail;
}

void CreateRandomTrailsFile(string file_name, vector<Arc*> listOfArcs, int how_many_trails){
    if(how_many_trails > 0){
        srand (time(NULL));         // set seed
        vector<Trail> listOfTrails; 
        Graph graph;
        graph.FromArcs(listOfArcs);
        int cont = 0;
        do{
            Trail randomTrail = GenerateRandomTrail(graph);
            bool EqualTrails = false;
            bool EqualArcs = false;
            if(randomTrail.GetArcs().size()>0){
                // conferir se já tem uma trilha igual a trilha já está na lista de trilhas
                // adicionar a validação de que todos os arcos precisam estar cobertos
                for(int i =0; i< listOfTrails.size() && !EqualTrails; i++){
                    if(listOfTrails.at(i).GetArcs().size() == randomTrail.GetArcs().size()){
                        EqualArcs = false;
                        for(int j=0; j< randomTrail.GetArcs().size() && EqualArcs; j++){
                            if(randomTrail.GetArcs().at(j)->GetSource().GetNumber() == listOfTrails.at(i).GetArcs().at(j)->GetSource().GetNumber()
                            && randomTrail.GetArcs().at(j)->GetDestiny().GetNumber() == listOfTrails.at(i).GetArcs().at(j)->GetDestiny().GetNumber()
                            && EqualArcs){
                                EqualArcs = true;
                            }
                            else{
                                EqualArcs = false;
                            }
                        }
                        if(EqualArcs){
                            EqualTrails = true;
                        }
                        else{
                            EqualTrails = false;
                        }                        
                    }
                }
                if(!EqualTrails){
                    listOfTrails.push_back(randomTrail);
                    cont++;                       
                }
            }
        }while(cont < how_many_trails);
        WriteTrailFile(file_name,Set(listOfTrails));
    }
    else{
        cout<<" CreateRandomTrailsFile -- error -- input size is lower than or qual 0"<<endl; 
        exit(EXIT_FAILURE);  
    }

}