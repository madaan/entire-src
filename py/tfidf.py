#sg
'''
Attempts to find the most important words in a corpus using tf-idf
'''

def getSentsAsDocs(filePath):
    return [x.strip() for x in open(filePath, 'r')]

def analyze(filePath):
    docs = getSentsAsDocs(filePath)
    from sklearn.feature_extraction.text import TfidfVectorizer
    import numpy as np
    from collections import defaultdict
    cvec = TfidfVectorizer(stop_words = 'english')
    cvec.fit_transform(docs) #this creates the vocabulary
    revocab = cvec.vocabulary_
    vocab = defaultdict(str)
    for word in revocab.keys():
        vocab[int(revocab[word])] = word

    tfidfmat = cvec.transform(docs).todense()
    #print cvec.transform(docs).todense()
    #print vocab
    numrow = tfidfmat.shape[0]
    numcol = tfidfmat.shape[1]
    for i in range(0, numrow):
        currRow = tfidfmat[i].A

        ind = currRow.argsort()[0][::-1][0:3]
        #print ind
        #print 'Row : %d' % i
        for indd in np.nditer(ind):
            #print tfidfmat[i].A[0, indd]
            print vocab[int(indd)],
        print

if __name__ == '__main__':
    analyze('/home/aman/popmatches')
    #analyze('/home/aman/inetmatches')
    #analyze('/home/aman/inm')
    #analyze('test')

    



