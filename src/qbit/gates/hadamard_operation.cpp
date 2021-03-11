#include "qbit/gates/hadamard_operation.h"
#include "qbit/circuits/quantum_circuit.h"
#include "qbit/gates/hadamard_gate.h"

namespace qbit {
namespace gates {

HOperation::HOperation(uint_t qid)
    :
      OperationBase(),
      qid_(qid)
{}

void
HOperation::set_input(const circuits::QCircuit& circuit){
    input_ = circuit.get_qubit(qid_);
}

HOperation::output_t
HOperation::operator()()const{

    HadamardGate<std::vector<Qubit>> gate(input_);
    return gate();
}

}

}
