/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_myStringTests_init = false;
#include "/media/mult/USB/oop/myStringTests.cpp"

static myStringTests suite_myStringTests;

static CxxTest::List Tests_myStringTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_myStringTests( "myStringTests.cpp", 8, "myStringTests", suite_myStringTests, Tests_myStringTests );

static class TestDescription_suite_myStringTests_testDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testDefaultConstructor() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 11, "testDefaultConstructor" ) {}
 void runTest() { suite_myStringTests.testDefaultConstructor(); }
} testDescription_suite_myStringTests_testDefaultConstructor;

static class TestDescription_suite_myStringTests_testFromCharsArrayConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testFromCharsArrayConstructor() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 20, "testFromCharsArrayConstructor" ) {}
 void runTest() { suite_myStringTests.testFromCharsArrayConstructor(); }
} testDescription_suite_myStringTests_testFromCharsArrayConstructor;

static class TestDescription_suite_myStringTests_testCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testCopyConstructor() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 32, "testCopyConstructor" ) {}
 void runTest() { suite_myStringTests.testCopyConstructor(); }
} testDescription_suite_myStringTests_testCopyConstructor;

static class TestDescription_suite_myStringTests_testFromMyStringconstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testFromMyStringconstructor() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 41, "testFromMyStringconstructor" ) {}
 void runTest() { suite_myStringTests.testFromMyStringconstructor(); }
} testDescription_suite_myStringTests_testFromMyStringconstructor;

static class TestDescription_suite_myStringTests_testMyStringClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringClear() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 53, "testMyStringClear" ) {}
 void runTest() { suite_myStringTests.testMyStringClear(); }
} testDescription_suite_myStringTests_testMyStringClear;

static class TestDescription_suite_myStringTests_testMyStringAppendCharArray : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringAppendCharArray() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 62, "testMyStringAppendCharArray" ) {}
 void runTest() { suite_myStringTests.testMyStringAppendCharArray(); }
} testDescription_suite_myStringTests_testMyStringAppendCharArray;

static class TestDescription_suite_myStringTests_testMyStringAppendMyString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringAppendMyString() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 79, "testMyStringAppendMyString" ) {}
 void runTest() { suite_myStringTests.testMyStringAppendMyString(); }
} testDescription_suite_myStringTests_testMyStringAppendMyString;

static class TestDescription_suite_myStringTests_testMyStringAppendChar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringAppendChar() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 90, "testMyStringAppendChar" ) {}
 void runTest() { suite_myStringTests.testMyStringAppendChar(); }
} testDescription_suite_myStringTests_testMyStringAppendChar;

static class TestDescription_suite_myStringTests_testMyStringAssignCharArray : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringAssignCharArray() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 102, "testMyStringAssignCharArray" ) {}
 void runTest() { suite_myStringTests.testMyStringAssignCharArray(); }
} testDescription_suite_myStringTests_testMyStringAssignCharArray;

static class TestDescription_suite_myStringTests_testMyStringAssignMyString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringAssignMyString() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 120, "testMyStringAssignMyString" ) {}
 void runTest() { suite_myStringTests.testMyStringAssignMyString(); }
} testDescription_suite_myStringTests_testMyStringAssignMyString;

static class TestDescription_suite_myStringTests_testMyStringAssignChar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringAssignChar() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 131, "testMyStringAssignChar" ) {}
 void runTest() { suite_myStringTests.testMyStringAssignChar(); }
} testDescription_suite_myStringTests_testMyStringAssignChar;

static class TestDescription_suite_myStringTests_testMyStringInsertMyString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringInsertMyString() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 143, "testMyStringInsertMyString" ) {}
 void runTest() { suite_myStringTests.testMyStringInsertMyString(); }
} testDescription_suite_myStringTests_testMyStringInsertMyString;

static class TestDescription_suite_myStringTests_testMyStringInsertCharArray : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringInsertCharArray() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 154, "testMyStringInsertCharArray" ) {}
 void runTest() { suite_myStringTests.testMyStringInsertCharArray(); }
} testDescription_suite_myStringTests_testMyStringInsertCharArray;

static class TestDescription_suite_myStringTests_testMyStringInsertChar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringInsertChar() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 165, "testMyStringInsertChar" ) {}
 void runTest() { suite_myStringTests.testMyStringInsertChar(); }
} testDescription_suite_myStringTests_testMyStringInsertChar;

static class TestDescription_suite_myStringTests_testMyStringReplaceMySrting : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringReplaceMySrting() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 176, "testMyStringReplaceMySrting" ) {}
 void runTest() { suite_myStringTests.testMyStringReplaceMySrting(); }
} testDescription_suite_myStringTests_testMyStringReplaceMySrting;

static class TestDescription_suite_myStringTests_testMyStringReplaceCharArray : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringReplaceCharArray() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 193, "testMyStringReplaceCharArray" ) {}
 void runTest() { suite_myStringTests.testMyStringReplaceCharArray(); }
} testDescription_suite_myStringTests_testMyStringReplaceCharArray;

static class TestDescription_suite_myStringTests_testMyStringReplaceMySrtingMyString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringReplaceMySrtingMyString() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 205, "testMyStringReplaceMySrtingMyString" ) {}
 void runTest() { suite_myStringTests.testMyStringReplaceMySrtingMyString(); }
} testDescription_suite_myStringTests_testMyStringReplaceMySrtingMyString;

static class TestDescription_suite_myStringTests_testMyStringReplaceCharArrayCharArray : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringReplaceCharArrayCharArray() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 224, "testMyStringReplaceCharArrayCharArray" ) {}
 void runTest() { suite_myStringTests.testMyStringReplaceCharArrayCharArray(); }
} testDescription_suite_myStringTests_testMyStringReplaceCharArrayCharArray;

static class TestDescription_suite_myStringTests_testMyStringReplaceCharChar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringReplaceCharChar() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 245, "testMyStringReplaceCharChar" ) {}
 void runTest() { suite_myStringTests.testMyStringReplaceCharChar(); }
} testDescription_suite_myStringTests_testMyStringReplaceCharChar;

static class TestDescription_suite_myStringTests_testMyStringSwap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringSwap() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 260, "testMyStringSwap" ) {}
 void runTest() { suite_myStringTests.testMyStringSwap(); }
} testDescription_suite_myStringTests_testMyStringSwap;

static class TestDescription_suite_myStringTests_testMyStringCountMyString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringCountMyString() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 277, "testMyStringCountMyString" ) {}
 void runTest() { suite_myStringTests.testMyStringCountMyString(); }
} testDescription_suite_myStringTests_testMyStringCountMyString;

static class TestDescription_suite_myStringTests_testMyStringCountCharArray : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringCountCharArray() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 280, "testMyStringCountCharArray" ) {}
 void runTest() { suite_myStringTests.testMyStringCountCharArray(); }
} testDescription_suite_myStringTests_testMyStringCountCharArray;

static class TestDescription_suite_myStringTests_testMyStringCountChar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringCountChar() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 295, "testMyStringCountChar" ) {}
 void runTest() { suite_myStringTests.testMyStringCountChar(); }
} testDescription_suite_myStringTests_testMyStringCountChar;

static class TestDescription_suite_myStringTests_testMyStringFindMyString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringFindMyString() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 308, "testMyStringFindMyString" ) {}
 void runTest() { suite_myStringTests.testMyStringFindMyString(); }
} testDescription_suite_myStringTests_testMyStringFindMyString;

static class TestDescription_suite_myStringTests_testMyStringFindCharArray : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringFindCharArray() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 311, "testMyStringFindCharArray" ) {}
 void runTest() { suite_myStringTests.testMyStringFindCharArray(); }
} testDescription_suite_myStringTests_testMyStringFindCharArray;

static class TestDescription_suite_myStringTests_testMyStringFindChar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_myStringTests_testMyStringFindChar() : CxxTest::RealTestDescription( Tests_myStringTests, suiteDescription_myStringTests, 326, "testMyStringFindChar" ) {}
 void runTest() { suite_myStringTests.testMyStringFindChar(); }
} testDescription_suite_myStringTests_testMyStringFindChar;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
