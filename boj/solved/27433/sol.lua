local function main()
  local n = io.read('n')
  if n == 0 then
    print(1)
    return
  end
  for i = n - 1, 1, -1 do
    n = n * i
  end
  print(n)
end

main()