#include "Vertex.hpp"

Vertex::Vertex(int Vertex_number) {
    this->number = Vertex_number;
}

Vertex::Vertex() {
    this->number = -1;
}

int Vertex::getNumber() {
    return this->number;
}