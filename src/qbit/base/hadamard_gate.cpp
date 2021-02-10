#include "qbit/base/config.h"
#include "qbit/base/hadamard_gate.h"
#include "qbit/base/qubit.h"

#include <cmath>

#ifdef QBIT_DEBUG
#include <stdexcept>
#endif

namespace qbit
{

HadamardGate::HadamardGate()
    :
      GateBase(),
      matrix_()
{}


const DynMat<real_t>&
HadamardGate::as_matrix()const{

    if(matrix_.rows() == 0){
        matrix_.resize(2, 2);

        matrix_(0, 0) = 1.0/std::sqrt(2);
        matrix_(0, 1) = 1.0/std::sqrt(2);
        matrix_(1, 0) = 1.0/std::sqrt(2);
        matrix_(1, 1) = -1.0/std::sqrt(2);
    }


    return matrix_;
}

///
/// \brief operator () Apply the action of the gate to the input
///
HadamardGate::output_t
HadamardGate::operator()(const input_t& input)const {

#ifdef QBIT_DEBUG
    if(input.size() != 1){
        raise std::logic_error("Hadamard gate can only accept one "
                               "input but it received "+std::to_string(input.size()));
    }
#endif

    output_t out(1);
    auto& mat = as_matrix();
    DynVec<real_t> tmp = mat*input[0].as_vector();

    State<2> s;
    s[0] = tmp[0];
    s[1] = tmp[1];
    out[0] =  s;
    return out;
}
}
