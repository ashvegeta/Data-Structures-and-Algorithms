#include<stdio.h>
#include<limits.h>

#define MAX_SIZE 100

typedef struct
{
    int data;
    /* extra data */
} stack;

stack arr[MAX_SIZE];
int top = -1;

void insert(int val)
{
    if(top==MAX_SIZE)
    {
        printf("stack full !!");
        return;
    }

    arr[++top].data = val;
}

int pop()
{
    if(top==-1)
    return INT_MIN;

    return arr[top--].data; 
}

int getTop()
{
    if(top==-1)
    return INT_MIN;

    return arr[top].data;
}

void display()
{
    if(top==-1)
    {
        printf("\n\nstack empty !!\n\n");
        return;
    }

    for(int i= top;i>=0;i--)
    {
        printf("\t\n-----------------\n");
        printf("|\t%d \t|",arr[i].data);
        printf("\t\n-----------------");
    }
}

int main()
{
    int no,ch;

    while(1)
    {
        printf("\n\nMenu:\n1.insert\n2.remove\n3.peek\n4.display\n5.exit\n");
        printf("\nenter choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("\nenter number to insert: ");
            scanf("%d",&no);
            insert(no);
            break;
        
        case 2:
            no = pop();
            if(no!=INT_MIN)
            printf("\n\n%d removed from top of stack\n",no);
            else
            printf("\n\n stack empty !!\n\n");
            break;

        case 3:
            no = getTop();
            if(no!=INT_MIN)
            printf("\n\ntop of stack : %d\n",no);
            else
            printf("\n\n top of stack : %d\n",no);
            break;

        case 4:
            display();
            break;
        
        default:
            return 1;
        }
    }
}