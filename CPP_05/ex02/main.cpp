/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:51:59 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/09 23:09:29 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
// std::cin.get();

	Bureaucrat merz("Merz", 1);   //TEST BUREAU CAN SIGN AND EXECUTE
	// Bureaucrat merz("Merz", 142); //TEST BUREAU CAN SIGN BUT NOT EXECUTE
	// Bureaucrat merz("Merz", 150); //TEST BUREU CAN'T SIGN NOR EXECUTE

	AForm* shrubbery = new ShrubberyCreationForm("zzztreezzz");
	std::cout << *shrubbery << std::endl << std::endl;
	
	merz.signForm(*shrubbery);
	std::cout << *shrubbery << std::endl << std::endl;
	
	merz.executeForm(*shrubbery);
	std::cout << std::endl;

std::cin.get();	

	AForm* robotomy = new RobotomyRequestForm("robot");
	std::cout << *robotomy << std::endl << std::endl;
std::cin.get();
	merz.signForm(*robotomy);
	std::cout << *robotomy << std::endl << std::endl;
	
std::cin.get();
	merz.executeForm(*robotomy);
	std::cout << "1" << std::endl;
std::cin.get();
	merz.executeForm(*robotomy);
	std::cout << "2" << std::endl;
std::cin.get();
	merz.executeForm(*robotomy);
	std::cout << "3" << std::endl;
std::cin.get();
	merz.executeForm(*robotomy);
	std::cout << "4" << std::endl;

std::cin.get();

	AForm* presidential = new PresidentialPardonForm("Presida");
	std::cout << *presidential << std::endl << std::endl;

	merz.signForm(*presidential);
	std::cout << *presidential << std::endl << std::endl;
	
	merz.executeForm(*presidential);
	std::cout << *presidential << std::endl << std::endl;
	
	delete presidential;
	delete robotomy;
	delete shrubbery;
}

//COMPLETE TESTING

// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
// #include <iostream>
// #include <iomanip>
// #include <vector>
// #include <cstdlib>
// #include <ctime>

// // Struct to track test results
// struct TestResult {
//     std::string testName;
//     bool passed;
//     std::string notes;
// };

// // Global vector to track test results
// std::vector<TestResult> testResults;

// // Function to record test results
// void recordTestResult(const std::string& testName, bool passed, const std::string& notes) {
//     TestResult result;
//     result.testName = testName;
//     result.passed = passed;
//     result.notes = notes;
//     testResults.push_back(result);
// }

// // Function to print dividers for better output readability
// void printDivider(const std::string& title) {
//     std::cout << "\n" << std::string(50, '*') << std::endl;
//     std::cout << "* " << title << std::endl;
//     std::cout << std::string(50, '*') << "\n" << std::endl;
// }

// // Function to print test summary
// void printTestSummary() {
//     printDivider("TEST RESULTS SUMMARY");
    
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
//         std::cout << "\n[ALL TESTS PASSED] All form classes are working correctly." << std::endl;
//     } else {
//         std::cout << "\n[SOME TESTS FAILED] Please review the failures above." << std::endl;
//     }
// }

// // Test ShrubberyCreationForm
// void testShrubberyCreationForm() {
//     printDivider("TESTING SHRUBBERY CREATION FORM");
//     bool success = true;
//     std::string notes = "Files should be created with ASCII trees";
    
//     try {
//         // Create forms with different targets
//         ShrubberyCreationForm form1("garden");
//         ShrubberyCreationForm form2("park");
        
//         // Create bureaucrats with different grades
//         Bureaucrat highLevel("Executive", 1);      // Can sign and execute all forms
//         Bureaucrat midLevel("Manager", 100);       // Can sign Shrubbery but not execute all
//         Bureaucrat lowLevel("Intern", 150);        // Cannot sign or execute any forms
        
//         std::cout << "Forms created:" << std::endl;
//         std::cout << form1 << std::endl;
//         std::cout << form2 << std::endl;
        
//         std::cout << "\nTrying to execute without signing first:" << std::endl;
//         try {
//             highLevel.executeForm(form1);
//         } catch (std::exception& e) {
//             std::cout << "Exception: " << e.what() << std::endl;
//         }
        
//         std::cout << "\nSigning forms:" << std::endl;
        
//         // Low level bureaucrat tries to sign (should fail)
//         lowLevel.signForm(form1);
        
//         // Mid level bureaucrat tries to sign (should succeed)
//         midLevel.signForm(form1);
        
//         // High level bureaucrat signs the second form
//         highLevel.signForm(form2);
        
//         std::cout << "\nAfter signing attempts:" << std::endl;
//         std::cout << form1 << std::endl;
//         std::cout << form2 << std::endl;
        
//         std::cout << "\nExecuting forms:" << std::endl;
        
//         // Mid level tries to execute (should fail - grade too low)
//         midLevel.executeForm(form1);
        
//         // Low level tries to execute (should fail - grade too low)
//         lowLevel.executeForm(form2);
        
//         // High level executes both forms (should succeed)
//         highLevel.executeForm(form1);
//         highLevel.executeForm(form2);
        
//         std::cout << "\nChecking if files were created (you can verify the content manually)" << std::endl;
        
//         recordTestResult("ShrubberyCreationForm", success, notes);
//     } catch (std::exception& e) {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//         recordTestResult("ShrubberyCreationForm", false, std::string("Unexpected exception: ") + e.what());
//     }
// }

// // Test RobotomyRequestForm
// void testRobotomyRequestForm() {
//     printDivider("TESTING ROBOTOMY REQUEST FORM");
//     bool success = true;
//     std::string notes = "Should make drilling noises and have 50% success rate";
    
//     try {
//         // Seed random number generator for robotomy success/failure
//         std::srand(static_cast<unsigned int>(std::time(NULL)));
        
//         // Create forms with different targets
//         RobotomyRequestForm form1("Bender");
//         RobotomyRequestForm form2("R2D2");
        
//         // Create bureaucrats with different grades
//         Bureaucrat president("President", 1);       // Can sign and execute all forms
//         Bureaucrat director("Director", 50);        // Can sign but not execute Robotomy
//         Bureaucrat assistant("Assistant", 100);     // Cannot sign or execute Robotomy
        
//         std::cout << "Forms created:" << std::endl;
//         std::cout << form1 << std::endl;
//         std::cout << form2 << std::endl;
        
//         std::cout << "\nSigning forms:" << std::endl;
        
//         // Assistant tries to sign (should fail)
//         assistant.signForm(form1);
        
//         // Director tries to sign (should succeed)
//         director.signForm(form1);
        
//         // President signs the second form
//         president.signForm(form2);
        
//         std::cout << "\nAfter signing attempts:" << std::endl;
//         std::cout << form1 << std::endl;
//         std::cout << form2 << std::endl;
        
//         std::cout << "\nExecuting forms:" << std::endl;
        
//         // Director tries to execute (should fail - grade too low)
//         director.executeForm(form1);
        
//         // President executes both forms (should succeed with 50% chance each)
//         president.executeForm(form1);
//         president.executeForm(form2);
        
//         // Execute a few more times to demonstrate the randomness
//         std::cout << "\nExecuting multiple times to show randomness:" << std::endl;
//         for (int i = 0; i < 3; ++i) {
//             president.executeForm(form1);
//         }
        
//         recordTestResult("RobotomyRequestForm", success, notes);
//     } catch (std::exception& e) {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//         recordTestResult("RobotomyRequestForm", false, std::string("Unexpected exception: ") + e.what());
//     }
// }

// // Test PresidentialPardonForm
// void testPresidentialPardonForm() {
//     printDivider("TESTING PRESIDENTIAL PARDON FORM");
//     bool success = true;
//     std::string notes = "Should pardon target by Zaphod Beeblebrox";
    
//     try {
//         // Create forms with different targets
//         PresidentialPardonForm form1("Arthur Dent");
//         PresidentialPardonForm form2("Ford Prefect");
        
//         // Create bureaucrats with different grades
//         Bureaucrat president("Zaphod", 1);         // Can sign and execute all forms
//         Bureaucrat vicePresident("VP", 15);        // Can sign but not execute Presidential
//         Bureaucrat secretary("Secretary", 30);     // Cannot sign or execute Presidential
        
//         std::cout << "Forms created:" << std::endl;
//         std::cout << form1 << std::endl;
//         std::cout << form2 << std::endl;
        
//         std::cout << "\nSigning forms:" << std::endl;
        
//         // Secretary tries to sign (should fail)
//         secretary.signForm(form1);
        
//         // VP tries to sign (should succeed)
//         vicePresident.signForm(form1);
        
//         // President signs the second form
//         president.signForm(form2);
        
//         std::cout << "\nAfter signing attempts:" << std::endl;
//         std::cout << form1 << std::endl;
//         std::cout << form2 << std::endl;
        
//         std::cout << "\nExecuting forms:" << std::endl;
        
//         // VP tries to execute (should fail - grade too low)
//         vicePresident.executeForm(form1);
        
//         // Secretary tries to execute (should fail - grade too low)
//         secretary.executeForm(form1);
        
//         // President executes both forms (should succeed)
//         president.executeForm(form1);
//         president.executeForm(form2);
        
//         recordTestResult("PresidentialPardonForm", success, notes);
//     } catch (std::exception& e) {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//         recordTestResult("PresidentialPardonForm", false, std::string("Unexpected exception: ") + e.what());
//     }
// }

// // Test copy and assignment
// void testFormCopyAndAssignment() {
//     printDivider("TESTING FORM COPY AND ASSIGNMENT");
//     bool success = true;
//     std::string notes = "Copied and assigned forms should maintain signed state";
    
//     try {
//         // Create original forms
//         ShrubberyCreationForm shrubbery1("original_garden");
//         RobotomyRequestForm robotomy1("original_robot");
//         PresidentialPardonForm pardon1("original_criminal");
        
//         // Create bureaucrat to sign the forms
//         Bureaucrat boss("Boss", 1);
//         boss.signForm(shrubbery1);
//         boss.signForm(robotomy1);
//         boss.signForm(pardon1);
        
//         std::cout << "Original forms (all signed):" << std::endl;
//         std::cout << shrubbery1 << std::endl;
//         std::cout << robotomy1 << std::endl;
//         std::cout << pardon1 << std::endl;
        
//         // Test copy constructor
//         std::cout << "\nCreating copies with copy constructor:" << std::endl;
//         ShrubberyCreationForm shrubbery2(shrubbery1);
//         RobotomyRequestForm robotomy2(robotomy1);
//         PresidentialPardonForm pardon2(pardon1);
        
//         std::cout << "Copied forms:" << std::endl;
//         std::cout << shrubbery2 << std::endl;
//         std::cout << robotomy2 << std::endl;
//         std::cout << pardon2 << std::endl;
        
//         // Test assignment operator
//         std::cout << "\nCreating forms for assignment:" << std::endl;
//         ShrubberyCreationForm shrubbery3("unused_garden");
//         RobotomyRequestForm robotomy3("unused_robot");
//         PresidentialPardonForm pardon3("unused_criminal");
        
//         std::cout << "Before assignment:" << std::endl;
//         std::cout << shrubbery3 << std::endl;
//         std::cout << robotomy3 << std::endl;
//         std::cout << pardon3 << std::endl;
        
//         std::cout << "\nAssigning original forms to new forms:" << std::endl;
//         shrubbery3 = shrubbery1;
//         robotomy3 = robotomy1;
//         pardon3 = pardon1;
        
//         std::cout << "After assignment:" << std::endl;
//         std::cout << shrubbery3 << std::endl;
//         std::cout << robotomy3 << std::endl;
//         std::cout << pardon3 << std::endl;
        
//         // Execute copies to verify they work properly
//         std::cout << "\nExecuting copied forms:" << std::endl;
//         boss.executeForm(shrubbery2);
//         boss.executeForm(robotomy2);
//         boss.executeForm(pardon2);
//         boss.executeForm(shrubbery3);
        
//         recordTestResult("Form Copy & Assignment", success, notes);
//     } catch (std::exception& e) {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//         recordTestResult("Form Copy & Assignment", false, std::string("Unexpected exception: ") + e.what());
//     }
// }

// // Test edge cases
// void testEdgeCases() {
//     printDivider("TESTING EDGE CASES");
//     bool success = true;
//     std::string notes = "Tests unsigned forms, already signed forms";
    
//     try {
//         // Test with invalid grades (should be caught by AForm constructor)
//         std::cout << "Testing creation with invalid grades (should throw exceptions):" << std::endl;
        
//         try {
//             // These would be tested if we could create AForm directly, but since it's abstract,
//             // we'll just mention that the concrete classes should validate these through AForm
//             std::cout << "Note: Grade validations should be handled by AForm constructor" << std::endl;
//             std::cout << "      which is called by the concrete form constructors" << std::endl;
//         } catch (std::exception& e) {
//             std::cout << "Exception as expected: " << e.what() << std::endl;
//         }
        
//         // Test executing a form that isn't signed
//         std::cout << "\nTesting execution of unsigned form:" << std::endl;
//         ShrubberyCreationForm unsignedForm("unsigned");
//         Bureaucrat ceo("CEO", 1);
        
//         try {
//             ceo.executeForm(unsignedForm);
//         } catch (std::exception& e) {
//             std::cout << "Exception as expected: " << e.what() << std::endl;
//         }
        
//         // Test signing an already signed form
//         std::cout << "\nTesting signing an already signed form:" << std::endl;
//         ShrubberyCreationForm signedForm("already_signed");
//         ceo.signForm(signedForm);
//         std::cout << "Form after first signing: " << signedForm << std::endl;
//         ceo.signForm(signedForm);
//         std::cout << "Form after second signing attempt: " << signedForm << std::endl;
        
//         recordTestResult("Edge Cases", success, notes);
//     } catch (std::exception& e) {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//         recordTestResult("Edge Cases", false, std::string("Unexpected exception: ") + e.what());
//     }
// }

// // Basic functionality test
// void testBasicFunctionality() {
//     printDivider("TESTING BASIC FUNCTIONALITY");
//     bool success = true;
//     std::string notes = "Tests all three forms with a high-level bureaucrat";
    
//     try {
//         Bureaucrat merz("Merz", 1);   // Can sign and execute all forms
        
//         // Test Shrubbery Creation Form
//         AForm* shrubbery = new ShrubberyCreationForm("test_trees");
//         std::cout << "Shrubbery Form before signing:\n" << *shrubbery << std::endl;
        
//         merz.signForm(*shrubbery);
//         std::cout << "After signing:\n" << *shrubbery << std::endl;
        
//         merz.executeForm(*shrubbery);
//         std::cout << std::endl;
        
//         // Test Robotomy Request Form
//         AForm* robotomy = new RobotomyRequestForm("test_robot");
//         std::cout << "Robotomy Form before signing:\n" << *robotomy << std::endl;
        
//         merz.signForm(*robotomy);
//         std::cout << "After signing:\n" << *robotomy << std::endl;
        
//         std::cout << "Executing robotomy multiple times to demonstrate randomness:" << std::endl;
//         merz.executeForm(*robotomy);
//         merz.executeForm(*robotomy);
        
//         // Test Presidential Pardon Form
//         AForm* presidential = new PresidentialPardonForm("test_pardon");
//         std::cout << "Presidential Form before signing:\n" << *presidential << std::endl;
        
//         merz.signForm(*presidential);
//         std::cout << "After signing:\n" << *presidential << std::endl;
        
//         merz.executeForm(*presidential);
        
//         // Clean up memory
//         delete presidential;
//         delete robotomy;
//         delete shrubbery;
        
//         recordTestResult("Basic Functionality", success, notes);
//     } catch (std::exception& e) {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//         recordTestResult("Basic Functionality", false, std::string("Unexpected exception: ") + e.what());
//     }
// }

// int main() {
//     // Set random seed for robotomy
//     std::srand(static_cast<unsigned int>(std::time(NULL)));
    
//     std::cout << "\n====== BUREAUCRAT FORM TESTING PROGRAM ======\n" << std::endl;
    
//     // Basic functionality first
//     testBasicFunctionality();
    
//     // Then more comprehensive tests
//     testShrubberyCreationForm();
//     testRobotomyRequestForm();
//     testPresidentialPardonForm();
//     testFormCopyAndAssignment();
//     testEdgeCases();
    
//     // Print test summary at the end
//     printTestSummary();
    
//     printDivider("ALL TESTS COMPLETED");
    
//     return 0;
// }