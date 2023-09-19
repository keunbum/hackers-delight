{$R-,S-,Q-,I-,O+}
const
  dx: array[0..7] of longint = (-1, -1, 0, 1, 1, 1, 0, -1);
  dy: array[0..7] of longint = (0, -1, -1, -1, 0, 1, 1, 1);
var
  i,j,k,dir,ans: longint;
  a: array[1..4,1..4,0..1] of longint;

function Get(k: longint; var x,y: longint): boolean;
begin
  for i:=1 to 4 do for j:=1 to 4 do if a[i,j,0] = k then
  begin
    x:=i;
    y:=j;
    Get:=True;
    exit;
  end;
  Get:=False;
end;

procedure DFS(sx,sy,sdir,cur: longint);
var
  i,x,y,rep,pre,nx,ny,nsx,nsy: longint;
  ta: array[1..4,1..4,0..1] of longint;
  tt: array[0..1] of longint;
begin
  if cur > ans then ans:=cur;
  ta:=a;
  for i:=1 to 16 do
  begin
    if not Get(i,x,y) then continue;
    for rep:=1 to 8 do
    begin
      nx:=x+dx[a[x,y,1]];
      ny:=y+dy[a[x,y,1]];
      if (nx > 0) and (ny > 0) and (nx <= 4) and (ny <= 4) and ((nx <> sx) or (ny <> sy)) then
      begin
        tt:=a[x,y];
        a[x,y]:=a[nx,ny];
        a[nx,ny]:=tt;
        break;
      end;
      a[x,y,1]:=(a[x,y,1]+1) mod 8;
    end;
  end;
  nsx:=sx;
  nsy:=sy;
  for rep:=1 to 3 do
  begin
    inc(nsx,dx[sdir]);
    inc(nsy,dy[sdir]);
    if (nsx > 0) and (nsy > 0) and (nsx <= 4) and (nsy <= 4) and (a[nsx,nsy,0] <> 0) then
    begin
      id:=a[nsx,nsy,0];
      a[nsx,nsy,0]:=0;
      DFS(nsx,nsy,a[nsx,nsy,1],cur+id);
      a[nsx,nsy,0]:=id;
    end;
  end;
  a:=ta;
end;

begin
  for i:=1 to 4 do
    for j:=1 to 4 do
    begin
      read(k,dir);
      dec(dir);
      a[i,j,0]:=k;
      a[i,j,1]:=dir;
    end;
  i:=a[1,1,0];
  a[1,1,0]:=0;
  ans:=0;
  DFS(1,1,a[1,1,1],i);
  writeln(ans);
end.
