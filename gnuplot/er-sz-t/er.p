clear
reset
unset key
set grid
set logscale y
set yr[0.001:1]
set key top right
set ylabel "Error Rate"
#set term post eps enhanced color lw 2 "Helvetica" 20
set style data histogram
set style histogram gap 1
set xr[0:20]
set style fill pattern border
set key at 8,.7
set key font ",20"
set xtics ("1"0, "2"1, "5.5"2, "11"3, "1"6, "2"7, "5.5"8, "11"9, "1"11, "2"12, "5.5"13, "11"14, "1"16, "2"17, "5.5"18, "11"19)
set term post eps enhanced color lw 2 "Helvetica" 20
set output "er.eps"
plot newhistogram "SNR = 13db" lt 1 at 0, "er-sz-rt.txt" every ::0::3 using 2 t '100 bytes', '' every ::0::3 using 4 t '500 bytes', '' every ::0::3 using 6 t '1400 bytes', \
     newhistogram "SNR = 7db" lt 1 at 6, "er-sz-rt.txt" every ::4::7 using 2 notitle, '' every ::4::7 using 4 notitle, '' every ::4::7 using 6 notitle, \
     newhistogram "SNR = 3db" lt 1, "er-sz-rt.txt" every ::8::11 using 2 notitle, '' every ::8::11 using 4 notitle, '' every ::8::11 using 6 notitle, \
     newhistogram "SNR = 2db" lt 1, "er-sz-rt.txt" every ::12::15 using 2 notitle, '' every ::12::15 using 4 notitle, '' every ::12::15 using 6 notitle;
set term x11
set output
