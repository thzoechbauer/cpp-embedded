#ifndef MY_STDEXCEPT_H_INCLUDED
#define MY_STDEXCEPT_H_INCLUDED

#include <exception>
#include <cstring>

namespace my_std
{
    class logic_error : std::exception
    {
    public:
        logic_error(const char* pmsg)
        {
            if (pmsg != nullptr)
            {
                std::strncpy(msg, pmsg, max_msg_length);
                msg[max_msg_length] = '\0';   // Null-termination of c-string.
            }
            else
            {
                msg[0] = '\0';  // Null-termination of fist character.
            }

        }
        virtual ~logic_error() {}
        const char* what() { return msg; }

    private:
        constexpr static std::size_t max_msg_length = 63;
        char msg[max_msg_length+1]; // +1 for null-termination.
    };
}



#endif // MY_STDEXCEPT_H_INCLUDED
