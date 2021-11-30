#include "ati3dcif/Error.hpp"

namespace glrage {
namespace cif {

Error::Error(const char *message, C3D_EC errorCode)
    : std::runtime_error(message)
    , m_errorCode(errorCode)
{
}

Error::Error(const std::string &message, C3D_EC errorCode)
    : Error(message.c_str(), errorCode)
{
}

Error::Error(const char *message)
    : Error(message, C3D_EC_GENFAIL)
{
}

Error::Error(const std::string &message)
    : Error(message.c_str(), C3D_EC_GENFAIL)
{
}

C3D_EC
Error::getErrorCode() const
{
    return m_errorCode;
}

}
}