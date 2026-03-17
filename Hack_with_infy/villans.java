// "static void main" must be defined in a public class.
public class Main {
    private static boolean isVaild(int[] arr,int start,int N,int H){
        int heros = 1, curH = H;
        for(int i=start;i<arr.length;i++){
            if(curH > arr[i]){
                curH -= arr[i];
            }else if(curH == arr[i]){
                heros += 1;
                curH = H;
            }else{
                if(arr[i] > H)return false;
                heros += 1;
                curH = H - arr[i];
            }
        }
        return heros <= N;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), H = sc.nextInt();
        int M = sc.nextInt();
        int[] arr = new int[M];
        for(int i=0;i<M;i++){
            arr[i] = sc.nextInt();
        }
        int left = 0, right = M-1;
        int ans = M;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isValid()){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        System.out.println(ans);
    }
}
/*
N - No. of Heros, H - Health of Each hero
M - No. of Villians, arr of size M - Each villian Health

Hero health > Villian Health -- hero win -> hero health - villian health

Hero health < Villian Health -- hero loss -> villian health wont change

Hero health = Villian Health -- both loss
N = 2, M = 4, H = 4
arr -> [3, 1, 3, 3] // villian, hero health -> [4, 4] -> [1, 4] -> [0, 1] -> 

N = 1, H = 4, M = 5, arr= [1,2,3,1,3]

i = 0 --> 3 heros --> False [3,3,2,1,1,0]
i = 1 --> 3 heros --> False
i = 2 --> 2 heros --> False
i = 3 --> 1 heros --> True
i = 4 --> 1 heros --> True
i = 5 --> 0 heros --> True
*/
// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        int N = sc.nextInt();
        int X = sc.nextInt(), Y = sc.nextInt();
        int[] arr = new int[N];
        for(int i=0;i<N;i++)arr[i] = sc.nextInt();
        
        List<Integer>[] adj = new List[N];
        for(int i=0;i<N;i++){
            adj[i] = ArrayList<>();
            adj[i].add((i + arr[i]) % N);
            add[i].add((N + (i - arr[i]))%N);
        }
        int[] moves = new int[N];
        Arrays.fill(moves, N+1);
        TreeSet<int[]> heap = new TreeSet<>((x,y)->Arrays.compare(x,y)); //[moves, cur]
        heap.add(new int[]{X, 0});
        moves[X] = 0;
        while(!heap.isEmpty()){
            int[] x = heap.removeFirst();
            if(moves[x[1]] != x[0])continue;
            for(Integer i: adj[x[1]]){
                if(moves[i] <= x[0]+1){
                    continue;
                }
                moves[i] = x[0] + 1;
                heap.add(new int[]{i, moves[i]});
            }
        }
        int ans = moves[Y];
        if(ans == N+1)ans = -1;
        System.out.println(ans);
    }
}