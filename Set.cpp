#include "Set.hpp"

void Set::numberOfTrailsCorrection(){
    for(int i=0; i<this->trails.size(); i++){
        this->trails.at(i).numberOfTrailsCorrection();
    }
}

Set::Set(vector<Trail> new_set) {
    this->trails = new_set;
}

void Set::print() {
    for(int i=0; i < this->trails.size(); i++){
        cout << "----------------------------"<<endl;
        cout << "set    :   " << i << endl;
        cout << "----------------------------"<<endl;
        cout << "#trails:   "<<this->trails.at(i).getNumberOfTrails()<<endl<<endl;
        this->trails.at(i).print(); 
        cout << endl; 
        cout << "----------------------------"<<endl;
    }
}

int Set::size(){
    return this->trails.size();
}

int Set::getTrailSize(int index){
    return this->trails.at(index).size(); 
}

int Set::getTrailHead(int index){
    return this->trails.at(index).getHead(); 
}

int Set::getTrailTail(int index){
    return this->trails.at(index).getTail(); 
}

vector <Arc*> Set::getTrailArcs(int index){
    return this->trails.at(index).getArcs();
}

int Set::coveredBy(int index_trail, int index_arc){ 
    return this->trails.at(index_trail).coveredBy(index_arc); 
}

void Set::changeTrailTail(int index, int n){ 
    this->trails.at(index).changeTail(n); 
}

void Set::sort(){
    int i, j;

    this->numberOfTrailsCorrection();

    for (i = 1; i < this->trails.size(); i++)
    {
        Trail key = this->trails.at(i); 
        j = i - 1;

        while (j >= 0 && this->trails.at(j).size() > key.size())
        {
            this->trails.at(j+1) = this->trails.at(j);
            j = j - 1;
        }

        if( j>=0 && this->trails.at(j).size() == key.size()){
            if(this->trails.at(j).getNumberOfTrails() < key.getNumberOfTrails()){
                this->trails.at(j+1) = this->trails.at(j);
                this->trails.at(j) = key;
            }
        }
        else this->trails.at(j+1) = key;
        
    }
}

void Set::addTrail(Trail t){
    // a0 a1 a2 ... ah-1 ah ah+1 ... at-1 at at+1... an-1
    vector <Arc*> arcs; 
    arcs = t.getArcs(); 
    // a0 a1 a2 ... ah-1 ah ah+1 ... at-1 at
    if(t.getTail() < arcs.size()) arcs.erase(arcs.begin() + t.getTail() , arcs.begin() + arcs.size());
    // ah ah+1 ... at-1 at
    if(t.getHead() > 0) arcs.erase(arcs.begin(), arcs.begin() + t.getHead()); 
    
    Trail aux(arcs); 
    this->trails.push_back(aux); 
}

Trail Set::getTrail(int index){
    return this->trails.at(index);
}

void Set::deleteTrail(int index){
    this->trails.erase(trails.begin() + index); 
}

void Set::changeCover(int new_cover, int arc_index, int trail_index){
    this->trails.at(trail_index).changeCover(new_cover, arc_index); 
}

void Set::changeTrailHead( int trail_index, int new_head){
    this->trails.at(trail_index).changeHead(new_head); 
}

vector <Trail> Set::split(int capacity){ 
    vector <Trail> new_set_of_trails; 
    vector <Trail> aux; 
    for(int i=0; i < this->trails.size(); i++){
        aux = this->trails.at(i).split(capacity); 
        for(int j=0; j < aux.size(); j++ ){
            new_set_of_trails.push_back(aux.at(j));
        }
    }
    return new_set_of_trails; 
}

int  Set::subtrailSize(int trail_index){
    return this->trails.at(trail_index).subtrailSize();
}