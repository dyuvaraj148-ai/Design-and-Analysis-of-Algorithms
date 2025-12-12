import java.util.Scanner;

public class sudoku {
    static boolean isSafe(char[][] board,int r,int c,char d){

        for(int i=0;i<9;i++){
            if(board[r][i]==d)
            return false;
        }

        for(int j=0;j<9;j++){
            if(board[j][c]==d)
            return false;
        }

        int sr=3*(r/3);
        int sc=3*(c/3);
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==d)
                return false;
            }
        }

        return true;
    }

    static boolean helper(char[][] board,int r,int c){
        if(r==9)
        return true;

        if(c==9)
        return helper(board,r+1,0);

        if(board[r][c]!='.')
        return helper(board,r,c+1);

        for(char d='1';d<='9';d++){
            if(isSafe(board,r,c,d)){
                board[r][c]=d;
                if(helper(board,r,c+1)) return true;
                board[r][c]='.';
            }
        }

        return false;
    }

    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        char[][] board=new char[9][9];
        System.out.println("Enter number if it present else (.) as 2D array:");
        for(int i=0;i<9;i++){//reading board
            for(int j=0;j<9;j++){
                board[i][j]=scan.next().charAt(0);
            }
        }
        scan.close();

        if(!(helper(board,0,0)))
        System.out.println("NOT POSSIBLE\n");
        else 
        System.out.println("HERE SOLUTION:\n");

        for(int i=0;i<9;i++){//output
            for(int j=0;j<9;j++){
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }
}
