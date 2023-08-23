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

	int weight = 500;
	double size = 1.0;
	char dest[4] = "12D";

	printf("\n\nCase 1: Testing the program for proper shipment on the yellow line with no diversion.\n");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	printf("\n\n\nCase 2: Testing the program for ensuring that the shipment performed on yellow line without diversion.\n");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	printf("\n\n\nCase 3: Testing the program for proper shipment on the blue line with no diversion.\n");
	strcpy(dest, "12L");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	printf("\n\n\nCase 4: Testing the program for ensuring that the shipment performed on blue line without diversion.\n");
	strcpy(dest, "12L");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	printf("\n\n\nCase 5: Testing the program for handling the case of trucks' full capacity\n");
	strcpy(dest, "12L");
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest);
	header();
	input(weight, size, dest);
	footer();


	return 0;
}