{$R-,S-,Q-,I-,O+}
var
  ok: boolean;
  n,i,j,ni,nj,di,dj,v,s: longint;
  was: array[0..9] of boolean;
  a: array[0..9] of longint;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a[i]);
    dec(a[i]);
  end;
  ok:=True;
  for v:=1 to n-1 do
  begin
    was[a[v]]:=True;
    ok:=ok and not was[a[v+1]];
    i:=a[v] div 3;
    j:=a[v] mod 3;
    ni:=a[v+1] div 3;
    nj:=a[v+1] mod 3;
    di:=ni-i;
    dj:=nj-j;
    s:=di*di+dj*dj;
    ok:=ok and (((s <> 4) and (s <> 8)) or was[3*(i+di div 2)+(j+dj div 2)]);
  end;
  if ok then writeln('YES')
  else writeln('NO');
end.
