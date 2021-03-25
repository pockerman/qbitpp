#include "qbit/base/types.h"
#include "qbit/base/qubit.h"
#include "qbit/gates/hadamard_gate.h"

#include "qpp.h"
#include <vector>
#include <iostream>



int main(){

    using namespace qpp;
    std::cout << "Hello Quantum++!\nThis is the |0> state:\n";
    std::cout << disp(0_ket) << '\n';
}
