#include "qbit/base/qubit.h"
#include "qbit/gates/hadamard_gate.h"

#include "qpp.h"

#include <chrono>
#include <thread>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>

namespace example{

using namespace qpp;

ket deutsch_oracle(const ket in){

    // randomly select what
    // the orcale implements
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    auto f0 = distrib(gen);
    auto f1 = distrib(gen);

    ket result = in;
    result[0] *= std::pow(-1, f0);
    result[1] *= std::pow(-1, f1);

    /*auto state_x = in1[0].as_vector();
    state_x[0] *= std::pow(-1, f0);
    state_x[1] *= std::pow(-1, f1);

    std::vector<qbit::Qubit> result(2);

    // bottom qubit remains as is
    result[0] = qbit::Qubit(state_x);
    result[1] = in2[0];*/

    return result;
}

}


int main(){

    using namespace qpp;
    using namespace example;
    ket q0 = States::get_instance().zero();
    ket q1 = States::get_instance().one();

    std::cout << "Hello Quantum++!\nThis is the |0> state:\n";
    std::cout << disp(q0) << '\n';
    std::cout << disp(q1) << '\n';

    // apply hadamard on both qubits
    q0 = apply(q0, gt.H, {0});
    q1 = apply(q1, gt.H, {0});

    std::cout << disp(q0) << '\n';
    std::cout << disp(q1) << '\n';

    q0 = deutsch_oracle(q0);
    //q0 = apply(q0, gt.H, {0});
    auto measured = measure(q0, gt.H, {0});

    std::cout << ">> Measurement result: " << std::get<RES>(measured) << '\n';
    std::cout << ">> Probabilities: ";
    std::cout << disp(std::get<PROB>(measured), ", ") << '\n';
    std::cout << ">> Resulting states:\n";
    for (auto&& it : std::get<ST>(measured))
        std::cout << disp(it) << "\n\n";


    // the two qubit registers
    /*qbit::DynVec<qbit::real_t> state(2, 0.0);
    state[0] = 1.0;

    qbit::Qubit q0(state);
    std::cout<<q0<<std::endl;

    state[0] = 0.0;
    state[1] = 1.0;

    qbit::Qubit q1(state);
    std::cout<<q1<<std::endl;

    qbit::gates::HGate h0(q0);
    auto out_h0 = h0();

    qbit::gates::HGate h1(q1);


    auto out_h1 = h1();

    auto oracle_out = example::deutsch_oracle(out_h0, out_h1);

    qbit::gates::HGate h2(oracle_out[0]);
    auto out_h2 = h2();

    std::cout<<out_h2[0]<<std::endl;
    std::cout<<"Amplitudes squared: "<<out_h2[0].get_amplitudes_sqr()<<std::endl;*/

    return 0;
}
