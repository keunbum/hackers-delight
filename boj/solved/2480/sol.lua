local function main()
  local a, b, c = io.read('n', 'n', 'n')
  local ans = 0
  if (a == b) and (b == c) then
    ans = 10000 + a * 1000
  elseif (a == b) or (b == c) then
    ans = 1000 + b * 100
  elseif c == a then
    ans = 1000 + a * 100
  else
    ans = math.max(a, b, c) * 100
  end
  print(ans)
end

main()