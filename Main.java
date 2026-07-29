import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    int find( int u ){
        if( u == parent[u]) return u;
        return find( praent[u]) ;
    }
    bool union(int u ,int v ){
        int a = find( u ) ;
        int b = find(v );
        if( a != b ){
            parent[u] = parent[v];

            return 1;
        }
        else
            return false;
    }


    public static void main(String[] args) {
        
    }
}