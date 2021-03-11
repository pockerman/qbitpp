#ifndef HADAMARD_OPERATION_H
#define HADAMARD_OPERATION_H

#include "qbit/gates/operation_base.h"
#include "qbit/base/qubit.h"

namespace qbit {
namespace circuits {
class QCircuit;
}

namespace gates {

class HOperation final: public OperationBase
{
public:

    ///
    /// \brief input_t. The type of the input to the gate
    ///
    typedef qbit::Qubit input_t;

    ///
    /// \brief output_t. The type of the output to the gate
    ///
    typedef OperationBase::output_t output_t;

    ///
    /// \brief HOperation. Constructor
    ///
    HOperation(uint_t qid);

    ///
    /// \brief ~GateBase Destructor
    ///
    ~HOperation(){}

    ///
    /// \brief operator () Apply the action of the operation to the input
    ///
    virtual output_t operator()()const override final;

    ///
    /// \brief set_input. Set the input that the operation
    /// will do work on
    ///
    virtual void set_input(const circuits::QCircuit& circuit)override final;

private:

    ///
    /// \brief qid_. The id of the qubit the
    /// operation is working on
    ///
    uint_t qid_;

    ///
    /// \brief input_
    ///
    input_t input_;
};

}

}

#endif // HADAMARD_OPERATION_H
