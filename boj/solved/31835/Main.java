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
            char[] a = new char[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.next().charAt(0);
            }
            char c = in.next().charAt(0);
            if (n == 1) {
                out.println(c == a[0] ? 0 : 1);
                return;
            }
            boolean result = encode(a[0]);
            for (int i = 2; i < n - 2; i += 2) {
                result = calc(result, a[i - 1], encode(a[i]));
            }
            int answer = 2;
            for (char op : "&|".toCharArray()) {
                for (char v : "FT".toCharArray()) {
                    if (calc(result, op, encode(v)) == encode(c)) {
                        answer = Math.min(answer, (op == a[n - 2] ? 0 : 1) + (v == a[n - 1] ? 0 : 1));
                    }
                }
            }
            out.println(answer);
        }

        private static boolean encode(char v) {
            return v == 'T';
        }

        private static boolean calc(boolean x, char op, boolean y) {
            if (op == '&') return x && y;
            if (op == '|') return x || y;
            return false;
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
