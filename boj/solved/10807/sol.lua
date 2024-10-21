local function main()
  local n = io.read('n')
  local a = {}
  for _ = 1, n do
    table.insert(a, io.read('n'))
  end
  local v = io.read('n')
  local ans = 0
  for _, x in ipairs(a) do
    if x == v then
      ans = ans + 1
    end
  end
  print(ans)
end

main()