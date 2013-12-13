#sg
import numpy as np
from sklearn.svm import SVC
from sklearn import grid_search, preprocessing
from sklearn.pipeline import Pipeline
def main():
    targetset = np.genfromtxt(open('trainLabels.csv','r'), dtype='f16')
    target = [x for x in targetset]

    trainset = np.genfromtxt(open('train.csv','r'), delimiter=',', dtype='f16')
    train = np.array([x for x in trainset])
    
    #need to first scale the features
    mmxs = preprocessing.MinMaxScaler(feature_range=(-1, 1))
    scaled_train = mmxs.fit_transform(train)

    
    parameters = {'kernel':['rbf'], 'C':[2**i for i in range(-3,11)],  'gamma':[2**i for i in range(-3,11)]} 
    svr = SVC()

    clf = grid_search.GridSearchCV(svr, parameters)

    #clf = Pipeline([('scale', Scaler()), ('svm', SVC())])
    
    clf.fit(scaled_train, target)

    testset = np.genfromtxt(open('test.csv','r'), delimiter = ',',  dtype='f16')
    scaled_test = mmxs.fit_transform(testset)
    print 'Id,Solution'
    for i, t in enumerate(scaled_test):
        print '%d,%d' % (i + 1, int(clf.predict(t)[0]))

def cvalidate():
    from sklearn import cross_validation
    targetset = np.genfromtxt(open('trainLabels.csv','r'), dtype='f16')
    y = [x for x in targetset]

    trainset = np.genfromtxt(open('train.csv','r'), delimiter=',', dtype='f16')
    X = np.array([x for x in trainset])
    
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3, random_state = 0)

    '''
    mmxs = preprocessing.MinMaxScaler(feature_range=(-1, 1))
    X_train = mmxs.fit_transform(X_train)
    X_test = mmxs.fit_transform(X_test)
    '''
    clf = SVC(kernel = 'rbf', C = 8.0)
    clf.fit(X_train, y_train)


    print clf.score(X_test, y_test)




if __name__ == '__main__':
    cvalidate()

    
