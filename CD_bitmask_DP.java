import javax.swing.text.MutableAttributeSet;
import java.io.*;
import java.util.StringTokenizer;

public class CD_bitmask_DP {
    private static InputReader input = new InputReader(System.in);
    private static PrintWriter output = new PrintWriter(System.out);

    public static void main(String[] args) {
        Problem CD_1 = new Problem();
        CD_1.Solve();
        output.close();
    }

    static class Problem {
        int[] t;
        int[][] dp;
        int M, n;

        int offBit (int mask, int i) {
            return (mask & (~(1 << i)));
        }
        boolean isOn (int mask, int i)
        {
            return ((mask >> i) & 1) == 1;
        }

        void Solve() {

            while(input.Ready()) {
                M = input.nextInt();
                n = input.nextInt();

                t = new int[n];
                dp = new int[n][1 << n];

                for (int i = 0; i < n; ++i) {
                    t[i] = input.nextInt();
                }

                int MASK = (1 << n);

                for (int mask = 0; mask < MASK; ++mask) {
                    if(isOn(mask, 0) && t[0] <= M) {
                        dp[0][mask] = t[0];
                    }
                    else dp[0][mask] = 0;
                }

                for(int i = 1; i < n; ++i ){
                    for (int mask = 0; mask < MASK; ++mask) {
                        int pre = offBit(mask, i);
                        if(isOn(mask, i) && dp[i-1][pre] + t[i] <= M) {
                            dp[i][mask] = dp[i-1][pre] + t[i];
                        }
                        else dp[i][mask] = dp[i-1][pre];
                    }
                }

                int ans = 0;
                for (int mask = 0; mask < MASK; ++mask) {
                    if(dp[n-1][mask] > dp[n-1][ans])
                        ans = mask;
                }

                for (int i = 0; i < n; ++i) {
                    if(isOn(ans, i))
                        output.printf("%d ", t[i]);
                }
                output.printf("sum:%d\n", dp[n-1][ans]);
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
