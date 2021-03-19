#ifndef QUANTUM_CIRCUIT_H
#define QUANTUM_CIRCUIT_H

#include "qbit/base/types.h"
#include "qbit/gates/gate_base.h"
#include "qbit/gates/gate_type.h"
#include "qbit/circuits/circuit_graph.h"

#include <vector>
#include <memory>

namespace qbit{

///
/// \brief Forward declaration
///
class Qubit;

namespace gates {

class OperationBase;

}

namespace circuits {

///
/// Forward declarations
///
class SerialCircuitGraph;

///
/// \brief The QCircuit class. The QCircuit class
/// represents a program to be executed on some
/// quantum hardware. It is a network of gates
///
class QCircuit
{
public:

    ///
    /// \brief output_t. The type of the output of the circuit
    ///
    typedef std::vector<real_t> output_t;

    ///
    /// \brief QCircuit Constructor
    ///
    QCircuit();

    ///
    /// \brief QCircuit. Build a circuit with nqubits
    ///
    QCircuit(uint_t nqubits);

    ///
    /// \brief ~QCircuit destructor
    ///
    virtual ~QCircuit();

    ///
    /// \brief add_hadamard_gate Add a Hadamard gate acting
    /// on the qubit
    ///
    virtual void add_hadamard_gate(const Qubit& qubit);

    ///
    /// \brief add_operation. Add an operation
    /// applied on some of the qubits of the circuit
    ///
    virtual void add_operation(gates::OperationBase* operation_ptr);

    ///
    /// \brief execute Execute the gates of the circuit
    ///
    virtual output_t operator()()const;

    ///
    /// \brief get_qubit. Returns a copy of the
    /// i-th qubit
    ///
    Qubit get_qubit(uint_t i)const;

protected:

    ///
    /// \brief gates_. The gates of the circuit
    ///
    std::vector<std::shared_ptr<gates::GateBase>> gates_;

    ///
    /// \brief qubits_. The qubits used by the circuit
    ///
    std::vector<Qubit> qubits_;

    ///
    /// \brief operations_. The operations to apply on the
    /// qubits of the circuit
    ///
    std::vector<std::shared_ptr<gates::OperationBase>> operations_;

    ///
    /// \brief ciruit_output_. The output of the circuit
    ///
    mutable output_t ciruit_output_;

};

}
}

#endif // QUANTUM_CIRCUIT_H
