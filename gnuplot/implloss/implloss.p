clear
reset
unset key
set grid
set ylabel "Packet Drop(%)"
set xlabel "Node Id"
set style data histogram
set style histogram clustered
set key  top right
set style fill pattern border
set term post eps enhanced color lw 2 "Helvetica" 20 
set output 'implloss.eps' 
plot "impl-loss-stats.txt" u(($2+$3)/10):xticlabels(1) t 'Total',"impl-loss-stats.txt" u($2/10):xticlabels(1) t'Overflow', "impl-loss-stats.txt" u($3/10):xticlabels(1) t 'Retry-Limit'
#plot "impl-loss-stats.txt" u ($1 - 1):(($2+$3)/10) t 'Total',"impl-loss-stats.txt" u($2/10):xticlabels(1) t'Overflow', "impl-loss-stats.txt" u($3/10):xticlabels(1) t 'Retry-Limit'
#plot "impl-loss-stats.txt" u ($1 > $2 ? (($2+$3)/10) : 1/0) t 'Total',\
     "impl-loss-stats.txt" u ($1 > 2  ? (($3)/10) : 1/0) t 'Overflow'
#     "impl-loss-stats.txt" u ($0 == $1 ? (($2)/10) : 1/0) t 'Retry-Limit'
set term x11
set output

