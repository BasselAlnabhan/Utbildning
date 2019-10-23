/*
 *  TestMainTemplate.c
 *  Created on: 16 Sep 2019
 *  Author: Bassel Alnabhan
 */
#include <stdio.h>

#include "SimpleCTester.h"

/// supply path to .h file holding function headers of your test target
#include "C:\YA C programming\GitTry\BasicPointers\src\pointers.h"

SimpleTest_Initialize()					// Counters for all tests are reset here

/*********************************** Tests ***********************************/

/// supply name of your test as parameter
SimpleTest_CreateTest(mean_test1)  	// Single test defined
{
    /// define your test by calling functions from test target
    int test[] ={20,50,30,10,40};
    float mean=0;
    pnt_mean_value(test,5,&mean);


    /// assert that the outcome of your call matches expected outcome
    SimpleTest_AssertInteger(mean, 30, "pnt mean func fault");
}

SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(mean_test2)  	// Single test defined
{
    /// define your test by calling functions from test target
    int test[] ={20,50,30,10,40,16,11,23,43,66};
    float mean=0;
    pnt_mean_value(test,10,&mean);


    /// assert that the outcome of your call matches expected outcome
    SimpleTest_AssertTrue((mean<31&&mean>30.5), "pnt mean func fault");
}

SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(minmax_test1)  	// Single test defined
{
    /// define your test by calling functions from test target
    int test[] ={20,50,30,10,40};
    int min,max;
    min_max_values(test,5,&min,&max);


    /// assert that the outcome of your call matches expected outcome
    SimpleTest_AssertInteger(min, 10, "min_max func fault");
}

SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(minmax_test2)  	// Single test defined
{
	/// define your test by calling functions from test target
	int test[] ={20,50,30,10,40,16,11,23,43,66};
	int min,max;
	min_max_values(test,10,&min,&max);


	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertInteger(max, 66, "min_max func fault");
}

SimpleTest_FinalizeTest()				// End of test
/// Repeat the pattern above for all your tests for test target

/*********************************** Batch ***********************************/

// This is where we add up all tests to be run
static char* test_batch()
{
    /// supply info for presentation of outcome of test batch
    printf("\n Running tests for %s \n", "Basic_pointer");

    /// supply name of each test as parameter
    SimpleTest_RunTest(mean_test1);	// One test runs
    SimpleTest_RunTest(mean_test2);	// One test runs
    SimpleTest_RunTest(minmax_test1);	// One test runs
    SimpleTest_RunTest(minmax_test2);	// One test runs
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
