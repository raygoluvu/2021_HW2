#include <stdio.h>
#include <stdlib.h>

//declare struct, functions
struct ncs
{
    char name[10];
    char class[10];
    int score;
};
typedef struct ncs NCS;
void option();
void input(FILE *fPtr);
int numberOfStudents(FILE *fPtr);

//main funtcion
int main()
{
    FILE *filePtr = fopen("q4file.txt", "a+"); //open a file that can be appended texts.
    int selection = 0;
    int selection2 = 1;
    int counter = 0;
    char s[20] = {""};
    while (selection != -1)
    {
        option(); //pop the question.
        scanf("%d", &selection);
        printf("Your selection: %d\n", selection);

        switch (selection)
        {
        //case 1 let users to input grades.
        case 1:
            while (selection2 != 0)
            {
                puts("You\'re inputting grades currently.");
                input(filePtr);
                counter++;
                printf("%d record has been added.\n", counter);
                puts("Would you like to add new records? 1 for yes, 0 for no");
                scanf("%d", &selection2);
            }
            printf("Leaving the function...\n\n");
            rewind(filePtr); //let pointer point to the head of the file.
            break;

        //case 2 count the number of student in the file.
        case 2:
            printf("There are %d student(s):\n", numberOfStudents(filePtr));
            rewind(filePtr);
            while (fgets(s, 20, filePtr) != NULL)
            {
                printf("%s", s);
            }
            break;
        //case -1 to end the programe.
        case -1:
            printf("Bye!\n");
            break;
        //when input value not one of choice above the print the text then ask users input again.
        default:
            printf("Please enter a valid number.");
            break;
        }
    }
    return 0;
}

//the choice that users can chooce.
void option()
{
    puts("Welcome, enter choice:");
    puts("1 to input new grades,");
    puts("2 to print out all records in current file,");
    puts("-1 to leave.");
}

//write the input data into the file.
void input(FILE *fPtr)
{
    NCS temp;
    printf("Please enter student's name: ");
    scanf("%s", temp.name);
    printf("Please enter the student's class: ");
    scanf("%s", temp.class);
    printf("Please enter the student's score: ");
    scanf("%d", &temp.score);
    fprintf(fPtr, "%s %s %d\n", temp.name, temp.class, temp.score);
}

//count how many lines in the file to determine the amount of data.
int numberOfStudents(FILE *fPtr)
{
    int newline = 0;
    char c;
    while ((c = fgetc(fPtr)) != EOF)
    {
        if (c == '\n')
        {
            newline++;
        }
    }
    return newline;
}
