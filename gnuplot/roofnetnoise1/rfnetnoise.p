clear
reset
unset key
set xlabel "Transmitter-Receiver pair num."
set ylabel "Silence level (dBm)"
set datafile separator "\t"
set xtics 0, 10, 70
set autoscale
set yr[-100:-70]
set size 1, 0.5
set key at 55, -70
set xr[0:70]
set term post eps enhanced color lw 2 "Helvetica" 20 
set output 'roofnetnoise1.eps' 
plot "roofnetnoise1.txt" u 1 t "5%-ile" w lp lc rgb "red", \
     "roofnetnoise1.txt" u 4 t "Median (50%-ile)" w lp lt 9 lc rgb "blue",\
     "roofnetnoise1.txt" u 2 t "95%-ile" w lp lt 2 lc rgb "black"
set term x11
set output
