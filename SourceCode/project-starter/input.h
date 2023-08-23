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


#ifndef INPUT_H
#define INPUT_H

#define LOWWEIGHT 1      // kg
#define HIGHWEIGHT 1000  // kg

#define SZMIN 0.25      // cubic meter
#define SZMMID 0.5      // cubic meter
#define SZMAX 1         // cubic meter

#include "mapping.h"

struct PackageInf {
	double m_weight;	//valid 1-1000 Kg.
	double m_boxSize; //valid range in cubic meter: 0.25, 0.5, 1 
};


//print out header onto console "Seneca Deliveries"
void header();

//print out footer onto consol, "Thank you messegae"
void footer();

//get user input to enter package data related to weight, boxsize and destination, "0 0 x" to stop
void input(struct PackageInf*);



//checks the destination returns 1 if symbol == 1 ie building, else false
int isDestinationValid(const struct Map* routeMap, int destRow, int destCol);

//checks that destination is within the A-Y and 1-25 limit, pass by address
void checkDestInput(const char* inputString, int* num, char* character);

//returns 1 weight if package within limits (1-1000), else 0
int validatePackageWeight(double);

//returns 1 if package within cubic meter limits (0.25/0.5/1), else 0
int validatePackageBox(double);

//returns the symbol associated with the row, colum arg see MAP
char returnSymb(const struct Map* routeMap, int destRow, int destCol);

//CONVERSION: returns a point struct based on a validated destination, 12L = 12, 11
struct Point rtnPtforDest(int row, int col);

//returns the closest based on dest arg point to main
struct Point lineToShip(const struct Point dest, struct Route blueRoute, struct Route greenRoute, struct Route yellowRoute, struct PackageInf validPack[], const struct Map base);

//prints the new route diversion onto console in '7T' format
void printRouteDiversion(const struct Route* diversion, const struct Route* originalRoute, const struct Point* dest);


#endif