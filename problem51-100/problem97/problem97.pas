program problem97;
const maxl=10;
type arr=array[1..maxl] of longint;
var a:arr;
    i:longint;
procedure multiply(a:arr; b:longint; var c:arr);
 var i,k:longint;
 begin
     k:=0;
     for i:=1 to maxl do begin
	 c[i]:=a[i]*b+k;
	 k:=c[i] div 10;
	 c[i]:=c[i] mod 10;
     end;
 end;

begin
    fillchar(a,sizeof(a),0);
    a[1]:=1;
    for i:=1 to 7830457 do multiply(a,2,a);
    multiply(a,28433,a);
    a[1]:=a[1]+1;
    i:=1;
    while a[i]>=10 do begin
	a[i]:=a[i]-10;
	inc(i);
	inc(a[i]);
    end;
    for i:=maxl downto 1 do write(a[i]);
    writeln;
end.
