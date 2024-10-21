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
		const int N = 10;
		int n;
		int[,] a = new int[N, N];
		int answer = int.MaxValue;
		int used;

		public void Solve(int testNumber, InputReader reader, StreamWriter writer)
		{
			n = reader.NextInt();
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					a[i, j] = reader.NextInt();
					a[i, j] = (a[i, j] == 0) ? INF : a[i, j];
				}
			}
			used = 1 << (n - 1);
			DFS(n - 1, 0);
			writer.WriteLine(answer);
		}

		private void DFS(int v, int cost)
		{
			if (used == (1 << n) - 1)
			{
				answer = Math.Min(answer, cost + a[v, n - 1]);
				return;
			}
			for (int u = 0; u < n - 1; ++u)
			{
				if (((used >> u) & 1) == 0)
				{
					used |= (1 << u);
					DFS(u, cost + a[v, u]);
					used &= ~(1 << u);
				}
			}
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