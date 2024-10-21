local function main()
  local n = io.read('n')
  local a = {}
  for _ = 1, n do
    table.insert(a, io.read('n'))
  end
  table.sort(a)
  for _, v in ipairs(a) do
    io.write(v, '\n')
  end
end

main()