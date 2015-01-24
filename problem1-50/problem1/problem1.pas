program problem1;
const maxn=999;
var total,k:longint;
begin
    total:=0;
    for k:=1 to maxn do
	if (k mod 3=0) or (k mod 5=0) then total:=total+k;
    writeln(total);
end.
