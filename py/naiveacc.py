def naive_accuracy(true, pred):
    number_correct = 0
    i = 0
    for i, y in enumerate(true):
        if pred[i] == y:
            number_correct += 1.0
    return number_correct / len(true)


pred = list([1, 2, 2, 2]); 
test = list([1, 1, 1, 1])

print naive_accuracy(test, pred)
