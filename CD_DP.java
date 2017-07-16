import java.io.*;
import java.util.StringTokenizer;

public class CD_DP {
    final private static InputReader input = new InputReader(System.in);
    final private static PrintWriter output = new PrintWriter(System.out);

    public static void main(String[] args) {
        Problem CD = new Problem();
        CD.Solve();
        output.close();
    }

    static class Problem {
        int[] t;
        int[][] dp;
        int n, M;

        void Solve() {
            while(input.Ready()) {
                M = input.nextInt();
                n = input.nextInt();

                t = new int[n];
                dp = new int[n][M+1];

                for(int i = 0; i < n; ++i) {
                    t[i] = input.nextInt();
                }

                for(int m = 0; m <= M; ++m) {
                    if(t[0] <= m) dp[0][m] = t[0];
                    else dp[0][m] = 0;
                }

                for(int i = 1; i < n; ++i) {
                    for(int m = 0; m <= M; ++m) {
                        if(t[i] <= m) {
                            dp[i][m] = Math.max(dp[i-1][m], dp[i-1][m - t[i]] + t[i]);
                            continue;
                        }
                        dp[i][m] = dp[i-1][m];
                    }
                }

                trace(n-1, M);
                output.printf("sum:%d\n", dp[n-1][M]);
            }
        }

        void trace (int i, int m) {
            if(i == 0) {
                if(t[i] <= m) output.printf("%d ", t[i]);
            }
            else {
                if(t[i] <= m && dp[i][m] == dp[i-1][m - t[i]] + t[i]) {
                    trace(i-1, m - t[i]);
                    output.printf("%d ", t[i]);
                    return;
                }
                trace(i-1, m);
            }
        }
    }


    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public boolean Ready() {
            try {
                return reader.ready();
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
    }
}
