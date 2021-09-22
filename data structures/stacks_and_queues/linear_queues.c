#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define MAX_SIZE 5

typedef struct
{
    int data;
    /* extra data */
} queues;

queues queue[MAX_SIZE];
int front = 0,rear = 0;

bool insert(int val)
{
    if(rear==MAX_SIZE) return false;

    queue[rear++].data =  val;

    return true;
}

int pop()
{
    if(front==rear) return INT_MIN;

    return queue[front++].data;
}

void display()
{
    if(front==rear)
    {
        printf("\n\n queue is empty !! \n\n");
        return;
    }

    printf("\n\n");

    for(int i=front;i<rear-1;i++)
    {
        printf(" %d --",queue[i].data);
    }

    printf(" %d ",queue[rear-1].data);
}

int peek()
{
    if(front==rear) return INT_MIN;

    return queue[front].data;
}

int isempty()
{
    if(front==rear) return 1;

    return 0;
}

int isfull()
{
    if(rear==MAX_SIZE) return 1;

    return 0;
}

int main()
{
    int no,ch;

    while(1)
    {
        printf("\n\nMenu:\n1.add\n2.pop\n3.peek\n4.display\n5.exit\n");
        printf("\nenter choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            if(isfull()==1)
            {
                printf("\n\n queue is full !! \n\n");
                continue;
            }

            printf("\nenter number to add: ");
            scanf("%d",&no);
            if(insert(no)==true)
            printf("\nsuccessfully inserted !!\n\n");
            else
            printf("\n failed to insert element %d\n\n",no);  
            break;
        
        case 2:
            no = pop();
            if(no!=INT_MIN)
            printf("\n%d removed from front of queue\n",no);
            else
            printf("\n\n queue is empty !!\n\n");
            break;

        case 3:
            no = peek();
            if(no!=INT_MIN)
            printf("\nfront of queue : %d\n",no);
            else
            printf("\n\n queue is empty !! \n\n");
            break;

        case 4:
            display();
            break;
        
        default:
            return 1;
        }
    }
}
