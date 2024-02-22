#include "Debug/Debug.h"
#include "Fundamental/Fundamental.h"

struct ArrayOfObjects
{
    void** Location;
    Size Size;
};
struct TestData;
struct Test
{

    struct ArrayOfObjects DataGenerators;
    void(*TestFunction)(struct TestData*);
    struct ArrayOfObjects Checks;

};
struct TestOutput;
struct Tests;

void RunTests(struct Tests* p_tests)
{

    struct Test l_warnTest = {
        .DataGenerators = {"CString>0", 1},
        .TestFunction = TestWarn,
        .Checks = {&WarnCheck, 1}
    };


}

void TestWarn(struct TestData* p_testData)
{

    const char* l_string =
        GetPointerFromCStringAsValueUsingTestData("AribtraryString", &p_testData);

    Size l_lineNo = __LINE__;
    DaLibrary_Warn(l_string);

    ++l_lineNo;
    SetUsingPointerFromCStringAsValueUsingTestData(
        &l_lineNo, "LineNumber", &p_testData
    );

    const char* l_fileName = __FILE__;
    SetUsingPointerFromCStringAsValueUsingTestData(
        &l_fileName, "FileName", &p_testData
    );

}

int WarnCheck(struct TestOutput* p_testOutput)
{

}
