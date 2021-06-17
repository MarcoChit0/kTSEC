#include "data.hpp"

using namespace std; 

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
    this->cover_trail = 0;
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


Trail::Trail(vector<Arc*> list) {
    this->arcs = list;
    this->number_of_trails = 0;
    for (int i = 0; i < this->arcs.size(); i++) {
        this->arcs.at(i)->addTrail();
        this->number_of_trails += this->arcs.at(i)->getNumberOfTrails();
    }
    this->head = 0;
    this->tail = !this->arcs.empty() ? this->arcs.size()-1 : -1;
}

void Trail::print() {
    for(int i = 0; i < this->arcs.size(); i++) {  
        cout <<"trail   :   " << i << endl;
        this->arcs.at(i)->print();
    }
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