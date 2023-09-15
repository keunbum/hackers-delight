{$R-,S-,Q-,I-,O+}
type
  Arr = array[0..50] of longint;

var
  changed: boolean;
  h,w,tt,qq,i,j,sum,cnt,x,d,k,ii,jj: longint;
  a,na: array[0..50] of Arr;
  ta: Arr;

begin
  read(h,w,tt);
  for i:=1 to h do for j:=1 to w do read(a[i,j]);
  for qq:=1 to tt do
  begin
    read(x,d,k);
    if d = 0 then k:=w-k;
    i:=x;
    while i <= h do
    begin
      for j:=1 to w do ta[j]:=a[i,j];
      for j:=1 to w do a[i,((j-k+w-1) mod w)+1]:=ta[j];
      inc(i,x);
    end;
    for i:=1 to h do for j:=1 to w do na[i,j]:=a[i,j];
    changed:=False;
    for i:=1 to h do for j:=1 to w do
    begin
      jj:=(j mod w)+1;
      if (a[i,j] <> 0) and (a[i,j] = a[i,jj]) then
      begin
        na[i,j]:=0;
        na[i,jj]:=0;
        changed:=True;
      end;
    end;
    for j:=1 to w do for i:=1 to h-1 do
    begin
      ii:=i+1;
      if (a[i,j] <> 0) and (a[i,j] = a[ii,j]) then
      begin
        na[i,j]:=0;
        na[ii,j]:=0;
        changed:=True;
      end;
    end;
    for i:=1 to h do for j:=1 to w do a[i,j]:=na[i,j];
    if not changed then
    begin
      sum:=0;
      cnt:=0;
      for i:=1 to h do for j:=1 to w do if a[i,j] <> 0 then
      begin
        inc(sum,a[i,j]);
        inc(cnt);
      end;
      for i:=1 to h do for j:=1 to w do if a[i,j] <> 0 then
      begin
        d:=a[i,j]*cnt-sum;
        if d > 0 then dec(a[i,j]) else
        if d < 0 then inc(a[i,j]);
      end;
    end;
  end;
  sum:=0;
  for i:=1 to h do for j:=1 to w do inc(sum,a[i,j]);
  writeln(sum);
end.
