#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define MAX_SIZE 6

typedef struct 
{
    int data;
    /* extra data */
}circular_queue;

circular_queue queue[MAX_SIZE];
int front = 0,rear = 0,count = 0;

bool isEmpty()
{
    if(front==rear && count==0) return true;

    return false;
}

bool isFull()
{
    if(front==rear && count==MAX_SIZE) return true;

    return false;
}

bool insert(int val)
{
    if(isFull()==true) return false;

    queue[rear].data = val;
    rear = (rear + 1) % MAX_SIZE;
    count+=1;

    return true;
}

int pop()
{
    if(isEmpty()==true) return INT_MIN;

    int f = front;
    front = (front + 1) % MAX_SIZE;
    count-=1;

    return queue[f].data;
}

void display()
{
    if(isEmpty()==true)
    {
        printf("\n\nqueue is empty !! \n");
        return;
    }

    printf("\n\n");

    for(int i=0;i<count-1;i++)
    {
        printf(" %d --",queue[(i + front) % MAX_SIZE].data);
    }

    printf(" %d ",queue[rear-1].data);
}

int peek()
{
    if(isEmpty()==true) return INT_MIN;

    return queue[front].data;
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
            if(isFull()==1)
            {
                printf("\n\n queue is full !! \n\n");
                continue;
            }

            printf("\nenter number to add: ");
            scanf("%d",&no);
            if(insert(no)==true)
            printf("\nsuccessfully inserted !!\n\n");
            else
            printf("\n\n failed to insert element %d\n",no);  
            break;
        
        case 2:
            no = pop();
            if(no!=INT_MIN)
            printf("\n%d removed from front of queue\n",no);
            else
            printf("\n\nqueue is empty !!\n");
            break;

        case 3:
            no = peek();
            if(no!=INT_MIN)
            printf("\nfront of queue : %d\n",no);
            else
            printf("\n\nqueue is empty !! \n");
            break;

        case 4:
            display();
            break;
        
        default:
            return 1;
        }
    }
}