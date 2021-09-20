class heap2
{
    int[] arr;
    int size=0;

    heap2(int n)
    {
        arr = new int[n];
        System.out.println("created space of size : "+ n);
    }

    public void insert(int val)
    {
        arr[size] = val;
        int index = size;
        int parent = (index - 1)/2;

        while(parent>=0 && arr[parent] > arr[index])
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

    public int getMin()
    {
        return arr[0];
    }

    public void removeMin()
    {
        //get max 
        int min = arr[0];

        System.out.println("min element "+ min + " removed from heap ");

        //set the top element as the last element in the heap
        arr[0] = arr[size - 1];
        size-=1; // decrement the size of the heap as the last element was added as first element in the heap

        minHeapify(0);
    }

    public void minHeapify(int index)
    {
        int l,r;

        l = 2 * index + 1;
        r = 2 * index + 2;

        int smallest = index;

        if(l < size && arr[l]<arr[smallest])  // check if left node of the index is greater than the index if present
        smallest = l;

        if(r < size && arr[r]<arr[smallest])  // check if right node of the index is greater than the index if present
        smallest = r;

        if(smallest!=index) // if smallest is either of the child nodes then swap with the smallest node
        {
            int temp = arr[smallest];
            arr[smallest] = arr[index];
            arr[index] = temp;
        
            minHeapify(smallest);
        }

    }    
}

public class min_heap
{
    public static void main(String args[])
    {
        heap2 h = new heap2(10);

        h.insert(4);
        h.insert(10);
        h.insert(7);
        h.insert(11);
        h.insert(5);
        h.insert(2);
        h.insert(12);

        //h.removeMin();

        for(int i=0;i<h.size;i++)
        {
            System.out.println(h.arr[i]);
        }
    }
}