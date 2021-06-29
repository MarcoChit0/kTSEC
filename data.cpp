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

void Set::numberOfTrailsCorrection(){
    for(int i=0; i<this->trails.size(); i++){
        this->trails.at(i).numberOfTrailsCorrection();
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

Set algorithm_for_NEMO(vector <Arc *> arcs, Set trails, int capacity){
    // S <- empty 
    Set sol({}), unassigned_flows = trails; 
    // c <- 0
    int cover_index = 0; 
    // CoveredBy(a) <- null, for each a in A
    for(int i=0; i<unassigned_flows.size(); i++){
        for(int j=0; j<unassigned_flows.getTrailSize(i); j++){
            unassigned_flows.changeCover(NO_COVER, j, i); 
        }
    }
    // UF <- sort
        // sorted in ascending order by the length of each trail and,
        // in case of ties, in descending order by the sum of the number of trails covering ther arcs of each trail
    unassigned_flows.sort(); 
    unassigned_flows.print();
    system("pause");
    // for each f in UF do... 
    for(int flow=0; flow< unassigned_flows.size(); flow++){ cout << "flow : " << flow << endl; // debug
        // h <- 0
        unassigned_flows.changeTrailHead(flow, 0);
        // t <- 0 
        unassigned_flows.changeTrailTail(flow, 0);
            // head and tail for each tail in unassigned_flows are already equal to EMPTY_TRAIL = 0
        // while t < |f| do... 
        while(unassigned_flows.getTrailTail(flow) < unassigned_flows.getTrailSize(flow)){ cout << "1" <<endl; // debug
            // g <- coveredBy(f(t))
            int aux = unassigned_flows.coveredBy(flow, unassigned_flows.getTrailTail(flow));
            // if g = null, then...
            if (aux == NO_COVER){cout << "2" <<endl; // debug
                // t <- t + 1
                unassigned_flows.changeTrailTail(flow, (unassigned_flows.getTrailTail(flow) + 1));
            }
            // else...
            else{cout << "3" <<endl; // debug
                // if subtrail(S(g),f), then... 
                if(isSubtrail(sol.getTrailArcs(aux), unassigned_flows.getTrailArcs(flow))){cout << "4" <<endl; // debug
                    // t <- t + |S(g)|
                    unassigned_flows.changeTrailTail(flow, (sol.getTrailArcs(aux).size() + unassigned_flows.getTrailTail(flow) -1)); 
                    // S(g) <- null
                    sol.deleteTrail(aux); 
                }
                // else...
                else{cout << "5" <<endl; // debug
                    // if |f(h:t)| > 0, then... 
                    if(unassigned_flows.subtrailSize(flow)){ cout << "6" <<endl; // debug
                        // S <- S u f(h:t) 
                        sol.addTrail(unassigned_flows.getTrail(flow)); 
                        // for each a in f(h:t) do... 
                        for(int i= unassigned_flows.getTrailHead(flow); i < unassigned_flows.getTrailTail(flow); i++) {cout << "7" <<endl; // debug
                            // CoveredBy(a) <- c
                            sol.changeCover(cover_index, i, flow); 
                        }
                        // c <- c + 1
                        cover_index++; 
                        // h <- t
                        unassigned_flows.changeTrailHead(flow, unassigned_flows.getTrailTail(flow)); 
                    }
                    // else... 
                    else{ cout << "8" <<endl; // debug 
                        // h <- h + 1
                        unassigned_flows.changeTrailHead(flow, unassigned_flows.getTrailHead(flow) + 1);
                        // t <- h
                        unassigned_flows.changeTrailTail(flow, unassigned_flows.getTrailHead(flow)); 
                    }
                }
            }
        }

        // if |f(h:t)| > 0, then... 
        if(unassigned_flows.subtrailSize(flow)){cout << "9" <<endl; // debug
            // S <- S u f(h:t) 
            sol.addTrail(unassigned_flows.getTrail(flow));
            sol.print();
            system("pause");
            // for each a in f(h:t) do... 
            for(int i=0; i < (unassigned_flows.getTrailTail(flow) - unassigned_flows.getTrailHead(flow ) ); i++) {cout << "10" <<endl; // debug
                sol.changeCover(cover_index, i, flow); 
            }
            sol.print();
            system("pause");
            // c <- c + 1
            cover_index = cover_index + 1; 
        }
    }
    // R <- empty 
    // for each sub-trail s in S do... 
        // for a <- 0, k, 2k, ... do...
        // R<- R u s(a:min(a+k,|s|))
    Set R(sol.split(capacity)); 
    return R; 
}


bool isSubtrail(vector <Arc*> a, vector <Arc*> b){
     size_t len = min(a.size(), b.size());

    return equal(a.begin(), a.begin()+len, 
                 b.begin(), b.begin()+len);
}