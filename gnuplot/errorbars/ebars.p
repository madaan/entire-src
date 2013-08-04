clear
reset
set grid
set ylabel "Average weight of potato sack (kg)"
set xlabel "Supplier number"
set term post eps enhanced color "Helvetica" 20 lw 2
set output 'myerrorbars.eps'
plot "errorbars.txt" u 1:2 w lp t 'Average over 10 sacks', "errorbars.txt" with errorbars notitle
set term x11
set output
