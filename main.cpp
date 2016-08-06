#include <iostream>

#include "graph.h"
#include <cassert>

int main(int argc, char *argv[])
{
    my::Graph g;
    my::Graph::Node u = g.addNode();
    my::Graph::Node v = g.addNode();
    my::Graph::Edge e = g.addEdge(u, v);

    assert(g.degree() == 2);

    std::cout << "Success!!" << std::endl;

    return 0;
}

