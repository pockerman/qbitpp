#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "qbit/base/types.h"
#include "boost/noncopyable.hpp"

namespace qbit{

///
/// \brief MathConsts
///
class MathConsts: private boost::noncopyable
{
public:

    ///
    /// \brief The mathematical constant PI
    ///
    constexpr static real_t PI = 3.14159265359;


private:

    ///
    /// \brief Constructor
    ///
    MathConsts()
    {}
};

}

#endif // CONSTANTS_H
