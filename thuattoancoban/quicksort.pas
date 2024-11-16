program sortseq;
var     n,i,j:longint;
        a:array[1..100000] of longint;
        f1,f2:text;
const
        fi='sortseq.inp';
        fo='sortseq.out';
procedure       sort(l,r:longint);
var     i,j,tam,mid:longint;
begin
        if l>=r then exit;
        i:=l; j:=r;
        mid:=a[(l+r) div 2];
        repeat
                while a[i]< mid do inc(i);
                while a[j]>mid do dec(j);
                if i<=j then
                        begin
                        	tam:=a[i];
                        	a[i]:=a[j];
                        	a[j]:=tam;
                        	inc(i);
                        	dec(j);
                        end;
        until i>j;
        sort(l,j);
        sort(i,r);
end;
begin
        assign(f1,fi);
        reset(f1);
        readln(f1,n);
        for i:=1 to n do read(f1,a[i]);
        close(f1);
        assign(f2,fo);
        rewrite(f2);
        sort(1,n);
        for i:=1 to n do write(f2,a[i],' ');
        close(f2);
end.
