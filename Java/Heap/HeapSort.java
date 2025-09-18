import java.util.*;

class Build_Heap
{
    private int []Heap;
    private int Index = 0;

    Build_Heap()
    {
        Heap = new int[100];
    }

    void Insert(int data)
    {
        Index++;
        Heap[Index] = data;

        int parent = Index;
        // int index = Index;
        while(parent>1 && Heap[parent/2] < Heap[parent])
        {
            int temp = Heap[parent];
            Heap[parent] = Heap[parent/2];
            Heap[parent/2] = temp;

            parent = parent/2;
        }
    }

    void Delete()
    {
        if(Index<1)
            return;

        Heap[1] = Heap[Index];
        Index--;

        int index = 1;
        while(true)
        {
            int max = index;
            int left = index*2;
            int right = index*2+1;

            if(left <= Index && Heap[max] < Heap[left])
                max = left;
            
            if(right <= Index && Heap[max] < Heap[right])
                max = right;

            if(max!=index)
            {
                int temp = Heap[index];
                Heap[index] = Heap[max];
                Heap[max] = temp;

                index = max;
            }
            else
                break;
        }
    }

    void Display()
    {
        for(int i = 1; i<=Index; i++)
            System.out.print(Heap[i]+" -> ");

        System.out.println();
    }

    void HeapiFy(int tempIndex)
    {
        int index = 1;

        while(true)
        {
            int max = index;
            int left = index*2;
            int right = index*2+1;

            if(left <= tempIndex && Heap[max] < Heap[left])
                max = left;
            
            if(right <= tempIndex && Heap[max] < Heap[right])
                max = right;

            if(max!=index)
            {
                int temp = Heap[index];
                Heap[index] = Heap[max];
                Heap[max] = temp;

                index = max;
            }
            else
                break;
        }
    }

    void HeapSort()
    {
        int index = Index;

        while(index>0)
        {
            int temp = Heap[1];
            Heap[1] = Heap[index];
            Heap[index] = temp;

            index--;

            HeapiFy(index);
        }

    }
};

class HeapSort
{
    public static void main(String str[])
    {
        Build_Heap Heap = new Build_Heap();
        Heap.Insert(5);
        Heap.Insert(4);
        Heap.Insert(3);
        Heap.Insert(6);
        Heap.Insert(2);
        // Heap.Delete();
        Heap.HeapSort();
        Heap.Display();
    }
}