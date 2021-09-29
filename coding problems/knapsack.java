import java.util.HashMap;
import java.util.Scanner;
import java.util.Arrays;

public class knapsack 
{
    static void printArray(float[][] arr,int row, int col)
    {
        System.out.println("\n\nKnapsack array : \n");

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                System.out.print(arr[i][j] + "  ");
            }
            System.out.println("");
        }

        System.out.println("");
    }

    static float findProfit(HashMap<Integer,Integer> items,int limit)
    {
        int n = items.size();
        float[][] arr = new float[n + 1][limit + 1];
        int[] keys = new int[n];
        int i = 0;
        
        for(Integer key : items.keySet())
        {
            keys[i] = key; 
            i+=1;
        } 

        Arrays.sort(keys);

        for(i=1 ;i < n + 1; i++)
        {
            for(int j=1 ;j < limit + 1; j++)
            {
                if(keys[i - 1] <= j) arr[i][j] = Math.max(arr[i-1][j] , arr[i-1][j - keys[i - 1]] + items.get(keys[i - 1]));
                else arr[i][j] = arr[i-1][j];
            }
        }

        printArray(arr, n + 1, limit + 1);
  
        
        return arr[n][limit];
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int key = 0,val = 0,n = 0,limit = 0;
        HashMap<Integer,Integer> items= new HashMap<Integer,Integer>();

        items.put(2,1);
        items.put(3,2);
        items.put(4,5);
        items.put(5,6);

        System.out.print("enter no of elements in knapsack : ");
        n = sc.nextInt();

        for(int i=0;i<n;i++)
        {
            System.out.print("\nenter weight , value : ");
            key = sc.nextInt();
            val = sc.nextInt();

            items.put(key, val);
        }

        System.out.print("\nenter max weight limit of knapsack : ");
        limit = sc.nextInt();
        System.out.println("\nprofit : " + findProfit(items,limit));
    }
}
