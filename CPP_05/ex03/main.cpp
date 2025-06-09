/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:35:07 by demrodri          #+#    #+#             */
/*   Updated: 2025/06/09 23:29:06 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

// void test()
int main()
{
	Bureaucrat lula("Lula", 5);
	Intern someIntern;

	AForm* shrubbery = someIntern.makeForm("shrubbery creation", "zzztreezzz");
	AForm* robotomy = someIntern.makeForm("robotomy request", "robo");
	AForm* presidential = someIntern.makeForm("presidential pardon", "lula");
	
	someIntern.makeForm("makeMoney request", "lula");

	std::cout << lula << std::endl;
	std::cout << std::endl;

	std::cout << *shrubbery << std::endl;
	lula.signForm(*shrubbery);
	std::cout << *shrubbery << std::endl;
	lula.executeForm(*shrubbery);
	std::cout << std::endl;

	std::cout << *robotomy << std::endl;
	lula.signForm(*robotomy);
	std::cout << *robotomy << std::endl;
	lula.executeForm(*robotomy);
	std::cout << std::endl;

	std::cout << *presidential << std::endl;
	lula.signForm(*presidential);
	std::cout << *presidential << std::endl;
	lula.executeForm(*presidential);
	std::cout << std::endl;

std::cin.get();

	Intern	someRandomIntern;
	AForm*	rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;

std::cin.get();
	
	delete rrf;
	delete presidential;
	delete robotomy;
	delete shrubbery;
}

// COMPLETE TESTING

// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
// #include "Intern.hpp"
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
//     std::vector<std::string> errors; // Added to track specific errors
// };

// // Global vector to track test results
// std::vector<TestResult> testResults;
// TestResult* currentTest = NULL; // Pointer to the current test being executed

// // Function to start a new test
// void startTest(const std::string& testName, const std::string& notes) {
//     TestResult result;
//     result.testName = testName;
//     result.passed = true; // Start optimistic
//     result.notes = notes;
//     testResults.push_back(result);
//     currentTest = &testResults.back();
    
//     std::cout << "\n" << std::string(50, '*') << std::endl;
//     std::cout << "* STARTING TEST: " << testName << std::endl;
//     std::cout << "* " << notes << std::endl;
//     std::cout << std::string(50, '*') << "\n" << std::endl;
// }

// // Function to record an error in the current test
// void recordError(const std::string& errorMessage) {
//     if (currentTest) {
//         currentTest->passed = false;
//         currentTest->errors.push_back(errorMessage);
        
//         // Immediate visible error feedback
//         std::cout << "\033[1;31m[ERROR]\033[0m " << errorMessage << std::endl;
//     }
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
//                   << std::setw(10) << (result.passed ? "\033[1;32mPASSED\033[0m" : "\033[1;31mFAILED\033[0m") 
//                   << result.notes << std::endl;
        
//         // Print specific errors if the test failed
//         if (!result.passed) {
//             std::cout << "  \033[1;31mErrors found:\033[0m" << std::endl;
//             for (size_t j = 0; j < result.errors.size(); ++j) {
//                 std::cout << "   - " << result.errors[j] << std::endl;
//             }
//         }
        
//         if (result.passed) passed++;
//         else failed++;
//     }
    
//     std::cout << std::string(70, '-') << std::endl;
//     std::cout << "TOTAL TESTS: " << testResults.size() << std::endl;
//     std::cout << "PASSED: " << "\033[1;32m" << passed << "\033[0m" << std::endl;
//     std::cout << "FAILED: " << (failed > 0 ? "\033[1;31m" : "") << failed << (failed > 0 ? "\033[0m" : "") << std::endl;
    
//     if (failed == 0) {
//         std::cout << "\n\033[1;32m[ALL TESTS PASSED] All classes are working correctly.\033[0m" << std::endl;
//     } else {
//         std::cout << "\n\033[1;31m[SOME TESTS FAILED] Please review the failures above.\033[0m" << std::endl;
//     }
// }

// // Test for memory leaks
// void testForMemoryLeaks() {
//     startTest("Memory Management", "Basic memory allocation/deallocation tests");
    
//     std::cout << "To thoroughly test for memory leaks, run this program with Valgrind:" << std::endl;
//     std::cout << "   valgrind --leak-check=full --show-leak-kinds=all ./bureaucrat" << std::endl << std::endl;
    
//     std::cout << "Creating and destroying multiple objects to stress test memory management..." << std::endl;
    
//     try {
//         // Create and destroy some objects in various ways
//         for (int i = 0; i < 5; i++) {
//             // Stack allocation
//             ShrubberyCreationForm shrub("test_shrub");
//             RobotomyRequestForm robot("test_robot");
//             PresidentialPardonForm pardon("test_pardon");
//             Intern intern;
            
//             // Heap allocation with polymorphism
//             AForm* forms[3];
//             forms[0] = new ShrubberyCreationForm("heap_shrub");
//             forms[1] = new RobotomyRequestForm("heap_robot");
//             forms[2] = new PresidentialPardonForm("heap_pardon");
            
//             // Use intern to create forms with exact names
//             AForm* internForm1 = intern.makeForm("shrubbery creation", "intern_shrub");
//             AForm* internForm2 = intern.makeForm("robotomy request", "intern_robot");
//             AForm* internForm3 = intern.makeForm("presidential pardon", "intern_pardon");
            
//             if (!internForm1) recordError("Intern failed to create shrubbery form");
//             if (!internForm2) recordError("Intern failed to create robotomy form");
//             if (!internForm3) recordError("Intern failed to create presidential pardon form");
            
//             // Clean up
//             for (int j = 0; j < 3; j++) {
//                 delete forms[j];
//             }
            
//             delete internForm1;
//             delete internForm2;
//             delete internForm3;
//         }
        
//         std::cout << "Memory test completed. Any leaks would be detected by Valgrind." << std::endl;
//     } catch (std::exception& e) {
//         recordError(std::string("Unexpected exception: ") + e.what());
//     }
// }

// // Basic functionality test
// void testBasicFunctionality() {
//     startTest("Basic Functionality", "Tests all three forms with a high-level bureaucrat");
    
//     try {
//         Bureaucrat merz("Merz", 1);   // Can sign and execute all forms
        
//         // Test Shrubbery Creation Form
//         AForm* shrubbery = new ShrubberyCreationForm("test_trees");
//         if (!shrubbery) {
//             recordError("Failed to create ShrubberyCreationForm");
//             return;
//         }
//         std::cout << "Shrubbery Form before signing:\n" << *shrubbery << std::endl;
        
//         merz.signForm(*shrubbery);
//         std::cout << "After signing:\n" << *shrubbery << std::endl;
        
//         // Check if form was actually signed
//         if (!shrubbery->getIsSigned()) {
//             recordError("Bureaucrat failed to sign ShrubberyCreationForm");
//         }
        
//         merz.executeForm(*shrubbery);
//         std::cout << std::endl;
        
//         // Test Robotomy Request Form
//         AForm* robotomy = new RobotomyRequestForm("test_robot");
//         if (!robotomy) {
//             recordError("Failed to create RobotomyRequestForm");
//             delete shrubbery;
//             return;
//         }
//         std::cout << "Robotomy Form before signing:\n" << *robotomy << std::endl;
        
//         merz.signForm(*robotomy);
//         std::cout << "After signing:\n" << *robotomy << std::endl;
        
//         // Check if form was actually signed
//         if (!robotomy->getIsSigned()) {
//             recordError("Bureaucrat failed to sign RobotomyRequestForm");
//         }
        
//         std::cout << "Executing robotomy multiple times to demonstrate randomness:" << std::endl;
//         merz.executeForm(*robotomy);
//         merz.executeForm(*robotomy);
        
//         // Test Presidential Pardon Form
//         AForm* presidential = new PresidentialPardonForm("test_pardon");
//         if (!presidential) {
//             recordError("Failed to create PresidentialPardonForm");
//             delete shrubbery;
//             delete robotomy;
//             return;
//         }
//         std::cout << "Presidential Form before signing:\n" << *presidential << std::endl;
        
//         merz.signForm(*presidential);
//         std::cout << "After signing:\n" << *presidential << std::endl;
        
//         // Check if form was actually signed
//         if (!presidential->getIsSigned()) {
//             recordError("Bureaucrat failed to sign PresidentialPardonForm");
//         }
        
//         merz.executeForm(*presidential);
        
//         // Clean up memory
//         delete presidential;
//         delete robotomy;
//         delete shrubbery;
//     } catch (std::exception& e) {
//         recordError(std::string("Unexpected exception: ") + e.what());
//     }
// }

// // Test Intern functionality
// void testIntern() {
//     startTest("Intern Functionality", "Tests intern creating all form types and handling invalid requests");
    
//     try {
//         Intern intern;
//         Bureaucrat boss("Boss", 1);
        
//         std::cout << "Testing valid form creation:" << std::endl;
        
//         // Test creating shrubbery form
//         std::cout << "\n1. Creating shrubbery creation form:" << std::endl;
//         AForm* shrubForm = intern.makeForm("shrubbery creation", "Garden");
        
//         if (shrubForm) {
//             std::cout << "Form created successfully: " << *shrubForm << std::endl;
            
//             // Verify form type
//             ShrubberyCreationForm* testCast = dynamic_cast<ShrubberyCreationForm*>(shrubForm);
//             if (!testCast) {
//                 recordError("Form is not a proper ShrubberyCreationForm");
//             }
            
//             boss.signForm(*shrubForm);
//             if (!shrubForm->getIsSigned()) {
//                 recordError("Failed to sign ShrubberyCreationForm");
//             }
            
//             boss.executeForm(*shrubForm);
//             delete shrubForm;
//         } else {
//             recordError("Failed to create shrubbery form");
//         }
        
//         // Test creating robotomy form
//         std::cout << "\n2. Creating robotomy request form:" << std::endl;
//         AForm* robotForm = intern.makeForm("robotomy request", "Bender");
        
//         if (robotForm) {
//             std::cout << "Form created successfully: " << *robotForm << std::endl;
            
//             // Verify form type
//             RobotomyRequestForm* testCast = dynamic_cast<RobotomyRequestForm*>(robotForm);
//             if (!testCast) {
//                 recordError("Form is not a proper RobotomyRequestForm");
//             }
            
//             boss.signForm(*robotForm);
//             if (!robotForm->getIsSigned()) {
//                 recordError("Failed to sign RobotomyRequestForm");
//             }
            
//             boss.executeForm(*robotForm);
//             delete robotForm;
//         } else {
//             recordError("Failed to create robotomy form");
//         }
        
//         // Test creating presidential pardon form
//         std::cout << "\n3. Creating presidential pardon form:" << std::endl;
//         AForm* pardonForm = intern.makeForm("presidential pardon", "Zaphod");
        
//         if (pardonForm) {
//             std::cout << "Form created successfully: " << *pardonForm << std::endl;
            
//             // Verify form type
//             PresidentialPardonForm* testCast = dynamic_cast<PresidentialPardonForm*>(pardonForm);
//             if (!testCast) {
//                 recordError("Form is not a proper PresidentialPardonForm");
//             }
            
//             boss.signForm(*pardonForm);
//             if (!pardonForm->getIsSigned()) {
//                 recordError("Failed to sign PresidentialPardonForm");
//             }
            
//             boss.executeForm(*pardonForm);
//             delete pardonForm;
//         } else {
//             recordError("Failed to create presidential pardon form");
//         }
        
//         // Test with an invalid form name
//         std::cout << "\n4. Testing with invalid form name:" << std::endl;
//         AForm* invalidForm = intern.makeForm("coffee making", "Office");
        
//         if (invalidForm) {
//             recordError("Created a form for invalid name 'coffee making'");
//             delete invalidForm;
//         } else {
//             std::cout << "SUCCESS: Correctly handled invalid form name" << std::endl;
//         }
        
//     } catch (std::exception& e) {
//         recordError(std::string("Unexpected exception: ") + e.what());
//     }
// }

// // Test example from subject
// void testSubjectExample() {
//     startTest("Subject Example", "Direct test of the example provided in the subject");
    
//     try {
//         std::cout << "Running the exact example from the subject:" << std::endl;
//         std::cout << "{ Intern someRandomIntern; AForm* rrf; rrf = someRandomIntern.makeForm(\"robotomy request\", \"Bender\"); }" << std::endl;
//         std::cout << std::endl;
        
//         {
//             Intern someRandomIntern;
//             AForm* rrf;
//             rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            
//             if (rrf) {
//                 std::cout << "Form details: " << *rrf << std::endl;
                
//                 // Verify the target is set correctly
//                 if (rrf->getTarget() != "Bender") {
//                     recordError("Form target was not set to 'Bender'");
//                 }
                
//                 // Test execution with the form
//                 std::cout << "Testing form execution:" << std::endl;
//                 Bureaucrat highRanking("CEO", 1);
//                 highRanking.signForm(*rrf);
                
//                 if (!rrf->getIsSigned()) {
//                     recordError("Form was not properly signed");
//                 }
                
//                 highRanking.executeForm(*rrf);
                
//                 delete rrf;
//             } else {
//                 recordError("Could not create the form in the subject example");
//             }
//         }
//     } catch (std::exception& e) {
//         recordError(std::string("Unexpected exception: ") + e.what());
//     }
// }

// // Test combined workflow between Intern, Bureaucrat and Forms
// void testWorkflow() {
//     startTest("Office Workflow", "Tests complete office workflow with intern, bureaucrats, and forms");
    
//     try {
//         // Create office staff
//         Intern intern;
//         Bureaucrat clerk("Clerk", 140);       // Low level - can only sign ShrubberyCreationForm
//         Bureaucrat manager("Manager", 50);    // Mid level - can sign and execute ShrubberyCreationForm, sign RobotomyRequestForm
//         Bureaucrat director("Director", 5);   // High level - can sign and execute all forms
        
//         std::cout << "Office staff created:" << std::endl;
//         std::cout << clerk << std::endl;
//         std::cout << manager << std::endl;
//         std::cout << director << std::endl;
        
//         std::cout << "\nIntern prepares forms for processing:" << std::endl;
        
//         // Intern creates various forms
//         AForm* shrubForm = intern.makeForm("shrubbery creation", "Office Garden");
//         AForm* robotForm = intern.makeForm("robotomy request", "Broken Printer");
//         AForm* pardonForm = intern.makeForm("presidential pardon", "Late Employee");
        
//         if (!shrubForm) recordError("Failed to create shrubbery form");
//         if (!robotForm) recordError("Failed to create robotomy form");
//         if (!pardonForm) recordError("Failed to create presidential pardon form");
        
//         // If any form creation failed, stop the test
//         if (!shrubForm || !robotForm || !pardonForm) {
//             if (shrubForm) delete shrubForm;
//             if (robotForm) delete robotForm;
//             if (pardonForm) delete pardonForm;
//             return;
//         }
        
//         std::cout << "\nForms are passed to the office staff for processing:" << std::endl;
        
//         // Clerk attempts to process forms
//         std::cout << "\nClerk attempts to process forms:" << std::endl;
//         clerk.signForm(*shrubForm);      // Should succeed
        
//         // Verify clerk properly signed the form
//         if (!shrubForm->getIsSigned()) {
//             recordError("Clerk (grade 140) failed to sign shrubbery form (min grade 145)");
//         }
        
//         clerk.executeForm(*shrubForm);   // Should fail (not high enough level)
//         clerk.signForm(*robotForm);      // Should fail (not high enough level)
//         clerk.signForm(*pardonForm);     // Should fail (not high enough level)
        
//         // Verify clerk properly failed to sign higher grade forms
//         if (robotForm->getIsSigned()) {
//             recordError("Clerk (grade 140) incorrectly signed robotomy form (min grade 72)");
//         }
        
//         if (pardonForm->getIsSigned()) {
//             recordError("Clerk (grade 140) incorrectly signed presidential form (min grade 25)");
//         }
        
//         // Manager attempts to process forms
//         std::cout << "\nManager attempts to process forms:" << std::endl;
//         manager.executeForm(*shrubForm); // Should succeed for already signed form
//         manager.signForm(*robotForm);    // Should succeed
        
//         // Verify manager properly signed the robotomy form
//         if (!robotForm->getIsSigned()) {
//             recordError("Manager (grade 50) failed to sign robotomy form (min grade 72)");
//         }
        
//         manager.executeForm(*robotForm); // Should fail (not high enough level)
//         manager.signForm(*pardonForm);   // Should fail (not high enough level)
        
//         // Verify manager properly failed to sign higher grade form
//         if (pardonForm->getIsSigned()) {
//             recordError("Manager (grade 50) incorrectly signed presidential form (min grade 25)");
//         }
        
//         // Director processes the remaining forms
//         std::cout << "\nDirector processes remaining forms:" << std::endl;
//         director.executeForm(*robotForm);  // Should succeed for already signed form
//         director.signForm(*pardonForm);    // Should succeed
        
//         // Verify director properly signed the presidential form
//         if (!pardonForm->getIsSigned()) {
//             recordError("Director (grade 5) failed to sign presidential form (min grade 25)");
//         }
        
//         director.executeForm(*pardonForm); // Should succeed
        
//         std::cout << "\nAll forms processed. Office workflow complete." << std::endl;
        
//         // Clean up
//         delete shrubForm;
//         delete robotForm;
//         delete pardonForm;
//     } catch (std::exception& e) {
//         recordError(std::string("Unexpected exception: ") + e.what());
//     }
// }

// // Main function
// int main() {
//     // Set random seed for robotomy
//     std::srand(static_cast<unsigned int>(std::time(NULL)));
    
//     std::cout << "\n====== BUREAUCRACY TESTING PROGRAM (EXERCISE 03) ======\n" << std::endl;
    
//     // Test basic functionality first
//     testBasicFunctionality();
    
//     // Test Intern class - the focus of Exercise 03
//     testIntern();
//     testSubjectExample();
    
//     // Test complete workflow
//     testWorkflow();
    
//     // Test for memory leaks
//     testForMemoryLeaks();
    
//     // Print test summary
//     printTestSummary();
    
//     printDivider("ALL TESTS COMPLETED");
    
//     return 0;
// }