#sg
import numpy as np
from sklearn.datasets import load_digits
def features():
    digits = load_digits()
    np.savetxt('train', digits.data, fmt="%d")

def target():
    digits = load_digits()
    np.savetxt('target', digits.target, fmt="%d")

if __name__ == '__main__':
    #features()
    target()
