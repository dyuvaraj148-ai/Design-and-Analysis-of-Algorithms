import java.util.Arrays;
import java.util.Scanner;

public class micetoholes {
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int[] mice=new int[n];
        int[] hole=new int[n];

        for(int i=0;i<n;i++)
        mice[i]=scan.nextInt();
        Arrays.sort(mice);

        for(int i=0;i<n;i++)
        hole[i]=scan.nextInt();
        Arrays.sort(hole);

        int maxd=0;
        for(int i=0;i<n;i++){
            int d=Math.abs(mice[i]-hole[i]);
            if(d>maxd)
            maxd=d;
        }
        System.out.println("Minimum time:"+maxd);
    }
}
