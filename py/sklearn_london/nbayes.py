#sg
import numpy as np
from sklearn.svm import SVC
from sklearn import grid_search, preprocessing, decomposition
from sklearn.pipeline import Pipeline
from sklearn.neighbors import KNeighborsClassifier
from sklearn.naive_bayes import GaussianNB

def main():
    targetset = np.genfromtxt(open('trainLabels.csv','r'), dtype='f16')
    target = [x for x in targetset]

    trainset = np.genfromtxt(open('train.csv','r'), delimiter=',', dtype='f16')
    train = np.array([x for x in trainset])
    
    gnb = GaussianNB()
    gnb.fit(train, target)

    testset = np.genfromtxt(open('test.csv','r'), delimiter = ',',  dtype='f16')

    print 'Id,Solution'
    for i, t in enumerate(testset):
        print '%d,%d' % (i + 1, int(neigh.predict(t)[0]))


def decomposition_pca(train, test):
    """ Linear dimensionality reduction """
    pca = decomposition.PCA(n_components=12, whiten=True)
    train_pca = pca.fit_transform(train)
    test_pca = pca.transform(test)
    return train_pca, test_pca

def cvalidate():
    from sklearn import cross_validation
    targetset = np.genfromtxt(open('trainLabels.csv','r'), dtype='f16')
    y = [x for x in targetset]

    trainset = np.genfromtxt(open('train.csv','r'), delimiter=',', dtype='f16')
    X = np.array([x for x in trainset])
    
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3, random_state = 0)

    gnb = GaussianNB()
    X_train, X_test = decomposition_pca(X_train, X_test)
    gnb.fit(X_train, y_train)

    print gnb.score(X_test, y_test)



if __name__ == '__main__':
    cvalidate()

    
