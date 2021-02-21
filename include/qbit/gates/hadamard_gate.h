#ifndef HADAMARD_GATE_H
#define HADAMARD_GATE_H

#include "qbit/base/types.h"
#include "qbit/base/qubit.h"
#include "qbit/gates/gate_type.h"

#include <array>

namespace qbit
{

///
/// \brief Froward declare but not implement
/// Here to establish the template parameter. The
/// HadamardGate is template on the output type.
/// This can be either of the two
///
/// std::array<Qubit, 1>
/// QMeasurement
///
///
template<typename OupT> class HadamardGate;

///
/// \brief Forward declare of the measurement
/// type possibly used by the gate
///
struct QMeasurement;

namespace hadamard_detail {

///
/// \brief The hadamard_helper class. Helper class to implement
/// not template parameters for the Hadamard gate
///
class hadamard_helper
{
public:

    ///
    /// \brief input_t. The type of the input to the gate
    ///
    typedef Qubit input_t;

    ///
    /// \brief input_size. The size of the input
    ///
    static constexpr uint_t input_size = 1;

    ///
    /// \brief ouput_size. The size of the ouptu
    ///
    static constexpr uint_t ouput_size = 1;

    ///
    /// \brief as_matrix. Returns the gate matrix representation
    ///
    static DynMat<real_t> as_matrix();

    ///
    /// \brief Default constructor
    ///
    hadamard_helper()=default;

protected:

    ///
    /// \brief input_ Store a copy of the input
    ///
    mutable input_t input_;
};

DynMat<real_t>
hadamard_helper::as_matrix(){

    static DynMat<real_t> mat(2, 2);

    if(mat.rows() == 0){
        mat.resize(2, 2);

        mat(0, 0) = 1.0/std::sqrt(2);
        mat(0, 1) = 1.0/std::sqrt(2);
        mat(1, 0) = 1.0/std::sqrt(2);
        mat(1, 1) = -1.0/std::sqrt(2);
    }

    return mat;
}

}

///
/// \brief The HadamardGate class. Represents the
/// Hadamard gate where the output of the gate is
/// a Qubit.
///
template<>
class HadamardGate<std::array<Qubit, 1>> final: public hadamard_detail::hadamard_helper
{
public:

    ///
    /// \brief input_t. The type of the input to the gate
    ///
    typedef hadamard_detail::hadamard_helper::input_t input_t;

    ///
    /// \brief output_t. The type of the output to the gate
    ///
    typedef std::array<Qubit, 1> output_t;

    ///
    /// \brief type. The type of the gate
    ///
    static constexpr GateType type = GateType::HADAMARD;

    ///
    /// \brief HadamardGate Constructor
    ///
    HadamardGate()=default;

    ///
    /// \brief operator () Apply the action of the gate to the input
    ///
    output_t operator()(const input_t& input)const;

private:

};


///
/// \brief The HadamardGate class. Represents the
/// Hadamard gate where the output of the gate is
/// a Qubit.
///
template<>
class HadamardGate<QMeasurement> final: public hadamard_detail::hadamard_helper
{
public:

    ///
    /// \brief input_t. The type of the input to the gate
    ///
    typedef hadamard_detail::hadamard_helper::input_t input_t;

    ///
    /// \brief output_t. The type of the output to the gate
    ///
    typedef QMeasurement output_t;

    ///
    /// \brief type. The type of the gate
    ///
    static constexpr GateType type = GateType::HADAMADARD_WITH_MES;

    ///
    /// \brief HadamardGate Constructor
    ///
    HadamardGate()=default;

    ///
    /// \brief operator () Apply the action of the gate to the input
    ///
    output_t operator()(const input_t& input)const;

private:

};

}

#endif // HADAMARD_GATE_H
