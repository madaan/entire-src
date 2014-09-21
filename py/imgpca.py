import numpy as np
import mahotas as mh
from sklearn.cross_validation import train_test_split
from sklearn.metrics import classification_report
from sklearn.decomposition import PCA
from sklearn.linear_model import LogisticRegression
from os import walk
from sklearn.preprocessing import scale
import os
X = []
y = []
for dir_path, dir_names, file_names in walk('att-faces/orl_faces'):
    for fn in file_names:
        if fn[-3:] == 'pgm':
            image_filename = os.path.join(dir_path, fn)
            X.append(scale(mh.imread(image_filename, as_grey=True).reshape(10304).astype('float32')))
            y.append(dir_path)

X = np.array(X)
X_train, X_test, y_train, y_test = train_test_split(X, y)
pca = PCA(n_components=150)
X_train_reduced = pca.fit_transform(X_train)
X_test_reduced = pca.transform(X_test)
print 'The original dimensions of the training data were', X_train.shape
print 'The reduced dimensions of the training data are', X_train_reduced.shape
classifier = LogisticRegression()
classifier.fit_transform(X_train_reduced, y_train)
print 'Accuracy', classifier.score(X_test_reduced, y_test)
predictions = classifier.predict(X_test_reduced)
print classification_report(y_test, predictions)
