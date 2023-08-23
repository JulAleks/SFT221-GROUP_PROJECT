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
#include "convert.h"
#include <stdio.h>

//converting the letter into an int
int returnInt(char letter){
    int value=-1;

  switch(letter) {
    case 'A':
        value = 0;
        break;
case 'B':
        value = 1;
        break;
case 'C':
        value = 2;
        break;
case 'D':
        value =3;
        break;
case 'E':
        value =4;
        break;
case 'F':
        value = 5;
        break;
case 'G':
        value = 6;
        break;
case 'H':
        value = 7;
        break;
case 'I':
        value = 8;
        break;
case 'J':
        value = 9;
        break;
case 'K':
        value = 10;
        break;
case 'L':
        value = 11;
        break;
case 'M':
        value = 12;
        break;
case 'N':
        value = 13;
        break;
case 'O':
        value = 14;
        break;
case 'P':
        value = 15;
        break;
 case 'Q':
        value = 16;
        break;
  case 'R':
        value = 17;
        break;
  case 'S':
        value = 18;
        break;
      case 'T':
        value = 19;
        break;
      case 'U':
        value = 20;
        break;
      case 'V':
        value = 21;
        break;
      case 'W':
        value = 22;
        break;
     case 'X':
        value = 23;
        break;
      case 'Y':
        value = 24;
        break;
}
  return value; 
}

//this function gets the colum char and the row int and assigns to the point sruct the coresponding values from the map
struct Point translatedDirections(int row, char col)
{
    struct Point point = { 0, 0 };

    switch (col)
    {
    case 'A':
        point.row = row;
        point.col = (row == 6 || row == 7 || row == 11 || row == 12 || row == 13 || row == 14 || row == 15) ? 0 : 1;
        break;
    case 'B':
        point.row = row;
        point.col = (row == 1 || row == 2 || row == 6 || row == 7 || row == 21 || row == 22 || row == 23 || row == 24) ? 1 : 2;
        break;
    case 'C':
        point.row = row;
        point.col = (row == 1 || row == 2 || row == 6 || row == 7 || row == 21 || row == 22 || row == 23 || row == 24) ? 2 : 3;
        break;
    case 'D':
        point.row = row;
        point.col = (row == 11 || row == 13 || row == 14 || row == 21 || row == 22 || row == 23 || row == 24) ? 3 : 4;
        break;
    case 'E':
        point.row = row;
        point.col = (row == 0 || row == 1 || row == 2 || row == 3 || row == 6 || row == 7 || row == 11 || row == 13 || row == 14 || row == 21 || row == 22 || row == 23 || row == 24) ? 4 : 5;
        break;
    case 'F':
        point.row = row;
        point.col = (row == 0 || row == 1 || row == 2 || row == 3 || row == 6 || row == 7 || row == 11 || row == 21 || row == 22 || row == 23 || row == 24) ? 5 : 6;
        break;
    case 'G':
        point.row = row;
        point.col = (row == 0 || row == 1 || row == 2 || row == 3 || row == 6 || row == 7 || row == 21 || row == 22 || row == 23 || row == 24) ? 6 : 7;
        break;
    case 'H':
        point.row = row;
        point.col = (row == 12 || row == 13 || row == 15 || row == 16 || row == 17 || row == 18 || row == 21 || row == 22 || row == 23 || row == 24) ? 7 : 8;
        break;
    case 'I':
        point.row = row;
        point.col = (row == 1 || row == 2 || row == 6 || row == 7 || row == 12 || row == 13 || row == 15 || row == 16 || row == 17 || row == 18) ? 8 : 9;
        break;
    case 'J':
        point.row = row;
        point.col = (row == 12 || row == 13) ? 9 : 10;
        break;
    case 'K':
        point.row = (row == 2 || row == 7 || row == 8 || row == 21 || row == 22 || row == 23) ? 10 : 11;
        point.col = 0;
        break;
    case 'L':
        point.row = (row == 7 || row == 8 || row == 11 || row == 12 || row == 13 || row == 14 || row == 15 || row == 21 || row == 22 || row == 23 || row == 24) ? 11 : 12;
        point.col = 1;
        break;
    case 'M':
        point.row = (row == 2 || row == 11 || row == 12 || row == 13 || row == 14 || row == 15) ? 12 : 13;
        point.col = 2;
        break;
    case 'N':
        point.row = (row == 2 || row == 11 || row == 12 || row == 13 || row == 14 || row == 15 || row == 18 || row == 21 || row == 22 || row == 23 || row == 24) ? 13 : 14;
        point.col = 3;
        break;
    case 'O':
        point.row = (row == 11 || row == 12 || row == 13 || row == 14 || row == 15 || row == 18 || row == 21 || row == 22 || row == 23 || row == 24) ? 14 : 15;
        point.col = 4;
        break;
    case 'P':
        point.row = (row == 6 || row == 7 || row == 8 || row == 11 || row == 12 || row == 13 || row == 14 || row == 15 || row == 18 || row == 21 || row == 22 || row == 23 || row == 24) ? 15 : 16;
        point.col = 5;
        break;
    case 'Q':
        point.row = (row == 1 || row == 2 || row == 11 || row == 12 || row == 13 || row == 14 || row == 15 || row == 18 || row == 21 || row == 22) ? 16 : 17;
        point.col = 6;
        break;
    case 'R':
        point.row = (row == 1 || row == 2 || row == 6 || row == 11 || row == 12 || row == 13 || row == 14 || row == 15 || row == 18 || row == 21 || row == 22) ? 17 : 18;
        point.col = 7;
        break;
    case 'S':
        point.row = (row == 6 || row == 7 || row == 8 || row == 11 || row == 12 || row == 13 || row == 14 || row == 15 || row == 18 || row == 21 || row == 22) ? 18 : 19;
        point.col = 8;
        break;
    }

    return point;
}