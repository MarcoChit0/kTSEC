#include "data.hpp"

int main(){
    string input = "input.txt"; 
    Set s = Read(input);    
    s.print();
    s = algorithm_for_NEMO(s, 4); 
    s.print();
    string output = "out.txt"; 
    Write(output, s);
}