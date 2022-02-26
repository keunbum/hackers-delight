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
        for (i in 1..testCount) {
            solver.solve(i, `in`, out)
        }
        out.close()
    }
 
    internal class Task {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            var n = `in`.nextInt()
            var a = IntArray(n) { `in`.nextInt() }
            a.sort()
            var m = `in`.nextInt()
            var res = IntArray(m) { binarySearch(a, `in`.nextInt(), n) }
            out.println(res.joinToString(" "))
        }

        private fun binarySearch(a: IntArray, x: Int, n: Int): Int {
            var low = 0
            var high = n - 1
            while (low < high) {
                var mid = (low + high) / 2
                if (a[mid] < x) {
                    low = mid + 1
                } else {
                    high = mid
                }
            }
            return if (a[low] == x) 1 else 0
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