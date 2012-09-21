/*
 Enter your code here. Read input from STDIN. Print output to STDOUT
 Your class should be named Solution
*/
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class Solution {

    List<Integer> adj[] = new List[111];
    Integer[] cnt = new Integer[111];
    int p[] = new int[111];
    int n;
    int m;
    
    void traverse(int root) {
        cnt[root] = 1;
        for (int i : adj[root]) if (p[root] != i) {
            p[i] = root;
            traverse(i);
            cnt[root] += cnt[i];
        }
    }
    
    int gao(int root) {
        int ans = 0;
        for (int i : adj[root]) if (p[root] != i) {
            ans += gao(i);
            if (cnt[i] % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
    
    public void solve() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<Integer>();
        } 
        
        while (m-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        traverse(1);
        
        System.out.println(gao(1));
    }
    
    public static void main(String[] args) {
        new Solution().solve();
    }
}
