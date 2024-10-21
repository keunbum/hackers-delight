local function main()
  local tt = io.read('n')
  local ans = ''
  for _ = 1, tt do
    local a, b = io.read('n', 'n')
    ans = ans .. (a + b) .. '\n'
  end
  print(ans)
end

main()