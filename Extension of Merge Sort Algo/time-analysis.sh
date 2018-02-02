
#!/bin/bash

gcc union.c  && ./a r
gcc assign2.c  && ./a

gnuplot -persist <<-EOFMarker
    set xlabel "Sum of size of arrays (m+n)"
    set ylabel "Time" 
    set term png
    set title "Ringsum"
    set output "graph-for-ringsum.png"
    plot "temp.txt" title "Ringsum"
    set title "Ringsum"
    set output "for-ringsum.png"
    filenames = "min max avg"
    plot for [file in filenames] file.".txt" title file with lines
EOFMarker

gcc union.c  && ./a u
gcc assign2.c  && ./a

gnuplot -persist <<-EOFMarker
    set xlabel "Sum of size of arrays (m+n)"
    set ylabel "Time" 
    set term png
    set title "Union"
    set output "graph-for-union.png"
    plot "temp.txt" title "Union"
    set title "Union"
    set output "for-union.png"
    filenames = "min max avg"
    plot for [file in filenames] file.".txt" title file with lines
EOFMarker

gcc union.c  && ./a i
gcc assign2.c  && ./a

gnuplot -persist <<-EOFMarker 
    set xlabel "Sum of size of arrays (m+n)"
    set ylabel "Time"   
    set term png
    set output "graph-for-intersection.png"
    set title "Intersection"
    plot "temp.txt" title "Intersection"
    set output "for-intersection.png"
    set title "Intersection"
    filenames = "min max avg"
    plot for [file in filenames] file.".txt" title file with lines
EOFMarker
