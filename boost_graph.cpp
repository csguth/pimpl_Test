#include "graph.h"

#include <boost/graph/adjacency_list.hpp>

namespace my {

using graph_t = boost::adjacency_list<>;

class Graph::Impl {

public:
    graph_t m_graph;
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
    graph_t::vertex_descriptor n;
};

struct Graph::Edge::Impl {
    graph_t::edge_descriptor e;
};

struct Graph::NodeIterator::Impl {
public:
    boost::graph_traits<graph_t>::vertex_iterator it;
};


Graph::Node Graph::addNode()
{
    return Graph::Node{Graph::Node::Impl{boost::add_vertex(this_->m_graph)}};
}

Graph::Edge Graph::addEdge(const Node &u, const Node &v)
{
    auto edge = boost::add_edge(u.this_->n, v.this_->n, this_->m_graph);
    assert(edge.second);
    return Graph::Edge(Graph::Edge::Impl{edge.first});
}

const Graph::NodeIterator Graph::begin() const
{
    Graph::NodeIterator it{Graph::NodeIterator::Impl{boost::vertices(this_->m_graph).first}};
    return it;
}

const Graph::NodeIterator Graph::end() const
{
    return Graph::NodeIterator{};
}

std::size_t Graph::degree() const
{
    return boost::num_vertices(this_->m_graph);
}


Graph::NodeIterator::NodeIterator() :
    this_(new Impl)
{
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
    Graph::Node::Impl impl{(*this_->it)};
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
    boost::graph_traits<graph_t>::vertex_iterator aux = lhs.this_->it;
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
