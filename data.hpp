#include <iostream>
#include <vector> 
#include <utility>

using namespace std; 

#define NO_COVER -1
#define EMPTY_TRAIL 0 

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
        void changeTail(int new_tail);
        void changeHead(int new_head); 
        vector <Arc*> getArcs(); 
        void changeCover(int new_cover, int arc_index); 
        vector <Trail> split(int capacity); 

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
        vector <Arc*> getTrailArcs(int index); 
        Trail getTrail(int index); 
        int  coveredBy(int index_trail, int index_arc); 
        void changeTrailTail(int trail_index, int new_tail); 
        void deleteTrail(int index); 
        void addTrail(Trail t); 
        void changeCover(int new_cover, int arc_index, int trail_index); 
        void changeTrailHead(int trail_index, int new_head); 
        vector <Trail> split(int capacity);
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

// if a is subtrail of b 
//      then return true 
//      else return false
bool isSubtrail(vector <Arc*> a, vector <Arc*> b);