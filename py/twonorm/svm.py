#sg
import numpy as np
import pylab as pl
from sklearn.svm import SVC
from sklearn.datasets import load_iris
from sklearn.cross_validation import StratifiedKFold
from sklearn.grid_search import GridSearchCV

def cvalidate():
    from sklearn import cross_validation
    from sklearn import grid_search
    trainset = np.genfromtxt(open('Twonorm','r'), delimiter=' ')
    X = np.array([x[0:20] for x in trainset])
    y = np.array([x[20] for x in trainset])
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.1, random_state = 0)
    C_range = 10.0 ** np.arange(-2, 9)
    gamma_range = 1.5223 * (10.0 ** np.arange(-5, 5))
    param_grid = dict(gamma=gamma_range, C=C_range)
    grid = grid_search.GridSearchCV(SVC(), param_grid=param_grid)
    grid.fit(X_train, y_train)
    print(grid.best_estimator_)
if __name__ == '__main__':
    cvalidate()

    
