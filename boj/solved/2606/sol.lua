local function main()
  local n, m = io.read('n', 'n')
  local g = {}
  for i = 1, n do
    g[i] = {}
  end
  for _ = 1, m do
    local x, y = io.read('n', 'n')
    table.insert(g[x], y)
    table.insert(g[y], x)
  end
  local was = {}
  was[1] = true
  local que = {1}
  local b = 1
  while b <= #que do
    for _, u in ipairs(g[que[b]]) do
      if not was[u] then
        was[u] = true
        table.insert(que, u)
      end
    end
    b = b + 1
  end
  print(b - 2)
end

main()