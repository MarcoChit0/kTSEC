#include "Arc.hpp"

Arc::Arc(Vertex first_Vertex, Vertex last_Vertex) {
    this->Source = first_Vertex;
    this->Destiny = last_Vertex;
    this->NumberOfTrails = 0;
    this->CoverTrail = NO_COVER;
}

void Arc::AddTrail() {
    this->NumberOfTrails = this->NumberOfTrails + 1;
}

void Arc::Print() {
    cout << "arc     :   " << this->Source.GetNumber();
    cout << "  ->  " << this->Destiny.GetNumber()  << endl; 
    cout << "#trails :   " << this->NumberOfTrails <<endl;
    cout << "covered :   " << this->CoverTrail << endl << endl;  
}

int Arc::GetNumberOfTrails() {
    return this->NumberOfTrails;
}

int Arc::CoveredBy(){
    return this->CoverTrail; 
}

void Arc::SetCover(int new_cover){
    this->CoverTrail = new_cover; 
}

int Arc::GetDestinyValue(){
    return this->Destiny.GetNumber(); 
}

int Arc::GetSourceValue(){
    return this->Source.GetNumber();
}


Vertex Arc::GetSource(){
    return this->Source; 
}

Vertex Arc::GetDestiny(){
    return this->Destiny; 
}

        void Arc::SetSource(Vertex new_fst_vertex){
            this->Source = new_fst_vertex;
        }
        void Arc::SetDestiny(Vertex new_snd_vertex){
            this->Destiny = new_snd_vertex;
        }