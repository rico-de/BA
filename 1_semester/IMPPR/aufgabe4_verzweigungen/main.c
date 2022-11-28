#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int check(unsigned int num);

int main(int argc, char **argv) {
  unsigned int rannum;
  int i;

  srand(time(0));
  
  for(i = 0; i < 10; i++) {
    rannum = rand() % 100;
    printf("for-loop run %d: ", i);
    check(rannum);
  }

  i = 0;
  do {
    rannum = rand() % 100;
    printf("do-while-loop run %d: ", i);
    i++;
  } while(check(rannum));

  while(i++ < 20) {
    rannum = rand() % 100;
    printf("while-loop run %d: ", i);
    check(rannum);
  }

  return 0;
}


int check(unsigned int num) {
  int special_num = 0;
  if (num < 20) {
    printf("%d is smaller than 20\n", num);
  }
  else if (num < 40) {
    printf("%d is between 20 and 40\n", num);
  }
  else if (num < 60) {
    printf("%d is between 40 and 60\n", num);
  }
  else if (num < 80) {
    printf("%d is between 60 and 80\n", num);
  }
  else {
    printf("%d is between 80 and 100\n", num);
  }

  switch(num) {
    case 0: printf("Jackpot %d getroffen\n", num); 
            special_num  = 1;
            break;
    case 20: printf("Jackpot %d getroffen\n", num); 
            special_num  = 1;
            break;
    case 40: printf("Jackpot %d getroffen\n", num);
            special_num  = 1;
            break;
    case 60: printf("Jackpot %d getroffen\n", num);
            special_num  = 1;
            break;
    default: special_num = 0;
  }
  return special_num;
}
