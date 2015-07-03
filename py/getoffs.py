import sys
str = sys.argv[1]
str_split = str.split(" ")
offset = 0
for stn in str_split:
    print "%s %d:%d" %(stn, offset, offset + len(stn))
    offset += (len(stn) + 1)

