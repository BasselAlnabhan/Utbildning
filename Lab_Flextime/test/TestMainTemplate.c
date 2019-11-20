/*
 *  TestMainTemplate.c
 *  Created on: 16 Sep 2019
 *  Author: Bassel Alnabhan
 */
#include <stdio.h>

#include "SimpleCTester.h"

/// supply path to .h file holding function headers of your test target
#include "C:\YA C programming\C-programming course\Lab_Flextime\src\Flextime.h"

SimpleTest_Initialize()					// Counters for all tests are reset here

/*********************************** Tests ***********************************/

/// supply name of your test as parameter
SimpleTest_CreateTest(test1)  	// Single test defined
{
	/// define your test by calling functions from test target
	char input_string[] = {"308,07,33;308,11,44;308,12,31;308,16,10;"
			"309,07,52;309,11,52;309,12,35;309,16,18;"
			"310,07,24;310,11,40;310,12,30;310,16,14;"
			"311,07,15;311,11,38;311,12,36;311,16,27;"
			"312,07,12;312,11,47;312,12,30;312,16,12;"
			"315,07,12;315,11,34;315,12,27;315,16,52;"
			"316,07,15;316,11,49;316,12,31;316,16,13;"
			"317,07,59;317,11,44;317,12,38;317,16,42;"
		    "318,07,52;318,11,41;318,12,30;318,16,12;"
			"319,08,03;319,11,32;319,12,39;319,16,07;"};


	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertInteger(letters,6,"letters evaluation fault");

}

SimpleTest_FinalizeTest()				// End of test

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
