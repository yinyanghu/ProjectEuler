program problem16;
const maxl=500;
type arr=array[1..maxl] of longint;
var a:arr;
    ans,i:longint;
procedure multiply(a:arr; var c:arr);
 var i,k:longint;
 begin
     k:=0;
     for i:=1 to maxl do begin
	 c[i]:=a[i]*2+k;
	 k:=c[i] div 10;
	 c[i]:=c[i] mod 10;
     end;
 end;

begin
    fillchar(a,sizeof(a),0);
    a[1]:=1;
    for i:=1 to 1000 do multiply(a,a);
    ans:=0;
    for i:=1 to maxl do ans:=ans+a[i];
    writeln(ans);
end.
