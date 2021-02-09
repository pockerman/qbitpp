#include "qbit/base/config.h"

#ifdef USE_LOG
#include "qbit/utilities/log_message.h"

namespace qbit
{

std::string
LogMsg::type_to_string(LogMsg::Type t){

   switch(t)
   {

      case LogMsg::Type::ERROR:
              return "ERROR";
      case LogMsg::Type::WARNING:
              return "WARNING";
      case LogMsg::Type::INFO:
              return "INFO";

   }

   return "INVALID_TYPE";
}

std::string
LogMsg::type_to_rich_string(LogMsg::Type t){
        return std::string("[ "+LogMsg::type_to_string(t)+" ]");
}

}

#endif
