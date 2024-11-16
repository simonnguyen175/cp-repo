program remain;
var     n,i:longint; tam,d:int64;
        a,b:array[1..1000] of int64;
        f1,f2:text;
const
        fi='remain.inp';
        fo='remain.out';
function        uc(a,b:int64):int64;
var     r:int64;
begin
        while b>0 do
                begin
                        r:= a mod b;
                        a:=b;
                        b:=r;
                end;
        exit(a);
end;
begin
        assign(f1,fi);
        reset(f1);
        readln(f1,n);
        for i:=1 to n do read(f1,a[i]);
        close(f1);
        assign(f2,fo);
        rewrite(f2);
        d:=1;
        for i:=2 to n do if a[1]>a[i] then
                begin
                        tam:=a[1];
                        a[1]:=a[i];
                        a[i]:=tam;
                end;
        for i:=1 to n-1 do
                b[i]:=a[i+1]-a[1];
        d:=b[1];
        for i:=2 to n -1 do
                d:=uc(d,b[i]);
        write(f2,d);
        close(f2);
end.