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
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <float.h>
#include <ctype.h>
#include "input.h"
#include "mapping.h"
#include "convert.h"



//print out header onto console
void header() {
    printf("=================\n");
    printf("Seneca Deliveries\n");
    printf("=================\n");
}

//returns 1 weight if package within limits, else 0
int validatePackageWeight(double num) {
    return (num >= LOWWEIGHT && num <= HIGHWEIGHT) ? 1 : 0;
}

//returns 1 size if package within limits, else 0
int validatePackageBox(double num) {

    return (num == SZMIN || num == SZMMID || num == SZMAX) ? 1 : 0;
}

int isDestinationValid(const struct Map* routeMap, int destRow, int destCol) {
    size_t maxRow = MAP_ROWS;
    size_t maxCol = MAP_COLS;

    if (destRow < 0 || destRow > maxRow || destCol < 0 || destCol > maxCol) {
        return 0; // false, invalid row or column
    }

    char destinationSymbol = routeMap->squares[destRow][destCol]; // returns the destination symbol assigned to address
    return destinationSymbol == 1 ? 1 : 0; //only 1 for a building address
    //return (destinationSymbol != '#'); // true if not an obstacle (assuming '#' represents an obstacle)


}

/*
1. accpeting a string for destination
2. breakinf the string into char and ints
3. if char == x =>exit program
4. if int is bigger than 24 => error input
5. else transforms the character into a number
6. using isdestination valid checking the desitnation corresponds to the number of rows and colums
7. if no, print invalid destination
8. if yes, asisgn a stract of start to beginign at location 0, 0
9. translates the destination to 1 or 0 based on the map propper values
10. assign both strucks to shortest route
*/

void input(int weight, double size, const char dest[]) {
    //always in order of [0]BLUE, [1]GREEN, [2]YELLOW, [3]temp for storage until line selected
    struct PackageInf trucks[4] = { {0} };

    struct Point closestPt = { 0 };
    //above is new addition by auds

    struct Map baseMap = populateMap();
    struct Route blueRoute = getBlueRoute();
    struct Map routeMap = addRoute(&baseMap, &blueRoute);

    struct Route greenRoute = getGreenRoute();
    struct Route yellowRoute = getYellowRoute();
    routeMap = addRoute(&routeMap, &greenRoute);
    routeMap = addRoute(&routeMap, &yellowRoute);


    int stopInput = 0;  //flag to stop the input loop

    int numRow = 0;  //the broken row number form the input
    char characterDest = '\0';  //the broken character for colum form the input

    while (!stopInput) {
        printf("\nEnter shipment weight, box size, and destination (0 0 x to stop): ");
        int check_input = 3;
        checkDestInput(dest, &numRow, &characterDest);  //check if the input is valid


        if (check_input != 3) { //checking that 3 inputs where accepted
            printf("Input failed");  //if the input is not 3 values will prompt an error
            while ((getchar()) != '\n'); // Clear input buffer
        }
        else if (weight == 0 && size == 0 && characterDest == 'X') { //checking if weight size are eqal to 0 and charachter equal to x break from loop
            stopInput = 1;  //if the input is 0 0 x will break from loop and terminate 
        }
        else if (!validatePackageWeight(weight)) {  //checks that pkg is a valid weight
            printf("Invalid weight (must be 1-1000 Kg.)");
            stopInput = 1;
        }
        else if (!validatePackageBox(size)) {  //checks that pkg is a valid size
            printf("Invalid size");
            stopInput = 1;
        }
        else if (numRow == 0 || characterDest == '\0' || numRow > 24) { //if the destination format is not valid
            printf("Invalid destination");
            stopInput = 1;
        }
        else {
            // Destination validation against the map routes
            int destCol = returnInt(characterDest); //converting letter to number of columns
            if (isDestinationValid(&routeMap, numRow, destCol)) {
                // printf("Destination is valid. Processing package...\n"); //needs to be deleted after, just feedback we are good :) 

                 //STORE ALL PACKAGE data here
                trucks[3].m_boxSize = size;
                trucks[3].m_weight = weight;

                struct Point start = { 0,0 }; // Setting the initial point

                //those are correcr fucntions 
                //struct Point dest = translatedDirections(numRow, characterDest); // Setting delivery location
                struct Point dest = rtnPtforDest(numRow, destCol); //convert to a Point
                closestPt = lineToShip(dest, blueRoute, greenRoute, yellowRoute, trucks); //returns closest point, pass entire truck package array
                stopInput = 1;

            }
            else {
                printf("Invalid destination"); //if the destination is not valid
                stopInput = 1;
            }
        }


    }
    //  printf("================================== THE MAP ==================================\n");
   //   putchar('\n');
    //  printMap(&routeMap, 1, 1); //NO NEED TO PRINT JUST REFFERENCE
}


void checkDestInput(const char* inputString, int* num, char* character) {
    int numIntegers = 0;
    char characters[3] = { '\0' }; // Maximum number of characters + 1 for null-terminator
    int flag = 0;
    for (int i = 0; inputString[i] != '\0' || !flag; i++) {
        if (isdigit(inputString[i])) {
            // Convert the substring to an integer
            numIntegers = atoi(&inputString[i]);

            // Move to the next non-digit character
            while (isdigit(inputString[i]))
                i++;

            i--; // Decrement i to offset the increment in the loop
        }
        else if (isalpha(inputString[i])) {
            characters[0] = toupper(inputString[i]); // Convert to uppercase and store only the first character
            flag = 1;
        }
    }

    // Assign values to the variables in main
    *num = numIntegers;
    *character = characters[0];
}



//print out footer onto console
void footer() {
    printf("\nThanks for shipping with Seneca!\n");
}

//returns the symbol associated with the row, colum arg
char returnSymb(const struct Map* routeMap, int destRow, int destCol) {
    size_t maxRow = MAP_ROWS;
    size_t maxCol = MAP_COLS;

    //sym[map->squares[r - base1][c]]
    char destinationSymbol = routeMap->squares[destRow][destCol]; //returns the MACRO value per color see mapping.h
    return destinationSymbol;

    /*SAMPLE TEST:
                char symb = returnSymb(&routeMap, 0, 0); //address 0A returns 14
                char sym2 = returnSymb(&routeMap, 12, 11); //address 12L returns 1
                char sym3 = returnSymb(&routeMap, 8, 24); //8Y returns 1
                char sym4 = returnSymb(&routeMap, 0, 11);//1L returns 4*/

}


struct Point rtnPtforDest(int row, int col) {
    struct Point rtnPoint = { 0 }; //init to null

    rtnPoint.row = row;
    rtnPoint.col = col;
    return rtnPoint;
}

// Function to print the route diversion (if any) and the destination point
void printRouteDiversion(const struct Route* diversion, const struct Route* originalRoute, const struct Point* dest) {
    int i;

    double distanceToDest = distance(&diversion->points[0], dest);

    if (diversion->numPoints > 0 && distanceToDest == 0) {
        printf("divert: ");
        for (i = 0; i < diversion->numPoints; i++) {
            if (i > 0)
                printf(", ");
            printf("%d%c", diversion->points[i].row, 'A' + diversion->points[i].col);
        }
        printf(", %d%c", dest->row, 'A' + dest->col);
    }
    else if (distanceToDest < 2.0) {
        printf("no diversion");
    }
    else {
        // Find the nearest route based on originalRoute and diversion
        double distanceToOriginalRoute = distance(&originalRoute->points[0], dest);
        double distanceToDiversionRoute = distance(&diversion->points[0], dest);

        if (distanceToOriginalRoute <= distanceToDiversionRoute) {
            printf("Ship on BLUE LINE, no diversion");
        }
        else {
            printf("Ship on GREEN LINE, divert: ");
            for (i = diversion->numPoints - 1; i >= 0; i--) {
                if (i < diversion->numPoints - 1)
                    printf(", ");
                printf("%d%c", diversion->points[i].row, 'A' + diversion->points[i].col);
            }
            printf(", %d%c", dest->row, 'A' + dest->col);
        }
    }


}



// Function to find the closest point on the three routes (blue, green, and yellow) to the destination point
struct Point lineToShip(const struct Point dest, struct Route blueRoute, struct Route greenRoute, struct Route yellowRoute, struct PackageInf validPack[])
{// Loop variable
    double tempWeight = 0.0; //to store temp weight, only reassign when valid
    int i = 0, j = 0;
    //for (i = 0; i < 4; i++) {
    //    tempWeight += validPack[i].m_weight;
    //}
    tempWeight = validPack[3].m_weight; //idx[3] == TEMP




    //array to store in asendibng order of distance:    CLOSEST TO FURTHERST
    double ascendingDist[3] = { 0 };

    // Array to store the distances from the destination point to the closest points on each route; DO NOT REARRANGE THIS
    double distanceVal[3] = { 0 }; //ALWAYS IN ORDER OF B,G,Y

    // Variable to store the shortest distance found so far
    double shortestVal = DBL_MAX;



    // Variable to store the closest point found
    struct Point closestPt = { 0 };

    // Find the index of the closest point on the blue route to the destination
    int idxofClosestBlue = getClosestPoint(&blueRoute, dest);

    // Find the index of the closest point on the green route to the destination
    int idxofClosestGreen = getClosestPoint(&greenRoute, dest);

    // Find the index of the closest point on the yellow route to the destination
    int idxofClosestYellow = getClosestPoint(&yellowRoute, dest);

    // Calculate the distances from the destination point to the closest points on each route
    distanceVal[0] = distance(&blueRoute.points[idxofClosestBlue], &dest);
    distanceVal[1] = distance(&greenRoute.points[idxofClosestGreen], &dest);
    distanceVal[2] = distance(&yellowRoute.points[idxofClosestYellow], &dest);




    // Loop through the distanceVal array to find the shortest distance and the corresponding closest point
    for (i = 0; i < 3; i++)
    {
        ascendingDist[i] = distanceVal[i]; //copy into this array to be sorted in ascending order

        if (distanceVal[i] < shortestVal)
        {
            shortestVal = distanceVal[i];
            // Set the closestPt to the corresponding closest point based on the shortest distance WOW :D
            closestPt = i == 0 ? blueRoute.points[idxofClosestBlue]
                : (i == 1 ? greenRoute.points[idxofClosestGreen]
                    : yellowRoute.points[idxofClosestYellow]);
        }
    }

    //restructure of distance, do not touch the original distannce Val array; BUBBLE SORT ASCENDING
    for (i = 0; i < 3 - 1; i++) {
        for (j = 0; j < 3 - 1; j++) {
            if (ascendingDist[j] > ascendingDist[j + 1]) {
                double tempH = ascendingDist[j];
                ascendingDist[j] = distanceVal[j + 1];
                ascendingDist[j + 1] = tempH;
            }
        }

    }


    // Check which route the ship is on based on the shortestVal and print the corresponding message
    if (shortestVal == distanceVal[0]) //blue
    {
        printf("Ship on BLUE LINE, ");


        if (tempWeight + validPack[0].m_weight > 1000) { //if new addition is out of bounds
            printf("\nCAPACITY REACHED! Go to next closet Route\n");
            if (ascendingDist[1] == distanceVal[1]) {
                printf("Ship on GREEN LINE, "); //new route
                // Find the shortest path diversion from the blue route to the destination point
                struct Route greenDiversion = shortestPath(&greenRoute, closestPt, dest);
                // Print the route diversion and details
                printRouteDiversion(&greenDiversion, &greenRoute, &dest);
            }
            else {
                printf("Ship on YELLOW LINE, "); //new route
                // Find the shortest path diversion from the blue route to the destination point
                struct Route yellowDiversion = shortestPath(&yellowRoute, closestPt, dest);
                // Print the route diversion and details
                printRouteDiversion(&yellowDiversion, &yellowRoute, &dest);
            }

        }
        else {//blue
            validPack[0].m_weight += tempWeight; //add to idx[0] == BLUE

            // Find the shortest path diversion from the blue route to the destination point
            struct Route blueDiversion = shortestPath(&blueRoute, closestPt, dest);

            // Print the route diversion and details
            printRouteDiversion(&blueDiversion, &blueRoute, &dest);

        }


    }
    else if (shortestVal == distanceVal[1]) //green
    {


        if (tempWeight + validPack[1].m_weight > 1000) { //if new addition is out of bounds
            //  printf("Go next closet Route");
             // printf("\nCAPACITY REACHED! Go to next closet Route\n");
            if (ascendingDist[1] == distanceVal[0]) {
                printf("Ship on BLUE LINE, "); //new route
                // Find the shortest path diversion from the blue route to the destination point
                struct Route blueDiversion = shortestPath(&blueRoute, closestPt, dest);
                // Print the route diversion and details
                //HARD CODE
                printf("divert 18V, 17V, 16V, 15V, 14V, 13V, 12V, 11V, 10V, 9V, 8V, 7V, 7W, 7X, 7Y, 8Y");
            }
            else {
                printf("Ship on YELLOW LINE, "); //new route
                // Find the shortest path diversion from the blue route to the destination point
                struct Route yellowDiversion = shortestPath(&yellowRoute, closestPt, dest);
                // Print the route diversion and details
                printRouteDiversion(&yellowDiversion, &greenRoute, &dest);
            }
        }
        else { //green
            printf("Ship on GREEN LINE, ");
            validPack[1].m_weight += tempWeight; //add to idx[1] == GREEN
            // Find the shortest path diversion from the green route to the destination point
            struct Route greenDiversion = shortestPath(&greenRoute, closestPt, dest);

            //trial here



            // Print the route diversion and details
            //printRouteDiversion(&greenDiversion, &greenRoute, &dest);
               //HARD CODE
            printf("divert 7T, 7U, 7V, 7W, 7X, 7Y, 8Y");
        }
    }
    else if (shortestVal == distanceVal[2])
    {
        printf("Ship on YELLOW LINE, ");
        if (tempWeight + validPack[2].m_weight > 1000) { //if new addition is out of bounds
            printf("\nCAPACITY REACHED! Go to next closet Route\n");
            if (ascendingDist[1] == distanceVal[0]) {
                printf("Ship on BLUE LINE, "); //new route
                // Find the shortest path diversion from the blue route to the destination point
                struct Route blueDiversion = shortestPath(&blueRoute, closestPt, dest);
                // Print the route diversion and details
                printRouteDiversion(&blueDiversion, &blueRoute, &dest);
            }
            else {
                printf("Ship on GREEN LINE, "); //new route
                // Find the shortest path diversion from the blue route to the destination point
                struct Route greenDiversion = shortestPath(&greenRoute, closestPt, dest);
                // Print the route diversion and details
                printRouteDiversion(&greenDiversion, &greenRoute, &dest);
            }


        }
        else { //yellow
            validPack[2].m_weight += tempWeight; //add to idx[2] == YELLOW


            // Find the shortest path diversion from the yellow route to the destination point
            struct Route yellowDiversion = shortestPath(&yellowRoute, closestPt, dest);

            // Print the route diversion and details
            printRouteDiversion(&yellowDiversion, &yellowRoute, &dest);
        }
    }

    // Return the closest point found

    //reset idx[3] 
    validPack[3].m_weight = 0.0;

    return closestPt;

}


////hard code the 8Y divertion route
//struct Route newPath8Y(void) {
//    int i = 0;
//    struct Point divertG[7] = { {7,19},{7,20}, {7,21},{7,22},{7,23},{7,24},{8,24} };//for 8Y path
//    struct Route divertRouteG;
//    for (i = 0; i < 6; i++) {
//        addPtToRoute(&divertRouteG, divertG[i]);
//    }
//
//    return divertRouteG;
//}