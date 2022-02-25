import java.io.*
import java.util.*
 
object Main {
    @JvmStatic
    fun main(args: Array<String>) {
        val inputStream = System.`in`
        val outputStream: OutputStream = System.out
        val `in` = InputReader(inputStream)
        val out = PrintWriter(outputStream)
        val solver = Task()
        val testCount = 1
        for (i in 1..testCount) solver.solve(i, `in`, out)
        out.close()
    }
 
    internal class Task {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            var n = `in`.nextInt()
            var q = IntArray(4)
            var axis = 0
            while (n-- > 0) {
                var x = `in`.nextInt()
                var y = `in`.nextInt()
                if (x == 0 || y == 0) {
                    ++axis
                } else if (y > 0) {
                    if (x > 0) {
                        ++q[0]
                    } else {
                        ++q[1]
                    }
                } else {
                    if (x > 0) {
                        ++q[3]
                    } else {
                        ++q[2]
                    }
                }
            }
            for (i in 1..4) {
                out.println("Q" + i + ": " + q[i - 1])
            }
            out.println("AXIS: " + axis)
        }
    }
 
    internal class InputReader(stream: InputStream?) {
        var reader: BufferedReader
        var tokenizer: StringTokenizer?
        operator fun next(): String {
            while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
                tokenizer = try {
                    StringTokenizer(reader.readLine())
                } catch (e: IOException) {
                    throw RuntimeException(e)
                }
            }
            return tokenizer!!.nextToken()
        }
 
        fun nextInt(): Int {
            return next().toInt()
        }
 
        init {
            reader = BufferedReader(InputStreamReader(stream), 32768)
            tokenizer = null
        }
    }
}