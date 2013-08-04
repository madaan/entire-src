clear
reset
unset key
set xlabel "Number of Hops"
set ylabel "Latency (Seconds)"
set autoscale
set grid
set xr[1:6]
set yr[0:450]
set terminal post eps enhanced color lw 2 "Helvetica" 20
set output 'pip.eps'
set key at 5.7, 300
plot "./pip-latency-comparison.txt" u 1:2 t 'PIP' w lp lt 2 lc rgb "red","./pip-latency-comparison.txt" u 1:3 t 'Flush' w lp lt 1 lc rgb "blue","./pip-latency-comparison.txt" u 1:4 t 'PSFQ' w lp lt 7 lc rgb "black","./pip-latency-comparison.txt" u 1:5 t 'Fetch' w lp lt 9 lc rgb "magenta"
set term x11
set output
