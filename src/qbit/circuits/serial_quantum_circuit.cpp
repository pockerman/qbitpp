#include "qbit/circuits/serial_circuit.h"

namespace qbit{
namespace circuits{

SerialCircuit::SerialCircuit()
    :
      QCircuit(),
      circuit_graph_()
{}


SerialCircuit::SerialCircuit(uint_t nqubits)
    :
      QCircuit(nqubits),
      circuit_graph_()
{}


void
SerialCircuit::add_operation(gates::OperationBase* operation_ptr){

}

}
}
