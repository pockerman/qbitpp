#ifndef LP_METRIC_H
#define LP_METRIC_H

#include "qbit/base/types.h"


#include <array>
#include <vector>

namespace qbit
{

///
/// \brief The LpMetric class
/// It conforms to the metric policy
///
template<int P, bool TTakeRoot = true>
class LpMetric
{

public:

   static const int Power = P;
   static const bool TakeRoot = TTakeRoot;
   static real_t tolerance_value;
   typedef real_t cost_t;
   typedef real_t value_t;

   /// \brief Tolerance used by the class
   static real_t tolerance(){return tolerance_value;}

   ///
   /// \brief Default constructor.
   ///
   LpMetric()=default;

   ///
   /// \brief Overload operator()
   ///
   real_t operator()(const DynVec<real_t>& v1, const DynVec<real_t>& v2)const;

   ///
   /// \brief Evaluate for DynVec
   ///
   static real_t evaluate(const DynVec<real_t>& v1, const DynVec<real_t>& v2);

   ///
   /// \brief Evaluate for std::array
   ///
   template<int dim>
   static real_t evaluate(const std::array<real_t, dim>& v1, const std::array<real_t, dim>& v2);

   ///
   /// \brief Evaluate for std::vector
   ///
   static real_t evaluate(const std::vector<real_t>& v1, const std::vector<real_t>& v2);
};




///
/// \brief some useful shortcuts
///
using ManhattanMetric = LpMetric<1, false> ;
using SqrEuclidean_metric =  LpMetric<2, false> ;
using EuclideanMetric = LpMetric<2, true> ;

}

#include "qbit/maths/lp_metric_impl.h"

#endif // LP_METRIC_H
