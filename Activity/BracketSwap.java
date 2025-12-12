import java.util.Scanner;

public class bracketswap {
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
        arr[i]=scan.nextInt();
        scan.close();

        int swaps=0,count_close=0,count_open=0,imbalance=0;
        for(int a:arr){
            if(a=='['){
                count_open++;
                if(imbalance>0){
                    swaps+=imbalance;
                    imbalance--;
                }
            }
            else{
                count_close++;
                imbalance=count_close-count_open;    
            }
        }
        System.out.println(swaps);
    }
}
