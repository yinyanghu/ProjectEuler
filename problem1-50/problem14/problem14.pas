program problem14;
const maxn=1000000;
var i,max,k,x:longint;
    a:array[1..maxn] of longint;
function getlen(x:longint):longint;
 var s:longint;
     k:qword;
 begin
     s:=1; k:=x;
     while k<>1 do begin
	 if (k mod 2=1) then k:=k*3+1 else k:=k div 2;
         if (k<=maxn) and (a[k]<>-1) then exit(s+a[k]);
	 inc(s);
     end;
     getlen:=s;
 end;

begin
    max:=0;
    fillchar(a,sizeof(a),255);
    for i:=1 to maxn do begin
	k:=getlen(i);
        a[i]:=k;
	if k>max then begin
            max:=k;
            x:=i;
        end;
    end;
    writeln('Max Length=',max);
    writeln('Number=',x);
end.
