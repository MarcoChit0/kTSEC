#include "Arc.hpp"

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