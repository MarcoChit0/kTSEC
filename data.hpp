#include <iostream>
#include <vector> 
#include <utility>

using namespace std; 

class Vertex {
    private:
        int number;

    public:
        Vertex(int vertex_number);
        Vertex();
        int getNumber();
};

class Arc {
    private:
        Vertex arc_first_vertex;
        Vertex arc_last_vertex;      
        int number_of_trails; 
        int cover_trail;

    public: 
        Arc(Vertex first_vertex, Vertex last_vertex);
        void addTrail();
        void print();
        int getNumberOfTrails();
};

class Trail{ 
    public: 
        Trail(vector<Arc*> list);
        void print();

    private: 
        vector<Arc*> arcs; 
        int head; 
        int tail; 
        int number_of_trails; 
};

class Set{ 
    public: 
        Set(vector<Trail> new_set);
        void print();

    private: 
        vector<Trail> trails;  
};