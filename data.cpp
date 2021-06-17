#include "data.hpp"

using namespace std; 

#define NO_COVER -1

Vertex::Vertex(int Vertex_number) {
    this->number = Vertex_number;
}

Vertex::Vertex() {
    this->number = -1;
}

int Vertex::getNumber() {
    return this->number;
}


Arc::Arc(Vertex first_Vertex, Vertex last_Vertex) {
    this->arc_first_vertex = first_Vertex;
    this->arc_last_vertex = last_Vertex;
    this->number_of_trails = 0;
    this->cover_trail = NO_COVER;
}

void Arc::addTrail() {
    this->number_of_trails = this->number_of_trails + 1;
}

void Arc::print() {
    cout << "arc     :   " << this->arc_first_vertex.getNumber();
    cout << "  ->  " << this->arc_last_vertex.getNumber()  << endl; 
    cout << "#trails :   " << this->number_of_trails <<endl;
    cout << "covered :   " << this->cover_trail << endl << endl;  
}

int Arc::getNumberOfTrails() {
    return this->number_of_trails;
}

int Arc::coveredBy(){
    return this->cover_trail; 
}

void Arc::changeCover(int new_cover){
    this->cover_trail = new_cover; 
}

Trail::Trail(vector<Arc*> list) {
    this->arcs = list;
    this->number_of_trails = 0;
    for (int i = 0; i < this->arcs.size(); i++) {
        this->arcs.at(i)->addTrail();
        this->number_of_trails += this->arcs.at(i)->getNumberOfTrails();
    }
    this->head = 0;
    this->tail = 0;
}

void Trail::print() {
    for(int i = 0; i < this->arcs.size(); i++) {  
        cout <<"trail   :   " << i << endl;
        this->arcs.at(i)->print();
    }
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

int Trail::getNumberOfTrails(){
    return this->number_of_trails; 
}

int Trail::coveredBy(int index){ 
    return this->arcs.at(index)->coveredBy(); 
}

void Trail::addTail(){
    this->tail++; 
}

Set::Set(vector<Trail> new_set) {
    this->trails = new_set;
}

void Set::print() {
    for(int i=0; i < this->trails.size(); i++){
        cout << "set    :   " << i << endl;
        this->trails.at(i).print(); 
    }
}

int Set::size(){
    return this->trails.size();
}

int Set::getTrailSize(int index){
    return this->trails.at(index).size(); 
}

int Set::getTrailHead(int index){
    return this->trails.at(index).size(); 
}

int Set::getTrailTail(int index){
    return this->trails.at(index).size(); 
}

int Set::coveredBy(int index_trail, int index_arc){ 
    return this->trails.at(index_trail).coveredBy(index_arc); 
}

void Set::addTail(int index){ 
    this->trails.at(index).addTail(); 
}

Set algorithm_for_NEMO(vector <Arc *> arcs, Set trails, int capacity){
    Set S({}), UF = trails, R({}); 
    int index; 
    // all arcs start with 0 as value for coveredBy field
    // sorted in ascending order by the length of each trail and,
    // in case of ties, in descending order by the sum of the number of trails covering ther arcs of each trail
    UF.sort(); 

    for(int i=0; i< UF.size(); i++){
        // head and tail for each tail in UF are already equal to 0
        while(UF.getTrailTail(i) < UF.getTrailSize(i)){
            int aux = UF.coveredBy(i, UF.getTrailTail(i));
            if (aux == NO_COVER){
                UF.addTail(i);
            }
            else{

            }
        }
    }
}


