#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE 1

int main(int argc, char *argv[])
{
  /*Create and initialize variables */
  int dd1 = 0;
  int mm1 = 0;
  int yyyy1 = 0;
  int dd2 = 0;
  int mm2 = 0;
  int yyyy2 = 0;
  int ans = 0;
  int include = FALSE;
  int leapYear = FALSE;
  int dayOfYear[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 355};
  int dayOfYearLY[12] = {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 356};
  int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int i = 0;
  char day1[3] = {"00\0"};
  char mon1[3] = {"00\0"};
  char y1[5] = {"0000\0"};
  char day2[3] = {"00\0"};
  char mon2[3] = {"00\0"};
  char y2[5] = {"0000\0"};

  /*Set varioables to input if valid */
  if(argc < 3)
  {
    printf("Error - Input format: dd1-mm1-yyyy1 dd2-mm2-yyyy2 (include)\n");
    return(1);
  }

  for (i = 0; i < 2; i++) {
    day1[i] = argv[1][i];
  }
  day1[2] = '\0';

  for (i = 0; i < 2; i++) {
    mon1[i] = argv[1][i + 3];
  }
  mon1[2] = '\0';

  for (i = 0; i < 4; i++) {
    y1[i] = argv[1][i + 6];
  }
  y1[4] = '\0';

  for (i = 0; i < 2; i++) {
    day2[i] = argv[2][i];
  }
  day2[2] = '\0';

  for (i = 0; i < 2; i++) {
    mon2[i] = argv[2][i + 3];
  }
  mon2[2] = '\0';

  for (i = 0; i < 4; i++) {
    y2[i] = argv[2][i + 6];
  }
  y2[4] = '\0';

  dd1 = atoi(day1);
  mm1 = atoi(mon1);
  yyyy1 = atoi(y1);
  dd2 = atoi(day2);
  mm2 = atoi(mon2);
  yyyy2 = atoi(y2);

  if((yyyy1 % 4 == 0 && yyyy1 % 100 != 0) || yyyy1 % 400 == 0)
  {
    leapYear = TRUE;
  }

  if( argv[3] != NULL && strcmp(argv[3], "include") == 0)
  {
    include = TRUE;
  }

  /*Check for various errors */
  if(yyyy1 != yyyy2)
  {
    printf("Error - yyyy1 and yyyy2 should be the same year\n");
    return(2);
  }

  if(mm2 < mm1 || ((mm1 == mm2) && (dd2 < dd1)))
  {
    printf("Error - Final date should come after initial date\n");
    return(3);
  }

  if(mm1 < 1 || mm1 > 12 || mm2 < 1 || mm2 > 12)
  {
    printf("Error - Invalid month\n");
    return(5);
  }

  if(leapYear == TRUE)
  {
    if(mm1 == 2 && dd1 > 29)
    {
      printf("Error - Invalid day for given month\n");
      return(4);
    }
    else if(mm2 == 2 && dd2 > 29)
    {
      printf("Error - Invalid day for given month\n");
      return(4);
    }
  }
  else
  {
    if(dd1 > daysInMonth[mm1 - 1] || dd2 > daysInMonth[mm2 - 1] || dd1 < 1 || dd2 < 1)
    {
      printf("Error - Invalid day for given month\n");
      return(4);
    }
  }

  /*Calculate answer */
  switch(leapYear)
  {
    case FALSE:
      ans = dayOfYear[mm2 - 1] - dayOfYear[mm1 - 1] + dd2 - dd1;
      break;

    case TRUE:
      ans = dayOfYearLY[mm2 - 1] - dayOfYearLY[mm1 - 1] + dd2 - dd1;
      break;
  }

  if(include == TRUE)
  {
    ans++;
  }

  /*Output answer */
  printf("%d\n", ans);
  return(0);
}
