#ifndef GATE_BASE_H
#define GATE_BASE_H

#include "qbit/base/types.h"

#include <vector>

namespace qbit{


///
/// Forward declaration
///
class Qubit;

namespace gates{

///
/// \brief The GeteBase class. Base class for deriving
/// quantum gates
///
class GateBase
{
public:

    ///
    /// \brief input_t. The type of the input to the gate
    ///
    typedef std::vector<Qubit> input_t;

    ///
    /// \brief output_t. The type of the output to the gate
    ///
    typedef std::vector<Qubit> output_t;

    ///
    /// \brief ~GateBase Destructor
    ///
    virtual ~GateBase(){}

    ///
    /// \brief operator () Apply the action of the gate to the input
    ///
    virtual output_t operator()()const=0;

protected:


    ///
    /// \brief Constructor
    ///
    GateBase()=default;

};

}
}
#endif // GATE_BASE_H
