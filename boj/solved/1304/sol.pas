{$R-,S-,Q-,I-,O+}
var
  ok: boolean;
  n,m,x,y,i,j: int32;
  aux: array[0..3000] of boolean;
begin
  read(n,m);
  while m > 0 do
  begin
    read(x,y);
    if x > y then
      for i:=y to x-1 do
        aux[i]:=True;
    dec(m);
  end;
  for i:=1 to n do
  begin
    ok:=(n mod i) = 0;
    j:=i;
    while j <= n do
    begin
      ok:=ok and not aux[j];
      inc(j,i);
    end;
    if ok then
    begin
      writeln(n div i);
      halt;
    end;
  end;
  assert(False);
end.
