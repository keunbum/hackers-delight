{$R-,S-,Q-,I-,O+}
const
  DI: array[0..3] of int32 = (1, 0, -1, 0);
  DJ: array[0..3] of int32 = (0, 1, 0, -1);
var
  w,h: int32;
  was: array[0..99,0..99] of boolean;
  s: array[0..99,0..100] of char;

function DFS(i,j: int32): int32;
var
  ret,dir,ni,nj: int32;
begin
  ret:=1;
  for dir:=0 to 3 do
  begin
    ni:=i+DI[dir];
    nj:=j+DJ[dir];
    if (ni >= 0) and (nj >= 0) and (ni < h) and (nj < w) and (s[ni,nj] = s[i,j]) and (not was[ni,nj]) then
    begin
      was[ni,nj]:=True;
      inc(ret,DFS(ni,nj));
    end;
  end;
  DFS:=ret;
end;

var
  i,j,sz: int32;
  ret: array[0..1] of int32;
begin
  readln(w,h);
  for i:=0 to h-1 do readln(s[i]);
  ret[0]:=0;
  ret[1]:=0;
  fillchar(was,sizeof(was),False);
  for i:=0 to h-1 do
    for j:=0 to w-1 do
      if not was[i,j] then
      begin
        was[i,j]:=True;
        sz:=DFS(i,j);
        if s[i,j] = 'W' then inc(ret[0],sz*sz)
        else inc(ret[1],sz*sz);
      end;
  writeln(ret[0],' ',ret[1]);
end.
