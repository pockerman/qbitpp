#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

namespace qbit{

///
/// \brief The DivisionWithZero class. Exception to be
/// thrown when a division with zero is attempted
///
class DivisionWithZero: public std::logic_error
{
public:

    explicit DivisionWithZero(const std::string& what_arg)
    :
    std::logic_error(what_arg)
    {}

    explicit DivisionWithZero(const char* what_arg)
    :
    std::logic_error(what_arg)
    {}
};

class InvalidStateSize: public std::logic_error
{
public:

    explicit InvalidStateSize(const std::string& what_arg)
    :
    std::logic_error(what_arg)
    {}

    explicit InvalidStateSize(const char* what_arg)
    :
    std::logic_error(what_arg)
    {}

};
}

#endif // EXCEPTIONS_H
