program problem42;
var s:string;
    total,k,p:longint;
function value(s:string):longint;
 var ans,i:longint;
 begin
     ans:=0;
     for i:=1 to length(s) do ans:=ans+ord(s[i])-64;
     value:=ans;
 end;

begin
    assign(input,'problem42.txt'); reset(input);
    total:=0;
    while not eof do begin
	readln(s);
	k:=value(s)*2;
	p:=trunc(sqrt(k));
	if p*(p+1)=k then inc(total);
    end;
    writeln(total);
    close(input);
end.