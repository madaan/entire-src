% Program 11_11
% Computation of Linear Convolution Using DFT
%
g = input('Type in first sequence = ');
h = input('Type in second sequence = ');
ga = [g zeros(1,length(h)-1)];
ha = [h zeros(1,length(g)-1)];
G = fft(ga);H = fft(ha);
Y = G.*H;
y = ifft(Y);
disp('Output Sequence')
disp(real(y))