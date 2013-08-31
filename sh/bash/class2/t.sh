#! /bin/bash

function f() {
cat f1.txt
cat f2.txt
}
f > p1.txt

for i in *
    do
        echo $i
    done > fileList.txt
