#ifndef CIRCUIT_GRAPH_H
#define CIRCUIT_GRAPH_H

#include "qbit/base/types.h"
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/undirected_graph.hpp>

#include <vector>
#include <memory>

namespace qbit {
namespace gates{

///
/// Forward declaration
///
class OperationBase;
}


namespace circuits {

///
/// \brief The SerialGraph class. Models
/// the operations to be executed by the QCircuit
///
class SerialGraph
{
public:

    ///
    /// \brief Class that represents the Node of a graph
    ///
    struct SerialGraphNode;

    ///
    /// \brief vertex_data_t The type of the data held on a node
    ///
    typedef std::shared_ptr<gates::OperationBase> vertex_data_t;

    ///
    /// \brief vertex_t The vertex type
    ///
    typedef SerialGraphNode vertex_t;

    ///
    /// \brief edge_t The edge type
    ///
    typedef Null edge_t;

    ///
    /// \brief Class that represents the Node of a graph
    ///
    struct SerialGraphNode
    {

        ///
        /// \brief operation The operation to be applied
        /// by the node
        ///
        vertex_data_t operation;

        ///
        /// \brief id. Id of the node
        ///
        uint_t  id;

        ///
        /// \brief SerialGraphNode
        ///
        SerialGraphNode();

        ///
        /// \brief SerialGraphNode
        ///
        SerialGraphNode(const vertex_data_t& data);

        ///
        /// \brief SerialGraphNode
        ///
        SerialGraphNode(vertex_data_t&& data);

        ///
        /// \brief SerialGraphNode
        ///
        SerialGraphNode(const SerialGraphNode& o);

        ///
        /// \brief operator =
        ///
        SerialGraphNode& operator=(const SerialGraphNode& o);

        ///
        /// \brief operator ==
        ///
        bool operator==(const SerialGraphNode& o)const{return this->id==o.id;}

        ///
        /// \brief operator !=
        ///
        bool operator!=(const SerialGraphNode& o)const{return !(*this==o);}

        ///
        /// \brief parent. The parent of the node
        ///
        SerialGraphNode* parent;

        ///
        /// \brief children The children of the node
        ///
        std::vector<SerialGraphNode*> children;
    };

private:

    ///
    /// \brief graph_type The type of the graph
    ///
    typedef boost::undirected_graph<vertex_t, edge_t> graph_t;

    ///
    /// \brief vertex_descriptor_t The type of the vertex descriptor
    ///
    typedef typename boost::graph_traits<graph_t>::vertex_descriptor vertex_descriptor_t;

    ///
    /// \brief edge_descriptor_t The edge descriptor
    ///
    typedef typename boost::graph_traits<graph_t>::edge_descriptor edge_descriptor_t;

public:

    ///
    /// \brief SerialGraph
    ///
    explicit SerialGraph(uint_t nvs=0);

    ///
    /// \brief set_vertex_data. Set the vertex data for the vertex with the given id
    ///
    vertex_t& set_vertex_data(uint_t vid, const vertex_data_t& data);

    ///
    /// \brief Returns the number of vertices
    ///
    uint_t n_vertices()const{return g_.num_vertices();}

    ///
    /// \brief Clear the graph
    ///
    void clear(){g_.clear();}


private:


    ///
    /// \brief The actual graph
    ///
    graph_t g_;


    ///
    /// \brief set_up_vertex_ids_. Set up the vertex ids
    ///
    void set_up_vertex_ids_();


};

}

}

#endif // CIRCUIT_GRAPH_H
