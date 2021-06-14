#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fPtr = fopen("hw2_q1.txt", "r+"); //open a file to write, when it doesn't exits then create one.
    char word[20] = {""};
    char target[] = {"money"};
    int counter = 0;
    char str[100] = {""};

    //count the number of words which meet the requirments.
    while (!feof(fPtr))
    {
        fscanf(fPtr, "%s", word);
        if (strcmp(target, word) == 0)
        {
            counter++;
        }
    }
    fprintf(fPtr, "\n%s%d%s\n", "The number of times for the word \"money\": ", counter, " times.");
    fclose(fPtr); //close file

    //open a file to read only.
    fPtr = fopen("hw2_q1.txt", "r");
    //print the content.
    while (fgets(str, 1000, fPtr))
    {
        printf("%s", str);
    }
    fclose(fPtr);
}