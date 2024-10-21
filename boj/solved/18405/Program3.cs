class Program
{
	static void Main()
	{
		Stream inputStream = Console.OpenStandardInput();
		Stream outputStream = Console.OpenStandardOutput();
		InputReader reader = new(inputStream);
		StreamWriter writer = new(outputStream);
		int testCount = 1;
		for (int i = 1; i <= testCount; i++)
		{
			Task.Solve(i, reader, writer);
		}
		writer.Close();
	}

	class Task
	{
		const int N = 200;
		static int[,] a = new int[N, N];
		static (int, int, int)[][] t = { new (int, int, int)[N * N], new (int, int, int)[N * N] };

		public static void Solve(int testNumber, InputReader reader, StreamWriter writer)
		{
			int n = reader.NextInt();
			int k = reader.NextInt();
			(int, int, int)[] que = t[0];
			int end = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					a[i, j] = reader.NextInt();
					if (a[i, j] != 0)
					{
						que[end++] = (a[i, j], i, j);
					}
				}
			}
			Array.Sort(que, 0, end, Comparer<(int, int, int)>.Create((l, r) => l.Item1.CompareTo(r.Item1)));
			int[] DI = { 1, 0, -1, 0 };
			int[] DJ = { 0, 1, 0, -1 };
			(int, int, int)[] nque = t[1];
			int s = reader.NextInt();
			while (s-- > 0)
			{
				int nend = 0;
				for (int beg = 0; beg < end; ++beg)
				{
					var (id, i, j) = que[beg];
					for (int dir = 0; dir < 4; ++dir)
					{
						int ni = i + DI[dir];
						int nj = j + DJ[dir];
						if (ni >= 0 && nj >= 0 && ni < n && nj < n && a[ni, nj] == 0)
						{
							a[ni, nj] = id;
							nque[nend++] = (id, ni, nj);
						}
					}
				}
				(que, nque) = (nque, que);
				end = nend;
			}
			int x = reader.NextInt() - 1;
			int y = reader.NextInt() - 1;
			writer.WriteLine(a[x, y]);
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