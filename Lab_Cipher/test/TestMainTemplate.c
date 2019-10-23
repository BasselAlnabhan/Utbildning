/*
 *  TestMainTemplate.c
 *  Created on: 16 Sep 2019
 *  Author: Bassel Alnabhan
 */
#include <stdio.h>

#include "SimpleCTester.h"

/// supply path to .h file holding function headers of your test target
#include "C:\YA C programming\GitTry\Lab_Cipher\src\Cipher.h"

SimpleTest_Initialize()					// Counters for all tests are reset here

/*********************************** Tests ***********************************/

/// supply name of your test as parameter
SimpleTest_CreateTest(letters_test1)  	// Single test defined
{
	/// define your test by calling functions from test target
	char input[] = {'i',' ','a','n','d',' ','3','5','7',' ','x',' ','z','\0'};
	int letters = letters_evaluate(input);

	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertInteger(letters,6,"letters evaluation fault");

}

SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(letters_test2)  	// Single test defined
{
	/// define your test by calling functions from test target
	char input[] = {'1','e','r','a','w',' ','5','2',' ','l','w','7','x','\0'};
	int letters = letters_evaluate(input);

	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertInteger(letters,7,"letters evaluation fault");

}

SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(digit_test1)  	// Single test defined
{
	/// define your test by calling functions from test target
	char input[] = {'1','e','r','a','w',' ','5','2',' ','l','w','7','x','\0'};
	int letters = letters_evaluate(input);
	digits_modify(input,letters);

	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertTrue((input[0] == '8'),"digits modification fault");

}

SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(digit_test2)  	// Single test defined
{
	/// define your test by calling functions from test target
	char input[] = {'i',' ','a','n','d',' ','3','5','7',' ','x',' ','z','\0'};
	int letters = letters_evaluate(input);
	digits_modify(input,letters);

	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertTrue((input[8] == '3'),"digits modification fault");

}

SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(space_test1)  	// Single test defined
{
	/// define your test by calling functions from test target
	char input[] = {'i',' ','a','n','d',' ','3','5','7',' ','x',' ','z','\0'};
	int letters = letters_evaluate(input);
	digits_modify(input,letters);
	space_replace(input);

	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertTrue((input[11] == 'j'),"digits modification fault");

}

SimpleTest_FinalizeTest()				// End of test
/// Repeat the pattern above for all your tests for test target

/*********************************** Batch ***********************************/

// This is where we add up all tests to be run
static char* test_batch()
{
    /// supply info for presentation of outcome of test batch
    printf("\n Running tests for %s \n","Cipher_test");

    /// supply name of each test as parameter
    SimpleTest_RunTest(letters_test1);	// One test runs
    SimpleTest_RunTest(letters_test2);	// One test runs
    SimpleTest_RunTest(digit_test1);	// One test runs
    SimpleTest_RunTest(digit_test2);	// One test runs
    SimpleTest_RunTest(space_test1);	// One test runs
    return NULL;
}

/************************** Test application main ****************************/
int main(int argc, char **argv)
{
    test_batch();						// complete batch of tests will be run

    printf("\n\n Tests completed: %d", SimpleTestCounter);	// always present total number of tests run

    if( SimpleTestFailCounter == 0){
    	printf("\n All tests passed!"); 			// if batch is successful
    }
    else{
    	printf("\n Tests failed: %d", SimpleTestFailCounter); 	// otherwise the first failed test will be presented
    }

    return 0;
}
