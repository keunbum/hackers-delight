import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        int testCount = 1;
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            boolean ok = true;
            int[][] a = new int[n][n];
            boolean[] used = new boolean[n * n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    a[i][j] = in.nextInt();
                    ok &= (!used[a[i][j] - 1]);
                    used[a[i][j] - 1] = true;
                }
            }
            int sum = n * (n * n + 1) / 2;
            for (int r = 0; r < 2; ++r) {
                for (int i = 0; i < n; ++i) {
                    int cur = 0;
                    for (int j = 0; j < n; ++j) {
                        cur += (r == 0 ? a[i][j] : a[j][i]);
                    }
                    ok &= (cur == sum);
                }
            }
            for (int r = 0; r < 2; ++r) {
                int cur = 0;
                for (int i = 0; i < n; ++i) {
                    cur += (r == 0 ? a[i][i] : a[i][n - 1 - i]);
                }
                ok &= (cur == sum);
            }
            out.println(ok ? "TRUE" : "FALSE");
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
    }
}