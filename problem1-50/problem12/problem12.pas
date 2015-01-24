program problem12;
const maxn=500;
var f,i:longint;
function check(x:longint):boolean;
 var ans,i,k,p:longint;
 begin
     k:=x; i:=1; ans:=1;
     while k<>1 do begin
	 inc(i);
	 if (k mod i=0) then begin
	     p:=0;
	     while (k mod i=0) do begin
		 inc(p);
		 k:=k div i;
	     end;
	     ans:=ans*(p+1);
	     if ans>maxn then exit(true);
	 end;
     end;
     check:=false;
 end;

begin
    i:=1; f:=1;
    while (not check(f)) do begin
	inc(i);
	f:=f+i;
    end;
    writeln(f);
end.
