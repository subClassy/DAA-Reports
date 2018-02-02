#!/bin/bash

gcc case-analysis.c && ./a
gcc case2.c && ./a
gcc case3.c && ./a

gnuplot -persist <<-EOFMarker
    set xlabel "Sum of size of arrays (m+n)"
    set ylabel "Time" 
    set term png


    set title "Analysis of Union of Sets"
    set output "analysis-for-union.png"
    filenames = "best-case-union worst-case-union"
    plot for [file in filenames] file.".txt" title file with lines

    set title "Analysis of Intersection of Sets"
    set output "analysis-for-intersection.png"
    filenames = "best-case-intersection worst-case-intersection"
    plot for [file in filenames] file.".txt" title file with lines


    set title "Analysis of Ringsum of Sets"
    set output "analysis-for-ringsum.png"
    filenames = "best-case-ringsum worst-case-ringsum"
    plot for [file in filenames] file.".txt" title file with lines
EOFMarker


    