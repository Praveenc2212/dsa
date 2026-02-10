import java.util.*;

class Process{
    public int arrivalTime;
    public int burstTime;
    public int priority;

    public Process(int arrivalTime , int burstTime , int priority){
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
        this.priority = priority;
    }
}
public class PriorityScheduling{

    public static void main(String []args){
        
        Scanner scan = new Scanner(System.in);
        // System.out.print("Enter Number of Processes : ");
        int n = scan.nextInt();
        List<Process> processes = new ArrayList<>();
        for(int i = 0; i < n ; i +=1 ){
            // System.out.println("P"+i);
            // System.out.print("Enter Arrival Time : ");
            int a = scan.nextInt();
            // System.out.print("Enter Burst Time : ");
            int b = scan.nextInt();
            // System.out.print("Enter Priority Time : ");
            int pri = scan.nextInt();
            processes.add(new Process(a,b,pri));
        }


        Collections.sort(processes , ( a , b  ) -> a.arrivalTime - b.arrivalTime );

        // processes -- all 
        // pq

        PriorityQueue<Process> pq = new PriorityQueue<>( ( a , b ) -> a.priority - b.priority );

        int time = 0 ;
        while(true){
            
            time++;
            while( time  )

        }
    }
}