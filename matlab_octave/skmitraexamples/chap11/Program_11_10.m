% Program 11_10
% Spectral Analysis Using the DFT
%
N = input('Type in the length of DFT = ');
T = input('Type in the sampling period = ');
freq = input('Type in the frequency of the sinusoid -= ');
k = 0:N-1;
f = sin(2*pi*freq*k*T);
F = fft(f);
stem(k,abs(F));grid
xlabel('k');
ylabel('|X[k]|');