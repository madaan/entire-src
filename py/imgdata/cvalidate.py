#sg
import numpy as np
import pylab as pl
from sklearn.svm import SVC
from sklearn.datasets import load_iris
from sklearn.cross_validation import StratifiedKFold
from sklearn.grid_search import GridSearchCV

from sklearn import grid_search, preprocessing, decomposition

def cvalidate():

    trainset = np.genfromtxt(open('train','r'), delimiter=' ')
    targetset = np.genfromtxt(open('target','r'), delimiter=' ')
    X = np.array([x[0:64] for x in trainset])
    y = np.array([x for x in targetset])
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3, random_state = 0)
    C_range = 10.0 ** np.arange(-2, 9)
    gamma_range = 10.0 ** np.arange(-5, 4)
    param_grid = dict(gamma=gamma_range, C=C_range)
    grid = grid_search.GridSearchCV(SVC(), param_grid=param_grid)
    grid.fit(X_train, y_train)
    print(grid.best_estimator_)

def trainTestDataPrep():

    from sklearn import cross_validation
    trainset = np.genfromtxt(open('train','r'), delimiter=' ')
    targetset = np.genfromtxt(open('target','r'), delimiter=' ')
    X = np.array([x[0:64] for x in trainset])
    y = np.array([x for x in targetset])
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.1, random_state = 0)
    np.savetxt("train_x", X_train, fmt="%d")
    np.savetxt("test_x", X_test, fmt="%d")
    np.savetxt("train_y", y_train, fmt="%d")
    np.savetxt("test_y", y_test, fmt="%d")

if __name__ == '__main__':
    #cvalidate()
    trainTestDataPrep()

    
