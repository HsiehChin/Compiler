#include<stdio.h>

int factorial(int a);
int permutation(int n, int r);
int combination(int n, int r);

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
