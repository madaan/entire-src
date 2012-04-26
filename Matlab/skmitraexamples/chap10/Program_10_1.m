% Program 10_1
% Estimation of FIR Filter Order Using remezord
%
fedge = input('Type in the bandedges = ');
mval = input('Desired magnitude values in each band = ');
dev = input('Allowable deviation in each band = ');
FT = input('Type in the sampling frequency = ');
[N, fpts, mag, wt] = remezord(fedge, mval, dev, FT);
fprintf('Filter order is %d \n',N);