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
            int h = in.nextInt();
            int w = in.nextInt();
            char[][] s = new char[h][w];
            for (int i = 0; i < h; ++i) {
                s[i] = in.next().toCharArray();
                for (int j = 0; j < w; ++j) {
                    if (s[i][j] == '.') {
                        s[i][j] = 'D';
                    }
                }
            }
            boolean ok = true;
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if (j + 1 < w) {
                        ok &= s[i][j] != 'S' || s[i][j + 1] != 'W';
                        ok &= s[i][j] != 'W' || s[i][j + 1] != 'S';
                    }
                    if (i + 1 < h) {
                        ok &= s[i][j] != 'S' || s[i + 1][j] != 'W';
                        ok &= s[i][j] != 'W' || s[i + 1][j] != 'S';
                    }
                }
            }
            if (!ok) {
                out.println(0);
                return;
            }
            out.println(1);
            for (int i = 0; i < h; ++i) {
                out.println(s[i]);
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
    }
}