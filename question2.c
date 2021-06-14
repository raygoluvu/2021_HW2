#include <stdio.h>
#include <stdlib.h>

struct listnode
{
    char data;
    struct listnode *nextPtr;
};
typedef struct listnode ListNode;
typedef ListNode *ListNodePtr;
void printRevList(ListNodePtr sPtr);
void insert(ListNodePtr *sPtr, char c);
void printNode(ListNodePtr sPtr);
void option();

//main function
int main()
{
    ListNodePtr strPtr;
    int choice = 1;
    char character;

    //while choice true
    while (choice)
    {
        option(); //pop the choice.
        scanf("%d", &choice);

        switch (choice)
        {
        //case 1 is insert new node to the linked list.
        case 1:
            scanf(" %c", &character);
            insert(&strPtr, character);
            printNode(strPtr);
            break;
        //case 2 is to print the list from behind.
        case 2:
            printf("The reverslist is:\n\n");
            if (strPtr == NULL)
            {
                printf("The list is NULL.");
            }
            printRevList(strPtr);
            puts("\n");
            break;
        }
    }
    return 0;
}

void insert(ListNodePtr *sPtr, char c)
{
    //initialize
    ListNodePtr previousPtr, currentPtr, newPtr;
    newPtr = malloc(sizeof(ListNode));
    currentPtr = *sPtr;
    previousPtr = NULL;
    newPtr->data = c;
    newPtr->nextPtr = NULL;

    //find the right place we need.
    while (currentPtr != NULL && c > currentPtr->data)
    {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    //當遇到newnode是第一個插入的node或是newnode是最小的node
    if (previousPtr == NULL)
    {
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
    }
    //insert the newnode between previous node and current node.
    else
    {
        newPtr->nextPtr = previousPtr->nextPtr;
        previousPtr->nextPtr = newPtr;
    }
}

void printNode(ListNodePtr sPtr)
{
    //determine if the list is empty.
    if (sPtr == NULL)
    {
        printf("The list is empty!\n");
    }
    //print nodes in the list in order.
    else
    {
        printf("The list now is:\n\n");
        while (sPtr)
        {
            printf("%c-->", sPtr->data);
            sPtr = sPtr->nextPtr;
        }
    }
    puts("NULL\n");
}

void printRevList(ListNodePtr sPtr)
{
    //recursive step
    if (sPtr->nextPtr != NULL)
    {
        printRevList(sPtr->nextPtr);
        printf("<--%c", sPtr->data);
    }
    //base step
    else
    {
        printf("%s<--%c", "NULL", sPtr->data);
    }
}

void option()
{
    puts("Enter your choice");
    puts("1 to insert a character.");
    puts("2 to print the list from behind.");
    printf("0 to end.\n:");
}