#include "includes.hpp"
#include "defines.hpp"

namespace Geometry
{

    //interface class, wich gave properties to hyper-dimensional box objects
    class ITopology
    {
        //an interface class has no implementation
        //it contaions only a virtual destructor and pure virtual functions
        public:

        virtual ~ITopology() = default;    
        //even pure virtual functions must know ther argument list
        virtual void SetDimensions(const size_t &) = 0;
        virtual size_t GetDimensions() = 0;
    };

    //length of each dimension
    //vector with all og them
    //set function with for loop for their length
    class NBox: public ITopology
    {
        public:
        
        NBox() 
        {
            #ifdef DEBUG
            std::cout << "\033[0;31m\n NBox Constructor called.\n\033[0m";
           // std::cout << "\n\n NBox Constructor called.\n";
            #endif
        }; //need implemntation
        
        virtual ~NBox() 
        {
            #ifdef DEBUG
             std::cout << "\033[0;31m\n NBox Destructor called.\n\033[0m";
           // std::cout << "\n\n NBox Destructor called.\n";
            #endif

            m_nbox_lengths.clear();
        };

        virtual void SetDimensions( const size_t &dimension )
        {
            m_nbox_dimensions = dimension;
        }

        virtual size_t GetDimensions()
        {
            return m_nbox_dimensions;
        }

        //vector<double> with lengths
        virtual void SetLengthOfAllDimensions( const std::vector<double> &lengths ) 
        {
            m_nbox_lengths = lengths;
        }

        virtual std::vector<double>* GetSizeOfAllDimensions() 
        {
            return &m_nbox_lengths;
        }

        //pure virtual, wich will be derivated and described, 
        //used to show polymorphism
        virtual void ShowName() = 0;

        //CalculateVolume

        protected:
        size_t m_nbox_dimensions;
        std::vector<double> m_nbox_lengths;
    };

    class ThreeDimensionalBox: public NBox
    {
        public:
        ThreeDimensionalBox():NBox()
        {
            #ifdef DEBUG
            std::cout << "\033[0;31m\n ThreeDimensionalBox Constructor called.\n\033[0m";
            //std::cout << "\n\n ThreeDimensionalBox Constructor called.\n";
            #endif

            this->SetDimensions( THREE );
        };  

        ~ThreeDimensionalBox()
        {
            #ifdef DEBUG
            std::cout << "\033[0;31m\n ThreeDimensionalBox Constructor called.\n\033[0m";           
           //std::cout << "\n\n ThreeDimensionalBox Destructor called.\n";            
            #endif
        };     

        virtual void ShowName()
        {
            std::cout << "\033[0;36m\n3D box\n\033[0m"; 
            //std::cout << "\n3D box\n";
        }
    };

    class FourDimensionalBox: public NBox
    {
        public:
        FourDimensionalBox():NBox()
        {
            #ifdef DEBUG
            std::cout << "\033[0;31m\n FourDimensionalBox Constructor called.\n\033[0m";  
            
            //std::cout << "\n\n FourDimensionalBox Constructor called.\n";
            #endif

            this->SetDimensions( FOUR );
        };  

        ~FourDimensionalBox()
        {
            #ifdef DEBUG
            std::cout << "\033[0;31m\n FourDimensionalBox Destructor called\n\033[0m"; 
            //std::cout << "\n\n FourDimensionalBox Destructor called.\n";            
            #endif
        };     

        virtual void ShowName()
        {  
            std::cout << "\033[0;35m\n4D box\n\033[0m"; 
            //std::cout << "\n4D box\n";
        }
    };

};//end of namespace Geometry
