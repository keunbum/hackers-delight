local function main()
  local n, m = io.read('n', 'n')
  local a = {}
  for i = 1, n do a[i] = io.read('n') end
  local ans = 0
  for i = 1, n do
    for j = i + 1, n do
      for k = j + 1, n do
        local s = a[i] + a[j] + a[k]
        if s <= m and s > ans then
          ans = s
        end
      end
    end
  end
  print(ans)
end

main()