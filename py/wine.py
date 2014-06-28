from sklearn.linear_model import LinearRegression
import pandas as pd
import matplotlib.pylab as plt
from sklearn import grid_search, preprocessing, decomposition
from sklearn.cross_validation import train_test_split

def decomposition_pca(train, test):
    """ Linear dimensionality reduction """
    pca = decomposition.PCA(n_components=10, whiten=True)
    train_pca = pca.fit_transform(train)
    test_pca = pca.transform(test)
    return train_pca, test_pca

df = pd.read_csv('/home/aman/winequality-red.csv', sep=';')
X = df[list(df.columns)[:-1]]
y = df['quality']
X_train, X_test, y_train, y_test = train_test_split(X, y)

X_train, X_test = decomposition_pca(X_train, X_test)
regressor = LinearRegression()
regressor.fit(X_train, y_train)
y_predictions = regressor.predict(X_test)
print 'R-squared:', regressor.score(X_test, y_test)



