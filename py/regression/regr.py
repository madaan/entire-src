#sg
import numpy as np
from sklearn import linear_model, cross_validation
data = np.loadtxt('data1', delimiter = '\t')
lend = len(data)
X1 = np.array(data[:, 0:2]).reshape(lend, 2)
X = np.hstack((X1, np.ones((X1.shape[0], 1), dtype=X1.dtype)))
y = np.array(data[:, 2]).reshape(lend, 1)
X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3, random_state = 0)
model = linear_model.LinearRegression()
model.fit(X_train, y_train)
print("Residual sum of squares: %.2f"
      % np.mean((model.predict(X_test) - y_test) ** 2))



