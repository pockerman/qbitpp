#ifndef OPERATION_BASE_H
#define OPERATION_BASE_H

#include "qbit/gates/gate_base.h"

namespace qbit{
namespace circuits{
class QCircuit;
}

namespace gates{

///
/// \brief The OperationBase class. Base class
/// for modeling quantum oracles
///
class OperationBase
{

public:

    ///
    /// \brief output_t. The type of the output to the gate
    ///
    typedef std::vector<Qubit> output_t;

    ///
    /// \brief ~GateBase Destructor
    ///
    virtual ~OperationBase(){}

    ///
    /// \brief operator () Apply the action of the operation to the input
    ///
    virtual output_t operator()()const=0;

    ///
    /// \brief set_input. Set the input that the operation
    /// will do work on
    ///
    virtual void set_input(const circuits::QCircuit& circuit)=0;


protected:

    ///
    /// \brief OperationBase. Constructor
    ///
    OperationBase()=default;

};

}
}

#endif // OPERATION_BASE_H
