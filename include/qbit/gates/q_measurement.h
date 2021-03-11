#ifndef Q_MEASUREMENT_H
#define Q_MEASUREMENT_H

#include "qbit/gates/gate_base.h"

#include <vector>

namespace qbit{
namespace gates{

///
/// \brief The QMeasurement struct. Models
/// a measurement applied on a Qubit or
/// gate or circuit. For example in a layered
/// QCircuit the output layer consists of QMeasurement
/// units
///
class QMeasurement
{

public:

    ///
    /// \brief input_t. The type of the input to the gate
    ///
    typedef GateBase::input_t input_t;

    ///
    /// \brief output_t. The type of the output of the gate
    ///
    typedef std::vector<real_t> output_t;

    ///
    /// \brief QMeasurement. Constructor
    ///
    QMeasurement()=default;

    ///
    /// \brief QMeasurement. Constructor
    ///
    QMeasurement(const input_t& input);

    ///
    /// \brief operator () Apply the action of the gate to the input
    ///
    output_t operator()()const;

private:


    ///
    /// \brief input_ The input the gate executes on
    /// when operator() is called
    ///
    input_t input_;


};
}

}

#endif // Q_MEASUREMENT_H
