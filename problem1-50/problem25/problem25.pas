program problem25;
const maxn=5000;
      maxl=1000;
type arr=array[1..maxl] of shortint;
var f:array[1..maxn] of arr;
    l,i:longint;
function plus(a,b:arr):arr;
 var i,k:longint;
     c:arr;
 begin
     k:=0; fillchar(c,sizeof(c),0);
     for i:=1 to l do begin
	 c[i]:=a[i]+b[i]+k;
	 k:=c[i] div 10;
	 c[i]:=c[i] mod 10;
     end;
     if k<>0 then begin
	 inc(l);
	 c[l]:=k;
     end;
     plus:=c;
 end;

begin
    fillchar(f,sizeof(f),0);
    l:=1; f[1,1]:=1; f[2,1]:=1;
    for i:=3 to maxn do begin
	f[i]:=plus(f[i-1],f[i-2]);
	if l>=1000 then break;
    end;
    writeln(i);
end.