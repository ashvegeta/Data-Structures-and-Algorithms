#include<stdio.h>

void sort(int* arr,int n)
{
  int key,i,j;

  for(i=1;i<n;i++)
  {
     key = arr[i];

     j = i-1;

     while(j>=0 && key<arr[j])
     {
        arr[j+1]=arr[j];
	j-=1;
     } 

     arr[j+1] = key;
  }
}
int main()
{
   int i,n,no;

   printf("enter array size:\n");
   scanf("%d",&n);

   int arr[n];

   for(i=0;i<n;i++)
   {
     scanf("%d",&no); 
     arr[i] = no;
   }

   sort(arr,n);

   for(i=0;i<n;i++)
   {
     printf("%d ",arr[i]);
   }

   printf("\n");
}
