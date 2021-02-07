#include "qbit/base/qubit.h"
#include "qbit/maths/lp_metric.h"
#include "qbit/base/qbit_consts.h"

namespace qbit
{

Qubit::Qubit(const State<2>& state)
    :
      state_(state)
{
    normalize_();
}

void
Qubit::normalize_(){

    auto length = LpMetric<2>::evaluate(state_,
                                        QbitConsts::get_zero_state<2>());

    // make sure we don't divide with zero

    for(auto i=0; i<state_.size(); ++i){
        state_[i] /= length;
    }

}


}
