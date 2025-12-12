import java.util.PriorityQueue;
import java.util.Scanner;

public class connectRopes {
    public static void main(String[] args){

        Scanner scan =new Scanner(System.in);
        PriorityQueue<Integer> ropes=new PriorityQueue<>();
        
        int n=scan.nextInt();
        while(n-->0)
        ropes.add(scan.nextInt());

        int total=0;
        while(ropes.size()>1){
            int sum=ropes.poll()+ropes.poll();
            total+=sum;
            ropes.add(sum);
        }

        System.out.println("minimum cost:"+total);
        scan.close();
    }
}
