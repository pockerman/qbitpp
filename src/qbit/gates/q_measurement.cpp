#include "qbit/gates/q_measurement.h"
#include "qbit/base/qubit.h"

#include <cmath>

namespace qbit{


QMeasurement::QMeasurement(const input_t& input)
    :
      input_(std::move(input))
{}


QMeasurement::output_t
QMeasurement::operator()()const{


    QMeasurement::output_t out;
    out.reserve(input_.size());

    for(auto& qubit : input_){

        auto amplitudes = qubit.as_vector();

        for(auto ampl: amplitudes){
            out.push_back(std::pow(std::fabs(ampl), 2));
        }
    }

    return out;
}

}
