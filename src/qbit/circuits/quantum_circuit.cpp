#include "qbit/circuits/quantum_circuit.h"
#include "qbit/gates/hadamard_gate.h"
#include "qbit/gates/q_measurement.h"

namespace qbit{
namespace circuits {


QCircuit::QCircuit()
    :
      gates_()
{}

QCircuit::~QCircuit()
{}

void
QCircuit::add_hadamard_gate(const Qubit& qubit){
    gates_.push_back(std::make_shared<gates::HGate>(qubit));
}

Qubit
QCircuit::get_qubit(uint_t i)const{
    return qubits_[i];
}

void
QCircuit::add_operation(gates::OperationBase* operation_ptr){
    operations_.push_back(std::shared_ptr<gates::OperationBase>(operation_ptr));
}

QCircuit::output_t
QCircuit::operator()()const{

    gates::GateBase::output_t gate_out;

    for(auto& gate:gates_){
        gate_out = gate->operator()();
    }

    gates::QMeasurement measurement(gate_out);
    ciruit_output_ = measurement();
    return ciruit_output_;
}

}
}
