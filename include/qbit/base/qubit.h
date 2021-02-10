#ifndef QUBIT_H
#define QUBIT_H

#include "qbit/base/types.h"

namespace qbit{

///
/// \brief The Qubit class. Class  modeling a qubit
///
class Qubit
{
public:

    ///
    /// \brief Qubit. Constructor initialize the qubit
    /// at the given state
    ///
    Qubit(const State<2>& state);

    ///
    ///\brief Returns the qubit representation as vector
    ///
    DynVec<real_t> as_vector()const;
private:

    ///
    /// \brief state_. The state of the qubit
    ///
    State<2> state_;

    ///
    /// \brief normalize_. Normalize the qubit
    /// so that the square of its coefficients always sum up
    /// to one
    ///
    void normalize_();

};


}

#endif // QUBIT_H
