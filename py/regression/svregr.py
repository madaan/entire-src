#sg
import numpy as np
from sklearn import linear_model, cross_validation, svm
data = np.loadtxt('data', delimiter = '\t')
lend = len(data)
X = np.array(data[:, 0]).reshape(lend, 1)
y = np.array(data[:, 1]).reshape(lend)
X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3, random_state = 0)
model = svm.SVR(C=1024.0, epsilon=0.5)
model.fit(X_train, y_train)
print("Residual sum of squares: %.2f"
      % np.mean((model.predict(X_test) - y_test) ** 2))



