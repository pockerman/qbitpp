#include "qbit/base/qubit.h"
#include "qbit/circuits/quantum_circuit.h"

#include <chrono>
#include <thread>
#include <vector>
#include <iostream>



int main(){

    // the circuit to use
    //qbit::circuits::QCircuit circuit(2);

    //qbit::DynVec<qbit::real_t> state(2, 0.0);
    //state[0] = 1.0;

    // apply the hadamard operation to
    // qubit 0
    //circuit.add_hadamard_gate(0);

    // apply the hadamard gate to qubit 1
    //circuit.add_hadamard_gate(1);

    // add the oracle
    //circuit.add_operation();

    // add the measurement
    //circuit.add_measurement();

    // execute the circuit
    /*auto out = circuit();

    for(auto item:out){
        std::cout<<item<<std::endl;
    }*/

    return 0;
}
