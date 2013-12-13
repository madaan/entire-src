#sg
import numpy as np
from sklearn.svm import SVC
from sklearn import grid_search, preprocessing, decomposition
from sklearn.pipeline import Pipeline
def main():
    targetset = np.genfromtxt(open('trainLabels.csv','r'), dtype='f16')
    target = [x for x in targetset]

    trainset = np.genfromtxt(open('train.csv','r'), delimiter=',', dtype='f16')
    train = np.array([x for x in trainset])
    
    testset = np.genfromtxt(open('test.csv','r'), delimiter = ',',  dtype='f16')
    
    train, testset = decomposition_pca(train, testset)
    
    #Training begins
    c_range = 10.0 ** np.arange(6.5,7.5,.25)
    gamma_range = 10.0 ** np.arange(-2.5,0.5,.25)
    parameters = {'kernel':['rbf'], 'C':c_range,  'gamma':gamma_range} 
    svr = SVC()

    clf = grid_search.GridSearchCV(svr, parameters, cv = 10)


    clf.fit(train, target)
    
    #Prediction begins
    print 'Id,Solution'
    for i, t in enumerate(testset):
        print '%d,%d' % (i + 1, int(clf.predict(t)[0]))


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
    
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.1, random_state = 0)


    #mmxs = preprocessing.MinMaxScaler(feature_range=(-1, 1))
    #X_test = mmxs.fit_transform(X_test)
    #X_train = mmxs.fit_transform(X_train)

    X_train, X_test = decomposition_pca(X_train, X_test)
    parameters = {'kernel':('linear', 'rbf'), 'C':[1, 10]}
    c_range = 10.0 ** np.arange(6.5,7.5,.25)
    gamma_range = 10.0 ** np.arange(-2.5,0.5,.25)
    parameters = {'kernel':['rbf'], 'C':c_range,  'gamma':gamma_range} 
    svr = SVC()

    clf = grid_search.GridSearchCV(svr, parameters, cv = 10)

    print clf.estimator
    #clf = Pipeline([('scale', Scaler()), ('svm', SVC())])

    clf.fit(X_train, y_train)


    print clf.score(X_test, y_test)



if __name__ == '__main__':
    cvalidate()
    #main()
