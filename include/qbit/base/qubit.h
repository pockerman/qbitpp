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
    /// \brief Copy constructor
    ///
    Qubit(const Qubit& other);

    ///
    /// \brief operator = Copy assignment operator
    ///
    Qubit& operator=(const Qubit& other);

    ///
    ///\brief Returns the qubit representation as vector
    ///
    DynVec<real_t> as_vector()const;

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

    ///
    /// \brief get_id. Returns the id of the Qubit
    ///
    uint_t get_id()const{return id_;}

    ///
    /// \brief set_id. Returns the id of the Qubit
    ///
    void set_id(uint_t id){id_ = id;}

    ///
    /// \brief size Returns the size of the state vector of the qubit
    ///
    uint_t size()const{return state_.size();}

    ///
    /// \brief get_amplitudes_sqr. Returns the amplitudes of the
    /// state vector squared
    ///
    DynVec<real_t> get_amplitudes_sqr()const;

private:

    ///
    /// \brief state_. The state of the qubit
    ///
    DynVec<real_t> state_;

    ///
    /// \brief id_. The id of the qubit. Typically
    /// this will be set by QCircuits
    ///
    uint_t id_;

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
