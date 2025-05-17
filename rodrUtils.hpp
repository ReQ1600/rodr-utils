#pragma once
#include <functional>

namespace rodr
{
    using handler = std::function<void(const char*)>;

    enum class ERROR_TYPE
    {
        Creation = 0,
        Receive,
        AcceptPos,
        SendCmd,
        SendPos
    };

    namespace err_src
    {
        constexpr const char* TCP = "TCP";
        constexpr const char* UDP = "UDP";
    };


    namespace err_msgs
    {
        constexpr const char* CREATION = "Socket creation failed";

        constexpr const char* RECEIVE = "No data received";
        constexpr const char* ACCEPTPOS = "Bad return value";

        constexpr const char* SENDCMD = "Could not send command";
        constexpr const char* SENDPOS = "Could not send position";

        constexpr const char* getErrorMsg(ERROR_TYPE type)
        {
            switch(type)
            {
                case ERROR_TYPE::Creation: return CREATION;
                case ERROR_TYPE::Receive: return RECEIVE;
                case ERROR_TYPE::AcceptPos: return ACCEPTPOS;
                case ERROR_TYPE::SendCmd: return SENDCMD;
                case ERROR_TYPE::SendPos: return SENDPOS;
                default: return "bad type";
            }
        }
    };
}
