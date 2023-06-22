{$R-,S-,Q-,I-,O+}
const inf = longint((int64(1) << 31) - 1);

var
  _,i,x,n,k,ans,amin,amax,bmin,bmax: longint;
  a: array[0..1000] of longint;
  b: array[0..10000] of longint;

function Min(a,b: longint): longint;
begin
  if a < b then Min:=a
  else Min:=b;
end;

function Max(a,b: longint): longint;
begin
  if a > b then Max:=a
  else Max:=b;
end;

function Abs(a: longint): longint;
begin
  if a < 0 then a:=-a;
  Abs:=a;
end;

begin
  read(n,k);
  ans:=0;
  amin:=inf;
  amax:=0;
  for i:=1 to k do
  begin
    read(a[i]);
    if i > 1 then inc(ans,Abs(a[i]-a[i-1]));
    amin:=Min(amin,a[i]);
    amax:=Max(amax,a[i]);
  end;
  dec(n,k);
  if n = 0 then
  begin
    writeln(ans);
    exit;
  end;
  bmin:=inf;
  bmax:=0;
  for _:= 1 to n do
  begin
    read(x);
    bmin:=Min(bmin,x);
    bmax:=Max(bmax,x);
  end;
  if bmin < amin then inc(ans,Min(Min(a[1],a[k])-bmin,2*(amin-bmin)));
  if amax < bmax then inc(ans,Min(bmax-Max(a[1],a[k]),2*(bmax-amax)));
  writeln(ans);
end.
