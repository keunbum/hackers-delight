local function main()
  local x, n = io.read('n', 'n')
  for _ = 1, n do
    local a, b = io.read('n', 'n')
    x = x - a * b
  end
  print(x == 0 and 'Yes' or 'No')
end

main()