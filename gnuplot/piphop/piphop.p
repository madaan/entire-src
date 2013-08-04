clear
reset
unset key
set style data histogram
set grid
set yr[0:60]
set style histogram clustered
set style fill solid border
set key at 6, 60
set term post eps enhanced color lw 2 "Helvetica" 20 
set output 'mypiphop.eps'
plot "pip-channel-hop.txt" u ($2):xticlabels(1) t'Without-Hopping', "pip-channel-hop.txt" u ($3):xticlabels(1) t'With-Hopping', "pip-channel-hop.txt" u ($4):xticlabels(1) w lp t 'Without-Interference'
set term x11
set output
