#include "SEcho.hpp"
#include <iostream>

SEcho * SEcho::sech_instance_to_get = nullptr;

SEcho::SEcho() : message_to_show("Single instance obj. ") 
{
   std::cout << __PRETTY_FUNCTION__ << " called." << std::endl;   

   std::cout << __DATE__ << " date" << std::endl;  

   std::cout << __FILE__ << " file used" << std::endl;  

   std::cout << __LINE__ << " line" << std::endl; 
  
   std::cout << __TIME__ << " time" << std::endl; 

   // std::cout << __FUNCSIG__ << " time" << std::endl;     
};

SEcho& SEcho::getInstance()
{
    if(!sech_instance_to_get)
    {
        sech_instance_to_get = new SEcho();
    }

    return *sech_instance_to_get;
}


void SEcho::showMessageFromObject() const
{
    std::cout << __PRETTY_FUNCTION__ << " called." << std::endl; 

    std::cout << message_to_show << std::endl;

}