#include "qbit/base/types.h"
#include "qbit/base/qubit.h"
#include "qbit/gates/hadamard_gate.h"


#include <vector>
#include <iostream>

namespace  {

    using qbit::uint_t;
    using qbit::real_t;
    using qbit::HGate;
    using qbit::Qubit;
    using qbit::DynVec;

}

int main(){

    // prepare the qubit using the
    // Hadamard gate

    DynVec<real_t> state(2, 0.0);
    state[0] = 1.0;

    Qubit q1(state);
    std::cout<<q1<<std::endl;

    HGate gate(q1);

    // let's compute the transformation
    auto q2 = gate();
    std::cout<<q2[0]<<std::endl;
    return 0;
}
