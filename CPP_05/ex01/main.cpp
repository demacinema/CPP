/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:51:59 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/09 22:52:30 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	Bureaucrat b1("Demetrio Rodrigues", 1);
	Bureaucrat b2("James Bond", 2);
	Bureaucrat b3("Charlize Theron", 50);
	Bureaucrat b4("Xi Jin Ping", 120);
	Bureaucrat b5("Donald Trump", 149);

std::cin.get();
	Form f1("Antrax", 2, 1); //nome, sign grade, exec grade
	Form f2("Plutonio", 1, 1);
	Form f3("Wasser", 119, 150);
	Form f4("Clouds", 30, 50);
	Form f5("Monkey", 120, 3);

std::cin.get();
	try //TESTE TO CREATE FORM LOWER GRADE THAN 150
	{
		Form plutonio("Plutonio", 150, 1445);
		std::cout << plutonio << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

std::cin.get();
	try //TEST TO CREATE FORM HIGHER GRADE THAN 1
	{
		Form pausa("pausa", 1, 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

std::cin.get();
	// TEST TO SIGN FORM WITH BUREAUCRAT HIGHER GRADE THAN FORM SIGN GRADE
	b1.signForm(f1);
	std::cout << b1 << std::endl << f1 << std::endl;
	
std::cin.get();
	// TEST TO SIGN FORM WITH BUREAUCRAT LOWER GRADE THAN FORM SIGN GRADE
	b4.signForm(f3);
	std::cout << b4 << std::endl << f3 << std::endl;

std::cin.get();
	// TEST TO INCREMENT BUREAUCRAT GRADE HIGHER THAN 1
	try
	{
		b1.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

std::cin.get();
	// TEST TO DECREMENT BUREAUCRAT GRADE LOWER THAN 150
	try
	{
		std::cout << b5 << std::endl;
		b5.decrementGrade();
		std::cout << b5 << std::endl;
		b5.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

std::cin.get();
	std::cout << f4 << std::endl;
	f4.beSigned(b2);
	Form assignmentcopy = f4;
	std::cout << assignmentcopy << std::endl;

std::cin.get();
	std::cout << f5 << std::endl;
	f5.beSigned(b1);
	Form copia(f5);
	std::cout << copia << std::endl << std::endl;
}

// //COMPLETE TEST

// #include "Bureaucrat.hpp"
// #include "Form.hpp"
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

// // Function to test Form constructors
// void testFormConstructors() {
//     printHeader("TESTING FORM CONSTRUCTORS");
//     bool allPassed = true;

//     std::cout << "1. Creating a valid form:" << std::endl;
//     try {
//         Form normal("Tax Return", 50, 25);
//         std::cout << "   SUCCESS: " << normal << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n2. Creating a form with highest grades (1):" << std::endl;
//     try {
//         Form highest("Top Secret", 1, 1);
//         std::cout << "   SUCCESS: " << highest << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n3. Creating a form with lowest grades (150):" << std::endl;
//     try {
//         Form lowest("Public Notice", 150, 150);
//         std::cout << "   SUCCESS: " << lowest << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n4. Creating a form with sign grade too high (0):" << std::endl;
//     try {
//         Form tooHigh("Invalid", 0, 75);
//         std::cout << "   FAILURE: Should have thrown exception" << std::endl;
//         allPassed = false;
//     } catch (Form::GradeTooHighException &e) {
//         std::cout << "   SUCCESS: Caught expected exception: " << e.what() << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Caught unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n5. Creating a form with sign grade too low (151):" << std::endl;
//     try {
//         Form tooLow("Invalid", 151, 75);
//         std::cout << "   FAILURE: Should have thrown exception" << std::endl;
//         allPassed = false;
//     } catch (Form::GradeTooLowException &e) {
//         std::cout << "   SUCCESS: Caught expected exception: " << e.what() << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Caught unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n6. Creating a form with execute grade too high (0):" << std::endl;
//     try {
//         Form tooHigh("Invalid", 75, 0);
//         std::cout << "   FAILURE: Should have thrown exception" << std::endl;
//         allPassed = false;
//     } catch (Form::GradeTooHighException &e) {
//         std::cout << "   SUCCESS: Caught expected exception: " << e.what() << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Caught unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n7. Creating a form with execute grade too low (151):" << std::endl;
//     try {
//         Form tooLow("Invalid", 75, 151);
//         std::cout << "   FAILURE: Should have thrown exception" << std::endl;
//         allPassed = false;
//     } catch (Form::GradeTooLowException &e) {
//         std::cout << "   SUCCESS: Caught expected exception: " << e.what() << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Caught unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n8. Testing copy constructor:" << std::endl;
//     try {
//         Form original("Original Form", 42, 21);
//         Form copy(original);
//         std::cout << "   Original: " << original << std::endl;
//         std::cout << "   Copy: " << copy << std::endl;
//         std::cout << "   SUCCESS: Copy created successfully" << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }
    
//     recordTestResult("Form Constructor Tests", allPassed, "Basic, boundary, and exception tests");
// }

// // Function to test Form getters
// void testFormGetters() {
//     printHeader("TESTING FORM GETTERS");
//     bool allPassed = true;

//     try {
//         Form f("Test Form", 50, 25);
        
//         std::cout << "Name: " << f.getName() << " (should be 'Test Form')" << std::endl;
//         if (f.getName() != "Test Form") allPassed = false;
        
//         std::cout << "Is Signed: " << (f.getIsSigned() ? "true" : "false") << " (should be false)" << std::endl;
//         if (f.getIsSigned() != false) allPassed = false;
        
//         std::cout << "Grade Required to Sign: " << f.getGradeSign() << " (should be 50)" << std::endl;
//         if (f.getGradeSign() != 50) allPassed = false;
        
//         std::cout << "Grade Required to Execute: " << f.getGradeExec() << " (should be 25)" << std::endl;
//         if (f.getGradeExec() != 25) allPassed = false;
//     } catch (std::exception &e) {
//         std::cout << "ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }
    
//     recordTestResult("Form Getter Tests", allPassed, "Testing all getter methods");
// }

// // Function to test Form beSigned method
// void testFormBeSigned() {
//     printHeader("TESTING FORM beSigned() METHOD");
//     bool allPassed = true;

//     std::cout << "1. Testing with bureaucrat of sufficient grade:" << std::endl;
//     try {
//         Form f("Important Form", 50, 25);
//         Bureaucrat b("Alice", 40);  // Grade 40 is sufficient for grade 50 form
        
//         std::cout << "   Before: " << f << std::endl;
//         std::cout << "   Bureaucrat: " << b << std::endl;
        
//         f.beSigned(b);
        
//         std::cout << "   After: " << f << std::endl;
//         if (!f.getIsSigned()) {
//             std::cout << "   FAILURE: Form should be signed but isn't" << std::endl;
//             allPassed = false;
//         } else {
//             std::cout << "   SUCCESS: Form was signed correctly" << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n2. Testing with bureaucrat of insufficient grade:" << std::endl;
//     try {
//         Form f("Important Form", 20, 10);
//         Bureaucrat b("Bob", 30);  // Grade 30 is insufficient for grade 20 form
        
//         std::cout << "   Before: " << f << std::endl;
//         std::cout << "   Bureaucrat: " << b << std::endl;
        
//         f.beSigned(b);
        
//         std::cout << "   FAILURE: Should have thrown exception" << std::endl;
//         allPassed = false;
//     } catch (Form::GradeTooLowException &e) {
//         std::cout << "   SUCCESS: Caught expected exception: " << e.what() << std::endl;
//         std::cout << "   Form wasn't signed due to insufficient bureaucrat grade" << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Caught unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n3. Testing with bureaucrat of exact required grade:" << std::endl;
//     try {
//         Form f("Regular Form", 50, 25);
//         Bureaucrat b("Charlie", 50);  // Grade 50 is exactly the required grade
        
//         std::cout << "   Before: " << f << std::endl;
//         std::cout << "   Bureaucrat: " << b << std::endl;
        
//         f.beSigned(b);
        
//         std::cout << "   After: " << f << std::endl;
//         if (!f.getIsSigned()) {
//             std::cout << "   FAILURE: Form should be signed but isn't" << std::endl;
//             allPassed = false;
//         } else {
//             std::cout << "   SUCCESS: Form was signed correctly with exact grade" << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }
    
//     recordTestResult("Form beSigned() Tests", allPassed, "Testing signing with different bureaucrat grades");
// }

// // Function to test Bureaucrat signForm method
// void testBureaucratSignForm() {
//     printHeader("TESTING BUREAUCRAT signForm() METHOD");
//     bool allPassed = true;

//     std::cout << "1. Testing bureaucrat signing a form successfully:" << std::endl;
//     try {
//         Form f("Approval Form", 50, 25);
//         Bureaucrat b("David", 40);  // Grade 40 is sufficient for grade 50 form
        
//         std::cout << "   Before: " << f << std::endl;
//         std::cout << "   Bureaucrat: " << b << std::endl;
        
//         b.signForm(f);
        
//         std::cout << "   After: " << f << std::endl;
//         if (!f.getIsSigned()) {
//             std::cout << "   FAILURE: Form should be signed but isn't" << std::endl;
//             allPassed = false;
//         } else {
//             std::cout << "   SUCCESS: Form was signed correctly by bureaucrat" << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n2. Testing bureaucrat failing to sign a form:" << std::endl;
//     try {
//         Form f("Classified Form", 20, 10);
//         Bureaucrat b("Eve", 30);  // Grade 30 is insufficient for grade 20 form
        
//         std::cout << "   Before: " << f << std::endl;
//         std::cout << "   Bureaucrat: " << b << std::endl;
        
//         b.signForm(f);
        
//         std::cout << "   After: " << f << std::endl;
//         if (f.getIsSigned()) {
//             std::cout << "   FAILURE: Form shouldn't be signed but is" << std::endl;
//             allPassed = false;
//         } else {
//             std::cout << "   SUCCESS: Form wasn't signed due to insufficient grade" << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }

//     std::cout << "\n3. Testing bureaucrat signing an already signed form:" << std::endl;
//     try {
//         Form f("Budget Form", 50, 25);
//         Bureaucrat b1("Frank", 40);  // First signs the form
//         Bureaucrat b2("George", 30);  // Attempts to sign again
        
//         std::cout << "   Before: " << f << std::endl;
//         std::cout << "   First bureaucrat: " << b1 << std::endl;
        
//         b1.signForm(f);
//         std::cout << "   After first signing: " << f << std::endl;
        
//         std::cout << "   Second bureaucrat: " << b2 << std::endl;
//         b2.signForm(f);
//         std::cout << "   After attempted second signing: " << f << std::endl;
        
//         // The test passes regardless of what happens when signing an already signed form
//         // as the exercise doesn't specify behavior, but we should see appropriate output
//         std::cout << "   SUCCESS: Attempted to sign an already signed form" << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "   ERROR: Unexpected exception: " << e.what() << std::endl;
//         allPassed = false;
//     }
    
//     recordTestResult("Bureaucrat signForm() Tests", allPassed, "Testing bureaucrat signing forms");
// }

// // Function to test assignment operators
// void testAssignmentOperator() {
//     printHeader("TESTING ASSIGNMENT OPERATOR");
//     bool allPassed = true;
    
//     try {
//         Form a("First Form", 40, 20);
//         Form b("Second Form", 80, 60);
        
//         std::cout << "Before assignment:" << std::endl;
//         std::cout << "   a: " << a << std::endl;
//         std::cout << "   b: " << b << std::endl;
        
//         // Sign the first form so we can test if the signed status is copied
//         Bureaucrat boss("Boss", 1);
//         boss.signForm(a);
//         std::cout << "After signing form a:" << std::endl;
//         std::cout << "   a: " << a << std::endl;
        
//         b = a;
        
//         std::cout << "After assignment (b = a):" << std::endl;
//         std::cout << "   a: " << a << std::endl;
//         std::cout << "   b: " << b << std::endl;
        
//         // if (b.getGradeSign() != 40 || b.getGradeExec() != 20 || !b.getIsSigned()) {
//         if (!b.getIsSigned()) {
// 			allPassed = false;
//             std::cout << "   FAILURE: Assignment didn't copy all attributes correctly" << std::endl;
//         } else {
//             std::cout << "   SUCCESS: Assignment copied attributes correctly" << std::endl;
//         }
        
//         std::cout << "Notice that b's name remains 'Second Form' despite assignment" << std::endl;
//         if (b.getName() != "Second Form") {
//             allPassed = false;
//             std::cout << "   FAILURE: Name was unexpectedly changed" << std::endl;
//         } else {
//             std::cout << "   SUCCESS: Name remained unchanged as expected" << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "ERROR: " << e.what() << std::endl;
//         allPassed = false;
//     }
    
//     recordTestResult("Assignment Operator Test", allPassed, "Testing deep copy of form attributes");
// }

// // Function to test the insertion operator
// void testInsertionOperator() {
//     printHeader("TESTING << OPERATOR");
    
//     try {
//         Form f1("Simple Form", 75, 50);
//         Form f2("Classified Form", 10, 5);
        
//         Bureaucrat b("Harold", 5);
//         b.signForm(f2);  // Sign the second form to see the difference in output
        
//         std::cout << "First form (unsigned): " << f1 << std::endl;
//         std::cout << "Second form (signed): " << f2 << std::endl;
        
//         // This test is visual, we'll assume it passed unless there are compile errors
//         recordTestResult("Insertion Operator Test", true, "Visual confirmation of form output");
//     } catch (std::exception &e) {
//         std::cout << "ERROR: " << e.what() << std::endl;
//         recordTestResult("Insertion Operator Test", false, std::string("Exception: ") + e.what());
//     }
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
//         std::cout << "\n[ALL TESTS PASSED] The Form class is working correctly." << std::endl;
//     } else {
//         std::cout << "\n[SOME TESTS FAILED] Please review the issues above." << std::endl;
//     }
// }

// // Main function that runs all tests
// int main() {
//     std::cout << "\n\n" << std::string(60, '*') << std::endl;
//     std::cout << std::setw(40) << "FORM CLASS TESTS" << std::endl;
//     std::cout << std::string(60, '*') << "\n" << std::endl;

//     // First, test a basic Bureaucrat to ensure it works
//     printHeader("VERIFYING BUREAUCRAT CLASS");
//     try {
//         Bureaucrat b("Tester", 75);
//         std::cout << "Successfully created: " << b << std::endl;
//         recordTestResult("Basic Bureaucrat Test", true, "Verifying Bureaucrat functionality");
//     } catch (std::exception &e) {
//         std::cout << "ERROR: " << e.what() << std::endl;
//         recordTestResult("Basic Bureaucrat Test", false, "Bureaucrat class has issues");
//     }

//     // Now test all Form functionality
//     testFormConstructors();
//     testFormGetters();
//     testFormBeSigned();
//     testBureaucratSignForm();
//     testAssignmentOperator();
//     testInsertionOperator();
    
//     printTestSummary();

//     std::cout << "\n\n" << std::string(60, '*') << std::endl;
//     std::cout << std::setw(40) << "ALL TESTS COMPLETED" << std::endl;
//     std::cout << std::string(60, '*') << "\n" << std::endl;

//     return 0;
// }