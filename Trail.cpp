#include "Trail.hpp"

Trail::Trail(vector<Arc*> list) {
    this->Arcs = list;
    for(int i=0; i<list.size();i++){
        list.at(i)->AddTrail(); 
    }
    this->NumberOfTrails = EMPTY_TRAIL; 
    this->Head = EMPTY_TRAIL;
    this->Tail = EMPTY_TRAIL;
}

void Trail::Print() {
    for(int i = 0; i < this->Arcs.size(); i++) {  
        cout <<"trail   :   " << i << endl;
        this->Arcs.at(i)->Print();
    }
    cout << endl;
}

int Trail::Size(){
    return this->Arcs.size(); 
}

int Trail::GetHead(){
    return this->Head;  
}

int Trail::GetTail(){
    return this->Tail; 
}

vector <Arc*> Trail::GetArcs(){
    return this->Arcs; 
} 

int Trail::GetNumberOfTrails(){
    return this->NumberOfTrails; 
}

int Trail::CoveredBy(int index){ 
    return this->Arcs.at(index)->CoveredBy(); 
}

void Trail::SetTail(int new_tail){
    this->Tail = new_tail; 
}

void Trail::SetCover(int new_cover, int arc_index){
    this->Arcs.at(arc_index)->SetCover(new_cover); 
}

void Trail::SetHead(int new_head){ 
    this->Head = new_head; 
}

int Trail::SubtrailSize(){
    if( this->Tail != EMPTY_TRAIL && this->Tail > this->Head){
        return this->Tail - this->Head;
    }
    else return EMPTY_TRAIL; 
}

void Trail::NumberOfTrailsCorrection(){
    this->NumberOfTrails = 0;
    for(int i=0; i<this->Arcs.size(); i++){
        this->NumberOfTrails += this->Arcs.at(i)->GetNumberOfTrails(); 
    }
}

vector <Trail> Trail::Split(int capacity){ 
    int current =0, previous = 0; 
    vector <Arc*> aux_arcs= {};  
    vector <Trail> list_of_trails; 
    for(int i=0; i<this->Arcs.size(); i = i + capacity){ 
        for(int j=0; (j < capacity) && ((i+j) < this->Arcs.size()); j++){
            aux_arcs.push_back(this->Arcs.at(j+i)); 
        }
        Trail new_trail(aux_arcs);
        list_of_trails.push_back(new_trail);
        aux_arcs.clear(); 
    }
    return list_of_trails; 
}

Arc* Trail::GetArc(int arc_index){
    return this->Arcs.at(arc_index); 
}