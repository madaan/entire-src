#sg
'''
Gaussian process regeression
'''
import numpy as np
from sklearn.gaussian_process import GaussianProcess
from matplotlib import pyplot as pl
data = np.loadtxt('data', delimiter = '\t')
X = np.array(data[:,0]).reshape(30, 1)
y = np.array(data[:,1]).reshape(30, 1)
print X
print X.shape, y.shape
# Mesh the input space for evaluations of the real function, the prediction and
# its MSE
x = np.atleast_2d(np.linspace(15, 50, 100)).T

gp = GaussianProcess(corr='squared_exponential', theta0=1e-1,
                     thetaL=1e-3, thetaU=1, random_start=100)

# Fit to data using Maximum Likelihood Estimation of the parameters
gp.fit(X, y)

# Make the prediction on the meshed x-axis (ask for MSE as well)
y_pred, MSE = gp.predict(x, eval_MSE=True)
sigma = np.sqrt(MSE)

# Plot the function, the prediction and the 95% confidence interval based on
# the MSE
fig = pl.figure()
pl.plot(X, y, 'g:', label=u'$ True Values $')
pl.plot(x, y_pred, 'b-', label=u'Prediction')
pl.fill(np.concatenate([x, x[::-1]]),
        np.concatenate([y_pred - 1.9600 * sigma,
                       (y_pred + 1.9600 * sigma)[::-1]]),
        alpha=.5, fc='b', ec='None', label='95% confidence interval')
pl.xlabel('$Gain$')
pl.ylabel('$Amplitude$')
pl.ylim(-10, 20)
pl.legend(loc='upper left')
pl.show()

X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3, random_state = 0)
m
