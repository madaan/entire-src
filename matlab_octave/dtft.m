    


%sg
x=input('Enter the sequence');
w=-(pi):.01:(pi);
wl=length(w);
xl=length(x);
i=sqrt(-1);
res=zeros(1,1000);
for wc=1:wl
    for ec=1:xl
        res(wc)=res(wc)+exp(i*(ec-1)*w(wc));
    end
    
    

    
    
    
    
    
end

su
bplot(2,1,1);
plot(w,fft(x,wl));
subplot(2,1,2);
plot(w,res(1:wl));        