clear
reset
unset key
set grid
set ylabel "Allan Deviation"
set xlabel "Averaging Interval (sec)"
set logscale y
set yr[0.001:1]
set xr[1:11]
set xtics ("0.01"1, "0.02"2, "0.05"3, "0.1"4, "0.2"5, "0.5"6, "1"7, "2"8, "5"9, "10"10, "60"15)
set key top right
set term post eps enhanced color lw 2 "Helvetica" 20
set output "allan.eps"
plot "allan-dev.txt" u 2 w lp t 'Measured', "allan-dev.txt" u 4 w lp t 'Uniform'
set term x11
set output


