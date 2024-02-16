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
    table.sort(g[i], function(a, b)
      return a > b
    end)
  end
  local cnt = 1
  local ret = {}
  local function DFS(v)
    ret[v] = cnt
    cnt = cnt + 1
    for _, u in ipairs(g[v]) do
      if not ret[u] then
        DFS(u)
      end
    end
  end
  DFS(r)
  for i = 1, n do
    if not ret[i] then
      io.write(0, '\n')
    else
      io.write(ret[i], '\n')
    end
  end
end

main()