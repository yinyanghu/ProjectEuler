program problem20;
const maxl=200;
type arr=array[1..maxl] of longint;
var a:arr;
    i,k:longint;
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
    for i:=2 to 100 do multiply(a,i,a);
    k:=0;
    for i:=1 to maxl do k:=k+a[i];
    writeln(k);
end.
