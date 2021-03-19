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

void
SerialGraph::add_edge(uint_t v1, uint_t v2){

    //TODO what happens when v1 and v2 are not valid vertex indices?
    //at the moment we throw an assertion
    if(v1>=n_vertices() || v2 >=n_vertices())
            throw std::logic_error("Invalid vertex index v1/v2: "+
                                    std::to_string(v1)+
                                    "/"+
                                    std::to_string(v2)+
                                    " not in [0,"+
                                    std::to_string(n_vertices())+
                                    ")");

    edge_descriptor_t et;
    bool condition;

    // get the vertices that correspond to the indices
    vertex_descriptor_t a = boost::vertex(v1, g_);
    vertex_descriptor_t b = boost::vertex(v2, g_);
    uint_t idx = n_edges();

    // create an edge
    boost::tie(et, condition) = boost::add_edge(a,b,g_);

}



}

}
