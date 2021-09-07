#ifndef VERTEX_HPP
#define VERTEX_HPP

class Vertex {
    private:
        int Number;

    public:
        Vertex();
        /*
            name        :   Vertex
            input       :   vertex_number
            function    :   build a Vertex object
        */
        Vertex(int vertex_number);
        /*
            name        :   GetNumber
            output      :   this.Number
        */        
        int GetNumber();
};


#endif