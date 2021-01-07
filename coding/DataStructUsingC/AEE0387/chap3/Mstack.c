/* File name: Mstack.c */
/* Version 4.0, June, 2017 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX  10
#define UNIT  2
void pushFunction(int number1);
void popFunction(int number2);
void listFunction(int number3);

char MS[MAX][20];
int t[(MAX/UNIT)], b[(MAX/UNIT)];

int main()
{
    int option, i;
    int  number1, number2, number3;
    
    for (i=0; i<= UNIT-1; i++){
        if (UNIT == 1) {
            t[i+1] = MAX-1;
            b[i+1] = MAX-1;
            t[i] = i*(MAX/UNIT)-1;
            b[i] = i*(MAX/UNIT)-1;
        }
        else {
            t[i] = i*(MAX/UNIT)-1;
            b[i] = i*(MAX/UNIT)-1;
        }
    }
    while(1){
        printf("\n *****************************\n");
        printf("        <1> insert (push)\n");
        printf("        <2> delete (pop)\n");
        printf("        <3> list\n");
        printf("        <4> quit\n");
        printf(" *****************************\n");
        printf(" Please enter your choice...");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("\n The total number of Stack is %d !!", UNIT);
                printf("\n Please enter the number of stack ?");
                scanf("%d",&number1);
                if (number1 > UNIT)
                    printf(" Sorry, the number is out of Stack total 								number !!\n");
                else
                    pushFunction(number1);
                break;
            case 2:
                printf("\n Please enter the number of stack ?");
                scanf("%d",&number2);
                if (number2 > UNIT)
                    printf(" Sorry, the number is out of Stack total number !!\n");
                else
                    popFunction(number2);
                break;
            case 3:
                printf("\n Please enter the number of stack ?");
                scanf("%d",&number3);
                if (number3 > UNIT)
                    printf(" Sorry, the number is out of Stack total number !!\n");
                else
                    listFunction(number3);
                break;
            case 4:
                printf("\n");
                return 0;
        }
    }
}

void pushFunction(int number1)
{
    if(t[number1-1] == b[number1]){
        printf(" Stack%d is full !\n",number1);
        printf(" Please choose another Stack to insert !!\n");
    }
    else{
        printf(" Please enter item to insert: ");
        scanf("%s",&MS[++t[number1-1]]);
        printf(" You insert %s to #%d stack !!\n", MS[t[number1-1]], number1 );
    }
}

void popFunction(int number2)
{
    if(t[number2-1] == b[number2-1])
        printf("\n No item, stack%d is empty !\n",number2);
    else{
        printf("\n Item %s in Stack %d is deleted\n",MS[t[number2-1]], number2);
        t[number2-1]--;
    }
}

void listFunction(int number3)
{
    int count = 0, i, startNumber = 0;
    if(t[number3-1] == b[number3-1])
        printf("\n No item, stack is empty\n");
    else{
        startNumber = (number3-1)*(MAX/UNIT)-1;
        printf("\n  ITEM\n");
        printf(" ------------------\n");
        for(i = startNumber+1 ; i <= t[number3-1]; i++){
            printf("  %-20s\n", MS[i]);
            count++;
            if(count % 20 == 0) getchar();
        }
        printf(" ------------------\n");
        printf("  Total item: %d\n", count);
    }
}