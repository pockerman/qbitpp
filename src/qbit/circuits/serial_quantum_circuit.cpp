#include "qbit/circuits/serial_quantum_circuit.h"

namespace qbit{
namespace circuits{

SerialQCircuit::SerialQCircuit()
    :
      QCircuit(),
      circuit_graph_()
{}


SerialQCircuit::SerialQCircuit(uint_t nqubits)
    :
      QCircuit(nqubits),
      circuit_graph_()
{}


void
SerialQCircuit::add_operation(gates::OperationBase* operation_ptr){

}

}
}
