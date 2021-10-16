#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Arc.hpp"
#include <vector>
#include <algorithm>
#include <list>
#include <utility>

#define NEW_VERTEX -1

using namespace std;

bool CompareArcs(Arc* a1, Arc* a2);
bool CompareVertex(Vertex v1, Vertex v2);

 class BFSNode
 {
    private: 
        Vertex vertex; 
        Vertex father; 
        int fatherIndex;
        int vertexIndex;
    public:
        BFSNode(){
            this->vertexIndex = -1;
            this->fatherIndex = -1;
            this->vertex = Vertex();
            this->father = Vertex();
        }
        BFSNode(Vertex father, int fatherIndex, Vertex vertex, int vertexIndex){
            this->father = father;
            this->fatherIndex = fatherIndex;
            this->vertex = vertex;
            this->vertexIndex = vertexIndex;
        }
        Vertex GetFather(){
            return this->father;
        }
        Vertex GetVertex(){
            return this->vertex;
        }
        void SetVertex(Vertex v){
            this->vertex = v;
        }
        int GetFatherIndex(){
            return this->fatherIndex;
        }
        int GetVertexIndex(){
            return this->fatherIndex;
        }
        void Print(){
            cout << "father: "<<father.GetNumber()<<" - index: "<<fatherIndex;
            cout << "   //  vertex: "<<vertex.GetNumber()<<" - index: "<<vertexIndex<<endl;
        }
 };

class BFSNodeList
{
    private: 
        vector<BFSNode> nodeList;
    public:
        BFSNodeList(){
            nodeList = {};
        }
        void AddNode(BFSNode node){
            nodeList.push_back(node);
        }
        vector<BFSNode> GetChildrenByParent(BFSNode parent){
            vector<BFSNode> returnList;
            for(int i=0; i<this->nodeList.size(); i++){
                if(this->nodeList.at(i).GetFather().GetNumber() == parent.GetVertex().GetNumber()){
                    returnList.push_back(this->nodeList.at(i));
                }
            }
            return returnList;
        }     
        vector<BFSNode> GetNodeList(){
            return this->nodeList;
        }
    };

class Graph{
    private: 
        vector<AdjacencyListUnit> AdjacencyList;
    public:
        Graph(){
            this->AdjacencyList = {};
        }
        Graph(vector<AdjacencyListUnit> adjacencyList){
            this->AdjacencyList = adjacencyList;
        }
        Arc* GetAdjacencyListUnitBy(Vertex source, Vertex destiny){
            for(int i=0; i<this->AdjacencyList.size(); i++){
                if(source.GetNumber() == this->AdjacencyList.at(i).GetVertex().GetNumber()){
                    for(int j=0; j< this->AdjacencyList.at(i).GetArcs().size(); j++){
                        if(destiny.GetNumber() == this->AdjacencyList.at(i).GetArcs().at(j)->GetDestiny().GetNumber()){
                            return this->AdjacencyList.at(i).GetArcs().at(j);
                        }
                    }
                }
            }
            return nullptr;
        }
        AdjacencyListUnit GetAdjacencyListUnitAt(int index){
            return this->AdjacencyList.at(index);
        }
        int GetIndexFromVertex(Vertex v){
            bool found = false; 
            int vertexIndex = -1;
            for(int i=0; i< this->AdjacencyList.size() && !found; i++){
                if(v.GetNumber() == this->AdjacencyList.at(i).GetVertex().GetNumber()){
                    found = true;
                    vertexIndex = i;
                }
            }
            return vertexIndex;
        }
        void FromArcs(vector<Arc*> arcs){
            if(arcs.size() >0){
                sort(arcs.begin(), arcs.end(), CompareArcs);

                vector <AdjacencyListUnit> adj_list = {}; 
                AdjacencyListUnit adj_list_unit; 
                Vertex previous = arcs.at(0)->GetSource();
                Vertex current; 
                vector<Arc*> aux = arcs; 
                for(int i =0; i< aux.size(); i++){
                    current = aux.at(i)->GetSource(); 
                    if(current.GetNumber() == previous.GetNumber()){
                        adj_list_unit.AddArc(aux.at(i));
                    }
                    else{
                        adj_list_unit.SetVertex(previous);  // adiciona vertex a unidade de lista de adj
                        adj_list.push_back(adj_list_unit);  // adiciona unidade de lista de adj a lista de adj 
                        previous = current;                 // o atual vira o anterior
                        adj_list_unit.Clear();              // limpar a unidade para começar a adicionar novos vértices
                        adj_list_unit.AddArc(aux.at(i));    // cria uma nova unidade de lista de adj para adicionar o vértice atual (que é diferente do anterior)
                    }
                }
                // caso tenha saído antes de adicionar a unidade de lista de adj na lista de adj
                if(current.GetNumber() == previous.GetNumber()){
                    adj_list_unit.SetVertex(previous);
                    adj_list.push_back(adj_list_unit);                 
                }
                this->AdjacencyList = adj_list;                
            }
            else{
                cout << "Graph -- FromArcs -- error -- invalid input"<<endl;
                exit(EXIT_FAILURE); 
            }
        }
        vector<AdjacencyListUnit> GetAdjacencyList(){
            return this->AdjacencyList;
        }
        void Print(){
            for(int i =0; i< this->AdjacencyList.size(); i++){
                this->AdjacencyList.at(i).Print();
            }
        }
        
    BFSNodeList BFS(Vertex source);
};
#endif