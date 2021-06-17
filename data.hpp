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
        int coveredBy(); 
        void changeCover(int new_cover); 
};

class Trail{ 
    public: 
        Trail(vector<Arc*> list);
        void print();
        int size(); 
        int getHead();
        int getTail(); 
        int getNumberOfTrails(); 
        int coveredBy(int index); 
        void addTail(); 

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
        void sort(); 
        int  size(); 
        int  getTrailSize(int index); 
        int  getTrailTail(int index); 
        int  getTrailHead(int index); 
        int  coveredBy(int index_trail, int index_arc); 
        void addTail(int index); 

    private: 
        vector<Trail> trails;  
};

class Graph{ 
    public:
        Graph(vector <Arc*> arcs, vector <Vertex*> vertex);
        void print(); 
    private: 
        vector <vector<Arc*>> arcs; 
        vector <Vertex*> vertex; 
}; 

Set algorithm_for_NEMO(vector <Arc *> arcs, Set trails, int capacity);
