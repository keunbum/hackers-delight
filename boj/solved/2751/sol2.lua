local function main()
  local n = io.read('n')
  local a = {}
  for _ = 1, n do
    table.insert(a, io.read('n'))
  end
  table.sort(a)
  for i = 1, n do
    io.write(a[i], '\n')
  end
end

main()