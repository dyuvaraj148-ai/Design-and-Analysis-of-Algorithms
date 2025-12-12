import java.util.*;

public class activityselect {
    static class activity{
        int num;
        int start;
        int end;
        activity(int num,int start,int end){
            this.num=num;
            this.start=start;
            this.end=end;
        }
        void display(){
            System.out.println("activity:"+this.num+"("+this.start+","+this.end+")");
        }
    }
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        ArrayList<activity> acts=new ArrayList<>();
        int n=scan.nextInt();
        for(int i=0;i<n;i++){
            acts.add(new activity(i+1,scan.nextInt(),scan.nextInt()));
        }

        Collections.sort(acts,Comparator.comparingInt(obj->obj.start));
        int last=0;
        for(activity a:acts){
            if(a.start>last){
                a.display();
                last=a.end;
            }
        }
        scan.close();
    }
}
