#include "graph.h"

#include <lemon/smart_graph.h>

namespace my {

class Graph::Impl {

public:
    lemon::SmartGraph m_graph;
    virtual ~Impl(){

    }

};


Graph::Graph() :
    this_(new Impl)
{

}

Graph::~Graph()
{

}

struct Graph::Node::Impl {
    lemon::SmartGraph::Node n;
};

struct Graph::Edge::Impl {
    lemon::SmartGraph::Edge e;
};

struct Graph::NodeIterator::Impl {
public:
    lemon::SmartGraph::NodeIt it;
};


Graph::Node Graph::addNode()
{
    return Graph::Node{Graph::Node::Impl{this_->m_graph.addNode()}};
}

Graph::Edge Graph::addEdge(const Node &u, const Node &v)
{
    auto edge = this_->m_graph.addEdge(u.this_->n, v.this_->n);
    return Graph::Edge(Graph::Edge::Impl{edge});
}

const Graph::NodeIterator Graph::begin() const
{
    Graph::NodeIterator it{Graph::NodeIterator::Impl{lemon::SmartGraph::NodeIt(this_->m_graph)}};
    return it;
}

const Graph::NodeIterator Graph::end() const
{
    return Graph::NodeIterator{};
}

std::size_t Graph::degree() const
{
    return lemon::countNodes(this_->m_graph);
}


Graph::NodeIterator::NodeIterator() :
    this_(new Impl)
{
    this_->it = lemon::INVALID;
}

Graph::NodeIterator::NodeIterator(const Graph::NodeIterator &it)  :
    this_(new Impl)
{
    this_->it = it.this_->it;
}

Graph::NodeIterator::~NodeIterator()
{

}

Graph::NodeIterator &Graph::NodeIterator::operator=(const NodeIterator & it)
{
    this_->it = it.this_->it;
}

Graph::NodeIterator &Graph::NodeIterator::operator++()
{
    ++this_->it;
}

Graph::Node Graph::NodeIterator::operator*() const
{
    Graph::Node::Impl impl{static_cast<lemon::SmartGraph::Node>(this_->it)};
    return Graph::Node{impl};
}

bool Graph::NodeIterator::operator !=(const Graph::NodeIterator &it) const
{
    return this_->it != it.this_->it;
}

Graph::NodeIterator::NodeIterator(const Graph::NodeIterator::Impl &impl) :
    this_(new Impl)
{
    this_->it = impl.it;
}

void swap(Graph::NodeIterator &lhs, Graph::NodeIterator &rhs)
{
    lemon::SmartGraph::NodeIt aux = lhs.this_->it;
    lhs.this_->it = rhs.this_->it;
    rhs.this_->it = aux;
}

Graph::Node::Node() :
    this_(new Impl)
{

}

Graph::Node::Node(const Graph::Node &n) :
    this_(new Impl)
{
    this_->n = n.this_->n;
}

Graph::Node::~Node()
{

}

Graph::Node::Node(const Graph::Node::Impl &impl) :
    this_(new Impl)
{
    this_->n = impl.n;
}

Graph::Edge::Edge() :
    this_(new Impl)
{

}

Graph::Edge::Edge(const Graph::Edge &e) :
    this_(new Impl)
{
    this_->e = e.this_->e;
}

Graph::Edge::~Edge()
{

}

Graph::Edge::Edge(const Graph::Edge::Impl &impl) :
    this_(new Impl)
{
    this_->e = impl.e;
}

}
