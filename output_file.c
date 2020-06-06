#include<stdio.h>
FILE *fout;

void output_file_d(double test){
    fout = fopen("out_test_code.txt","a");
    if(fout == NULL){
        printf("Fail to open out_test_code.txt!!!\n");
        return;
    }
    fprintf(fout, "%.6f\n", test);

    fclose(fout);
}

void output_file_s(char * test){
    fout = fopen("out_test_code.txt","a");
    if(fout == NULL){
        printf("Fail to open out_test_code.txt!!!\n");
        return;
    }
    fprintf(fout, "%s\n", test);

    fclose(fout);
}

/*---- Clear up the file, before write file----*/
void clear_file(){
    fout = fopen("out_test_code.txt","w");
        if(fout == NULL){
        printf("Fail to open out_test_code.txt!!!\n");
        return;
    }
    fprintf(fout, "%s", "");
     fclose(fout);
}