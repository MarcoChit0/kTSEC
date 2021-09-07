#include "Vertex.hpp"

Vertex::Vertex(int Vertex_number) {
    this->Number = Vertex_number;
}

int Vertex::GetNumber() {
    return this->Number;
}

Vertex::Vertex()
{
    this->Number = -1;
}