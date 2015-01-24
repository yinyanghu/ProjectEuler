program problem48;
var ans,k,w:qword;
    i,j:longint;
begin
    ans:=0; w:=10000000000;
    for i:=1 to 1000 do begin
	k:=i mod w;
	for j:=1 to i-1 do begin
	    k:=(k*i) mod w;
	    if k=0 then break;
	end;
	ans:=(ans+k) mod w;
    end;
    writeln(ans);
end.