# -*- coding: utf-8 -*-
#sg
import codecs
def create_maps(filenames):
	return set(line for line in codecs.open(filenames, encoding='utf-8', errors = 'replace'))


def main():
	s = create_maps('test.txt')
	if u'Oberbürgermeister' in s:
		print 'found'
	else:
		print 'not found'
	t = open('t', 'w')
	for i in s:
		t.write(i.encode('utf-8'))

if __name__ == '__main__':
	main()
