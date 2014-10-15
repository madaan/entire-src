#sg
'''
Gaussian process regeression
'''
import numpy as np
from sklearn import cross_validation
from sklearn.gaussian_process import GaussianProcess
from matplotlib import pyplot as pl
data = np.loadtxt('data', delimiter = '\t')
X = np.array(data[:,0]).reshape(30, 1)
y = np.array(data[:,1]).reshape(30, 1)
X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3, random_state = 0)
# Mesh the input space for evaluations of the real function, the prediction and
# its MSE

gp = GaussianProcess(corr='squared_exponential', theta0=1e-1,
                     thetaL=1e-3, thetaU=1, random_start=100)

# Fit to data using Maximum Likelihood Estimation of the parameters
gp.fit(X_train, y_train)

# Make the prediction on the meshed x-axis (ask for MSE as well)
y_pred, MSE = gp.predict(X_test, eval_MSE=True)
print("Residual sum of squares: %.2f"
      % np.mean((y_pred - y_test) ** 2))

