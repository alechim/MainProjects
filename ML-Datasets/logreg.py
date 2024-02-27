# Alec Him
# NSHE ID: 2001543593
# CS 422 - 1001
# Assignment 4 - Logistic Regression

# Libraries
import numpy as np
import csv
import os
import re
from sklearn.model_selection import train_test_split
from sklearn.linear_model import SGDClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, recall_score, f1_score, log_loss

# Imported from Assignment 3
# Needed to find where emails.csv would be located
file = os.path.join(os.path.dirname(os.path.abspath(__file__)), "emails.csv")

# Store data from csvfile dataset in array
data = []
# Open file path to "emails.csv" and reads the data contained
with open(file, 'r') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        data.append(row)

# Data Preprocesing
# - Input 1: Detection of Keywords
#   > Some of the keywords used to detect spam
keywords = ["free", "win", "promotion", "urgent", "discount", "remove"]
#   > Double for loop: lowercases the data to detect keywords and gets the amount of keywords
keywordCount = np.array([sum(element['text'].lower().count(keyword) for keyword in keywords) for element in data])

# Input 2: Length of Email
lengthCount = np.array([len(element['text']) for element in data])

# Input 3: Detection and Count of URLs in Email
urlRE = r'https?://\S+|www\.\S+'
urlCount = np.array([len(re.findall(urlRE, element['text'])) for element in data])

# Output: Get the known Emails labeled with either spam or not spam 
output = np.array([int(element['spam']) for element in data])

# Input: Combines and stores input features into an array
 # - Transposed to swap features and samples of input
input = np.array((keywordCount, lengthCount, urlCount)).T

# Split the data randomly into an 80% training set and a 20% test set
xTrain, xTest, yTrain, yTest = train_test_split(input, output, test_size = 0.2, random_state = 0)

# Changed in Assignment 4
# Create a Logistic Regression Classifier
classifier = SGDClassifier(loss='log_loss', penalty='l2', max_iter=5695)

# Train the classifier on the training data
classifier.fit(xTrain, yTrain)

# Make predictions on the both training and test data
yTrainPredict = classifier.predict(xTrain)
yTestPredict = classifier.predict(xTest)

# Display evaluation metrics for training data
print("---------------")
print(" Training Data -")
print("---------------")
print(" > Accuracy:    ", accuracy_score(yTrain, yTrainPredict))
# recall_score calculates the Sensitivity of the Training Data
print(" > Sensitivity: ", recall_score(yTrain, yTrainPredict))
# Specificity Calculations
# - Uses ravel to unpack the matrix data for TN, FP, FN, and TP
trainTN, trainFP, trainFN, trainTP = confusion_matrix(yTrain, yTrainPredict).ravel()
print(" > Specificity: ", (trainTN / (trainTN + trainFP)))
print(" > F1 Score:    ", f1_score(yTrain, yTrainPredict))
print(" > Log Loss:    ", log_loss(yTrain, yTrainPredict))

# Display evaluation metrics for test data
print("---------------")
print(" Test Data -")
print("---------------")
print(" > Accuracy:    ", accuracy_score(yTest, yTestPredict))
print(" > Sensitivity: ", recall_score(yTest, yTestPredict))
testTN, testFP, testFN, testTP = confusion_matrix(yTest, yTestPredict).ravel()
print(" > Specificity: ", (testTN / (testTN + testFP)))
print(" > F1 Score:    ", f1_score(yTest, yTestPredict))
print(" > Log Loss:    ", log_loss(yTest, yTestPredict))

# Added for Assignment 4
# Display Model Parameters
print("---------------")
print(" Model Parameters -")
print("---------------")
print(" > Parameters:           ", classifier.coef_)
print(" > Bias:                 ", classifier.intercept_)
print(" > Number of Iterations: ", classifier.n_iter_)
# Combine Parameters and Bias to get Solution
print(" > Solution (w):         ", np.concatenate((classifier.intercept_, classifier.coef_[0])))