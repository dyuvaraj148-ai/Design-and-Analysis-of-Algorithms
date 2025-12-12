import java.util.*;

public class bftAndDft{
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter no of vertices and edges:");
        int v=scan.nextInt();
        int e=scan.nextInt();
        gph g1=new gph(v);

        System.out.println("Enter one by one edges(v1,v2,w):");
        int v1,v2,w;
        for(int i=0;i<e;i++){
            v1=scan.nextInt();
            v2=scan.nextInt();
            w=scan.nextInt();
            g1.insert(v1, v2, w);
        }

        g1.display();
        g1.bfs(v-1);
        g1.dfs(v-1);
        scan.close();
    }
}

class gph{
    static int MAX=100;
    int v;
    int[][] arr=new int[MAX][MAX];
    gph(int v){
        this.v=v;
    }
    void insert(int v1,int v2,int w){
        arr[v1][v2]=w;
        arr [v2][v1]=w;
    }

    void display(){
        System.out.println("Matrix Representation of Graph:");
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }

    void bfs(int source){
        ArrayDeque <Integer> que=new ArrayDeque<>();
        ArrayList <Integer> visit=new ArrayList<>(Collections.nCopies(v,0));
        System.out.print("BFS traversal:");

        que.add(source);
        visit.set(source,1);
        while(!que.isEmpty()){
            int a=que.removeFirst();
            System.out.print(a+" ");
            for(int i=0;i<v;i++){
                if(arr[a][i]!=0 &&visit.get(i)==0){
                    que.addLast(i);
                    visit.set(i,1);
                }   
            }
        }
        System.out.println();
    }

    void dfs(int source){
        Stack <Integer> sta=new Stack<>();
        ArrayList <Integer> visit=new ArrayList<>(Collections.nCopies(v,0));;
        System.out.print("DFS traversal:");

        sta.add(source);
        visit.set(source,1);
        while(!sta.isEmpty()){
            int a=sta.pop();
            System.out.print(a+" ");
            for(int i=0;i<v;i++){
                if(arr[a][i]!=0 &&visit.get(i)==0){
                    sta.add(i);
                    visit.set(i,1);
                }
            }
        }
        System.out.println();
    }
}
