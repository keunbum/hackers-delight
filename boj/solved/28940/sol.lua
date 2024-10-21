local function main()
  local w, h, n, a, b = io.read('n', 'n', 'n', 'n', 'n')
  local z = (w // a) * (h // b)
  print(z == 0 and -1 or (n + z - 1) // z)
end

main()