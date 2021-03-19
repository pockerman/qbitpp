#include "qbit/base/qubit.h"
#include "qbit/maths/lp_metric.h"
#include "qbit/base/qbit_consts.h"
#include "qbit/base/exceptions.h"

namespace qbit
{

Qubit::Qubit(const DynVec<real_t>& state)
    :
      state_(state),
      id_(QbitConsts::invalid_size_type())
{
    normalize_();
}

Qubit::Qubit(uint_t size)
    :
      state_(size, 0.0)
{}

Qubit::Qubit(const Qubit& other)
    :
      state_(other.state_),
      id_(other.id_)
{}

Qubit&
Qubit::operator=(const Qubit& other){
    state_ = other.state_;
    id_ = other.id_;
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
    out << id_    << std::endl;
    out << state_ << std::endl;
    return out;
}

DynVec<real_t>
Qubit::as_vector()const{
    return state_;
}

DynVec<real_t>
Qubit::get_amplitudes_sqr()const{
    return blaze::map(state_, [](real_t item){return item*item;});
}


}
