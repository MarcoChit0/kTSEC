
#include <iostream>
#include <vector> 
#include <utility>

using namespace std; 

class arc{
    public: 
        // create a new arc given a source a.first and a destiny a.second vertices
        void create( pair <int, int> a){
            edge.first = a.first; 
            edge.second = a.second; 
            trails = 0; 
            coveredBy = 0;
        }

        void addTrail(arc &a){
            a.trails ++; 
        }

        void print(){
                cout <<"arc     :   "<<edge.first << "  ->  "<<edge.second << endl; 
                cout <<"#trails :   "<<trails<<endl;
                cout <<"covered :   "<<coveredBy<< endl<<endl;     
        }

        private:    
        // source   =   edge.first 
        // destiny  =   edge.second 
        pair <int, int> edge;      
        // indicates how many trails covers this arc
        int trails; 
        // indicates what trail covers this arc
        int coveredBy; 

        friend class trail; 
};


class trail{ 
    public: 
        trail create(vector <arc> &list){
            trail aux; 
            aux.numberOfTrails=0;
            for(int i=0; i<list.size(); i++){list.at(i).addTrail();aux.numberOfTrails+= list.at(i).trails;}
            aux.head = 0; 
            if(!list.empty()){aux.tail = list.size() - 1; } else{aux.tail = -1; }
            aux.t = list;
            return aux;
        }
        void print(){
            for(int i=0; i<t.size(); i++){  
                cout <<"trail   :   "<<i<<endl; t.at(i).print();}
        } 
    private: 
        vector <arc> t; 
        int head; 
        int tail; 
        int numberOfTrails; 

        friend class set; 
};



class set{ 
    public: 
        set create(vector <trail> &new_set){ 
            set aux; 
            aux.s = new_set;
            return aux;
        }
        void print(){
            for(int i=0; i<s.size(); i++){
                cout << "set    :   "<<i<<endl; s.at(i).print(); 
            }
        }
    private: 
        vector <trail> s;  
};
