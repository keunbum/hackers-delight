using System.Collections.Immutable;

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
			string s = reader.Next();
			int n = reader.NextInt();
			int ans = 0;
			while (n-- > 0)
			{
				string t = reader.Next();
				for (int i = 0; i < 10; ++i)
				{
					bool ok = true;
					int k = i;
					for (int j = 0; j < s.Length; ++j)
					{
						ok &= (s[j] == t[k]);
						k = (k + 1) % 10;
					}
					if (ok)
					{
						ans += 1;
						break;
					}
				}
			}
			writer.WriteLine(ans);
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