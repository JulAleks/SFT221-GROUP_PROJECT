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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "mapping.h"
#include "input.h"


int main() {
	printf("*** Integration Testing of Input Functions ***\n\n\n");


	printf("\n\nCase 1: Testing the program for handling invalid size.\n");
	int weight = 20;
	double size = 0.2;
	char dest[4] = "12L";
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	printf("\n\n\nCase 2: Testing the program for handling invalid weight.\n");
	weight = 1005;
	size = 0.5;
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	printf("\n\n\nCase 3: Testing the program for handling invalid destination.\n");
	weight = 20;
	size = 0.5;
	strcpy(dest, "28x");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	printf("\n\n\nCase 4: Testing the program for proper shipment on the blue line without any diversion.\n");
	weight = 20;
	size = 0.5;
	strcpy(dest, "12L");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	printf("\n\n\nCase 5: Testing the program for proper shipment on the green line with diversion.\n");
	weight = 200;
	size = 1.0;
	strcpy(dest, "8Y");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	printf("\n\n\nCase 6: Testing the program for proper shipment on the green line with diversion (using another values).\n");
	weight = 500;
	size = 1.0;
	strcpy(dest, "8Y");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	printf("\n\n\nCase 7: Testing the program for proper shipment on the blue line with diversion (using the same values as in case 6).\n");
	weight = 500;
	size = 1.0;
	strcpy(dest, "8Y");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();

	//uncomment while running and perform the instuctions below
	/*printf("\n\n\nCase 8: Testing the program for proper exiting (comment other test cases for running this one and comment the flags from line 102 - 132.\n");
	weight = 0;
	size = 0;
	strcpy(dest, "X");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();*/



	return 0;
}