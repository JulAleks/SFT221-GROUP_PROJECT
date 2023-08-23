/***********************************************************************
//SFT GROUP 5 PROJECT

Group members:
152953220 - TAE YONG EOM - tyeom@myseneca.ca
051292134 - Julia Alekseev  - jalekseev@myseneca.ca
123231227 - Chan Ka Ying - kchan151@myseneca.ca
1122117229 - Azad Zeynalov - azeynalov1@myseneca.ca
019153147 - Audrey Duzon - amduzon@myseneca.ca
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "pch.h"
#include "CppUnitTest.h"
#include "input_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestInputFunctions
{
	TEST_CLASS(UnitTestInputFunctions)
	{
	public:
		// BLACK-BOX TESTING

		// *** Validation for PACKAGE WEIGHT ***
		// PACKAGE WEIGHT LIMITATION: 1 - 1000 kg

		TEST_METHOD(T01_lowestNumber) {
			double input = 1;
			bool actualResult = validatePackageWeight(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T02_largestNumber) {
			double input = 1000;
			bool actualResult = validatePackageWeight(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T03_lowest_outBounded) {
			double input = -0.1;
			bool actualResult = validatePackageWeight(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T04_largest_outBounded) {
			double input = 1000.1;
			bool actualResult = validatePackageWeight(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}

		// *** Validation for PACKAGE CUBIC METER ***
		// CUBIC METER LIMITATION: 0.25, 0.5, 1.0

		TEST_METHOD(T05_validValue_point25) {
			double input = 0.25;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T06_validValue_point5) {
			double input = 0.5;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T07_validValue_1) {
			double input = 1;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T08_outBounded_point24) {
			double input = 0.24;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T09_negativeValue) {
			double input = -0.5;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T10_outBounded_1point1) {
			double input = 1.1;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}

		// *** Validation for DESTINATION ***
		// DESTINATION LIMITATION: ROW number[1-25] and COLUMN letter[A-Y] within the map

		TEST_METHOD(T11_valid_location) {
			char* input = "7A";
			bool actualResult = validateDestination(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T12_valid_location2) {
			char* input = "13A";
			bool actualResult = validateDestination(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T13_outBounded_numLocation) {
			char* input = "26A";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T14_outBounded_letterLocation) {
			char* input = "12Z";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T15_wrongOrder) {
			char* input = "A7";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T16_randomInput) {
			char* input = "ABC123";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T17_valid_toStop) {
			char* input = "x";
			bool actualResult = validateDestination(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T18_inputNull) {
			char* input = "\0";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T19_inputNull_letter) {
			char* input = NULL;
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(T20_specialCharacters) {
			char* input = "!@#$%^";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}


		// WHITE-BOX TESTING

		//(1) White-box methods for validatePackageWeight (Limits 1-1000)
		TEST_METHOD(T33_IntendedPurpose1) {
			double testValue = 34.354;
			bool returnOfTheFunc = validatePackageWeight(testValue);
			bool result = true;
			Assert::AreEqual(returnOfTheFunc, result);
		}
		TEST_METHOD(T34_LowestPossibleValue) {
			double testValue = 1;
			bool returnOfTheFunc = validatePackageWeight(testValue);
			Assert::IsTrue(returnOfTheFunc); //if the returnOfTheFunc contains bool true, IsTrue will return true
		}
		TEST_METHOD(T35_HighestPossibleValue) {
			double testValue = 1000;
			bool returnOfTheFunc = validatePackageWeight(testValue);
			Assert::IsTrue(returnOfTheFunc);
		}
		TEST_METHOD(T36_ValueBeyondTheLimits) {
			double testValue = 1234.321;
			bool returnOfTheFunc = validatePackageWeight(testValue);
			Assert::IsFalse(returnOfTheFunc); //if the returnOfTheFunc contains bool false, IsFalse will return true
		}
		TEST_METHOD(T37_IrrelevantValue1) {
			char testValue = '$';
			bool returnOfTheFunc = validatePackageWeight(testValue);
			bool result = false;
			Assert::AreEqual(returnOfTheFunc, result);
		}

		//(2) White-box methods for validatePackageBox (Limits 0.25, 0.5, 1)
		TEST_METHOD(T38_IntendedPurposeWithMinValue) {
			double testValue = 0.25;
			bool returnOfTheFunc = validatePackageBox(testValue);
			Assert::IsTrue(returnOfTheFunc);
		}
		TEST_METHOD(T39_IntendedPurposeWithMidValue) {
			double testValue = 0.5;
			bool returnOfTheFunc = validatePackageBox(testValue);
			Assert::IsTrue(returnOfTheFunc);
		}
		TEST_METHOD(T40_IntendedPurposeWithMaxValue) {
			double testValue = 1;
			bool returnOfTheFunc = validatePackageBox(testValue);
			Assert::IsTrue(returnOfTheFunc);
		}
		TEST_METHOD(T41_ValueWithinTheLimits) { //value between 0.25 and 1, which is not in the list of limits
			double testValue = 0.75;
			bool returnOfTheFunc = validatePackageBox(testValue);
			Assert::IsFalse(returnOfTheFunc);
		}
		TEST_METHOD(T42_IrrelevantValue2) {
			char testValue = '#';
			bool returnOfTheFunc = validatePackageBox(testValue);
			bool result = false;
			Assert::AreEqual(returnOfTheFunc, result);
		}

		//(3) White-box methods for validateDestination 
		TEST_METHOD(T43_IntendedPurpose2) {
			char *testValue = "5F";
			bool returnOfTheFunc = validateDestination(testValue);
			Assert::IsTrue(returnOfTheFunc);
		}
		TEST_METHOD(T44_ClosestPossibleDestination) { // assuming that delivery location cannot be the actual office location
			char *testValue = "1A";
			bool returnOfTheFunc = validateDestination(testValue);
			Assert::IsFalse(returnOfTheFunc);
		}
		TEST_METHOD(T45_FarthestPossibleDestination1) {
			char *testValue = "24Y";
			bool returnOfTheFunc = validateDestination(testValue);
			Assert::IsTrue(returnOfTheFunc);
		}
		TEST_METHOD(T46_FarthestPossibleDestination2) {
			char* testValue = "23Y";
			bool returnOfTheFunc = validateDestination(testValue);
			Assert::IsTrue(returnOfTheFunc);
		}
		TEST_METHOD(T47_FourCharactersForArgument) {
			char *testValue = "225U";
			bool returnOfTheFunc = validateDestination(testValue);
			Assert::IsFalse(returnOfTheFunc);
		}
		TEST_METHOD(T48_IrrelevantValue3) {
			char *testValue = "$#%2345sdsa ";
			bool returnOfTheFunc = validateDestination(testValue);
			Assert::IsFalse(returnOfTheFunc);
		}
	};

	// *** VALIADATION FOR USER INPUT ***
	// &weight, &size, destination
	// [0 0 x] to stop the program

	// WILL BE DONE WITH THE CONSOLE.
}

