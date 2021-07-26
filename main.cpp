#include "data.hpp"

int main(){
    /*
    Arc a = Arc(Vertex(11), Vertex(1)); 
    Arc b = Arc(Vertex(1), Vertex(3)); 
    Arc c = Arc(Vertex(3), Vertex(2)); 
    Arc d = Arc(Vertex(2), Vertex(3)); 
    Arc e = Arc(Vertex(2), Vertex(12)); 
    Arc f = Arc(Vertex(12), Vertex(2)); 
    Arc g = Arc(Vertex(3), Vertex(5)); 
    Arc h = Arc(Vertex(5), Vertex(14)); 
    Arc i = Arc(Vertex(4), Vertex(3)); 
    Arc j = Arc(Vertex(3), Vertex(4)); 
    Arc k = Arc(Vertex(13), Vertex(4)); 
    Arc l = Arc(Vertex(4), Vertex(13));

    vector <Arc*> v1 = {&a, &b, &c, &e}; 
    vector <Arc*> v2 = {&a, &b, &j, &l}; 
    vector <Arc*> v3 = {&f, &d, &j, &l}; 
    vector <Arc*> v4 = {&k, &i, &g, &h}; 

    Trail f1(v1), f2(v2), f3(v3), f4(v4); 
    vector <Trail> fs1 = {f1, f2, f3, f4}; 
    Set s1(fs1);

    vector <Arc*> all_arcs = {&a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l};
    Set r = algorithm_for_NEMO( s1, 4);
    r.print();*/
    vector<Arc> arcs = read_arc_file("input_arcs.txt");
    vector<Arc*> list;
    make_list_of_pointers(arcs, &list);
    cout<< "list:       "<<endl<<endl;
    for(int i=0; i<list.size();i++){
        list.at(i)->print();
    }

    vector<Trail> list_of_trails = read_trail_file("input.txt",list); 
    for(int i =0; i<list_of_trails.size(); i++){
        list_of_trails.at(i).print();
    }
}
