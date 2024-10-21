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
			int n = reader.NextInt();
			char[] a = new char[n];
			for (int i = 0; i < n; ++i)
			{
				a[i] = reader.Next()[0];
			}
			char c = reader.Next()[0];
			if (n == 1)
			{
				writer.WriteLine(Convert.ToInt32(c != a[0]));
				return;
			}
			bool result = Encode(a[0]);
			for (int i = 2; i < n - 2; i += 2)
			{
				result = Calc(result, a[i - 1], Encode(a[i]));
			}
			int answer = 2;
			foreach (char op in "&|")
			{
				foreach (char v in "FT")
				{
					if (Calc(result, op, Encode(v)) == Encode(c))
					{
						answer = Math.Min(answer, (Convert.ToInt32(op != a[n - 2])) + Convert.ToInt32(v != a[n - 1]));
					}
				}
			}
			writer.WriteLine(answer);
		}

		private static bool Encode(char v)
		{
			return v == 'T';
		}

		private static bool Calc(bool x, char op, bool y)
		{
			return op switch
			{
				'&' => x && y,
				'|' => x || y,
				_ => false
			};
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