import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        char[][] a = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            a[i] = s.toCharArray();
        }
        char[][] b = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            b[i] = s.toCharArray();
        }

        int ans = 0;
        for (int i = 0; i < m - 2; i++) {
            for (int j = i + 1; j < m - 1; j++) {
                for (int k = j + 1; k < m; k++) {
                    // System.out.printf("%d, %d, %d\n", i, j, k);
                    HashSet<String> hs = new HashSet<>();

                    // System.out.print("a | ");
                    for (int r = 0; r < n; r++) {
                        String s = a[r][i] + "" + a[r][j] + "" + a[r][k];
                        // System.out.print(s + " ");
                        hs.add(s);
                    }
                    // System.out.println();

                    boolean isDup = false;
                    for (int r = 0; r < n; r++) {
                        String s = b[r][i] + "" + b[r][j] + "" + b[r][k];
                        if(hs.contains(s)) {
                            // System.out.printf("dup with %s\n", s);
                            isDup = true;
                            break;
                        }
                    }

                    if (isDup) continue;
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}