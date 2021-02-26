#include "qbit/circuits/quantum_circuit.h"
#include "qbit/gates/hadamard_gate.h"

namespace qbit
{
QCircuit::QCircuit()
    :
      gates_()
{}

void
QCircuit::add_hadamard_gate(const Qubit& qubit){
    gates_.push_back(std::make_shared<HGate>(qubit));
}

void
QCircuit::execute(){

    for(auto& gate:gates_){
        auto gate_result = gate->operator()();
    }
}

}
