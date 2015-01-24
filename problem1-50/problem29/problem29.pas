program problem29;
const e=0.000000000000001;
var a,b,ans,total,k:longint;
    f:array[1..20000] of extended;
procedure sort(l,r:longint);
 var i,j:longint;
     x,y:extended;
 begin
     i:=l; j:=r; x:=f[(l+r) shr 1];
     repeat
	while f[i]<x do inc(i);
	while f[j]>x do dec(j);
	if i<=j then begin
	    y:=f[i]; f[i]:=f[j]; f[j]:=y;
	    inc(i); dec(j);
	end;
     until i>j;
     if l<j then sort(l,j);
     if i<r then sort(i,r);
 end;

function value(a,b:longint):extended;
 begin
     value:=b*ln(a);
 end;

begin
    total:=0;
    for a:=2 to 100 do
	for b:=2 to 100 do begin
	    inc(total); f[total]:=value(a,b);
	end;
    sort(1,total);
    k:=0; ans:=0;
    while k<total do begin
	inc(k); inc(ans);
	while (k<total) and (abs(f[k+1]-f[k])<e) do inc(k);
    end;
    writeln(ans);
end.