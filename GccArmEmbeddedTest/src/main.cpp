/*
**                           main.cpp
**
**********************************************************************/

#include <cstdint>

struct delay
{
    template<std::uint32_t N>
    inline static void wait()
    {
        for (std::uint32_t i = 0; i < N; i++)
        {
            __asm__("nop");
        }
    }
};

inline auto add_auto(auto a, auto b)
{
    return a+b;
}

template<typename first_t, typename second_t, typename return_t>
inline return_t add_template(first_t first, second_t second)
{
    return static_cast<return_t>(first+second);
}

int main(void)
{
    auto a_x = 0;       // auto x, deduced as int
    auto a_y = 1.23;    // auto y, deduced as double

    int t_x = 0;        // type specified x
    double t_y = 1.23;  // type specified y

    while(1)
    {
        // do some adds with add_auto function:
        a_x = add_auto(a_x, 1);         // add_auto<int, int>(int, int)
        a_y = add_auto(a_y, a_x);       // add_auto<double, int>(double, int)

        // perform the same adds with add_template function:
        t_x = add_template<int, int, double>(t_x, 1);       // add_template<int, int, double>(int, int)
        t_y = add_template<double, int, double>(t_y, t_x);  // add_template<int, int, double>(int, int)

        delay::wait<250000U>();
    }
}
