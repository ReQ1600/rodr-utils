#pragma once
#include <functional>

namespace rodr
{
    using handler = std::function<void(const char*)>;

    enum class ERROR_TYPE
    {
        Receive = 0,
        Send,
        Creation
    };

    namespace err_src
    {
        constexpr const char* TCP = "TCP";
        constexpr const char* UDP = "UDP";
    };


    namespace err_msgs
    {
        constexpr const char* RECEIVE = "No return value received";
        constexpr const char* SEND = "Could not send data";
        constexpr const char* CREATION = "Socket creation failed";

        constexpr const char* getErrorMsg(ERROR_TYPE type)
        {
            switch(type)
            {
                case ERROR_TYPE::Creation: return CREATION;
                case ERROR_TYPE::Receive: return RECEIVE;
                case ERROR_TYPE::Send: return SEND;
            }

            return "Unknown";
        }
    };
}
