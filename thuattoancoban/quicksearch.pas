program equa0;
var     n,i,j,k,dem,dau,cuoi,giua:longint;
        a,b,c:array[1..100000] of longint;
        f1,f2:text;
const
        fi='equa0.inp';
        fo='equa0.out';
procedure       sort(l,r:longint);
var     i,j,tam,mid:longint;
begin
        if l>=r then exit;
        i:=l; j:=r;
        mid:=c[(l+r) div 2];
        repeat
                while c[i]< mid do inc(i);
                while c[j]>mid do dec(j);
                if i<=j then
                        begin
                        	tam:=c[i];
                        	c[i]:=c[j];
                        	c[j]:=tam;
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
        j:=1;
        k:=1;
        dem:=0;
        for i:=1 to n do
                begin
                if a[i]<0 then
                        begin
                                b[j]:=a[i];
                                inc(j);
                        end
                else
                        begin
                                c[k]:=a[i];
                                inc(k);
                        end;
                end;
        sort(1,k-1);
        for i:=1 to j-1 do
                b[i]:=abs(b[i]);
        for i:=1 to j-1 do
        begin
                dau:=1; cuoi:=k-1;
                while dau<= cuoi do
                        begin
                                giua:=(dau+cuoi) div 2;
                                if  b[i]=c[giua]then
                                        begin
                                                inc(dem);
                                                break;
                                        end
                                else if b[i]<c[giua] then cuoi:=giua-1
                                        else dau:=giua+1;
                        end;
        end;
        write(f2,dem);
        close(f2);
end.
