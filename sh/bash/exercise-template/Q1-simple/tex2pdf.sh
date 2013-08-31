#/bin/bash

# This program should compile paper.tex, a tex file assumed to be in
# the current/working directory.  And it should tar-gzip the entire
# current directory (from the current directory) to a tgz file called
# paper.tgz.  It should then move the paper.tgz file to /tmp.
latex paper.tex
tar -cvzf --ignore-failed-read paper.tgz .
mv paper.tgz /tmp
