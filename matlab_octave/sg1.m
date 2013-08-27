%sg
x=input(' first seq ');
y=input(' second seq' );
lx=length(x);
ly=length(y);
for i=1:ly
  
    for j=1:lx
        a1=x(j);
        b1=y(i)
        a(i,j)=a1*b1;
    end
end
display(a);
