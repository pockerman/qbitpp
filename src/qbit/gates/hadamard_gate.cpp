#include "qbit/base/config.h"
#include "qbit/base/qubit.h"

#include "qbit/gates/hadamard_gate.h"
#include "qbit/gates/q_measurement.h"

#include <cmath>

#ifdef QBIT_DEBUG
#include <stdexcept>
#endif

namespace qbit
{

namespace hadamard_detail{

DynMat<real_t>
hadamard_helper::as_matrix(){

    static DynMat<real_t> mat;

    if(mat.rows() == 0){
        mat.resize(2, 2);

        mat(0, 0) = 1.0/std::sqrt(2);
        mat(0, 1) = 1.0/std::sqrt(2);
        mat(1, 0) = 1.0/std::sqrt(2);
        mat(1, 1) = -1.0/std::sqrt(2);
    }

    return mat;
}

hadamard_helper::hadamard_helper(const input_t& input)
    :
      input_(input)
{}

}

HadamardGate<std::vector<Qubit>>::HadamardGate(const input_t& input)
    :
    hadamard_helper(input),
    GateBase()
{}

HadamardGate<std::vector<Qubit>>::output_t
HadamardGate<std::vector<Qubit>>::operator()()const {

    HadamardGate<std::vector<Qubit>>::output_t out(1);
    auto mat = HadamardGate<std::vector<Qubit>>::as_matrix();
    DynVec<real_t> tmp = mat*this->input_.as_vector();

    DynVec<real_t> s(2, 0.0);
    s[0] = tmp[0];
    s[1] = tmp[1];
    out[0] =  s;

    return out;
}

Qubit
HadamardGate<std::vector<Qubit>>::evaluate(const Qubit& input)const {

    auto mat = HadamardGate<std::vector<Qubit>>::as_matrix();
    DynVec<real_t> tmp = mat*input.as_vector();
    return Qubit(tmp);
}


HadamardGate<QMeasurement>::output_t
HadamardGate<QMeasurement>::operator()(const input_t& input)const {

    HadamardGate<std::vector<Qubit>>::output_t out;
    auto mat = HadamardGate<std::vector<Qubit>>::as_matrix();
    DynVec<real_t> tmp = mat*input.as_vector();

    DynVec<real_t> s(2, 0.0);
    s[0] = tmp[0];
    s[1] = tmp[1];
    out[0] =  s;
    return QMeasurement();
}




} //qbit
