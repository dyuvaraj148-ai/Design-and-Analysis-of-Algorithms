import java.util.*;

public class jobdeadline {
    static class jobd{
        int profit;
        int dline;
        jobd(int profit,int dline){
            this.profit=profit;
            this.dline=dline;
        }
        void display(){
            System.out.println("profit:"+this.profit+"\ndeadline:"+this.dline);
        }
    }
    public static void main(String[] args){

        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        jobd[] arr=new jobd[n];
        for(int i=0;i<n;i++){
            int profit=scan.nextInt();
            int dline=scan.nextInt();
            arr[i]=new jobd(profit, dline);
        }

        Arrays.sort(arr,(a,b)->b.profit-a.profit);
        int maxdline=0;
        for(jobd a:arr)
        maxdline=Math.max(maxdline,a.dline);

        boolean[] slots=new boolean[maxdline];
        int maxprofit=0;
        
        for(jobd j:arr){
            for(int i=j.dline-1;i>=0;i--){
                if(!slots[i]){
                    slots[i]=true;
                    maxprofit+=j.profit;
                    break;
                }
            }   
        }
        System.out.println("Max Profit:"+maxprofit);
    }
}
