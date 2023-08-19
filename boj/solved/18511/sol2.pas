{$R-,S-,Q-,I-,O+}
var
  n,k,i,ans,b,e,ee,u: longint;
  a: array[0..3] of longint;
  t,s: array[0..6600] of longint;
  que,new_que,tmp: ^longint;
begin
  read(n,k);
  for i:=1 to k do read(a[i]);
  que:=t;
  new_que:=s;
  que[0]:=0;
  b:=0;
  e:=1;
  ans:=0;
  while b < e do
  begin
    ee:=0;
    while b < e do
    begin
      for i:=1 to k do
      begin
        u:=que[b]*10+a[i];
        if u <= n then
        begin
          if u > ans then ans:=u;
          new_que[ee]:=u;
          inc(ee);
        end;
      end;
      inc(b);
    end;
    tmp:=que;
    que:=new_que;
    new_que:=tmp;
    b:=0;
    e:=ee;
  end;
  writeln(ans);
end.
