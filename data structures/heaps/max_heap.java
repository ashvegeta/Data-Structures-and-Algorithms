class heap1
{
    int[] arr;
    int size=0;

    heap1(int n)
    {
        arr = new int[n];
        System.out.println("created space of size : "+ n);
    }

    public void insert(int val)
    {
        arr[size] = val;
        int index = size;
        int parent = (index - 1)/2;

        while(parent>=0 && arr[parent] < arr[index])
        {
            // if the above is the condition then swap
            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;


            //then select index's parent and repeat the same process with its parent
            index = parent;
            parent = (index - 1)/2;
        }

        size++;
    }

    public int getMax()
    {
        return arr[0];
    }

    public void removeMax()
    {
        //get max 
        int max = arr[0];

        System.out.println("max element "+ max + " removed from heap ");

        //set the top element as the last element in the heap
        arr[0] = arr[size - 1];
        size-=1; // decrement the size of the heap as the last element was added as first element in the heap

        maxHeapify(0);
    }

    public void maxHeapify(int index)
    {
        int l,r;

        l = 2 * index + 1;
        r = 2 * index + 2;

        int largest = index;

        if(l < size && arr[l]>arr[largest])  // check if left node of the index is greater than the index if present
        largest = l;

        if(r < size && arr[r]>arr[largest])  // check if right node of the index is greater than the index if present
        largest = r;

        if(largest!=index) // if largest is either of the child nodes then swap with the largest node
        {
            int temp = arr[largest];
            arr[largest] = arr[index];
            arr[index] = temp;
        
            maxHeapify(largest);
        }

    }    
}

public class max_heap
{
    public static void main(String args[])
    {
        heap1 h = new heap1(10);

        h.insert(4);
        h.insert(10);
        h.insert(7);
        h.insert(11);
        h.insert(5);
        h.insert(2);
        h.insert(12);

        h.removeMax();

        for(int i=0;i<h.size;i++)
        {
            System.out.println(h.arr[i]);
        }
    }
}