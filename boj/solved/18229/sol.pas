{$R-,S-,Q-,I-,O+}
var
  n,m,k,i,j: int32;
  a: array[0..100,0..100] of int32;
begin
  read(n,m,k);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for j:=1 to m do
    for i:=1 to n do
    begin
      a[i,j] += a[i,j-1];
      if a[i,j] >= k then
      begin
        writeln(i,' ',j);
        halt;
      end;
    end;
  assert(False);
end.
