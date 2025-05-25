#pragma once
#include <functional>
#include <map>

namespace rodr
{
    using handler = std::function<void(const char*)>;

    enum class ERROR_TYPE
    {
        Creation = 0,
        Receive,
        BadReturnVal,
        StmAcceptPos,
        SendCmd,
        SendPos,
        OpenFile
    };

    namespace err_src
    {
        constexpr const char* TCP = "TCP";
        constexpr const char* UDP = "UDP";
        constexpr const char* RECORDING = "RECORDING";
    }

    namespace err_msgs
    {
        constexpr const char* CREATION = "Socket creation failed";

        constexpr const char* RECEIVE = "No data received";
        constexpr const char* BADRETURNVAL = "Bad return value";
        constexpr const char* STMACCEPTPOS = "Bad position argument";

        constexpr const char* SENDCMD = "Could not send command";
        constexpr const char* SENDPOS = "Could not send position";

        constexpr const char* OPEN = "Could not open file at the specified path";

        constexpr const char* getErrorMsg(ERROR_TYPE type)
        {
            switch(type)
            {
                case ERROR_TYPE::Creation: return CREATION;
                case ERROR_TYPE::Receive: return RECEIVE;
                case ERROR_TYPE::BadReturnVal: return BADRETURNVAL;
                case ERROR_TYPE::StmAcceptPos: return STMACCEPTPOS;
                case ERROR_TYPE::SendCmd: return SENDCMD;
                case ERROR_TYPE::SendPos: return SENDPOS;
                case ERROR_TYPE::OpenFile: return OPEN;
                default: return "bad type";
            }
        }
    }

    //map for filtering feedback columns
    const std::map<const char*, int> ColmumnMap = {
        {"time", 0},
        {"pos", 1},
        {"hum", 2}
    };

}
