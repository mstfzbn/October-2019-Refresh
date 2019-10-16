#include "functions.hpp"

int main(){
    #ifdef DEBUG
    DEBUG_TOOLS::StartProgramExecutionTimer();
    #endif  
    
    Container<int> * tcont = new Container<int>;  

    printThis("Container initial size: ", tcont->getSize());

    for (int i = 1; i < 15; ++i)
    {
        a = a*i;

        tcont->putElementAtEnd(i);
    }

    printThis("res: ", a);    

    printThis("Container actual size: ", tcont->getSize());

    printThis("Some T sum: " , CUSTOM_MATH::sumTwoTings(tcont->getSize(), tcont->getSize()));  

    delete tcont;

    printThis("Just a new line", "!");

    Container<std::string> string_cont;
    string_cont.putElementAtEnd("Test");
    string_cont.putElementAtEnd("with");
    string_cont.putElementAtEnd("strings");

    for(size_t j = 0; j < string_cont.getSize(); ++j)
    {      
       std::cout << string_cont.getElementsValueAt(j) << " ";
    }

    string_cont.clear();

    printThis("\nJust a new line", "!");

    #ifdef DEBUG
    DEBUG_TOOLS::StopProgramExecutionTimer();
    #endif

    return 0;
}