import java.util.*;

class minH {
    private ArrayList<Integer> heap;
    minH(){
        heap=new ArrayList<>();
    }

    private int parent(int i){
        return (i-1)/2;
    }
    private int left(int i){
        return 2*i+1;
    }
    private int right(int i){
        return 2*i+2;
    }

    private void swap(int i,int j){
        int temp=heap.get(i);
        heap.set(i,heap.get(j));
        heap.set(j,temp);
    }

    void insert(int val){
        heap.add(val);
        int i=heap.size()-1;
        while(i>0 && heap.get(parent(i))>heap.get(i)){
            swap(parent(i),i);
            i=parent(i);
        }
    }

    int getMin(){
        if(heap.isEmpty()) throw new IllegalStateException("Heap is Empty");
        else 
        return heap.get(0);
    }

    int extractMin(){
        if(heap.isEmpty()) throw new IllegalStateException("Heap is Empty");
        else{
            int min=heap.get(0);
            int last=heap.remove(heap.size()-1);
            if(!heap.isEmpty()){
                heap.set(0,last);
                heapify(0);
            }
            return min;
        }
    }

    private void heapify(int i){
        int small=i;
        int left=left(i);
        int right=right(i);
        if(left<heap.size()-1 && heap.get(left)<heap.get(small))
        small=left;
        if(right<heap.size()-1 && heap.get(right)<heap.get(small))
        small=right;
        if(small!=i){
            swap(i,small);
            heapify(small);
        }
    }

    void display(){
        for(int i:heap)
        System.out.print(i+" ");
        System.out.println();
    }
}

public class minHeap{
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        minH h1=new minH();
        System.out.println("MINHEAP\n*********");
        System.out.println("1.Insert\n2.GetMin\n3.ExtractMin\n4.Display\n5.exit");
        while(true){
            System.out.print("Enter your choice:");
            int c=scan.nextInt();
            if(c==1){
                System.out.print("Enter value to insert:");
                h1.insert(scan.nextInt());
            }
            else if(c==2)
            System.out.println("Minimum value:"+ h1.getMin());
            else if(c==3)
            System.out.println("Minimum value Extracted:"+h1.extractMin());
            else if(c==4){
                System.out.println("Sorted List:");
                h1.display();
            }
            else if(c==5)
            break;
            else
            System.out.println("Enter correct choice");
        } 
        scan.close();

    }
}