local function main()
  local h, w = io.read('n', 'n')
  io.read()
  local cnt = 0
  for i = 1, h do
    local s = io.read()
    for j = 1, w do
      if s:sub(j, j) == '0' then
        cnt = cnt + 1
      end
    end
  end
  print(math.min(cnt, h * w - cnt))
end

main()