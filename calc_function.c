#include<stdio.h>

int factorial(int a);
int permutation(int n, int r);
int combination(int n, int r);
char* decimal_to_binary(int n);
char* decimal_to_hex(int n);

int factorial(int a){
  return (a<1)? 1 : a*factorial(a-1);
}

int permutation(int n, int r){
  if(n<r) return -1;
  return factorial(n)/factorial(n-r);
}

int combination(int n, int r){
  if(n<r) return -1;
  return factorial(n)/(factorial(n-r)*factorial(r));
}

// Decimal2Binary
char* decimal_to_binary(int n) {

  char ps[8 * sizeof(n) + 1];
  int size = 8 * sizeof(n);
  int i = size -1;

  while(i+1) {
    ps[i--] = (1 & n) + '0';
    n >>= 1;
  }

  ps[size] = '\0';
  printf("= %s\n", ps);
  return ps;
}


char* decimal_to_hex(int n)
{   
  char ps[2 * sizeof(n) + 1];
  int size = 2 * sizeof(n);
  int i = size -1;
  int temp;
	int j=0;
  while(i--)
  {
    temp = (n&(0xf<<(4*i)))>>(4*i);
    if(temp > 9){
      ps[j] = 'A'+temp-10;
    } else{
      ps[j] = '0'+temp;
    }
    j++;
  }
	ps[size] = '\0';
  printf("= %s\n", ps);
  return ps;
}


