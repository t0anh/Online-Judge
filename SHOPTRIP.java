import java.awt.*;
import java.io.*;
import java.util.StringTokenizer;


public class SHOPTRIP {

    public static void main(String[] args) {
        InputReader input = new InputReader(System.in);
        PrintWriter output = new PrintWriter(System.out);

        Problem SHOPTRIP = new Problem();
        SHOPTRIP.Solve(input, output);
        output.close();
    }

    static class Problem {
        int n, k;
        Point[] pos;
        int[] shops;
        double[][] dp;
        int full;

        double dist (int from, int to) {
            int dx = pos[from].x - pos[to].x;
            int dy = pos[from].y - pos[to].y;
            return Math.sqrt(dx*dx + dy*dy);
        }

        double calc (int cur, int state) {
            if(state == full) {
                /*Go home*/
                return dist(0, cur);
            }
            if(dp[cur][state] != 0) return dp[cur][state];
            dp[cur][state] = Double.MAX_VALUE;
            for(int nxt = 1; nxt <= n; ++nxt) {
                if(nxt == cur) continue;
                int nxt_state = state | shops[nxt];
                if(nxt_state > state) {
                    dp[cur][state] = Math.min(dp[cur][state], dist(cur, nxt) + calc(nxt, nxt_state));
                }
            }
            return dp[cur][state];
        }


        int toInt(String bin) {
            int ret = 0;
            for(int i = 0; i < bin.length(); ++i) {
                if(bin.charAt(i) == '1')
                    ret += (1 << (bin.length() - 1 - i));
            }
            return ret;
        }

        boolean impossible () {
            int total = 0;
            for(int i = 1; i <= n; ++i)
                total |= shops[i];
            return total != full;
        }

        void Solve(InputReader input, PrintWriter output) {
            int testCases = input.nextInt();
            for(int test = 0; test < testCases; ++test) {
                n = input.nextInt();
                k = input.nextInt();
                pos = new Point[n+1];
                shops = new int[n+1];
                full = (1 << k) - 1;

                pos[0] = new Point(0, 0);
                for(int i = 1; i <= n; ++i) {
                    int x = input.nextInt();
                    int y = input.nextInt();
                    pos[i] = new Point(x, y);
                }
                for(int i = 1; i <= n; ++i) {
                    shops[i] = toInt(input.nextWord());
                }

                if(impossible()) {
                    output.println("-1");
                    continue;
                }

                dp = new double[n+1][1 << k];

                output.printf("%.10f\n", calc(0, 0));
            }

        }
    }


    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String nextWord() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextWord());
        }

        long nextLong() {
            return Long.parseLong(nextWord());
        }

        double nextDouble() {
            return Double.parseDouble(nextWord());
        }

        boolean isReady() {
            try {
                return reader.ready();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
