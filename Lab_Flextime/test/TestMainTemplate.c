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
SimpleTest_CreateTest(readingtest1)  	// Single test defined
{
	/// define your test by calling functions from test target
	char filename[] = {"Bjork_209_201945.txt"};
	char *content[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE];
	file_read(filename,content);

	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertString(content[0][4][3],"312,16,12","dismatch in reading");

}

SimpleTest_FinalizeTest()				// End of test

///// supply name of your test as parameter
//SimpleTest_CreateTest(readingtest2)  	// Single test defined
//{
//	/// define your test by calling functions from test target
//	char filename[] = {"Bjork_209_201945.txt"};
//	char *content[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE];
//	file_read(filename,content);
//char SP[] = {' ', '\0'};
//	/// assert that the outcome of your call matches expected outcome
//	SimpleTest_AssertString(content[1][4][4],"dismatch in reading");
//
//}
//
//SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(stamplestest1)  	// Single test defined
{
	/// define your test by calling functions from test target
	char filename[] = {"Bjork_209_201945.txt"};
	char *content[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE];
	file_read(filename,content);
	TimeStamp *test= get_stamples(content);

	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertInteger(test[37].day_number,319,"wrong day number");

}

SimpleTest_FinalizeTest()				// End of test

SimpleTest_CreateTest(stamplestest2)  	// Single test defined
{
	/// define your test by calling functions from test target
	char filename[] = {"Bjork_209_201945.txt"};
	char *content[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE];
	file_read(filename,content);
	TimeStamp *test= get_stamples(content);

	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertInteger(test[17].minute_part,37,"wrong minute part");

}

SimpleTest_FinalizeTest()				// End of test

/// supply name of your test as parameter
SimpleTest_CreateTest(worktimetest1)  	// Single test defined
{
	/// define your test by calling functions from test target
	char filename[] = {"Bjork_209_201945.txt"};
	char *content[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE];
	file_read(filename,content);
	TimeStamp *test= get_stamples(content);
WorkTime *wt= convert2work_struct(test);
	/// assert that the outcome of your call matches expected outcome
	SimpleTest_AssertTrue((wt[5].time<8.1 && wt[5].time>7.9),"wrong time calculation");

}

SimpleTest_FinalizeTest()				// End of test
/*********************************** Batch ***********************************/

// This is where we add up all tests to be run
static char* test_batch()
{
    /// supply info for presentation of outcome of test batch
    printf("\n Running tests for %s \n","FlexTime_test");

    /// supply name of each test as parameter
    SimpleTest_RunTest(readingtest1);	// One test runs
    SimpleTest_RunTest(stamplestest1);	// One test runs
    SimpleTest_RunTest(stamplestest2);	// One test runs
    SimpleTest_RunTest(worktimetest1);	// One test runs
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
