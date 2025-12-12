import java.util.*;

class point{
    int x,y;
    point(int x,int y){
        this.x=x;
        this.y=y;
    }
    public String toString(){
        return "("+this.x+","+this.y+")";
    }
}

class result{
    point p1,p2;
    double dis;
    result(point p1,point p2,double dis){
        this.p1=p1;
        this.p2=p2;
        this.dis=dis;
    }
    void display(){
        System.out.println("points:"+this.p1+","+this.p2);
        System.out.println("Distance:"+this.dis);
    }
}

public class pointsmindistance {
    public static void main(String args[]){

        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        ArrayList <point> arr=new ArrayList<>();

        for(int i=0;i<n;i++)
        arr.add(new point(scan.nextInt(),scan.nextInt()));
        Collections.sort(arr,Comparator.comparingInt(obj->obj.x));

        result res=mindistance(arr,0,n);
        res.display();
    }

    static result mindistance(ArrayList<point> arr,int s,int e){

        if(e-s<=3){
            point p1=null,p2=null;
            double d=Double.MAX_VALUE;

            for(int i=s;i<e;i++){
                for(int j=i+1;j<e;j++){
                    double ds=distance(arr.get(i),arr.get(j));
                    if(ds<d){
                        d=ds;
                        p1=arr.get(i);
                        p2=arr.get(j);
                    }
                }
            }
            return new result(p1,p2,d);
        }
        else{
            int m=(s+e)/2;
            point mid=arr.get(m);
            result r1=mindistance(arr,s,m);
            result r2=mindistance(arr,m+1,e);
            result d=r1.dis>r2.dis?r2:r1;

            ArrayList<point> strip=new ArrayList<>();
            for(int i=s;i<e;i++){
                if(Math.abs(arr.get(i).x-mid.x)<d.dis)
                strip.add(arr.get(i));
            }

            Collections.sort(strip, Comparator.comparingInt(obj -> obj.y));

            for (int i = 0; i < strip.size(); i++) {
                for (int j = i + 1; j < strip.size()&& (strip.get(j).y-strip.get(i).y)< d.dis; j++) {
                    double dist = distance(strip.get(i), strip.get(j));
                    if (dist < d.dis) 
                    d = new result(strip.get(i), strip.get(j), dist);
                }
            }
            return d;

        }
    }

    static double distance(point p1,point p2){
         return Math.hypot(p1.x-p2.x, p1.y-p2.y);
    }

}
