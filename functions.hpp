#pragma once

#include "includes.hpp"
#include "defines.hpp"
#include "IBox.hpp"

template<typename T>
void printThis(std::string message_to_print ,T info_to_print) //? how to put N parameters to method - complicated and kind of useless
{
    std::cout << message_to_print << info_to_print << std::endl;
}


//print with colors
//      zero is not bold,1 is bold; 34 is color code  
//std::cout << "\033[0;34m bold red text \033[0m\n";
//         foreground background  light
// black        30         40       90
// red          31         41       91
// green        32         42       92
// yellow       33         43       93
// blue         34         44       94
// magenta      35         45       95
// cyan         36         46       96
// white        37         47       97

// reset             0  (everything back to normal)
// bold/bright       1  (often a brighter shade of the same colour)
// underline         4
// inverse           7  (swap foreground and background colours)
// bold/bright off  21
// underline off    24
// inverse off      27


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

        //std::cout << "\033[0;32m Program execution time: "<< end_time <<" ms.\033[0m\n"; //working
       
       //with bold ms
       std::cout << "\033[0;32m Program execution time: \033[0m" << "\033[1;32m" << end_time << "\033[0m" <<"\033[0;92m ms.\033[0m\n";

        //std::cout << "\033[0;32mProgram execution time: \033[0m"<< end_time <<"\033[0;32m ms.\033[0m\n";
        //std::cout << "Program execution time: " << end_time  << " ms." << std::endl;
    }  
}
#endif