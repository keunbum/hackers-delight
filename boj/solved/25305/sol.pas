{$R-,S-,Q-,I-,O+}
var
  n,i,k: int32;
  a: array[0..1000] of int32;

procedure swap(var x, y: int32); inline;
begin
  x:=x xor y;
  y:=x xor y;
  x:=x xor y;
end;

(* [st, en] *)
procedure downheap(var a: array of int32; st, en: int32);
var
  pr,ch,l,r: int32;
begin
  pr:=st;
  while true do
  begin
    l:=2*pr+1;
    r:=l+1;
    if l > en then exit;
    if (r > en) or (a[l] < a[r]) then ch:=l
    else ch:=r;
    if a[pr] <= a[ch] then exit;
    swap(a[pr], a[ch]);
    pr:=ch;
  end;
end;

procedure heapsort(var a: array of int32; n: int32);
var
  i: int32;
begin
  for i:=(n-1) div 2 downto 0 do
    downheap(a, i, n - 1);
  for i:=n-1 downto 1 do
  begin
    swap(a[0], a[i]);
    downheap(a, 0, i-1);
  end;
end;

begin
  read(n, k);
  for i:=0 to n-1 do
    read(a[i]);
  heapsort(a, n);
  write(a[k-1]);
end.
