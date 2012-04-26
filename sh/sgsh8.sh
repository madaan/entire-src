#sg
tr -s ' \011' '\012\012'<$1|tr -cd "[a-zA-Z\012]" |sort|uniq -c|sort -nr|pr -6 -t|more
