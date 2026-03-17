import java.util.*;

public class Main{
        static Scanner scan =new Scanner(System.in);
       public  static void solve(){

            int n =scan.nextInt();
            int arr[] = new int[n];
            
            for(int i =0; i<n; i++){
                arr[i] = scan.nextInt();
            }
            
            int k = scan.nextInt();
            Deque<Integer> dq  = new ArrayDeque<>();

            for(int i = 0; i < k ;i++){

                while( !dq.isEmpty() && arr[ dq.getLast() ]  >= arr[i]  ){
                    dq.removeLast();
                }
                dq.addLast(i);
            }
            List<Integer> ans = new ArrayList<>();
            ans.add(arr[dq.getFirst()]);
            for(int i = k ;i  < n ; i += 1 ){
                while( !dq.isEmpty() && dq.getFirst() <= i-k  ){
                    dq.removeFirst();
                }
                
                while( !dq.isEmpty() && arr[ dq.getLast() ]  >= arr[i]  ){
                    dq.removeLast();
                }
                dq.addLast( i  );
            
                ans.add(arr[dq.getFirst()]);
                
            }
            
            for( int a :  ans ){
                System.out.print( a + " " );
            }

    }
    public static void main(String []args){
        
        solve();
    }
}