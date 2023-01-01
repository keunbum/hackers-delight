{$R-,S-,Q-,I-,O+}
var
  found: boolean;
  i,t,n,top: int32;
  cnt: array[0..1] of int32;
  a: array[0..200] of int32; 
begin
  read(n);
  for i:=1 to n do
  begin
    read(t);
    a[t]:=1;
  end;
  t:=1;
  top:=0;
  cnt[0]:=n;
  cnt[1]:=n;
  while (cnt[0] > 0) and (cnt[1] > 0) do
  begin
    found:=False;
    for i:=top+1 to n+n do
    begin
      if a[i] = t then
      begin
        found:=True;
        break;
      end;
    end;
    if not found then top:=0 else
    begin
      top:=i;
      a[i]:=-1;
      dec(cnt[t]);
    end;
    t:=t xor 1;
  end;
  for i:=0 to 1 do
    writeln(cnt[i]);
end.
