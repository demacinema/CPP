/* demrodri@student.42wolfsburg.de
   CPP09 - ex01 - RPN - main.cpp */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong amount of arguments!" << std::endl;
        return (1);
    }

    std::string equation = argv[1];
    
    if (check_input(equation))
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    rpn(equation);
    return (0);
}