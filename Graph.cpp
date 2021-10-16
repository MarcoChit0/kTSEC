#include "Graph.hpp"

using namespace std; 

bool CompareArcs(Arc* a1, Arc* a2){
    if(a1->GetSourceValue() > a2->GetSourceValue()){
        return false;
    }
    else{
        if(a1->GetSourceValue() == a2->GetSourceValue()){
            if(a1->GetDestinyValue() >= a2->GetDestinyValue()){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return true;
        }
    }
}

 BFSNodeList Graph::BFS(Vertex source)
{
    // -----------------
    BFSNodeList hierarchy;
    Vertex father; 
    // -----------------

    vector<pair<bool, Vertex>> visited;
    pair<bool, Vertex> temp;
    for(int i = 0; i < this->AdjacencyList.size(); i++){
        temp.first = false;
        temp.second = this->AdjacencyList.at(i).GetVertex();
        visited.push_back(temp);        
    }
    list<Vertex> queue;
    for(int i=0; i<visited.size(); i++){
        if(visited.at(i).second.GetNumber() == source.GetNumber()){
            visited.at(i).first = true;
            // -----------------
            // primeiro vérice não tem pai 
            hierarchy.AddNode(BFSNode(Vertex(),-1,source,i));
            // -----------------
        }
    }

    queue.push_back(source);
    vector<Arc*>::iterator arc;

    while(!queue.empty())
    {
        Vertex popped = queue.front();
        queue.pop_front();
        
        // -----------------
        father = popped;
        // -----------------
        
        int fatherIndex = -1;
        for(int i = 0; (i< visited.size()) && (fatherIndex == -1); i++){
            if(popped.GetNumber() == visited.at(i).second.GetNumber()){
                fatherIndex =  i; 
            }           
        }
        
        if(fatherIndex != -1){
            vector<Vertex> listOfAdjacentVertices = {}; 
            for(int j = 0; j< this->AdjacencyList.at(fatherIndex).GetArcs().size(); j++){
                listOfAdjacentVertices.push_back(this->AdjacencyList.at(fatherIndex).GetArcs().at(j)->GetDestiny());
            }
            for(int k=0; k < visited.size(); k++){
                for(int l=0; l< listOfAdjacentVertices.size(); l++){
                    if(visited.at(k).second.GetNumber() == listOfAdjacentVertices.at(l).GetNumber()){
                        if(visited.at(k).first == false){
                            visited.at(k).first = true;
                            queue.push_back(visited.at(k).second);
                            // -----------------
                            hierarchy.AddNode(BFSNode(popped, fatherIndex, visited.at(k).second, k));
                            // -----------------
                        }
                    }
                }
            }
        }
        else{
            cout << "Graph -- BFS -- Error"<<endl;
            return {};
        }
    }
    return hierarchy;

}
