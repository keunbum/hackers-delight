local function main()
  local function Fact(n)
    if n <= 1 then
      return 1
    end
    return n * Fact(n - 1)
  end
  print(Fact(io.read('n')))
end

main()