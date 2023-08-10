#include "functions.hpp"

int main(int argc, char *argv[]){
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

    printThis("\n", " ");

    Container<std::string> string_cont;
    string_cont.putElementAtEnd("Test");
    string_cont.putElementAtEnd("with");
    string_cont.putElementAtEnd("strings");

    for(size_t j = 0; j < string_cont.getSize(); ++j)
    {      
       std::cout << string_cont.getElementsValueAt(j) << " ";
    }


    printThis("\n", " ");

    string_cont.putElementAtBegin("New begin");
    string_cont.putElementAtPostition("Second_One",1);

    printThis("\nNew size: ", string_cont.getSize());

    for(size_t j = 0; j < string_cont.getSize(); ++j)
    {      
       std::cout << string_cont.getElementsValueAt(j) << " ";
    }

    string_cont.clear();

    printThis("\n", " ");

    Geometry::ThreeDimensionalBox test_3d_box;
    std::vector<double> test_lenghts;
    test_lenghts.push_back(4.56);
    test_lenghts.push_back(2.59);
    test_lenghts.push_back(1.14);

    test_3d_box.SetLengthOfAllDimensions(test_lenghts);

    test_lenghts.clear();
    
    Geometry::FourDimensionalBox test_4d_box;
    test_lenghts.push_back(25.89);
    test_lenghts.push_back(63.41);
    test_lenghts.push_back(82.99);
    test_lenghts.push_back(14.06);

    test_4d_box.SetLengthOfAllDimensions(test_lenghts);

    Container<Geometry::NBox *> test_conti; //test cont
    test_conti.putElementAtEnd(&test_3d_box);
    test_conti.putElementAtEnd(&test_4d_box);

   

    printThis("\n", " Size print test: \n");
     
    for(size_t k = 0; k < test_conti.getSize(); ++k)
    {
        //this is polymorphism ;)
        for(size_t j = 0; j < test_conti.getElementsValueAt(k)->GetDimensions(); ++j)
        {
            std::cout << "\033[0;33m"<< "  size " << j << ':' <<"\033[0m" <<
            test_conti.getElementsValueAt(k)->GetSizeOfAllDimensions()->at(j)<<"\n";
        }

        //this is polymorphism ;)
        test_conti.getElementsValueAt(k)->ShowName();
        printThis("\n", " ");
    }


    #ifdef DEBUG
    DEBUG_TOOLS::StopProgramExecutionTimer();
    #endif

    return 0;
}
