import java.util.*;

public class robinKarp{
    static long MOD=1_000_000_007;
    static long BASE=31;
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int len=str.length();

        int n=scan.nextInt();
        scan.nextLine();
        String[] patterns=new String[n];
        for(int i=0;i<n;i++)
        patterns[i]=scan.nextLine();

        Map<String,Integer> result=new HashMap<>();
        Map<Integer,Map<Long,List<String>>> map=new HashMap<>();

        for(String p:patterns){
            int m=p.length();
            long hash=0;
            for(char c:p.toCharArray())
                hash=(hash*BASE+c)%MOD;

            map.putIfAbsent(m, new HashMap<>());
            map.get(m).putIfAbsent(hash,new ArrayList<>());
            map.get(m).get(hash).add(p);
            result.put(p,0);
        }

        for(int l:map.keySet()){
            if(l>len) continue;

            long power=1;
            for(int i=0;i<l-1;i++)
                power=(power*BASE)%MOD;

            long sHash=0;
            for(int i=0;i<l;i++)
            sHash=(sHash*BASE+str.charAt(i))%MOD;

            for(int i=0;i<=len-l;i++){
                if(map.get(l).containsKey(sHash)){
                    for(String p:map.get(l).get(sHash)){
                        if(p.equals(str.substring(i, l+i)))
                            result.put(p,result.get(p)+1);
                    }
                }

                if(i<len-l){
                    sHash=(sHash-str.charAt(i)*power)%MOD;
                    sHash=(sHash*BASE+str.charAt(i+l))%MOD;
                    if(sHash<0) sHash+=MOD;
                }
            }
        }

        System.out.println("String contains:");
        for(String p:result.keySet()){
            if(result.get(p)>0)
            System.out.println(p);
        }
    }
} 