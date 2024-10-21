﻿class Program
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
		public void Solve(int testNumber, InputReader reader, StreamWriter writer)
		{
			int n = reader.NextInt();
			int k = reader.NextInt();
			int[,] a = new int[n, n];
			List<(int, int, int)> que = new();
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					a[i, j] = reader.NextInt();
					if (a[i, j] != 0)
					{
						que.Add((a[i, j], i, j));
					}
				}
			}
			que.Sort((l, r) => l.Item1.CompareTo(r.Item1));
			int[] DI = { 1, 0, -1, 0 };
			int[] DJ = { 0, 1, 0, -1 };
			int s = reader.NextInt();
			while (s-- > 0)
			{
				List<(int, int, int)> newQue = new();
				for (int beg = 0; beg < que.Count; ++beg)
				{
					var (id, i, j) = que[beg];
					for (int dir = 0; dir < 4; ++dir)
					{
						int ni = i + DI[dir];
						int nj = j + DJ[dir];
						if (ni >= 0 && nj >= 0 && ni < n && nj < n && a[ni, nj] == 0)
						{
							a[ni, nj] = id;
							newQue.Add((id, ni, nj));
						}
					}
				}
				(que, newQue) = (newQue, que);
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