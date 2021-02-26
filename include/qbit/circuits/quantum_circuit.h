#ifndef QUANTUM_CIRCUIT_H
#define QUANTUM_CIRCUIT_H

#include "qbit/base/types.h"
#include "qbit/gates/gate_base.h"
#include "qbit/gates/gate_type.h"

#include <vector>
#include <memory>

namespace qbit
{

///
/// \brief Forward declaration
///
class Qubit;

///
/// \brief The QCircuit class. The QCircuit class
/// represents a program to be executed on some
/// quantum hardware. It is a network of gates
///
class QCircuit
{
public:

    ///
    /// \brief QCircuit Constructor
    ///
    QCircuit();

    ///
    /// \brief add_hadamard_gate Add a Hadamard gate acting
    /// on the qubit
    ///
    void add_hadamard_gate(const Qubit& qubit);

    ///
    /// \brief execute Execute the gates of the circuit
    ///
    void execute();

private:

    ///
    /// \brief gates_. The gates of the circuit
    ///
    std::vector<std::shared_ptr<GateBase>> gates_;

};

}

#endif // QUANTUM_CIRCUIT_H
