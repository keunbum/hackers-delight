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
  local cnt = 2
  local ret = {}
  ret[r] = 1
  local que = {r}
  local b = 1
  while b <= #que do
    local v = que[b]
    for i = 1, #g[v] do
      local u = g[v][i]
      if not ret[u] then
        ret[u] = cnt
        cnt = cnt + 1
        table.insert(que, u)
      end
    end
    b = b + 1
  end
  for i = 1, n do
    io.write(ret[i] and ret[i] or 0, '\n')
  end
end

main()
