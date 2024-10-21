local function main()
  local n = io.read('n')
  for i = 1, n do
    local s = i
    local x = i
    while x > 0 do
      s = s + x % 10
      x = x // 10
    end
    if s == n then
      print(i)
      return
    end
  end
  print(0)
end

main()