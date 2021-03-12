#include "qbit/circuits/circuit_graph.h"
#include "qbit/gates/operation_base.h"

#include <stdexcept>

namespace qbit{
namespace circuits {

SerialGraph::SerialGraph(uint_t nvs)
    :
      g_(nvs)
{
    set_up_vertex_ids_();
}

SerialGraph::vertex_t&
SerialGraph::set_vertex_data(uint_t vid, const vertex_data_t& operation){

    if( vid >= n_vertices()){
        std::logic_error("Invalid vertex index");
    }

    auto a = boost::vertex(vid, g_);
    auto& vertex = g_[a];

    // set the operation
    vertex.operation = operation;
    return vertex;
}


void
SerialGraph::set_up_vertex_ids_(){

    for(uint_t vid=0; vid < n_vertices(); ++vid){
        auto a = boost::vertex(vid, g_);
        auto& vertex = g_[a];
        vertex.id = vid;
    }

}


SerialGraph::SerialGraphNode::SerialGraphNode()
    :
      operation(),
      id()
{}


SerialGraph::SerialGraphNode::SerialGraphNode(const vertex_data_t& data)
    :
      operation(data),
      id()
{}


SerialGraph::SerialGraphNode::SerialGraphNode(vertex_data_t&& data)
    :
      operation(data),
      id()
{}


SerialGraph::SerialGraphNode::SerialGraphNode(const SerialGraphNode& o)
    :
      operation(o.operation),
      id(o.id)
{}


SerialGraph::SerialGraphNode&
SerialGraph::SerialGraphNode::operator=(const SerialGraph::SerialGraphNode& o){

    if(this == &o){
        return *this;
    }

    operation = o.operation;
    id = o.id;
    return *this;
}




}

}
