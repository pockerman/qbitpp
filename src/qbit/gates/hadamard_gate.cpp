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

HadamardGate<std::array<Qubit, 1>>::output_t
HadamardGate<std::array<Qubit, 1>>::operator()(const input_t& input)const {

    HadamardGate<std::array<Qubit, 1>>::output_t out;
    auto mat = HadamardGate<std::array<Qubit, 1>>::as_matrix();
    DynVec<real_t> tmp = mat*input.as_vector();

    State<2> s;
    s[0] = tmp[0];
    s[1] = tmp[1];
    out[0] =  s;

    this->input_ = input;
    return out;
}


HadamardGate<QMeasurement>::output_t
HadamardGate<QMeasurement>::operator()(const input_t& input)const {

    HadamardGate<std::array<Qubit, 1>>::output_t out;
    auto mat = HadamardGate<std::array<Qubit, 1>>::as_matrix();
    DynVec<real_t> tmp = mat*input.as_vector();

    State<2> s;
    s[0] = tmp[0];
    s[1] = tmp[1];
    out[0] =  s;
    return QMeasurement();
}


} //qbit
