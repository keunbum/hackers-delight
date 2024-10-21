local function main()
  local n, m, r = io.read('n', 'n', 'n')
  local g = {}
  for i = 1, n do
    g[i] = {}
  end
  for _ = 1, m do
    local x, y = io.read('n', 'n')
    table.insert(g[x], y)
    table.insert(g[y], x)
  end
  for i = 1, n do
    table.sort(g[i])
  end
  local was = {}
  local function DFS(v)
    io.write(v, ' ')
    for _, u in ipairs(g[v]) do
      if not was[u] then
        was[u] = true
        DFS(u)
      end
    end
  end
  was[r] = true
  DFS(r)
  print()
  local que = {r}
  was[r] = false
  local b = 1
  while b <= #que do
    local v = que[b]
    io.write(v, ' ')
    for _, u in ipairs(g[v]) do
      if was[u] then
        was[u] = false
        table.insert(que, u)
      end
    end
    b = b + 1
  end
end

main()