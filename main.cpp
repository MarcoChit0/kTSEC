#include "data.hpp"

int main(){
    Arc a = Arc(Vertex(2), Vertex(3)); 
    Arc b = Arc(Vertex(2), Vertex(3)); 
    Arc c = Arc(Vertex(3), Vertex(4)); 
    
    vector <Arc*> v1 = {&a, &b, &c}; 
    Trail t1 = Trail(v1);
    t1.print();
    a.print();

    Arc d = Arc(Vertex(1), Vertex(4)); 
    Arc e = Arc(Vertex(4), Vertex(2)); 
    Arc f = Arc(Vertex(2), Vertex(1)); 
    
    vector <Arc*> v2 = {&d, &e, &f}; 
    Trail t2 = Trail(v2);
    t2.print();

    Arc g = Arc(Vertex(4), Vertex(3)); 
    Arc h = Arc(Vertex(3), Vertex(1)); 
    
    vector <Arc*> v3 = {&g, &h}; 
    Trail t3 = Trail(v3);
    t3.print();

    vector <Arc*> v4 = {&f, &d, &g, &h}; 
    Trail t4 = Trail(v4);
    t4.print();

    vector<Trail> vs1 = {t1, t2, t3, t4};
    Set s1 = Set(vs1);
    s1.print();
}