#include<stdio.h>

void sort(int* arr,int n)
{
   int i,j,temp;

   for(i=0;i<n;i++)
   {
     for(j=0;j<n-i-1;j++)
     {
       if(arr[j]>arr[j+1])
       {
          temp = arr[j+1];
	  arr[j+1] = arr[j];
	  arr[j] = temp;
       }
     }
   }
}

int main()
{
   int i,n;

   printf("enter size of array : \n");
   scanf("%d",&n);

   int arr[n];

   printf("\n enter elements of array : \n");
   for(i=0;i<n;i++)
   {
     scanf("%d",&arr[i]);
   }

   sort(arr,n);

   for(i=0;i<n;i++)
   {
     printf("%d ",arr[i]);
   }
}
