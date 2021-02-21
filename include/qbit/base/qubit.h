#ifndef QUBIT_H
#define QUBIT_H

#include "qbit/base/types.h"

#include <ostream>

namespace qbit{

///
/// \brief The Qubit class. Class  modeling a qubit
///
class Qubit
{
public:

    ///
    /// \brief Default constructor
    ///
    Qubit()=default;

    ///
    /// \brief constructor
    ///
    Qubit(uint_t size);

    ///
    /// \brief Qubit. Constructor initialize the qubit
    /// at the given state
    ///
    Qubit(const DynVec<real_t>& state);

    ///
    ///\brief Returns the qubit representation as vector
    ///
    DynVec<real_t> as_vector()const;

    ///
    /// \brief operator = Copy assignment operator
    ///
    Qubit& operator=(const Qubit& other);

    ///
    /// \brief print Helper functions to print the state of
    /// the qubit
    ///
    std::ostream& print(std::ostream& out)const;

    ///
    /// \brief get_probability Returns the probability
    /// that the qubit represents the given array of bits
    ///
    real_t get_probability(DynVec<uint_t> bits)const;

private:

    ///
    /// \brief state_. The state of the qubit
    ///
    DynVec<real_t> state_;

    ///
    /// \brief normalize_. Normalize the qubit
    /// so that the square of its coefficients always sum up
    /// to one
    ///
    void normalize_();

};


inline
std::ostream& operator<<(std::ostream& out, const Qubit& q){
    return q.print(out);
}

}

#endif // QUBIT_H
