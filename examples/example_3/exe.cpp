#include "qbit/base/qubit.h"
#include "qbit/gates/hadamard_gate.h"

#include <chrono>
#include <thread>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>

namespace example{

template<typename InTp>
qbit::Qubit deutsch_oracle(const InTp& in1, const InTp& in2){

    // randomly select what
    // the orcale implements
    /*std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);
    auto f = distrib(gen);

    qbit::DynVec<qbit::real_t> state(2, 0.0);
    auto coeff = std::sqrt(1.0/std::pow(2,2));
    for(qbit::uint_t q=0; q<2; ++q){

    }*/

    return qbit::Qubit(state);
}

}


int main(){

    // the two qubit registers
    qbit::DynVec<qbit::real_t> state(2, 0.0);
    state[0] = 1.0;

    qbit::Qubit q0(state);
    std::cout<<q0<<std::endl;

    state[0] = 0.0;
    state[1] = 1.0;

    qbit::Qubit q1(state);
    std::cout<<q1<<std::endl;

    qbit::gates::HGate h0(q0);
    qbit::gates::HGate h1(q1);

    auto out_h0 = h0();
    auto out_h1 = h1();

    auto oracle_out = example::deutsch_oracle(out_h0, out_h1);

    qbit::gates::HGate h2(oracle_out);
    auto out_h2 = h2();

    return 0;
}
