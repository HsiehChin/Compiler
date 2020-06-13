#include <stdio.h>
#include <stdbool.h>
#include<math.h>

int factorial(int a);
int permutation(int n, int r);
int combination(int n, int r);
char* decimal_to_binary(int n);
char* decimal_to_hex(int n);
char* decimal_to_octal(int n);
void print(int size, int i, double n);
void print_double_ans(int size, int crt_size, double n);
void print_int_ans(int size, int crt_size, int n);


bool check_type(double answer){
  double tmp = answer;
  tmp*= 10000.0;
  tmp = (int)tmp%10000;
  return (tmp==0.0)?true:false;
}

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
  int temp = size;
  int i;
  
	for(m=0;n>0;m++)
	{
		a[m]=n%8;
		n=n/8;
    d2o[temp] = a[m] + '0';
    temp--;
	}
  
  for(i = temp ; i >= 0; i--){
    d2o[i] = '0';
  }

  return d2o;
}

void show_vec(double *vec, int size){
  int i;
  printf("answer:(");
  for(i = 0; i < size; i++) printf("%.2lf ", vec[i]);
  printf(")\n");
}

void vec_sort(double *vec, int size){
	double tmp;
  int i, j;
	for(i = 0; i < size; i++){
		for(j = i + 1; j < size; j++){
			if(vec[i] > vec[j]){
				tmp = vec[i];
				vec[i] = vec[j];
				vec[j] = tmp;
			}
		}
	}
}

double median(double *vec, int size){
	double median;
  int i;
	vec_sort(vec, size);
	if(size % 2 == 0) median = (vec[size/2-1]+vec[size/2])/2;
	else median = vec[size/2];
  return median;
}

double max(double *vec, int size){
	vec_sort(vec, size);
  return vec[size-1];
}

double min(double *vec, int size){
	vec_sort(vec, size);
  return vec[0];
}

void vec_plus(double *v1, double *v2, int size){
  int i;
  double tmp[10];
  for(i = 0; i < size; i++) tmp[i] = v1[i] + v2[i];
  show_vec(tmp, size);
}

void vec_minus(double *v1, double *v2, int size){
  int i;
  double tmp[10];
  for(i = 0; i < size; i++) tmp[i] = v1[i] - v2[i];
  show_vec(tmp, size);
}

double vec_inner(double *v1, double *v2, int size){
  int i;
  double ans = 0;
  for(i = 0; i < size; i++) ans += v1[i]*v2[i];
  return ans;
}

void vec_outer(double *v1, double *v2, int size){
  int i;
  double tmp[3];
  tmp[0] = v1[1]*v2[2]-v1[2]*v2[1];
  tmp[1] = v1[2]*v2[0]-v1[0]*v2[2];
  tmp[2] = v1[0]*v2[1]-v1[1]*v2[0];
  show_vec(tmp, size);
}

int check_size_zero(int size){//for one vector
  return (size == 0) ? 0 : 1;
}

int cmp_vec_size(int size1, int size2){//for two vector
  if(size1 == size2 && size1 == 3) return 0;
  else return (size1 == size2) ? 1 : -1;
}

double vector(){
  double *v1, *v2, *temp1, *temp2;
  int size1, size2;
  int num, vec_id, i;
  printf("vector1 size:");
  scanf("%d", &size1);
  if(size1 > 0){
    printf("vector1:");
    v1 = (double*)malloc(sizeof(double)*size1);
    temp1 = (double*)malloc(sizeof(double)*size1);
    for(i = 0;i < size1; i++) scanf("%lf", &v1[i]);
    printf("v1:(");
    for(i = 0;i < size1; i++) {
      printf("%.2lf ", v1[i]);
      temp1[i] = v1[i];
    }
    printf(")\n");
  }
  printf("vector2 size:");
  scanf("%d", &size2);
  if(size2 > 0){
    printf("vector2:");
    v2 = (double*)malloc(sizeof(double)*size2);
    temp2 = (double*)malloc(sizeof(double)*size2);
    for(i = 0;i < size2; i++) scanf("%lf", &v2[i]);
    printf("v2:(");
    for(i = 0;i < size2; i++) {
      printf("%.2lf ", v2[i]);
      temp2[i] = v2[i];
    }
    printf(")\n");
  }
  while(1){
    double ans;
    if(size1 > 0 || size2 > 0){
      printf("1 : find median, 2 : find maximum, 3 : find minimum, 4 : plus, 5 : minus,\n");
      printf("6 : inner product, 7 : outer product, 8 : sorting, -1 : leave\n");
      scanf("%d", &num);
      getchar();
      if(num == 1 || num == 2 || num == 3 || num == 8){//median, max, min, sort
        printf("choose which vector(1 or 2):");
        scanf("%d", &vec_id);
        getchar();
        int k = (vec_id == 1) ? check_size_zero(size1) : check_size_zero(size2);
        if(k == 0) printf("vector size is zero\n");
        else{
          if(num == 8){
            if(vec_id == 1){
              vec_sort(temp1, size1);
              show_vec(temp1, size1);
            }
            else{
              vec_sort(temp2, size2);
              show_vec(temp2, size2);
            }
          }
          else{
            if(num == 1) ans = (vec_id == 1) ? median(temp1, size1) : median(temp2, size2);
            else if(num == 2) ans = (vec_id == 1) ? max(temp1, size1) : max(temp2, size2);
            else if(num == 3) ans = (vec_id == 1) ? min(temp1, size1) : min(temp2, size2);
            printf("answer = %.2lf\n", ans);
          }
        }
      }
      else if(num == 4||num == 5||num == 6){//plus, minus, inner product
        int k = cmp_vec_size(size1, size2);
        if(k == -1) printf("different vectors size\n");
        else{
          if(num == 4) vec_plus(v1, v2, size1);
          else if(num == 5) vec_minus(v1, v2, size1);
          else if(num == 6) {
            ans = vec_inner(v1, v2, size1);
            printf("answer = %.2lf\n", ans);
          }
        }
      }
      else if(num == 7){//outer product
        int k = cmp_vec_size(size1, size2);
        if(k == 0) vec_outer(v1, v2, size1);
        else printf("differet vectors size or size error\n");
      }
      else if(num == -1) {
        printf("Return 0 means leave vector successful\n"); 
        return 0;
      }
    }
  }
  return 0;
}

double calculus(){
  double *v1;
  int size;
  int num, i;
  printf("please enter your highest exponential size: ");
  scanf("%d", &size);
  if(size >= 0){
    printf("please enter constant term, separated by one space: ");
    v1 = (double*)malloc(sizeof(double)*size);
    for(i = size;i >= 0; i--) scanf("%lf", &v1[i]);
    if(size > 0 && v1[size] == 0) {
      printf("Illegal input!\n");
      printf("Return 0 means leave calculus successful\n"); 
      return 0;
    }
    printf("your polynomial: ");
    for(i = size;i >= 0; i--) {
      print(size, i, v1[i]);
    }
    printf("\n");
  }
  while(1){
    double ans;
    if(size >= 0){
      printf("1 : differential, 2 : integral, -1 : leave\n");
      scanf("%d", &num);
      getchar();
      printf("ans = ");
      if(num == 1){
        if(size == 0) printf("0");
        else {
          for(i = size; i >= 1; i--){
            double constant = (double)v1[i]*(double)i;
            print(size-1, i-1, constant);
          }
        }
        printf("\n");
      }
      else if(num == 2){
        if(size == 0 && v1[size] == 0) printf("0");
        else {
          for(i = size; i >= 0; i--){
            double constant = (double)v1[i] / (double)(i+1);
            print(size+1, i+1, constant);
          }
        }
        printf("\n");
      }
      else if(num == -1) {
        printf("Return 0 means leave calculus successful\n"); 
        return 0;
      }

    }
  }
}

void print(int size, int i, double n){
  if((n > 0 && n - (int)n > 0) || (n < 0 && n - (int)n < 0)) {
    print_double_ans(size, i, n);
  }
  else {
    print_int_ans(size, i, (int)n);
  }
}

void print_double_ans(int size, int crt_size, double n){
  if(size == 0) printf("%.4lf", n);
  else if(size == 1) {
      if(n == 1) printf("x");
      else if(n == -1) printf("-x");
      else printf("%.4lfx", n);
  }
  else if(crt_size == size) {
    printf("%.4lfx^%d", n, crt_size);
  }
  else {
    char sign = '+';
    if(n < 0){
      sign = '-';
      n *= (-1);
    }
    if(crt_size == 1) {
      printf(" %c %.4lfx", sign, n);
    }
    else if(crt_size == 0) printf(" %c %.4lf", sign, n);
    else {
      printf(" %c %.4lfx^%d", sign, n, crt_size);
    }
  }
}

void print_int_ans(int size, int crt_size, int n){
  if(size == 0) printf("%d", n);
  else if(n != 0) {
    if(size == 1) {
      if(n == 1) printf("x");
      else if(n == -1) printf("-x");
      else printf("%dx", n);
    }
    else if(crt_size == size) {
      if(n == 1) printf("x^%d", crt_size);
      else if(n == -1) printf("-x^%d", crt_size);
      else printf("%dx^%d", n, crt_size);
    }
    else {
      char sign = '+';
      if(n < 0){
        sign = '-';
        n *= (-1);
      }
      if(crt_size == 1) {
        if(n == 1) printf(" %c x", sign);
        else printf(" %c %dx", sign, n);
      }
      else if(crt_size == 0) printf(" %c %d", sign, n);
      else {
        if(n == 1)  printf(" %c x^%d", sign, crt_size);
        else printf(" %c %dx^%d", sign, n, crt_size);
      }
    }
  }
}