#include "data.hpp"

void arc::CreateArc(int s, int d){
    edge.first  =   s; 
    edge.second =   d; 
    numberOfTrails = 0; 
    coveredBy = 0;
} 

void arc::ChangeCover( int c){
    coveredBy = c;
}

void arc::AddTrail(){
    numberOfTrails = numberOfTrails + 1;
}

int arc::InformNumberOfTrails(){
    return numberOfTrails; 
};

void arc::PrintArc(){
    std::cout << "---------------------"<<std::endl;
    std::cout << "arc: "<<  std::endl; 
    std::cout << "   ( "<< edge.first << " ,  " << edge.second << " )"<<std::endl; 
    std::cout << "#trails: "<< numberOfTrails << std::endl;
    std::cout << "covered by: "<< coveredBy << std::endl; 
    std::cout << "---------------------"<<std::endl;
}

void trail::CreateTrail(std::vector <arc> new_trail){
    t = new_trail; 
    head = 0; 
    if(!new_trail.empty()){
        tail = new_trail.size() - 1; 
    } 
    else tail = 0; 
    numberOfTrails = 0; 
    for( int i = 0; i< new_trail.size(); i++){
        numberOfTrails = new_trail.at(i).InformNumberOfTrails(); 
    }
    size = new_trail.size(); 
}

void trail::ChangeHead( int new_head){
    head = new_head; 
}

void trail::ChangeTail( int new_tail){
    tail = new_tail; 
}

void trail::PrintTrail(){
    for(int i = 0; i< t.size(); i++){
        std::cout << std::endl<< "i = "<<i << std::endl;
        t.at(i).PrintArc();
    }
    std::cout << std::endl << "size= "<< size<<std::endl;
}

int trail::return_size(){
    return size;
}

int trail::Return_numberOfTrails(){
    return numberOfTrails; 
}

void set::CreateSet(std::vector <trail> new_setOfTrails){
    trails = new_setOfTrails; 
    for(int i = 0; i < new_setOfTrails.size(); i++){
        size.at(i) = trails.at(i).return_size(); 
        numberOfTrails.at(i)= trails.at(i).Return_numberOfTrails(); 
    }
}

void set::AddTrail(trail new_trail){
    trails.push_back(new_trail); 
    size.push_back(new_trail.return_size());
    numberOfTrails.push_back(new_trail.Return_numberOfTrails()); 
}

void set::PrintSet(){
    for(int i = 0; i< trails.size(); i++){
        std::cout<<"-------------------------"<<std::endl<<std::endl;
        std::cout << std::endl<< "TRAIL NUMBER: "<<i << std::endl;
        trails.at(i).PrintTrail(); 
        std::cout<<std::endl<<"-------------------------"<<std::endl;
    }
}