program problem2;
const max=1000000;
var f:array[1..30] of longint;
    total,i,j:longint;
begin
    f[1]:=1; f[2]:=2;
    for i:=3 to 30 do begin
	f[i]:=f[i-1]+f[i-2];
	if f[i]>max then break;
    end;
    total:=0;
    for j:=1 to i-1 do 
	if not odd(f[j]) then total:=total+f[j];
    writeln(total);
end.
