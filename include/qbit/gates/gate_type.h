#ifndef GATE_TYPE_H
#define GATE_TYPE_H

namespace qbit {
namespace gates {

///
/// \brief The GateType enum. Useful enumeration of the
/// gate types used around the simulator
///
enum class GateType{

    NONE=0, HADAMARD, HADAMADARD_WITH_MES,
    IDENTITY, IDENTITY_WITH_MES, MEASUREMENT

};

}
}

#endif // GATE_TYPE_H
