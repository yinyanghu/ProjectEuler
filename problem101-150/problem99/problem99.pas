program problem99;
const maxn=1000;
type node=record
	 x,y,line:longint;
     end;
var a,b,total,i,max,k:longint;
    f:array[1..maxn] of node;
function value(a,b:longint):longint;
 begin
     value:=trunc(b*ln(a));
 end;

begin
    assign(input,'problem99.txt'); reset(input);
    max:=-1;
    for i:=1 to maxn do begin
	readln(a,b);
	k:=value(a,b);
	if k>max then begin
	    total:=1;
	    f[total].x:=a; f[total].y:=b; f[total].line:=i;
	    max:=k;
	end else if k=max then begin
	    inc(total);
	    f[total].x:=a; f[total].y:=b; f[total].line:=i;
	end;
    end; 
    close(input);
    writeln('Max=',max);
    for i:=1 to total do writeln(f[i].x,' ',f[i].y,' ',f[i].line);
end.