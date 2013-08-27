#returns the training data read from a file in list of list format
#

from decimal import *

def readDataList(fileName):
    data = []
    f = open(fileName)
    for line in f:
        data.append(line.split(","))
    return data


#converts the feature data to binary format
def convertToBin(trainingData):
    for instance in trainingData:
        for i in range(len(instance)):
            if(float(instance[i]) > 0):
                instance[i] = 1
            else:
                instance[i] = 0
    return trainingData

#The function to learn the parameters for naive bayes learning :
#he dataset has 50 attributes, the last one the class.

#Training data is a bit vector

def learnParameters(trainingData):
    #since it is naive bayes, we should learn the parameters for each class, for each feature.
    #this makes 2 * 54 parameters. Since we have assumed a bernoulli distribution for each of the 
    #features, there is just one parameter for each feature.
    #       P(i,class) = (#freq_ith_word)/(#total_words_in_that_class)
    
    parametersClassNonSpam = [0] * 55
    parametersClassSpam = [0] * 55
    totalSpam = total = 0;
    #I use only 55 attributes of the dataset, first 54 and the 58th(class)
    for t in trainingData:
        
        total = total + 1
        if(t[57] == 1):  #class spam?
            totalSpam = totalSpam + 1
            for i in range(55):
                parametersClassSpam[i] = parametersClassSpam[i] + t[i]

        else : #not spam
            for i in range(55):
                parametersClassNonSpam[i] = parametersClassNonSpam[i] + t[i]
    
    totalNonSpam = total - totalSpam

    numClasses = 55
    #begin normalization + laplace smoothing:
    #for laplace smoothing, you add 1 to the numerator, and K to den
    for i in range(55):
        parametersClassSpam[i] = float(parametersClassSpam[i] + 1) / (totalSpam + 2)
        parametersClassNonSpam[i] = float(parametersClassNonSpam[i]+ 1) / (totalNonSpam + 2)

 #   for i in range(55):
  #      print ("%f, %f") % (parametersClassSpam[i], parametersClassNonSpam[i])
    return {'spam':parametersClassSpam, 'nonspam':parametersClassNonSpam, "pspam":float(totalSpam)/total}

def classify(test, nbmodel):
    
    getcontext().prec = 50
    paramsClassS = nbmodel["spam"]
    priorSpam = nbmodel["pspam"]
    paramsClassNS = nbmodel["nonspam"]
    predictSpam = Decimal(priorSpam)
    predictNSpam = Decimal(1 - priorSpam)
    for i in range(len(test)):

        #each word is modelled independent of any other word. Thus, take all the words, and for each, keep multiplying the correct probabilities
        pterm = Decimal((1 - test[i]) * (1 - paramsClassNS[i]) + test[i] * paramsClassNS[i])

        predictNSpam = Decimal(predictNSpam * pterm)

        pterm = Decimal((1 - test[i]) * (1 - paramsClassS[i]) + test[i] * paramsClassS[i])
        predictSpam = Decimal(predictSpam * pterm)

    if(predictSpam >= predictNSpam):
        print "I predict this as spam!"
    else:
        print "Looks clean to me."
def main():
    
    nbmodel = learnParameters(convertToBin(readDataList('nb.txt')))
    test = "0,1,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1"
    classify([int(i) for i in test.split(",")], nbmodel)

if __name__ == "__main__":
    main()


