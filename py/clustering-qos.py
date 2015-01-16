#sg
from sklearn.cluster import KMeans
from numpy.random import RandomState
import numpy as np
import pylab as pl
from matplotlib import pyplot as pl
from itertools import cycle
def plot_2D(data, target, target_names):
    colors = cycle('rgbcmykw')
    target_ids = range(len(target_names))
    pl.figure()
    for i, c, label in zip(target_ids, colors, target_names):
        pl.scatter(data[target == i, 0], data[target == i, 1],
                   c=c, label=label)
    pl.legend()
    pl.show()
    pl.xlabel("Latency")
    pl.ylabel("Drops")

data = np.loadtxt('qos.csv', delimiter = ',')
X = np.array(data[:,:]).reshape(97, 2)
centers = np.zeros(shape=(4, 2))
centers[0] = np.array([0,0])
centers[1] = np.array([80,0.15])
centers[2] = np.array([0,0.15])
centers[3] = np.array([80,0])
kmeans = KMeans(n_clusters=4, init=centers).fit(X)
print kmeans.cluster_centers_
plot_2D(X, kmeans.labels_, ["C", "B", "C", "D"])
