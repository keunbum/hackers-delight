{$R-,S-,Q-,I-,O+}
var
  w, h, n, a, b, z: longint;
begin
  read(w,h,n,a,b);
  z:=(w div a)*(h div b);
  if z = 0 then write(-1)
  else write((n + z - 1) div z);
end.
