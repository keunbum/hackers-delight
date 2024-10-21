local function main()
  for i = 1, io.read('n') do
    local a, b = io.read('n', 'n')
    io.write(string.format('Case #%d: %d\n', i, a + b))
  end
end

main()