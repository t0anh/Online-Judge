import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;


public class CC_KNICOV {
    public static void main(String[] args) {
        InputReader input = new InputReader(System.in);
        PrintWriter output = new PrintWriter(System.out);

        Problem CC_KNICOV = new Problem();
        CC_KNICOV.Solve(input, output);

        output.close();
    }

    static class Problem {
        int[][][][][] dp = new int[55][8][8][8][8];
        final int dx[] = {-2, -2, -1, -1, 1, 1, 2, -2};
        final int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        final int INF = (int)1e9;
        int R, C, full;

        int setBit(int mask, int idx) {
            return (mask | (1 << idx));
        }
        boolean isOn (int mask, int idx) {
            return ((mask >> idx) & 1) == 1;
        }

        int calc (int col, int pr2, int pr1, int cur, int nxt) {
            if(col >= C) {
                return (pr2 == full && pr1 == full) ? 0 : INF;
            }
            int ret = dp[col][pr2][pr1][cur][nxt];
            if(ret != -1) return ret;
            ret = INF;
            for(int mask = 0; mask <= full; ++mask) {
                int[] pos = {pr2, pr1, mask | cur, nxt, 0};
                for(int row = 0; row < R; ++row) {
                    if(isOn(mask, row)) {
                        for(int i = 0; i < 8; ++i) {
                            int x = row + dx[i];
                            int y = 2 + dy[i];
                            if(x < 0 || x >= R) continue;
                            pos[y] = setBit(pos[y], x);
                        }
                    }
                }
                if(pos[0] == full) {
                    ret = Math.min(ret, Integer.bitCount(mask) + calc(col+1, pos[1], pos[2], pos[3], pos[4]));
                }
            }
            dp[col][pr2][pr1][cur][nxt] = ret;
            return ret;
        }

        void Solve(InputReader input, PrintWriter output) {
            int testCases = input.nextInt();
            for(int test = 0; test < testCases; ++test) {
                R = input.nextInt();
                C = input.nextInt();

                if(R == 1) {
                    output.println(C);
                    continue;
                }

                for(int col = 0; col < 55; ++col)
                    for(int pr2 = 0; pr2 < 8; ++pr2)
                        for(int pr1 = 0; pr1 < 8; ++pr1)
                            for(int cur = 0; cur < 8; ++cur)
                                for(int nxt = 0; nxt < 8; ++nxt)
                                    dp[col][pr2][pr1][cur][nxt] = -1;

                full = (1 << R) - 1;
                output.println(calc(0, full, full, 0, 0));
            }
        }
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        String nextWord() {
            try {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
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
