local function main()
  local tt = io.read('n')
  for qq = 1, tt do
    local a, b = io.read('n', 'n')
    io.write(string.format('Case #%d: %d + %d = %d\n', qq, a, b, a + b))
  end
end

main()