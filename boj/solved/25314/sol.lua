local function main()
  local n = io.read('n')
  for _ = 1, n // 4 do
    io.write('long ')
  end
  print('int')
end

main()