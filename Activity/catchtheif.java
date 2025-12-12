import java.util.ArrayList;
import java.util.Scanner;

public class catchtheif {
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        char[] arr=new char[n];
        for(int i=0;i<n;i++)
        arr[i]=scan.next().charAt(0);
        int k=scan.nextInt();
        int max=maxtheif(arr,n,k);
        System.out.println(max);
    }

    static int maxtheif(char[] arr,int n,int k){
        ArrayList <Integer> theif=new ArrayList<>();
        ArrayList <Integer> police=new ArrayList<>();
        for(int i=0;i<n;i++){
            if(arr[i]=='T')
            theif.add(i);
            else
            police.add(i);
        }

        int i=0,j=0,c=0;
        while(i<police.size() &&j<theif.size()){
            if(Math.abs(police.get(i)-theif.get(j))<=k){
                c++;
                j++;
                i++;
            }
            else if(police.get(i)>theif.get(j))
            j++;
            else 
            i++;
        }
        return c;
    }
}
