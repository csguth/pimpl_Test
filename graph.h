#ifndef GRAPH_H
#define GRAPH_H

#include <memory>

namespace my {

class Graph
{  
public:

    class Node {
    public:
        friend class Graph;
        Node();
        Node(const Node& n);
        virtual ~Node();
    private:
        struct Impl;
        Node(const Impl& impl);
        std::unique_ptr<Impl> this_;
    };

    class Edge {
    public:
        friend class Graph;
        Edge();
        Edge(const Edge& e);
        virtual ~Edge();
    private:
        struct Impl;
        Edge(const Impl& impl);
        std::unique_ptr<Impl> this_;
    };


    class NodeIterator {
    public:
        friend class Graph;
        NodeIterator();
        NodeIterator(const NodeIterator& it);
        virtual ~NodeIterator();
        NodeIterator& operator=(const NodeIterator&);
        NodeIterator& operator++();
        Node operator*() const;
        friend void swap(NodeIterator& lhs, NodeIterator& rhs);
        bool operator !=(const NodeIterator& it) const;
    private:
        struct Impl;
        NodeIterator(const Impl& impl);
        std::unique_ptr<Impl> this_;
    };


    Graph();
    virtual ~Graph();

    Node addNode();
    Edge addEdge(const Node& u, const Node& v);

    const NodeIterator begin() const;
    const NodeIterator end() const;

    std::size_t degree() const;

private:
    class Impl;
    std::unique_ptr<Impl> this_;

};

}

#endif // GRAPH_H
