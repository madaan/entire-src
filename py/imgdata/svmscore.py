
#sg
import numpy as np
from sklearn.svm import SVC
from sklearn import grid_search, preprocessing, decomposition
from sklearn.pipeline import Pipeline
from sklearn.neighbors import KNeighborsClassifier

def decomposition_pca(train, test):
    """ Linear dimensionality reduction """
    pca = decomposition.PCA(n_components=10, whiten=True)
    train_pca = pca.fit_transform(train)
    test_pca = pca.transform(test)
    return train_pca, test_pca




def cvalidate():
    from sklearn import cross_validation

    trainset = np.genfromtxt(open('train','r'), delimiter=' ')
    targetset = np.genfromtxt(open('target','r'), delimiter=' ')
    X = np.array([x[0:64] for x in trainset])
    y = np.array([x for x in targetset])
    #print X,y
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3, random_state = 0)

    #X_train, X_test = decomposition_pca(X_train, X_test)
    

    X_train, X_test = decomposition_pca(X_train, X_test)
    c_range = 10.0 ** np.arange(6.5,7.5,1)
    gamma_range = 10.0 ** np.arange(-2.5,0.5,1)
    #parameters = {'kernel':['rbf'], 'C':c_range} 
    parameters = {'kernel':['rbf'], 'C':c_range,  'gamma':gamma_range} 
    svr = SVC(kernel = 'rbf', C = 0.72, gamma = 0.299)

    #clf = grid_search.GridSearchCV(svr, parameters)

    #print clf.estimator
    ##clf = Pipeline([('scale', Scaler()), ('svm', SVC())])

    svr.fit(X_train, y_train)
    print svr.score(X_test, y_test)





if __name__ == '__main__':
    cvalidate()

    
