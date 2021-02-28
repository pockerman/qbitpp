#include "qbit/circuits/quantum_circuit.h"
#include "qbit/gates/hadamard_gate.h"
#include "qbit/gates/q_measurement.h"

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

QCircuit::output_t
QCircuit::operator()()const{

    GateBase::output_t gate_out;

    for(auto& gate:gates_){
        gate_out = gate->operator()();
    }

    QMeasurement measurement(gate_out);
    ciruit_output_ = measurement();
    return ciruit_output_;
}

}
