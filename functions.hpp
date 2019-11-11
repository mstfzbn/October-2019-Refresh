#pragma once

#include "includes.hpp"
#include "defines.hpp"
#include "IBox.hpp"

template<typename T>
void printThis(std::string message_to_print ,T info_to_print) //? how to put N parameters to method - complicated and kind of useless
{
    std::cout << message_to_print << info_to_print << std::endl;
}

namespace CUSTOM_MATH{

    template<typename T>
    T sumTwoTings(T a, T b)
    {
        return a + b;
    }
}

#ifdef DEBUG
namespace DEBUG_TOOLS{

    static clock_t starting_time;

    static void StartProgramExecutionTimer()   
    {
        starting_time = clock();
    }

    static void StopProgramExecutionTimer()
    {
        static clock_t end_time = (clock() - starting_time);
        std::cout << "Program execution time: " << end_time  << " ms." << std::endl;
    }  
}
#endif