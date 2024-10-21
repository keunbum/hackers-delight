{$R-,S-,Q-,I-,O+}
var
  ok: boolean;
  n,i,j,r,s,c: int32;
  chk: array[0..10000] of boolean;
  a: array[0..100,0..100] of int32;
begin
  read(n);
  ok:=True;
  fillchar(chk,sizeof(chk),False);
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      read(a[i,j]);
      ok:=ok and (not chk[a[i,j]]);
      chk[a[i,j]]:=True;
    end;
  end;
  s:=n*(n*n+1) div 2;
  for r:=1 to 2 do
  begin
    for i:=1 to n do
    begin
      c:=0;
      for j:=1 to n do
      begin
        if r = 1 then inc(c,a[i,j])
        else inc(c,a[j,i]);
      end;
      ok:=ok and (c = s);
    end;
  end;
  for r:=1 to 2 do
  begin
    c:=0;
    for i:=1 to n do
    begin
      if r = 1 then inc(c,a[i,i])
      else inc(c,a[i,n+1-i]);
    end;
    ok:=ok and (c = s);
  end;
  if ok then writeln('TRUE')
  else writeln('FALSE');
end.