{$R-,S-,Q-,I-,O+}
var
  ok: boolean;
  ch: char;
  n,i,x,y,ans: int32;
  a: array[0..10] of int32;
  cmd: array[0..10] of ansistring;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(ch);
    cmd[i]:='';
    while ch in ['A'..'Z'] do
    begin
      cmd[i] += ch;
      read(ch);
    end;
    readln(a[i]);
  end;
  ans:=0;
  for x:=1 to 100 do
  begin
    y:=x;
    ok:=True;
    for i:=1 to n do
    begin
      if cmd[i] = 'ADD' then y += a[i];
      if cmd[i] = 'SUBTRACT' then
      begin
        y -= a[i];
        ok:=ok and (y >= 0);
      end;
      if cmd[i] = 'MULTIPLY' then y *= a[i];
      if cmd[i] = 'DIVIDE' then
      begin
        ok:=ok and (y mod a[i] = 0);
        y:=y div a[i];
      end;
    end;
    if not ok then ans += 1;
  end;
  writeln(ans);
end.