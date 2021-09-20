import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

class heaps
{
    PriorityQueue<Integer> heap;
    int[] arr;

    heaps(int[] array)
    {
        arr = array;
    }

    public void minHeap()
    {
        heap = new PriorityQueue<>();

        System.out.println("min heap created");

        for(int i=0;i<arr.length;i++)
        {
            heap.add(arr[i]);
            System.out.println(heap.peek());
        }
    }

    public void maxHeap()
    {
        heap = new PriorityQueue<>(Collections.reverseOrder());

        System.out.println("max heap created");

        for(int i=0;i<arr.length;i++)
        {
            heap.add(arr[i]);
            System.out.println(heap.peek());
        }
    }   
}

public class heaps_java_lib
{    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("enter size of heap: ");
        int size = sc.nextInt();

        int[] arr = new int[size];

        for(int i=0;i<size;i++)
        arr[i] = sc.nextInt();

        System.out.print("\n\n1. min heap \n2. max heap\n\nEnter choice : ");
        int ch = sc.nextInt();

        if(ch==1)
        {
            heaps h = new heaps(arr);
            h.minHeap();
        }

        else
        {
            heaps h = new heaps(arr);
            h.maxHeap();
        }
       
        sc.close();
    }
}
