#sg
#This script runs LDA on a given set of sentences with the hope that it will help in uncovering keywords to be used with topics.

#The code uses document term matrix, and this function takes a list of files and creates a document term matrix from it

def readInList(file_list):
    res = []
    for file_name in file_list:
        for line in open(file_name, 'r'):
            res.append(line.rstrip('\n'))
    return res


def createDTMat(fileList):
    #step 1: create term document matrix
    from sklearn.feature_extraction.text import CountVectorizer
    from lda import lda
    import numpy as np
    cvec = CountVectorizer(stop_words = 'english')
    lines_list = readInList(fileList)
    X = cvec.fit_transform(lines_list).toarray()
    vocab = cvec.get_feature_names()

    #step 2: create the model
    model = lda.LDA(n_topics = 20, n_iter = 500, random_state = 1)

    #step 3: train the model
    model.fit(X)
    
    #step 4: extract results
    topic_word = model.topic_word_ 
    for i, topic_dist in enumerate(topic_word):
        topic_words = np.array(vocab)[np.argsort(topic_dist)][:-4:-1]
        print topic_words


if __name__ == '__main__':
    import sys
    createDTMat(sys.argv[1:])

    

