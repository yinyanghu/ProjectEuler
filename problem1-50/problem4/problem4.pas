program problem4;
var k,ans,i,j:longint;
function check(x:longint):boolean;
 var i,l:longint;
     s:string;
 begin
     str(x,s);
     l:=length(s);
     for i:=1 to (l div 2) do 
	if s[i]<>s[l-i+1] then exit(false);
     check:=true;
 end;

begin
    ans:=0;
    for i:=100 to 999 do
	for j:=100 to 999 do begin
	    k:=i*j;
	    if check(k) then
		if k>ans then ans:=k;
	end;
    writeln(ans);
end.
