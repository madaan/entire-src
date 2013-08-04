clear
reset
unset key
set grid
set y2label "Utilization (%)"
set ylabel "Queue Overflow (%)"
set xlabel "Queue Size"
set yrange[0:20]
set y2range[60:100]
set xr[0:20]
set xtics
set y2tics
set ytics
set key at 20,9
set term post eps color enhanced lw 2 "Helvetica" 20
set output "aloss.eps"
plot  "anal-loss01-node1-stats.txt" u 1:($2*100) t 'Q0:Err 01%' w lp lc rgb "red" axes x1y2,\
    "anal-loss05-node1-stats.txt" u 1:($2*100)  t 'Q0:Err 05%' w lp lc rgb "red" axes x1y2,\
    "anal-loss10-node1-stats.txt" u 1:($2*100)  t 'Q0:Err 10%' w lp lc rgb "red" axes x1y2,\
    "anal-loss20-node1-stats.txt" u 1:($2*100)  t 'Q0:Err 20%' w lp lc rgb "red" axes x1y2,\
    "anal-loss01-node1-stats.txt" u 1:($3*100) t 'Util:Err 01%' w lp  lc rgb "blue" axes x1y1,\
    "anal-loss05-node1-stats.txt" u 1:($3*100) t 'Util:Err 05%' w lp lc rgb "blue" axes x1y1,\
   "anal-loss10-node1-stats.txt" u 1:($3*100) t 'Util:Err 10%' w lp  lc rgb "blue" axes x1y1,\
    "anal-loss20-node1-stats.txt" u 1:($3*100) t 'Util:Err 20%' w lp lc rgb "blue" axes x1y1

set term x11
set output
