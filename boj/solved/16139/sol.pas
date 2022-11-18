{$R-,S-,Q-,I-,O+}
var
  ch: char;
  i,j,l,r,q: int32;
  p: array[0..200000,1..26] of int32;
  s: ansistring;
begin
  readln(s);
  fillchar(p,sizeof(p),0);
  for i:= 1 to length(s) do
    for j:=1 to 26 do
      p[i,j]:=p[i-1,j]+int32(j = (ord(s[i])-ord('a')+1));
  readln(q);
  while q > 0 do
  begin
    readln(ch, l, r);
    j:=ord(ch)-ord('a')+1;
    writeln(p[r+1,j]-p[l,j]);
    dec(q);
  end;
end.
