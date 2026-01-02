import java.util.*;

class belleman{
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();

        int[][] matrix=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i)
                matrix[i][j]=Integer.MAX_VALUE;
            }
        }

        int e=scan.nextInt();
        for(int i=0;i<e;i++){
            int a=scan.nextInt();
            int b=scan.nextInt();
            int d=scan.nextInt();
            matrix[a][b]=d;
        }

        int sorce=scan.nextInt();
        int[] dis=new int[n];
        Arrays.fill(dis,Integer.MAX_VALUE);
        dis[sorce]=0;

        int stops=scan.nextInt();
        for(int m=0;m<=stops;m++){
            int[] temp=dis.clone();

            for(int i=0;i<n;i++){
                if(dis[i]==Integer.MAX_VALUE)
                continue;

                for(int j=0;j<n;j++){
                    if(matrix[i][j]!=Integer.MAX_VALUE && dis[i]+matrix[i][j]<temp[j])
                    temp[j]=dis[i]+matrix[i][j];
                }
            }
            dis=temp.clone();
        }

        for(int a:dis)
            if(a==Integer.MAX_VALUE)
                System.out.print("INF ");
            else
                System.out.print(a+" ");
    }
}
