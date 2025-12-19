/* demrodri@student.42wolfsburg.de
   CPP09 - ex01 - RPN - RPN.hpp */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>
#include <climits>

int		operation(int first, int second, std::string sign);
void	rpn(std::string equation);
int		check_input(std::string equation);

#endif