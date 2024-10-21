local function main()
  local h, w = io.read('n', 'n')
  a = {}
  for i = 1, h do
    a[i] = {}
    for j = 1, w do
      a[i][j] = io.read('n')
    end
  end
  for i = 1, h do
    for j = 1, w do
      io.write(a[i][j] + io.read('n') .. ' ')
    end
    io.write('\n')
  end
end

main()