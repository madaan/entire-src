lines = [line.strip() for line in open('index.txt')]
for line in lines:
    print int(float(line))
