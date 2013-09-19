#sg


def hypothesis(theta, x):
    return x * x * theta[2] + x * theta[1] + theta[0];

def hypothesis1(theta, x):
    return  x * theta[1] + theta[0];
    
#Gradient of the cost function with respect to the 0th dimension
def gradient0(currTheta, features, y):
    
    m = len(features)
    temp = 0
    for i in range(0, m):
        temp = temp + (hypothesis(currTheta, features[i]) - y[i]);
    return (float(temp) / m)


#cost function

def cost(theta, features, y):
    temp = float(0)
    m = len(features)
    for i in range(0, len(features)):
        error = hypothesis(theta, features[i]) - y[i]
        temp = temp + error * error;

    temp = float(temp) / (2 * m)
    return temp


#Gradient of the cost function with respect to the 1st dimension
def gradient1(currTheta, features, y):
    
    m = len(features)
    temp = 0
    for i in range(0, m):
        temp = temp + (hypothesis(currTheta, features[i]) - y[i]) * features[i];

        
    return (float(temp) / m)

#Gradient of the cost function with respect to the 3rd dimension
def gradient2(currTheta, features, y):
    
    m = len(features)
    temp = 0
    for i in range(0, m):
        temp = temp + (hypothesis(currTheta, features[i]) - y[i]) * features[i] * features[i];

        
    return (float(temp) / m)


def readData(fileName):
    
    f = open(fileName, "r")
    y = []
    features = []

    for i in f:
        vals = i.strip('\n').split(',')
        features.append(float(vals[0]))
        y.append(float(vals[1]))
    
    return {'y':y, 'features':features}

def main():

    data = readData("trainingdata.txt")
    y = data['y']
    features = data['features']

    m = len(features)

    #new and old theta values. Another pair is used while 
    #iterating to ensure simulataneous updates
    theta2_c = .001
    theta1_c = 1
    theta0_c = 1

    #The much celebrated step size
    alpha = .01
    
    #condition to stop the gradient descent
    gradThreshold = .0006

    #the gradients
    grad2 = 1
    grad1 = 1
    grad0 = 1

    #iteration count
    iterCount = 0


    theta = [theta0_c, theta1_c, theta2_c]
    while(abs(grad2) > gradThreshold or abs(grad1) > gradThreshold or abs(grad0) > gradThreshold):


        grad2 = gradient2(theta, features, y)
        grad1 = gradient1(theta, features, y)
        grad0 = gradient0(theta, features, y)

        #because we want to do simultaneous update, we must not update before 
        #both the theta values are calculated

        theta[2] = theta[2] - alpha * grad1
        theta[1] = theta[1] - alpha * grad1
        theta[0] = theta[0] - alpha * grad0

        #theta1_c = theta1_c_s
        #theta0_c = theta0_c_s

        iterCount = iterCount + 1
        print "%d) %f Grads : %f %f %f" % (iterCount, cost(theta, features, y), theta[2], theta[1], theta[1])
        raw_input("next>")


    print "T[0] = %f, T[1] = %f, T[2] = %f" %(theta[0], theta[1], theta[2])
    #import sys
    #data = sys.stdin.readlines()
    #for line in data:
    #    l = float(line)
    #    prediction =  theta[2] * l * l  + theta[1] * l + theta[0]
    #    print prediction
    #for line in sys.stdin:
    #    print "hi" , 
if __name__ == "__main__":
    main()



