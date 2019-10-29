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

  /*Set varioables to input if valid */
  if(argc < 7)
  {
    printf("Error - Input format: dd1 mm1 yyyy1 dd2 mm2 yyyy2 (include)\n");
    return(1);
  }

  dd1 = atoi(argv[1]);
  mm1 = atoi(argv[2]);
  yyyy1 = atoi(argv[3]);
  dd2 = atoi(argv[4]);
  mm2 = atoi(argv[5]);
  yyyy2 = atoi(argv[6]);

  if((yyyy1 % 4 == 0 && yyyy1 % 100 != 0) || yyyy1 % 400 == 0)
  {
    leapYear = TRUE;
  }

  if( argv[7] != NULL && strcmp(argv[7], "include") == 0)
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
  if(leapYear == FALSE)
  {
    ans = dayOfYear[mm2 - 1] - dayOfYear[mm1 - 1] + dd2 - dd1;
  }
  else
  {
    ans = dayOfYearLY[mm2 - 1] - dayOfYearLY[mm1 - 1] + dd2 - dd1;
  }

  if(include == TRUE)
  {
    ans++;
  }

  /*Output answer */
  printf("%d\n", ans);
  return(0);
}
