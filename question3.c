#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//declare structure, global varaible, functions.
typedef struct listnode
{
    char data;
    int linkNum;
    int flag;
    struct listnode *nodeList[25];
} ListNode;

typedef struct listnode *ListNodePtr;

void displaynodeList(ListNodePtr sPtr);
int isConnected(ListNodePtr node1, ListNodePtr node2);
void connect(ListNodePtr sPtr, ListNodePtr oPtr);
void resetFlag(ListNodePtr net[], int n);
ListNodePtr newNode(char c);

int main()
{

    //initialize
    ListNodePtr aPtr = newNode('a');
    ListNodePtr bPtr = newNode('b');
    ListNodePtr zPtr = newNode('z');
    ListNodePtr gPtr = newNode('g');
    ListNodePtr hPtr = newNode('h');
    ListNodePtr yPtr = newNode('y');
    ListNodePtr fPtr = newNode('f');
    ListNodePtr xPtr = newNode('x');

    int num = 8;
    ListNodePtr net[] = {aPtr, bPtr, zPtr, gPtr, hPtr, yPtr, fPtr, xPtr};

    //connect nodes
    connect(aPtr, bPtr);
    connect(bPtr, zPtr);
    connect(bPtr, gPtr);
    connect(gPtr, hPtr);
    connect(yPtr, fPtr);
    connect(yPtr, xPtr);

    //check the result
    displaynodeList(yPtr);
    displaynodeList(xPtr);
    displaynodeList(bPtr);

    printf("Is \"x\" and \"a\" connected? : %s\n", isConnected(xPtr, aPtr) ? "Yes" : "No");
    resetFlag(net, num);
    printf("Is \"a\" and \"b\" connected? : %s\n", isConnected(aPtr, bPtr) ? "Yes" : "No");
    resetFlag(net, num);
    printf("Is \"a\" and \"h\" connected? : %s\n", isConnected(aPtr, hPtr) ? "Yes" : "No");
    return 0;
}

//connect two nodes.
void connect(ListNodePtr strPtr, ListNodePtr oPtr)
{
    strPtr->nodeList[strPtr->linkNum++] = oPtr;
    oPtr->nodeList[oPtr->linkNum++] = strPtr;
}

//determine if two nodes connected.
int isConnected(ListNodePtr node1, ListNodePtr node2)
{
    node1->flag = 1; //if the node has been checked the flag value set to 1.
    int index = 0;   //start from the first element of nodeList.

    while (node1->nodeList[index] != NULL && node1->nodeList[index]->data != node2->data)
    {
        if (!node1->nodeList[index]->flag)
        {
            //recursive step.
            if (isConnected(node1->nodeList[index], node2) == 1)
            {
                break;
            }
        }
        index++;
    }
    //if True return 1, else return 0;
    return (node1->nodeList[index]) ? 1 : 0;
}

//print the connected node if the pointers in the node are not point to NULL.
void displaynodeList(ListNodePtr sPtr)
{
    int i = 0;
    ListNode cpy = *sPtr;
    while (i < cpy.linkNum)
    {
        printf("%c ", cpy.nodeList[i]->data);
        i++;
    }
    puts("");
}

//initialize a new node, give memory space to it.
ListNodePtr newNode(char c)
{
    int i;
    ListNodePtr Node = malloc(sizeof(ListNode));
    Node->data = c;
    Node->linkNum = 0;
    Node->flag = 0;
    //initialize elements of nodeList to NULL.
    for (i = 0; i < 25; i++)
    {
        Node->nodeList[i] = NULL;
    }
    return Node;
}

//reset the flag of nodes value to 0;
void resetFlag(ListNodePtr net[], int n)
{
    int i = 0;
    while (i < n)
    {
        net[i++]->flag = 0;
    }
}