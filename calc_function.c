#include<stdio.h>

int factorial(int a);
int permutation(int n, int r);
int combination(int n, int r);
char* decimal_to_binary(int n);
char* decimal_to_hex(int n);
char* decimal_to_octal(int n);

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

  static char d2b[4 * sizeof(n) + 1];
  int size = 4 * sizeof(n);
  int i = size -1;

  while(i+1) {
    d2b[i--] = (1 & n) + '0';
    n >>= 1;
  }

  d2b[size] = '\0';
  return d2b;
}


char* decimal_to_hex(int n)
{   
  static char d2h[2 * sizeof(n) + 1];
  int size = 2 * sizeof(n);
  int i = size -1;
  int temp;
	int j=0;
  while(i--)
  {
    temp = (n&(0xf<<(4*i)))>>(4*i);
    if(temp > 9){
      d2h[j] = 'A'+temp-10;
    } else{
      d2h[j] = '0'+temp;
    }
    j++;
  }
	d2h[size] = '\0';
  return d2h;
}

char* decimal_to_octal(int n){

  static char d2o[2 * sizeof(n) + 1];
  int size = sizeof(n) - 1;
  int p,m,a[100];

	for(m=0;n>0;m++)
	{
		a[m]=n%8;
		n=n/8;
    d2o[size] = a[m] + '0';
    size--;
	}

  d2o[size] = '\0';
  return d2o;
}

