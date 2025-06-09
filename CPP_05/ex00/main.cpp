/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:55:06 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/09 22:26:31 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat merz("Merz", 1);
	Bureaucrat merkel("Merkel", 150);
	// Bureaucrat noparametertest; //not possible, as it is forbidden to create a Bureaucrat without parameters
	// Grade will be checked on the construction by the method checkGrade
	
std::cin.get();
	try
	{
		std::cout << "TEST: GRADE INCREMENT >> " << merz << std::endl;
		merz.incrementGrade();
		std::cout << merz << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}

std::cin.get();
	try
	{
		std::cout << "TEST: GRADE DECREMENT >> " << merz << std::endl;
		merz.decrementGrade();
		std::cout << merz << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}

std::cin.get();
	Bureaucrat normalcopy(merz);
	Bureaucrat operatorcopy("maria", 50);
	operatorcopy = normalcopy; //will have the grade of kafka, but not the name (as it is const and can only be set at contruction)
	
	std::cout << normalcopy << std::endl;
	std::cout << operatorcopy << std::endl << std::endl;

std::cin.get();
	std::cout << merkel << std::endl;
	try
	{
		std::cout << "TEST: GRADE DECREMENT >> " << merkel << std::endl;
		merkel.decrementGrade();
		std::cout << merkel << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}

std::cin.get();	
	try
	{
		std::cout << "TEST: GRADE INCREMENT >> " << merkel << std::endl;
		merkel.incrementGrade();
		std::cout << merkel << std::endl;
	} 
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}

std::cin.get();
	try
	{
		std::cout << "TEST: LOWER THAN MINIMAL " << std::endl;
		Bureaucrat lower("Lower", 151);
		std::cout << lower << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}

std::cin.get();
	try
	{
		std::cout << "TEST: BIGGER THAN MAXIMAL " <<std::endl;
		Bureaucrat maximal("Maximal", 0);
		std::cout << maximal << std::endl << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) //specific exception
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) //general exception
	{
		std::cerr << e.what() << std::endl;
	}
}

//COMPLETE TESTING
// #include "Bureaucrat.hpp"
// #include <iostream>
// #include <iomanip>
// #include <vector>
// #include <string>

// // Struct to track test results
// struct TestResult {
//     std::string testName;
//     bool passed;
//     std::string notes;
// };

// std::vector<TestResult> testResults;

// // Function to print test section headers
// void printHeader(const std::string& title) {
//     std::cout << "\n" << std::string(50, '=') << std::endl;
//     std::cout << "  " << title << std::endl;
//     std::cout << std::string(50, '=') << "\n" << std::endl;
// }

// // Function to track test results
// void recordTestResult(const std::string& testName, bool passed, const std::string& notes) {
//     TestResult result;
//     result.testName = testName;
//     result.passed = passed;
//     result.notes = notes;
//     testResults.push_back(result);
// }

// // Function to test Bureaucrat constructors
// void testConstructors() {
//     printHeader("TESTING CONSTRUCTORS");
//     bool allPassed = true;

//     std::cout << "1. Creating a valid bureaucrat:" << std::endl;
//     try {
//         Bureaucrat normal("John", 75);
//         std::cout << "   SUCCESS: " << normal << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n2. Creating a bureaucrat with the highest grade (1):" << std::endl;
//     try {
//         Bureaucrat highest("Max", 1);
//         std::cout << "   SUCCESS: " << highest << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n3. Creating a bureaucrat with the lowest grade (150):" << std::endl;
//     try {
//         Bureaucrat lowest("Min", 150);
//         std::cout << "   SUCCESS: " << lowest << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n4. Creating a bureaucrat with grade too high (0):" << std::endl;
//     try {
//         Bureaucrat tooHigh("TooHigh", 0);
//         std::cout << "   FAILURE: Should have thrown exception" << std::endl;
//         allPassed = false;
//     } catch (Bureaucrat::GradeTooHighException &e) {
//         std::cout << "   SUCCESS: Caught expected exception: " << e.what() << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Caught unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n5. Creating a bureaucrat with grade too low (151):" << std::endl;
//     try {
//         Bureaucrat tooLow("TooLow", 151);
//         std::cout << "   FAILURE: Should have thrown exception" << std::endl;
//         allPassed = false;
//     } catch (Bureaucrat::GradeTooLowException &e) {
//         std::cout << "   SUCCESS: Caught expected exception: " << e.what() << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Caught unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n6. Testing copy constructor:" << std::endl;
//     try {
//         Bureaucrat original("Original", 42);
//         Bureaucrat copy(original);
//         std::cout << "   Original: " << original << std::endl;
//         std::cout << "   Copy: " << copy << std::endl;
//         std::cout << "   SUCCESS: Copy created successfully" << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }
    
//     recordTestResult("Constructor Tests", allPassed, "Basic, boundary, and exception tests");
// }

// // Function to test getters
// void testGetters() {
//     printHeader("TESTING GETTERS");
//     bool allPassed = true;

//     Bureaucrat b("TestBureaucrat", 42);
    
//     std::cout << "Name: " << b.getName() << " (should be 'TestBureaucrat')" << std::endl;
//     if (b.getName() != "TestBureaucrat") allPassed = false;
    
//     std::cout << "Grade: " << b.getGrade() << " (should be 42)" << std::endl;
//     if (b.getGrade() != 42) allPassed = false;
    
//     recordTestResult("Getter Tests", allPassed, "Testing getName() and getGrade()");
// }

// // Function to test increment and decrement
// void testIncrementDecrement() {
//     printHeader("TESTING INCREMENT AND DECREMENT");
//     bool allPassed = true;

//     std::cout << "1. Basic incrementing:" << std::endl;
//     try {
//         Bureaucrat b("Bob", 10);
//         std::cout << "   Before: " << b << std::endl;
//         b.incrementGrade();
//         std::cout << "   After increment: " << b << " (should be grade 9)" << std::endl;
//         if (b.getGrade() != 9) allPassed = false;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n2. Basic decrementing:" << std::endl;
//     try {
//         Bureaucrat b("Alice", 10);
//         std::cout << "   Before: " << b << std::endl;
//         b.decrementGrade();
//         std::cout << "   After decrement: " << b << " (should be grade 11)" << std::endl;
//         if (b.getGrade() != 11) allPassed = false;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n3. Incrementing at highest grade (1):" << std::endl;
//     try {
//         Bureaucrat b("TopDog", 1);
//         std::cout << "   Before: " << b << std::endl;
//         b.incrementGrade();
//         std::cout << "   FAILURE: Should have thrown exception" << std::endl;
//         allPassed = false;
//     } catch (Bureaucrat::GradeTooHighException &e) {
//         std::cout << "   SUCCESS: Caught expected exception: " << e.what() << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Caught unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n4. Decrementing at lowest grade (150):" << std::endl;
//     try {
//         Bureaucrat b("BottomDweller", 150);
//         std::cout << "   Before: " << b << std::endl;
//         b.decrementGrade();
//         std::cout << "   FAILURE: Should have thrown exception" << std::endl;
//         allPassed = false;
//     } catch (Bureaucrat::GradeTooLowException &e) {
//         std::cout << "   SUCCESS: Caught expected exception: " << e.what() << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Caught unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n5. Multiple increments:" << std::endl;
//     try {
//         Bureaucrat b("Climber", 10);
//         std::cout << "   Starting: " << b << std::endl;
//         for (int i = 0; i < 5; i++) {
//             b.incrementGrade();
//             std::cout << "   After increment " << (i + 1) << ": " << b << std::endl;
//         }
//         if (b.getGrade() != 5) allPassed = false;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n6. Multiple decrements:" << std::endl;
//     try {
//         Bureaucrat b("Faller", 145);
//         std::cout << "   Starting: " << b << std::endl;
//         for (int i = 0; i < 5; i++) {
//             b.decrementGrade();
//             std::cout << "   After decrement " << (i + 1) << ": " << b << std::endl;
//         }
//         if (b.getGrade() != 150) allPassed = false;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }
    
//     recordTestResult("Increment/Decrement Tests", allPassed, "Basic operations and boundary checks");
// }

// // Function to test assignment operator
// void testAssignmentOperator() {
//     printHeader("TESTING ASSIGNMENT OPERATOR");
//     bool allPassed = true;
    
//     try {
//         Bureaucrat a("First", 10);
//         Bureaucrat b("Second", 20);
        
//         std::cout << "Before assignment:" << std::endl;
//         std::cout << "   a: " << a << std::endl;
//         std::cout << "   b: " << b << std::endl;
        
//         b = a;
        
//         std::cout << "After assignment (b = a):" << std::endl;
//         std::cout << "   a: " << a << std::endl;
//         std::cout << "   b: " << b << std::endl;
        
//         if (b.getGrade() != 10) allPassed = false;
        
//         a.incrementGrade();
//         std::cout << "After modifying a:" << std::endl;
//         std::cout << "   a: " << a << " (should be grade 9)" << std::endl;
//         std::cout << "   b: " << b << " (should still be grade 10)" << std::endl;
        
//         if (a.getGrade() != 9 || b.getGrade() != 10) allPassed = false;
        
//         std::cout << "Notice that b's name remains 'Second' despite assignment" << std::endl;
//         if (b.getName() != "Second") allPassed = false;
//     } catch (std::exception &e) {
//         std::cout << "ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }
    
//     recordTestResult("Assignment Operator Test", allPassed, "Deep copy verification");
// }

// // Function to test the << operator
// void testInsertionOperator() {
//     printHeader("TESTING << OPERATOR");
    
//     Bureaucrat b1("Jack", 5);
//     Bureaucrat b2("Jill", 150);
    
//     std::cout << "Output format should be: '<name>, bureaucrat grade <grade>'" << std::endl;
//     std::cout << "First bureaucrat: " << b1 << std::endl;
//     std::cout << "Second bureaucrat: " << b2 << std::endl;
    
//     // This test is visual, we'll assume it passed unless there are compile errors
//     recordTestResult("Insertion Operator Test", true, "Visual confirmation required");
// }

// // Function to print test results summary
// void printTestSummary() {
//     printHeader("TEST RESULTS SUMMARY");
    
//     int passed = 0;
//     int failed = 0;
    
//     std::cout << std::left << std::setw(30) << "TEST NAME" 
//               << std::setw(10) << "STATUS" 
//               << "NOTES" << std::endl;
//     std::cout << std::string(70, '-') << std::endl;
    
//     for (size_t i = 0; i < testResults.size(); ++i) {
//         const TestResult& result = testResults[i];
//         std::cout << std::left << std::setw(30) << result.testName 
//                   << std::setw(10) << (result.passed ? "PASSED" : "FAILED") 
//                   << result.notes << std::endl;
        
//         if (result.passed) passed++;
//         else failed++;
//     }
    
//     std::cout << std::string(70, '-') << std::endl;
//     std::cout << "TOTAL TESTS: " << testResults.size() << std::endl;
//     std::cout << "PASSED: " << passed << std::endl;
//     std::cout << "FAILED: " << failed << std::endl;
    
//     if (failed == 0) {
//         std::cout << "\n[ALL TESTS PASSED] The Bureaucrat class is working correctly." << std::endl;
//     } else {
//         std::cout << "\n[SOME TESTS FAILED] Please review the issues above." << std::endl;
//     }
// }

// // Main function that runs all tests
// int main() {
//     std::cout << "\n\n" << std::string(60, '*') << std::endl;
//     std::cout << std::setw(40) << "BUREAUCRAT TESTS" << std::endl;
//     std::cout << std::string(60, '*') << "\n" << std::endl;

//     testConstructors();
//     testGetters();
//     testIncrementDecrement();
//     testAssignmentOperator();
//     testInsertionOperator();
    
//     printTestSummary();

//     std::cout << "\n\n" << std::string(60, '*') << std::endl;
//     std::cout << std::setw(40) << "ALL TESTS COMPLETED" << std::endl;
//     std::cout << std::string(60, '*') << "\n" << std::endl;

//     return 0;
// }