import java.lang.AssertionError
 
private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main() {
    var n = readInt()
    var res = IntArray(5) {0}
    while (n-- > 0) {
        var (x, y) = readInts()
        if (x == 0 || y == 0) {
            ++res[4]
        } else if (y > 0) {
            if (x > 0) {
                ++res[0]
            } else {
                ++res[1]
            }
        } else {
            if (x < 0) {
                ++res[2]
            } else {
                ++res[3]
            }
        }
    }
    for (i in 0..4) {
        println((if (i == 4) "AXIS" else "Q" + (i + 1).toString()) + ": " + res[i].toString())
    }
}

private fun readInt() = readLine()!!.toInt()
private fun readInts() = readLine()!!.split(" ").map {it.toInt()}