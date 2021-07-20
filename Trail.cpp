#include "Trail.hpp"

Trail::Trail(vector<Arc*> list) {
    this->arcs = list;
    for(int i=0; i<list.size();i++){
        list.at(i)->addTrail(); 
    }
    this->number_of_trails = EMPTY_TRAIL; 
    this->head = EMPTY_TRAIL;
    this->tail = EMPTY_TRAIL;
}

void Trail::print() {
    for(int i = 0; i < this->arcs.size(); i++) {  
        cout <<"trail   :   " << i << endl;
        this->arcs.at(i)->print();
    }
    cout << endl;
}

int Trail::size(){
    return this->arcs.size(); 
}

int Trail::getHead(){
    return this->head;  
}

int Trail::getTail(){
    return this->tail; 
}

vector <Arc*> Trail::getArcs(){
    return this->arcs; 
} 

int Trail::getNumberOfTrails(){
    return this->number_of_trails; 
}

int Trail::coveredBy(int index){ 
    return this->arcs.at(index)->coveredBy(); 
}

void Trail::changeTail(int new_tail){
    this->tail = new_tail; 
}

void Trail::changeCover(int new_cover, int arc_index){
    this->arcs.at(arc_index)->changeCover(new_cover); 
}

void Trail::changeHead(int new_head){ 
    this->head = new_head; 
}

int Trail::subtrailSize(){
    if( this->tail != EMPTY_TRAIL && this->tail > this->head){
        return this->tail - this->head;
    }
    else return EMPTY_TRAIL; 
}

void Trail::numberOfTrailsCorrection(){
    this->number_of_trails = 0;
    for(int i=0; i<this->arcs.size(); i++){
        this->number_of_trails += this->arcs.at(i)->getNumberOfTrails(); 
    }
}

vector <Trail> Trail::split(int capacity){ 
    int current =0, previous = 0; 
    vector <Arc*> aux_arcs= {};  
    vector <Trail> list_of_trails; 
    for(int i=0; i<this->arcs.size(); i = i + capacity){ 
        for(int j=0; (j < capacity) && ((i+j) < this->arcs.size()); j++){
            aux_arcs.push_back(this->arcs.at(j+i)); 
        }
        Trail new_trail(aux_arcs);
        list_of_trails.push_back(new_trail);
        aux_arcs.clear(); 
    }
    return list_of_trails; 
}

Arc* Trail::getArc(int index){
    return this->arcs.at(index); 
}