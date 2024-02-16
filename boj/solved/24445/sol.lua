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
  local ret = {}
  for i = 1, n do
    ret[i] = 0
  end
  ret[r] = 1
  local cnt = 2
  local que = {r}
  local b = 1
  while b <= #que do
    local v = que[b]
    for i = #g[v], 1, -1 do
      local u = g[v][i]
      if ret[u] == 0 then
        ret[u] = cnt
        cnt = cnt + 1
        table.insert(que, u)
      end
    end
    b = b + 1
  end
  for i = 1, n do
    io.write(ret[i], '\n')
  end
end

main()