
#sg
import numpy as np
from sklearn.svm import SVC
from sklearn import grid_search, preprocessing, decomposition
from sklearn.pipeline import Pipeline
from sklearn.neighbors import KNeighborsClassifier

def main():

    trainset = np.genfromtxt(open('train.csv','r'), delimiter=',')[1:]
    X = np.array([x[1:8] for x in trainset])
    y = np.array([x[8] for x in trainset])
    #print X,y
    import math
    for i, x in enumerate(X):
        for j, xx in enumerate(x):
            if(math.isnan(xx)):
                X[i][j] = 25.6
   
    
    testset = np.genfromtxt(open('test.csv','r'), delimiter = ',')[1:]

    test = np.array([x[1:8] for x in testset])
    for i, x in enumerate(test):
        for j, xx in enumerate(x):
            if(math.isnan(xx)):
                test[i][j] = 25.6
   

    X, test = decomposition_pca(X, test)

    neigh = KNeighborsClassifier(n_neighbors=20, algorithm='auto')
    neigh.fit(X, y)
    


    print 'PassengerId,Survived'
    for i, t in enumerate(test):
        print '%d,%d' % (i + 892, int(neigh.predict(t)[0]))

def decomposition_pca(train, test):
    """ Linear dimensionality reduction """
    pca = decomposition.PCA(n_components=14, whiten=True)
    train_pca = pca.fit_transform(train)
    test_pca = pca.transform(test)
    return train_pca, test_pca




def cvalidate():
    from sklearn import cross_validation

    trainset = np.genfromtxt(open('train.csv','r'), delimiter=',')[1:]
    X = np.array([x[1:8] for x in trainset])
    y = np.array([x[8] for x in trainset])
    #print X,y
    import math
    for i, x in enumerate(X):
        for j, xx in enumerate(x):
            if(math.isnan(xx)):
                X[i][j] = 25.6
   
    #print X[0:3]
    #print y[0:3]
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3, random_state = 0)

    X_train, X_test = decomposition_pca(X_train, X_test)
    neigh = KNeighborsClassifier(n_neighbors=20, algorithm='auto')
    neigh.fit(X_train, y_train)
    

    print neigh.score(X_test, y_test)



if __name__ == '__main__':
    #main()
    cvalidate()

    
