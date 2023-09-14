{$R-,S-,Q-,I-,O+}
const
  DX: array[0..3] of longint = (0, 0, -1, 1);
  DY: array[0..3] of longint = (1, -1, 0, 0);
  
type
Room = record
  top: longint;
  sz: longint;
end;

var
  n,k,i,j,x,y,dir,turn,rep,nx,ny,v,u,sz,t,b,e: longint;  
  a: array[0..13,0..13] of longint;
  rs: array[0..13,0..13] of Room;
  ps: array[1..10] of array[0..2] of longint;
  pre,nxt,us: array[1..10] of longint;

begin
  read(n,k);
  for i:=0 to n+1 do for j:=0 to n+1 do a[i,j]:=2;
  for i:=1 to n do for j:=1 to n do
  begin
    read(a[i,j]);
    rs[i,j].top:=0;
    rs[i,j].sz:=0;
  end;
  for i:=1 to k do
  begin
    read(x,y,dir);
    dec(dir);
    ps[i,0]:=x;
    ps[i,1]:=y;
    ps[i,2]:=dir;
    rs[x,y].top:=i;
    rs[x,y].sz:=1;
    pre[i]:=0;
    nxt[i]:=0;
  end;
  for turn:=1 to 1000 do
  begin
    for i:=1 to k do
    begin
      x:=ps[i,0];
      y:=ps[i,1];
      for rep:=1 to 2 do
      begin
        nx:=x+DX[ps[i,2]];
        ny:=y+DY[ps[i,2]];
        if a[nx,ny] = 2 then
        begin
          if rep = 1 then ps[i,2]:=ps[i,2] xor 1;
          continue;
        end;
        v:=i;
        if pre[v] <> 0 then nxt[pre[v]]:=0;
        rs[x,y].top:=pre[v];
        sz:=0;
        while v <> 0 do
        begin
          inc(sz);
          us[sz]:=v;
          v:=nxt[v];
        end;
        if a[nx,ny] = 1 then
        begin
          b:=1;
          e:=sz;
          while b < e do
          begin
            t:=us[b];
            us[b]:=us[e];
            us[e]:=t;
            inc(b);
            dec(e);
          end;
        end;
        for j:=1 to sz do
        begin
          u:=us[j];
          if rs[nx,ny].top <> 0 then nxt[rs[nx,ny].top]:=u;
          pre[u]:=rs[nx,ny].top;
          nxt[u]:=0;
          rs[nx,ny].top:=u;
          inc(rs[nx,ny].sz);
          dec(rs[x,y].sz);
          ps[u,0]:=nx;
          ps[u,1]:=ny;
        end;
        if rs[nx,ny].sz >= 4 then
        begin
          writeln(turn);
          exit();
        end;
        break;    
      end;
    end;
  end;
  writeln(-1);
end.
