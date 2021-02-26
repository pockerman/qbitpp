#include "qbit/base/qubit.h"
#include "qbit/circuits/quantum_circuit.h"

#include <chrono>
#include <thread>
#include <vector>
#include <iostream>



int main(){


    qbit::QCircuit circuit;

    qbit::DynVec<qbit::real_t> state(2, 0.0);
    state[0] = 1.0;
    circuit.add_hadamard_gate(qbit::Qubit(state));
    circuit.execute();

    return 0;
}
