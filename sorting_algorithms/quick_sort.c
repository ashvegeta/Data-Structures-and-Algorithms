#include<stdio.h>

int swap(int* a,int* b)
{
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b; 
}

int partition(int* arr,int start,int end)
{
   int pivot = arr[end];
   int pidx = start;
   int temp;

   for(int i=start;i<end;i++)
   {
     if(arr[i]<=pivot)
     {
       temp = arr[i];
       arr[i] = arr[pidx];
       arr[pidx] = temp;
       //swap(&arr[i],&arr[pidx]);
       pidx++;      
     }
   }

    temp = arr[pidx];
    arr[pidx] = arr[end];
    arr[end] = temp;
   //swap(&arr[pidx],&arr[end]);

   return pidx;
}

void sort(int* arr,int start,int end)
{	
 if(start<end)
 {
   int pidx = partition(arr,start,end);

   sort(arr,start,pidx-1);
   sort(arr,pidx+1,end); 
 }

}

int main()
{
   int i,n;

   printf("enter size of array : ");
   scanf("%d",&n);

   int arr[n];

   printf("enter elements of array : ");

   for(i=0;i<n;i++)
   {
     scanf("%d",&arr[i]);
   }

   sort(arr,0,n-1);

   for(i=0;i<n;i++)
   {
     printf("%d ",arr[i]);
   }
}
