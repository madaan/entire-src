#sg
import numpy as np
from sklearn.svm import SVC
from sklearn import grid_search, preprocessing, decomposition
from sklearn.pipeline import Pipeline
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn import cross_validation
from sklearn.neighbors import KNeighborsClassifier
 
def main():
    targetset = np.genfromtxt(open('trainLabels.csv','r'), dtype='f16')
    target = [x for x in targetset]

    trainset = np.genfromtxt(open('train.csv','r'), delimiter=',', dtype='f16')
    train = np.array([x for x in trainset])


    testset = np.genfromtxt(open('test.csv','r'), delimiter = ',',  dtype='f16')
    train, testset = decomposition_pca(train, testset)


    #bdt = AdaBoostClassifier(DecisionTreeClassifier(max_depth=10),
    #                     algorithm="SAMME",
    #                     n_estimators=200)

    parameters = {'kernel':('linear', 'rbf'), 'C':[1, 10]}
    c_range = 10.0 ** np.arange(6.5,7.5,.25)
    gamma_range = 10.0 ** np.arange(-2.5,0.5,.25)
    parameters = {'kernel':['rbf'], 'C':c_range,  'gamma':gamma_range} 
    svr = SVC(probability=True)

    clf = grid_search.GridSearchCV(svr, parameters)
    

    clf.fit(train, target)
    bdt = AdaBoostClassifier(base_estimator = clf.best_estimator_,
                         algorithm="SAMME",
                         n_estimators=200)

    

    bdt.fit(train, target)
     
    


    print 'Id,Solution'
    for i, t in enumerate(testset):
        print '%d,%d' % (i + 1, int(bdt.predict(t)[0]))



def decomposition_pca(train, test):
    """ Linear dimensionality reduction """
    pca = decomposition.PCA(n_components=12, whiten=True)
    train_pca = pca.fit_transform(train)
    test_pca = pca.transform(test)
    return train_pca, test_pca



def cvalidate():
    targetset = np.genfromtxt(open('trainLabels.csv','r'), dtype='f16')
    y = [x for x in targetset]

    trainset = np.genfromtxt(open('train.csv','r'), delimiter=',', dtype='f16')
    X = np.array([x for x in trainset])
    
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3, random_state = 0)

    X_train, X_test = decomposition_pca(X_train, X_test)

    #SVM

    parameters = {'kernel':('linear', 'rbf'), 'C':[1, 10]}
    c_range = 10.0 ** np.arange(6.5,7.5,.25)
    gamma_range = 10.0 ** np.arange(-2.5,0.5,.25)
    parameters = {'kernel':['rbf'], 'C':c_range,  'gamma':gamma_range} 
    svr = SVC(probability=True)

    clf = grid_search.GridSearchCV(svr, parameters)
    

    clf.fit(X_train, y_train)
    bdt = AdaBoostClassifier(base_estimator = clf.best_estimator_,
                         algorithm="SAMME",
                         n_estimators=200)

    
    #bdt = AdaBoostClassifier(base_estimator = KNeighborsClassifier(n_neighbors=10))
    bdt.fit(X_train, y_train)
    

    print bdt.score(X_test, y_test)



if __name__ == '__main__':
    main()
    #cvalidate()

    
