#include<stdio.h>

void merge(int* arr,int low,int mid,int high)
{	
   int i,j,l1,l2;

   l1 = mid - low + 1;
   l2 = high - mid;

   int l[l1],r[l2];

   for(i=0;i<l1;i++)
	   l[i] = arr[low + i];
   
   for(j=0;j<l2;j++)
	   r[j] = arr[mid + 1 + j]; 
   

   i=0;
   j=0;
   int k = low;

   while(i<l1 && j<l2)
   {
     if(l[i]<=r[j])
     {
       arr[k] = l[i];
       i++;
       k++;
     }

     else
     {
       arr[k] = r[j];
       j++;
       k++;
     }
   }


   while(i<l1)
   {
      arr[k] = l[i];
      i++;
      k++;
   }

   while(j<l2)
   {
     arr[k] = r[j];
     j++;
     k++;
   }
   

}

void sort(int* arr,int low,int high)
{
   if(low<high)
   {
      int mid = low + (high - low)/2 ;

      sort(arr,low,mid);
      sort(arr,mid+1,high);

      merge(arr,low,mid,high); 
   }
}

int main()
{
  int i,n;
 
  printf("enter size of array : ");
  scanf("%d",&n);

  int arr[n];

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
