#include "Set.hpp"

void Set::NumberOfTrailsCorrection(){
    for(int i=0; i<this->Trails.size(); i++){
        this->Trails.at(i).NumberOfTrailsCorrection();
    }
}

Set::Set(vector<Trail> new_set) {
    this->Trails = new_set;
}

void Set::Print() {
    for(int i=0; i < this->Trails.size(); i++){
        cout << "----------------------------"<<endl;
        cout << "set    :   " << i << endl;
        cout << "----------------------------"<<endl;
        cout << "#trails:   "<<this->Trails.at(i).GetNumberOfTrails()<<endl<<endl;
        this->Trails.at(i).Print(); 
        cout << endl; 
        cout << "----------------------------"<<endl;
    }
}

int Set::Size(){
    return this->Trails.size();
}

int Set::GetTrailSize(int index){
    return this->Trails.at(index).Size(); 
}

int Set::GetTrailHead(int index){
    return this->Trails.at(index).GetHead(); 
}

int Set::GetTrailTail(int index){
    return this->Trails.at(index).GetTail(); 
}

vector <Arc*> Set::GetTrailArcs(int index){
    return this->Trails.at(index).GetArcs();
}

int Set::CoveredBy(int index_trail, int index_arc){ 
    return this->Trails.at(index_trail).CoveredBy(index_arc); 
}

void Set::SetTrailTail(int index, int n){ 
    this->Trails.at(index).SetTail(n); 
}

void Set::Sort(){
    int i, j;

    this->NumberOfTrailsCorrection();

    for (i = 1; i < this->Trails.size(); i++)
    {
        Trail key = this->Trails.at(i); 
        j = i - 1;

        while (j >= 0 && this->Trails.at(j).Size() > key.Size())
        {
            this->Trails.at(j+1) = this->Trails.at(j);
            j = j - 1;
        }

        if( j>=0 && this->Trails.at(j).Size() == key.Size()){
            if(this->Trails.at(j).GetNumberOfTrails() < key.GetNumberOfTrails()){
                this->Trails.at(j+1) = this->Trails.at(j);
                this->Trails.at(j) = key;
            }
        }
        else this->Trails.at(j+1) = key;
        
    }
}

void Set::AddTrail(Trail t){
    // a0 a1 a2 ... ah-1 ah ah+1 ... at-1 at at+1... an-1
    vector <Arc*> arcs; 
    arcs = t.GetArcs(); 
    // a0 a1 a2 ... ah-1 ah ah+1 ... at-1 at
    if(t.GetTail() < arcs.size()) arcs.erase(arcs.begin() + t.GetTail() , arcs.begin() + arcs.size());
    // ah ah+1 ... at-1 at
    if(t.GetHead() > 0) arcs.erase(arcs.begin(), arcs.begin() + t.GetHead()); 
    
    Trail aux(arcs); 
    this->Trails.push_back(aux); 
}

Trail Set::GetTrail(int index){
    return this->Trails.at(index);
}

void Set::DeleteTrail(int index){
    this->Trails.erase(Trails.begin() + index); 
}

void Set::SetCover(int new_cover, int arc_index, int trail_index){
    this->Trails.at(trail_index).SetCover(new_cover, arc_index); 
}

void Set::SetTrailHead( int trail_index, int new_head){
    this->Trails.at(trail_index).SetHead(new_head); 
}

vector <Trail> Set::Split(int capacity){ 
    vector <Trail> new_set_of_trails; 
    vector <Trail> aux; 
    for(int i=0; i < this->Trails.size(); i++){
        aux = this->Trails.at(i).Split(capacity); 
        for(int j=0; j < aux.size(); j++ ){
            new_set_of_trails.push_back(aux.at(j));
        }
    }
    return new_set_of_trails; 
}

int  Set::SubtrailSize(int trail_index){
    return this->Trails.at(trail_index).SubtrailSize();
}