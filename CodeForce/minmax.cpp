class Solution {
    public ArrayList<ArrayList<Integer>> grp;
    public int[] nodes;
    public boolean vis[];
    public int rec(int u, int lev) {
        vis[u] = true;

        // System.out.println(u);
        if(nodes[u] != -1) {
            return lev - nodes[u];
        }

        nodes[u] = lev;

        int ans = -1;

        for(int v : grp.get(u)){
            ans = Math.max(ans, rec(v, lev + 1));
        } 
        
        nodes[u] = -1;

        return ans;
    }
    public int longestCycle(int[] edges) {
        grp = new ArrayList<>();
        nodes = new int[edges.length];

        Arrays.fill(nodes, -1);
        
        for(int i = 0 ; i < edges.length ; i++) {
            ArrayList<Integer> node = new ArrayList<>();
            
            if(edges[i] != -1)
                node.add(edges[i]);

            grp.add(node);
        }

        int ans = -1;

        vis = new boolean[edges.length];

        for(int  i = 0 ; i < edges.length ; i++) {
            if(!vis[i])
                ans = Math.max(ans, rec(i, 1));   
        } 
        
        return ans;
    }
}