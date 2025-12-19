/* demrodri@student.42wolfsburg.de
   CPP09 - ex01 - RPN - RPN.cpp */

#include "RPN.hpp"

// Function to perform the arithmetic operation
// 1. takes two integers and a string representing the operator
// 2. performs the operation and returns the result

int	operation(int first, int second, std::string sign)
{	
	int result;
	char operation = sign[0]; // get the operator character from the string

	switch(operation)
	{
		case '+':
		{
			if ((second > 0 && first > INT_MAX - second) ||
				(second < 0 && first < INT_MIN - second))
			{
				std::cerr << "INT Limit Reached!" << std::endl;
				exit (1);
			}
			result = (second + first);
			break ;
		}
		case '-':
		{
			if ((second > 0 && first < INT_MIN + second) ||
				(second < 0 && first > INT_MAX + second))
			{
				std::cerr << "INT Limit Reached!" << std::endl;
				exit (1);
			}
			result = (second - first);
			break ;
		}
		case '*':
		{
			long long result_check = (long long)second * first;
			if (result_check > INT_MAX || result_check < INT_MIN)
			{
				std::cerr << "INT Limit Reached!" << std::endl;
				exit (1);
			}
			result = (second * first);
			break ;
		}
		case '/':
		{
			if (first == 0)
			{
				std::cerr << "Can't divide by zero!" << std::endl;
				exit (1);
			}
			result = (second / first);
			break ;
		}
        default:
            result = 0;
            break ;
	}
	return (result);
}

// RPN function to evaluate the equation
// IN RESUME:
// 1. read each token from the equation
// 2. if token is a number, push it onto the stack (with std::stack<int>, as we are working with integers)
// 3. if token is an operator, pop the top two numbers from the stack,
//    apply the operator, and push the result back onto the stack (using the operation function)
// 4. at the end, the stack should contain only one number, which is the
//    result of the RPN expression (e.g.: for "5 1 2 + 4 * + 3 -", the result is 14)

void	rpn(std::string equation)
{	
	std::stack<int> stack; // stack to store numbers for RPN evaluation
	std::string temp;
	std::istringstream iss(equation); // for parsing the equation, token by token

	int	first;  // to store the first number popped (removed) from the stack
	int second; // to store the second number popped (removed) from the stack

	while (iss >> temp) // it finishes when there are no more tokens to read (iss >> temp returns false)
	{
		if (temp.find_first_not_of("0123456789") == std::string::npos) // if token is a number
			stack.push(std::atoi(temp.c_str())); // convert string to C style, then to int and push onto the stack
		else // if token is an operator
		{
			if (stack.size() < 2) // check if it is safe to pop two numbers from the stack
			{
				std::cerr << "Error" << std::endl;
				exit (1);
			}
			first = stack.top();  // get the top number from the stack
			stack.pop(); 		  // remove the top number from the stack
			second = stack.top(); // get the second number from the stack
			stack.pop(); // remove the second number from the stack
			stack.push(operation(first, second, temp)); // perform the operation and push the result back onto the stack
		}
	}
	std::cout << stack.top() << std::endl; // print the final result (the only number left in the stack)
}

// NEEDED CHECKS:
// 1. only valid characters (digits and +-/*) 
// 2. at least two numbers before an operator
// 3. operators = numbers - 1
int check_input(std::string equation)
{
    std::istringstream iss(equation); // for parsing the equation, token by token
    std::string temp;

    int num_token = 0;
    int op_token = 0;

    while (iss >> temp) // it finishes when there are no more tokens to read (iss >> temp returns false)
    {
        // CHECK IF TOKEN IS A VALID NUMBER OR OPERATOR
        if (temp.size() > 1 || temp.find_first_not_of("0123456789+-/*") != std::string::npos)
            return (1);

        if (temp == "+" || temp == "-" || temp == "*" || temp == "/") // Operator token
        {
            if (num_token < 2) // CHECK IF AT LEAST TWO NUMBERS BEFORE AN OPERATOR
                return (1);

            op_token++;
        }
        else // Number token
            num_token++;
    }
    // CHECK IF OPERATORS ARE ONE LESS THAN NUMBERS, and also the edge case of ./RPN "", "./RPN +" or "./RPN 5 +"
    if (--num_token != op_token)
        return (1);

    return (0);
}