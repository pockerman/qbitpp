#include "qbit/base/qubit.h"
#include "qbit/maths/lp_metric.h"
#include "qbit/base/qbit_consts.h"
#include "qbit/base/exceptions.h"

namespace qbit
{

Qubit::Qubit(const DynVec<real_t>& state)
    :
      state_(state)
{
    normalize_();
}

Qubit::Qubit(uint_t size)
    :
      state_(size, 0.0)
{}

Qubit&
Qubit::operator=(const Qubit& other){
    this->state_ = other.state_;
    return *this;
}

void
Qubit::normalize_(){

    auto length = LpMetric<2>::evaluate(state_, DynVec<real_t>(state_.size(), 0.0));

    // make sure we don't divide with zero
    if(length <= QbitConsts::tolerance()){
        throw DivisionWithZero("Division with zero for Qubit normalization");
    }

    for(auto i=0; i<state_.size(); ++i){
        state_[i] /= length;
    }
}

real_t
Qubit::get_probability(DynVec<uint_t> bits)const{

    if(bits.size() != state_.size()){
        throw InvalidStateSize("The given bits array size does not match Qubit state size");
    }

    return 0.0;
}

std::ostream&
Qubit::print(std::ostream& out)const{
    out << state_;
    return out;;
}

DynVec<real_t>
Qubit::as_vector()const{
    return state_;
}


}
