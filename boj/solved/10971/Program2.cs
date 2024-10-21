class Program
{
	static void Main()
	{
		Stream inputStream = Console.OpenStandardInput();
		Stream outputStream = Console.OpenStandardOutput();
		InputReader reader = new(inputStream);
		StreamWriter writer = new(outputStream);
		Task solver = new();
		int testCount = 1;
		for (int i = 1; i <= testCount; i++)
		{
			solver.Solve(i, reader, writer);
		}
		writer.Close();
	}

	class Task
	{
		const int INF = (int)1e8;
		public void Solve(int testNumber, InputReader reader, StreamWriter writer)
		{
			int n = reader.NextInt();
			int[,] a = new int[n, n];
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					a[i, j] = reader.NextInt();
					a[i, j] = (a[i, j] == 0) ? INF : a[i, j];
				}
			}
			int answer = INF;
			int[] perm = Enumerable.Range(0, n - 1).ToArray();
			do
			{
				int cost = a[n - 1, perm[0]];
				for (int id = 0; id < n - 1; ++id)
				{
					int i = perm[id];
					int j = (id == n - 2) ? n - 1 : perm[id + 1];
					cost += a[i, j];
				}
				answer = Math.Min(answer, cost);
			} while (Task.NextPermutation(perm));
			writer.WriteLine(answer);
		}

		private static bool NextPermutation(int[] a)
		{
			int i = a.Length - 2;
			while (i >= 0 && a[i] >= a[i + 1])
			{
				i -= 1;
			}
			if (i < 0)
			{
				return false;
			}
			int j = a.Length - 1;
			while (a[j] <= a[i])
			{
				j -= 1;
			}
			(a[i], a[j]) = (a[j], a[i]);
			Array.Reverse(a, i + 1, a.Length - i - 1);
			return true;
		}
	}

	class InputReader
	{
		private readonly StreamReader reader;
		private string[] tokens;
		private int tokenIndex;
		private readonly char[] separator;

		public InputReader(Stream stream)
		{
			reader = new StreamReader(stream);
			tokens = new string[0];
			tokenIndex = 0;
			separator = new char[] { ' ' };
		}

		public string Next()
		{
			EnsureTokens();
			return tokens[tokenIndex++];
		}

		public int NextInt()
		{
			return int.Parse(Next());
		}

		private void EnsureTokens()
		{
			if (tokenIndex >= tokens.Length)
			{
				string line = reader.ReadLine() ?? throw new InvalidOperationException("No more data to read.");
				tokens = line.Split(separator, StringSplitOptions.RemoveEmptyEntries);
				tokenIndex = 0;
			}
		}
	}
}