import java.io.*;
import java.util.StringTokenizer;

public class CD_backtracking {
    private static InputReader input = new InputReader(System.in);
    private static PrintWriter output = new PrintWriter(System.out);

    public static void main(String[] args) {
        Problem CD_backtracking = new Problem();
        CD_backtracking.Solve();
        output.close();
    }

    static class Problem {
        int M, n;
        int[] t;
        int answer;
        int best;

        void Solve() {

            while(input.Ready()) {
                M = input.nextInt();
                n = input.nextInt();

                t = new int[n];

                for (int i = 0; i < n; ++i) {
                    t[i] = input.nextInt();
                }

                answer = 0;
                best = 0;
                back(0,0, 0);

                for (int i = 0; i < n; ++i) {
                    if(isOn(answer, i)) {
                        output.printf("%d ", t[i]);
                    }
                }
                output.printf("sum:%d\n", best);
            }
        }

        boolean isOn (int mask, int i) {
            return ((mask >> i) & 1) == 1;
        }
        int onBit (int mask, int i) {
            return (mask | (1 << i));
        }

        void back (int i, int mask, int current) {
            if(current <= M && best < current) {
                best = current;
                answer = mask;
            }
            if(i < n) {
                back(i+1, mask, current);
                back(i+1, onBit(mask, i), current + t[i]);
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
