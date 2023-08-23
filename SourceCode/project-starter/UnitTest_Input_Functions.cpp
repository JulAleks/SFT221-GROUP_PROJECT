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
#include "input.h"
#include "mapping.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestInputFunctions
{
	TEST_CLASS(UnitTestInputFunctions)
	{
	public:
		// BLACK-BOX TESTING

		// *** Validation for PACKAGE WEIGHT ***
		// PACKAGE WEIGHT LIMITATION: 1 - 1000 kg
		
		TEST_METHOD(lowestNumber) {
			double input = 1;
			bool actualResult = validatePackageWeight(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(largestNumber) {
			double input = 1000;
			bool actualResult = validatePackageWeight(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(lowest_outBounded) {
			double input = -0.1;
			bool actualResult = validatePackageWeight(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(largest_outBounded) {
			double input = 1000.1;
			bool actualResult = validatePackageWeight(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}

		// *** Validation for PACKAGE CUBIC METER ***
		// CUBIC METER LIMITATION: 0.25, 0.5, 1.0

		TEST_METHOD(validValue_point25) {
			double input = 0.25;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(validValue_point5) {
			double input = 0.5;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(validValue_1) {
			double input = 1;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(outBounded_point24) {
			double input = 0.24;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(negativeValue) {
			double input = -0.5;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(outBounded_1point1) {
			double input = 1.1;
			bool actualResult = validatePackageBox(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}

		// *** Validation for DESTINATION ***
		// DESTINATION LIMITATION: ROW number[1-25] and COLUMN letter[A-Y] within the map

		TEST_METHOD(valid_location) {
			char *input = "7A";
			bool actualResult = validateDestination(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(valid_location2) {
			char* input = "13A";
			bool actualResult = validateDestination(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(outBounded_numLocation) {
			char* input = "26A";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(outBounded_letterLocation) {
			char* input = "12Z";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(wrongOrder) {
			char* input = "A7";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(randomInput) {
			char* input = "ABC123";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(valid_toStop) {
			char* input = "X";
			bool actualResult = validateDestination(input);
			bool expectedResult = true;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(inputNull) {
			char* input = "\0";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(inputNull_letter) {
			char* input = NULL;
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(specialCharacters) {
			char* input = "!@#$%^";
			bool actualResult = validateDestination(input);
			bool expectedResult = false;
			Assert::AreEqual(expectedResult, actualResult);
		}

		// *** Validation for USER INPUT ***
		// &weight, &size, destination
		// [0 0 x] to stop the program

		// WILL BE DONE WITH THE CONSOLE.
	};
}
