#sg
from sklearn import svm
import numpy as np
def train():

    trainset = np.genfromtxt(open('train_x','r'), delimiter=' ')
    targetset = np.genfromtxt(open('train_y','r'), delimiter=' ')

    X = np.array([x[0:64] for x in trainset])
    y = np.array([x for x in targetset])
    clf = svm.SVC(kernel="rbf", C=10, gamma=0.0001, tol = 0.001)
    clf.fit(X, y)
    testset = np.genfromtxt(open('test_x','r'), delimiter=' ')
    X_test = np.array([x[0:64] for x in testset])
    for row in X_test:
        print '%d' % clf.predict(row)[0]


if __name__ == '__main__':
    train()




