set xlabel "Number of Hops"
set ylabel "Latency (Seconds)"
set autoscale
set grid
set xr[1:6]
set yr[0:450]
plot "./pip-latency-comparison.txt" u 1:2 t 'PIP' w lp,\
     "./pip-latency-comparison.txt" u 1:3 t 'Flush' w lp,\
     "./pip-latency-comparison.txt" u 1:4 t 'PSFQ' w lp,\
     "./pip-latency-comparison.txt" u 1:5 t 'Fetch' w lp
