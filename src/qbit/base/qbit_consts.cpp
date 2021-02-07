#include "qbit/base/qbit_consts.h"

namespace qbit
{
    real_t
    QbitConsts::tol_ = 1.0e-8;

	void 
    QbitConsts::initialize(){

        QbitConsts::tol_ = 1.0e-8;
	}

}
