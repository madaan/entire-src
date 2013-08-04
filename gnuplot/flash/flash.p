set ylabel "Latency (ticks)"
set xlabel "Number of Bytes"
set xr[0:515]
set yr[0:1200]
set grid
set key at 485,700
set term post eps enhanced color lw 2 "Helvetica" 20
set output 'flash.eps' 
plot "flashexp.txt" u 1:2 t 'read' w lp, \
     "flashexp.txt" u 1:3 t 'write' w lp, \
     "flashexp.txt" u 1:4 t 'sync' w lp
set term x11
set output
