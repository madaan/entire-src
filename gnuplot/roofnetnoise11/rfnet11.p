set xlabel "Transmitter-Receiver pair num."
set ylabel "Silence level (dBm)"
set datafile separator "\t"
set xtics 0, 5, 25
set autoscale
set yr[-100:-70]
set size 1, 0.5
set key at 20, -71
set term post eps enhanced color lw 2 "Helvetica" 20 
set output 'roofnetnoise11.eps' 
plot "roofnet-noise11.txt" u 1 t "5%-ile" w lp lc rgb "red", \
     "roofnet-noise11.txt" u 4 t "Median (50%-ile)" w lp lt 9 lc rgb "blue",\
     "roofnet-noise11.txt" u 2 t "95%-ile" w lp lt 2 lc rgb "black"
set term x11
set output
