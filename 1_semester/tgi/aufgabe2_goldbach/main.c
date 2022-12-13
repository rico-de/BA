/* 
 * Goldbach Vermutung:
 *  Jede gerade Zahl, die größer als 2 ist, ist die Summe zweier Primzahlen.
 */

#include <stdio.h>
#include <math.h>

int isprime(int num);

int main(int argc, char** argv) {
  long long i;
  long long num;
  long long half_num;

  printf("Input an positive even number, greater than 2: ");
  scanf("%lld", &num);

  if (num <= 2 || num % 2) {
    printf("%lld is not an even number!\n", num);
    return 1;
  } 

  half_num = num / 2;
  for (i = 2; i <= half_num; i++) {
    if (isprime(i) && isprime(num - i)) {
      printf("primenumber %lld + primenumber %lld = %lld.\n", i, num - i, num);
      return 0;
    }
  }
     
  printf("There are no two prime numbers that add up %lld.\n", num);

  return 1;
}

int isprime(int num) {
  int x;
  int sqrt_num = sqrt(num);

  if (num < 2)
    return 0;
  if (num == 2) 
    return 1;
  if (!(num % 2))
    return 0;

  for (x = 3;  x <= sqrt_num; x += 2) {
    if (!(num % x)) 
      return 0; 
  }
  return 1;
}

