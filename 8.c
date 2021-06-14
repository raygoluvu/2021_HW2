#include <stdio.h>
#include <string.h>
void numOfRecords(FILE *);
int main(int argc , char *argv[]){
 // Number of input files is argc - 1
 FILE *fPtr[argc - 1]; // file pointers
 char tempStr[10000];
 char output[10000]; // used to store contents of all files
 // "header" is a flag variable used to check the first line of the text file.
 int header = 1, i, counter = 0; //"counter calculate how many records are in output
file"

 for(i = 1; i < argc;i++){
 // open files for reading
 if( (fPtr[i] = fopen(argv[i],"r")) == NULL)
 printf("Error, the file %s cannot be opened!\n", argv[i]);
 else{
 while(fgets(tempStr,10000,fPtr[i])){
 if(header == 1 ){
 strcpy(output,tempStr);
 header = 0;
 }
 else
 strcat(output,tempStr);
 }
 fclose(fPtr[i]);
 }
 }
 //printf("%d\n", header);
 FILE *fMtcars; // output mtcars.txt
 if ((fMtcars = fopen("mtcars.txt","w"))== NULL)
 printf("Error, the file mtcars.txt cannot be opened!\n");
 else{
 fprintf(fMtcars,"%s", output);
 fclose(fMtcars);
 }

 numOfRecords(fMtcars);

 return(0);
}
struct cars{
 char brand[20];
 char type[20];
 float mpg;
 int cyl;
 float disp;
 int hp;
};
void numOfRecords(FILE *fPtr){
 int count = 0;

 if ((fPtr = fopen("mtcars.txt","r"))== NULL)
 printf("Error, the file mtcars.txt cannot be opened!\n");
 else{
 printf("%10s %10s %6s %5s %6s %5s\n", "brand", "type", "mpg", "cyl", "disp",
"hp");
 while(!feof(fPtr)){
 struct cars car = {"", "", 0.0, 0, 0.0, 0};

 fscanf(fPtr, "%s %s %f %d %f %d\n", car.brand, car.type, &car.mpg, &car.cyl,
&car.disp, &car.hp);
 if(car.mpg > 20){
 printf("%10s %10s %6.1f %5d %6.1f %5d\n", car.brand, car.type, car.mpg,
car.cyl, car.disp, car.hp);
 count++;
 }
 }
 printf("There are %d car(s) whose mpg > 20.\n", count);
 fclose(fPtr);
 }
}
