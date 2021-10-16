#include "data.hpp"
#include "Graph.hpp"
#include <stdlib.h>
#include <time.h> 

int main(){
    /*
    vector<Arc*> arcs = ReadArcFile("input_arcs.txt");
    vector<Trail> trails = ReadTrailFile("input_trail.txt", arcs);
    Set my_set(trails);
    my_set = AlgorithmForNEMO(my_set, 4);
    WriteTrailFile("output_trail.txt",my_set);    
    */
    
    /*
    Arc a1 =Arc(0, 1); 
    Arc a2 =Arc(0, 2);
    Arc a3 =Arc(1, 2);
    Arc a4 =Arc(2, 0);
    Arc a5 =Arc(2, 3);
    Arc a6 =Arc(3, 3);

    vector<Arc*> list = {&a1, &a2, &a3, &a4, &a5, &a6};
    cout << "Graph" << endl<<endl;
    Graph g;
    g.FromArcs(list);
    g.Print();
    cout << "BFS" << endl<<endl;
    BFSNodeList hierarchy = g.BFS(2); 
    for(int i =0; i< hierarchy.GetNodeList().size(); i++){
        hierarchy.GetNodeList().at(i).Print();
        cout << endl;
    }
    cout << "Random Trail 1:" << endl<<endl;
    Trail r1 = GenerateRandomTrail(g);
    r1.Print();
    cout << "Random Trail 2:" << endl<<endl;
    Trail r2 = GenerateRandomTrail(g);
    r2.Print();
    */
    cout << "READ LIST OF ARCS FROM ARCS FILES" << endl; // DEBUG
    vector <Arc*> arcs = ReadArcFile("input_arcs.txt");
    for(int i=0; i<arcs.size();i++){
        arcs.at(i)->Print();
    }
    cout << "RANDOM TRAILS CREATION" << endl; // DEBUG
    CreateRandomTrailsFile("trails_a_lof_of_then.txt", arcs, 50000);
    cout << "READ LIST OF TRAILS FROM RANDOM TRAILS FILE" << endl; // DEBUG
    vector<Trail> trails = ReadTrailFile("trails_a_lof_of_then.txt", arcs);
    cout << "CREATE A SET BASED ON LIST OF TRAILS" << endl; // DEBUG
    Set mySetOfTrail = Set(trails);
    mySetOfTrail.Print();
    cout << "RUN  ALGO FOR NEMO" <<endl; // DEBUG
    Set result = AlgorithmForNEMO(mySetOfTrail,4);
    cout<< "WRITE RESULT IN OUTPUT FILE"<<endl; // DEBUG
    WriteTrailFile("trails_a_lof_of_then_output.txt",result);
    cout << "THAT'S ALL FOLKS" << endl; // DEBUG
}
