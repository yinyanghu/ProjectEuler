program problem7;
const maxn=1000000;
      ans=10001;
var a:array[1..maxn] of boolean;
    i,total:longint;
procedure makelist;
 var i,j:longint;
 begin
     fillchar(a,sizeof(a),true);
     i:=2; a[1]:=false;
     while i<sqrt(maxn) do begin
	 while not a[i] do inc(i);
	 j:=2;
	 while (i*j<=maxn) do begin
	     a[i*j]:=false;
	     inc(j);
	 end;
	 inc(i);
     end;
 end;

begin
    makelist;
    total:=0;
    for i:=1 to maxn do
	if a[i] then begin
	    inc(total);
	    if total=ans then begin
		writeln(i);
		halt;
	    end;
	end;
end.
