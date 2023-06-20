{$R-,S-,Q-,I-,O+}
var
  i,n,m,v,st,b,e,cnt: longint;
  was: array[0..40] of boolean;
  x,y,pred: array[0..40*40] of longint;
  que,last: array[0..40] of longint;
begin
  read(n,m);
  for v:=1 to n do 
  begin
    last[v]:=0;
    was[v]:=False;
  end;
  for i:=1 to m do
  begin
    read(x[i],y[i]);
    pred[i]:=last[x[i]];
    last[x[i]]:=i;
    x[i+m]:=y[i];
    y[i+m]:=x[i];
    pred[i+m]:=last[x[i+m]];
    last[x[i+m]]:=i+m;
  end;
  cnt:=0;
  for st:=1 to n do
  begin          
    if was[st] then continue;
    inc(cnt);
    was[st]:=True;
    que[0]:=st;
    b:=0;
    e:=1;
    while b < e do
    begin
      i:=last[que[b]];
      while i > 0 do
      begin
        if not was[y[i]] then
        begin
          was[y[i]]:=True;
          que[e]:=y[i];
          inc(e);
        end;
        i:=pred[i];
      end;
      inc(b);
    end;
  end;
  writeln(cnt-1);
end.
