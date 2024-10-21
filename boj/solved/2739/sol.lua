local function main()
  local n = io.read('n')
  for i = 1, 9 do
    print(string.format("%d * %d = %d", n, i, n * i))
  end
end

main()