import nltk
import re
from nltk.corpus.reader.plaintext import PlaintextCorpusReader
from nltk import FreqDist

corpus_root = '/home/aman/entire-src/py/dir'
speeches = PlaintextCorpusReader(corpus_root, '.*\.txt')

print "Finished importing corpus"

raw = speeches.raw().lower()
tokens = nltk.word_tokenize(raw)
tgs = nltk.trigrams(tokens)
fdist = nltk.FreqDist(tgs)
for k,v in fdist.items():
    print k,v
