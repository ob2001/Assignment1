#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define FALSE 0
#define TRUE 1

/*Code for getting time from system (ie using <time.h>) found from https://www.techiedelight.com/print-current-date-and-time-in-c/ */

int main(int argc, char *argv[])
{
  /*Create and initialize variables */
  int dd1 = 0, mm1 = 0, yyyy1 = 0, dd2 = 0, mm2 = 0, yyyy2 = 0, ans = 0, i = 0, ydiff = 0, numLY = 0;
  int include = FALSE, lY1 = FALSE, lY2 = FALSE;
  int monthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int monthLengthLY[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int dayOfYear[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
  int dayOfYearLY[12] = {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336};
  char day1[3] = {"00\0"}, mon1[3] = {"00\0"}, day2[3] = {"00\0"}, mon2[3] = {"00\0"};
  char y1[5] = {"0000\0"}, y2[5] = {"0000\0"};

  time_t today;
  time(&today);
  struct tm *local = localtime(&today);

  /*Set varioables to input if valid */
  if(argc < 3)
  {
    printf("Error - Input format: dd1-mm1-yyyy1 dd2-mm2-yyyy2 (include)\n");
    return(1);
  }

  if(argv[1] != NULL && strcmp(argv[1], "today") != 0){
    for (i = 0; i < 2; i++) {
      day1[i] = argv[1][i];
    }

    for (i = 0; i < 2; i++) {
      mon1[i] = argv[1][i + 3];
    }

    for (i = 0; i < 4; i++) {
      y1[i] = argv[1][i + 6];
    }
    dd1 = atoi(day1);
    mm1 = atoi(mon1);
    yyyy1 = atoi(y1);
  }

  else {
    dd1 = local->tm_mday;
    mm1 = local->tm_mon + 1;
    yyyy1 = local->tm_year + 1900;
  }

  if(argv[2] != NULL && strcmp(argv[2], "today") != 0){
    for (i = 0; i < 2; i++) {
      day2[i] = argv[2][i];
    }

    for (i = 0; i < 2; i++) {
      mon2[i] = argv[2][i + 3];
    }

    for (i = 0; i < 4; i++) {
      y2[i] = argv[2][i + 6];
    }
    dd2 = atoi(day2);
    mm2 = atoi(mon2);
    yyyy2 = atoi(y2);
  }

  else {
    dd2 = local->tm_mday;
    mm2 = local->tm_mon + 1;
    yyyy2 = local->tm_year + 1900;
  }

  if( argv[3] != NULL && strcmp(argv[3], "include") == 0){
    include = TRUE;
  }

  if((yyyy1 % 4 == 0 && yyyy1 % 100 != 0) || yyyy1 % 400 == 0){
    lY1 = TRUE;
  }

  if((yyyy2 % 4 == 0 && yyyy2 % 100 != 0) || yyyy2 % 400 == 0){
    lY2 = TRUE;
  }

  /*Check for various errors */
  if((yyyy2 < yyyy1) || ((yyyy2 == yyyy1) && (mm2 < mm1)) || ((yyyy2 == yyyy1) && (mm2 == mm1) && (dd2 < dd1))){
    printf("Error - Final date should come after initial date\n");
    return(3);
  }

  if(mm1 < 1 || mm1 > 12 || mm2 < 1 || mm2 > 12){
    printf("Error - Invalid month\n");
    return(5);
  }

  if((lY1 == FALSE && dd1 > monthLength[mm1 - 1]) || (lY2 == FALSE && dd2 > monthLength[mm2 - 1]) || dd1 < 1 || dd2 < 1){
    printf("Error - Invalid day for given month\n");
    return(4);
  } else if(dd1 > monthLengthLY[mm1 - 1] || dd2 > monthLengthLY[mm2 - 1]){
    printf("Error - Invalid day for given month\n");
  }

  /*Calculate answer */
  if(yyyy1 < yyyy2){
    ydiff = yyyy2 - yyyy1;
  }

  numLY = (ydiff / 4) - (ydiff / 100) + (ydiff / 400) + lY1 + lY2;

  if(yyyy1 != yyyy2){
    ans = ((ydiff - 1) * 365) + numLY;
    if(lY1 == FALSE){
      for (i = mm1; i < 12; i++) {
        ans += monthLength[i];
      }
      ans += (monthLength[mm1 - 1] - dd1);
    } else {
      for (i = mm1 + 1; i < 12; i++) {
        ans += monthLengthLY[i];
      }
      ans += (monthLengthLY[mm1 - 1] - dd1) - 1;
    }

    if(lY2 == FALSE){
      for (i = 0; i < mm2 - 1; i++) {
        ans += monthLength[i];
      }
      ans += dd2;
    } else {
      for (i = 0; i < mm2 - 1; i++) {
        ans += monthLengthLY[i];
      }
      ans += dd2 - 1;
    }
  } else if(yyyy1 != lY1) {
    ans = dayOfYear[mm2 - 1] + dd2 - dayOfYear[mm1 - 1] - dd1 + 1;
  } else {
    ans = dayOfYearLY[mm2 - 1] + dd2 - dayOfYearLY[mm1 - 1] - dd1 + 1;
  }

  if(include == TRUE)
  {
    ans++;
  }

  /*Output answer */
  printf("%d\n", ans);
  return(0);
}
