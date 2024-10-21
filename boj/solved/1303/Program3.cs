using System.ComponentModel.Design;
using System.Reflection.Metadata;

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
		public void Solve(int testNumber, InputReader reader, StreamWriter writer)
		{
			var DI = new[] { 1, 0, -1, 0 };
			var DJ = new[] { 0, 1, 0, -1 };
			int w = reader.NextInt();
			int h = reader.NextInt();
			string[] s = new string[h];
			for (int i = 0; i < h; ++i)
			{
				s[i] = reader.Next();
			}
			int[] ret = new int[2];
			bool[,] was = new bool[h, w];
			for (int i = 0; i < h; ++i)
			{
				for (int j = 0; j < w; ++j)
				{
					if (was[i, j])
					{
						continue;
					}
					was[i, j] = true;
					int DFS(int mi, int mj)
					{
						int result = 1;
						for (int dir = 0; dir < 4; ++dir)
						{
							int ni = mi + DI[dir];
							int nj = mj + DJ[dir];
							if (ni >= 0 && nj >= 0 && ni < h && nj < w && s[ni][nj] == s[i][j] && !was[ni, nj])
							{
								was[ni, nj] = true;
								result += DFS(ni, nj);
							}
						}
						return result;
					}
					int size = DFS(i, j);
					ret[s[i][j] == 'W' ? 0 : 1] += size * size;
				}
			}
			writer.WriteLine(ret[0] + " " + ret[1]);
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