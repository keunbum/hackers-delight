import java.io.OutputStream;
import java.io.InputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        int testNumber = 1;
        solver.solve(testNumber, in, out);
        out.close();
    }
 
    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q1 = 0;
            int q2 = 0;
            int q3 = 0;
            int q4 = 0;
            int axis = 0;
            while (n-- > 0) {
                int x = in.nextInt();
                int y = in.nextInt();
                if (x == 0 || y == 0) {
                    ++axis;
                } else if (y > 0) {
                    if (x > 0) {
                        ++q1;
                    } else {
                        ++q2;
                    }
                } else {
                    if (x < 0) {
                        ++q3;
                    } else {
                        ++q4;
                    }
                }
            }
            out.println("Q1: " + q1);
            out.println("Q2: " + q2);
            out.println("Q3: " + q3);
            out.println("Q4: " + q4);
            out.println("AXIS: " + axis);
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