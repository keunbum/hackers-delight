local function main()
  tt = io.read('n')
  for _ = 1, tt do
    a, b = io.read('n', 'n')
    print(a + b)
  end
end

main()