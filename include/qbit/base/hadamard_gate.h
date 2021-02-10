#ifndef HADAMARD_GATE_H
#define HADAMARD_GATE_H

#include "qbit/base/types.h"
#include "qbit/base/gate_base.h"

namespace qbit
{

///
/// \brief The HadamardGate class. Represents the
/// Hadamard gate
///
class HadamardGate final: public GateBase
{
public:

    ///
    /// \brief input_t. The type of the input to the gate
    ///
    typedef GateBase::input_t input_t;

    ///
    /// \brief output_t. The type of the output to the gate
    ///
    typedef GateBase::output_t output_t;

    ///
    /// \brief HadamardGate Constructor
    ///
    HadamardGate();

    ///
    /// \brief as_matrix. Get matrix representation
    /// of the class
    ///
    virtual const DynMat<real_t>& as_matrix()const override final;

    ///
    /// \brief operator () Apply the action of the gate to the input
    ///
    virtual output_t operator()(const input_t& input)const override final;

private:

    ///
    /// \brief matrix_. The matrix representation of the gate
    ///
    mutable DynMat<real_t> matrix_;

};

}

#endif // HADAMARD_GATE_H
