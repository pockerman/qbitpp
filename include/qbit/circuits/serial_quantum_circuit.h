#ifndef SERIAL_QUANTUM_CIRCUIT_H
#define SERIAL_QUANTUM_CIRCUIT_H

#include "qbit/circuits/quantum_circuit.h"
#include "qbit/circuits/circuit_graph.h"

namespace qbit {
namespace circuits {

class SerialQCircuit: public QCircuit
{
public:

    ///
    /// \brief graph_t The type of the graph used to
    /// represent the operations of the circuit
    ///
    typedef SerialGraph graph_t;

    ///
    /// \brief output_t. The type of the output of the circuit
    ///
    typedef QCircuit::output_t output_t;

    ///
    /// \brief QCircuit Constructor
    ///
    SerialQCircuit();

    ///
    /// \brief QCircuit. Build a circuit with nqubits
    ///
    SerialQCircuit(uint_t nqubits);

    ///
    /// \brief add_operation. Add an operation
    /// applied on some of the qubits of the circuit
    ///
    virtual void add_operation(gates::OperationBase* operation_ptr);

private:

    ///
    /// \brief circuit_graph_ The graph representing the circuit
    ///
    graph_t circuit_graph_;


};


}

}

#endif // SERIAL_CIRCUIT_H
