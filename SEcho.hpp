#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>

class SEcho
{   
    private:
    static SEcho * sech_instance_to_get;

    SEcho();

    std::string message_to_show{};

    SEcho( const SEcho & ) = delete;
    SEcho( SEcho && ) = delete;
    SEcho * operator= ( const SEcho & ) = delete;
    SEcho * operator= ( SEcho && ) = delete;    

    public:  

    static SEcho& getInstance();

    void showMessageFromObject() const;    
};