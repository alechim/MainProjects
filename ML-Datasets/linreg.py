# Alec Him
# NSHE ID: 2001543593
# CS 422 - 1001
# Assignment 5 - OLS Solution

# Two Linear Regression Algorithms
# Regression Problem
# - Housing Market
#   > Continuous real-valued input and output
#     - Input: 
#       > Area
#       > Bedrooms
#       > Bathrooms
#       > Stories
#     - Output: 
#       > Estimated Pricing

# How to implement the OLS Solution
#   > 1. Append 1's as the first column, which will represent x(0)
#     - x(0) = 1 for every data instance
#     - x(1)-x(5) are the input features
#     - y : output
#   > 2. Split the dataset into train and test data (80% + 20%)
#   > 3. Split both the training and test data into input and output
#     - Do the same thing w/ the test data
#     (*) OLS solution for the optimal parameters (w)
#       > cap_w = (x_train^T * x_train)^-1 * x_train^T * y_train
#       > w : will give the intercept(bias) and the other 5 parameters: w(0), w(1), w(2), w(3), w(4), w(5)
#       * : To transpose a matrix, use: numpy.matrix.transpose()
#       * : To inverse a matrix use: numpy.linalg.inv()
#       * : Do not implement transpose and/or inverse from scratch
#       (*) : To multiply matricies use numpy.matmul()
#       (*) : To predict the outputs of training data using the OLS solution:
#         - cap_y_train = x_train * cap_w
#       (*) : To predict the outputs of test data using the OLS solution:
#         - cap_y_test = x_test * cap_w
#       (*) : To compute the metrics, use from scikit-learn:
#         - MSE: metrics.mean_squared_error()
#         - MAE: metrics.mean_absolute_error()
#         - R^2: metrics.r2_score()
#       (*) : For SGDRegressor(), do not append ls to your dataset

# Libraries
import numpy as np
import csv
import os
from sklearn.model_selection import train_test_split
from sklearn.linear_model import SGDRegressor
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score

# Copied from Assignment 3 & 4 in case of error of locating file
file = os.path.join(os.path.dirname(os.path.abspath(__file__)), "Housing.csv")

# Store data from csvfile dataset in array
data = []
# Choose which specific columns that are going to be used as inputs and output
spec_columns = ['area', 'bedrooms', 'bathrooms', 'stories', 'price']
# Open file path to "Housing.csv" and reads the data contained
with open(file, 'r') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        spec_row = [row[key] for key in spec_columns]
        data.append(spec_row)

# Input: Get the columns except for price for inputs
# - [:, :-1] - excludes the last column from the data array
input = np.array(data)[:, :-1]

# Apply standardization to input set
scaler = StandardScaler()
input = scaler.fit_transform(input)

# Typecast input to float to make sure calculations function correctly
input = input.astype(float)

# Output: Get the known prices of housing and store in an array
# - [:, -1] - grabs only the last column from the data array
output = np.array(data)[:, -1]
# Typecast output to float to make sure calculations function correctly
output = output.astype(float)
# Apply log transformation to handle skewness
output = np.log(output)

# =======
# OLS 
# =======

# Append 1's to the front of the input matrix as x(0)
ols_input = np.c_[np.ones(input.shape[0]), input]

# Split the data randomly into an 80% training set and a 20% test set
ols_xTrain, ols_xTest, ols_yTrain, ols_yTest = train_test_split(ols_input, output, test_size = 0.2, random_state = 0)

# cap_w = (x_train^T * x_train)^-1 * x_train^T * y_train
cap_w = np.matmul(np.matmul(np.linalg.inv(np.matmul(np.matrix.transpose(ols_xTrain), ols_xTrain)), np.matrix.transpose(ols_xTrain)), ols_yTrain)

# Make predictions on both training and test data
# cap_y_train = x_train * cap_w
ols_yTrainPredict = np.matmul(ols_xTrain, cap_w)
ols_yTestPredict = np.matmul(ols_xTest, cap_w)

print("<=============>")
print("  OLS Metrics")
print("<=============>")

# Display evaluation metrics for training data
print("---------------")
print(" Training Data -")
print("---------------")
print(" > MSE:          ", mean_squared_error(ols_yTrain, ols_yTrainPredict))
print(" > MAE:          ", mean_absolute_error(ols_yTrain, ols_yTrainPredict))
print(" > R^2:          ", r2_score(ols_yTrain, ols_yTrainPredict))

# Display evaluation metrics for test data
print("---------------")
print(" Test Data -")
print("---------------")
print(" > MSE:          ", mean_squared_error(ols_yTest, ols_yTestPredict))
print(" > MAE:          ", mean_absolute_error(ols_yTest, ols_yTestPredict))
print(" > R^2:          ", r2_score(ols_yTest, ols_yTestPredict))

# Display solution for OLS
print("---------------")
print(" > Solution (w): ", cap_w)

# =======
# SGDRegressor
# =======

# Split the data randomly into an 80% training set and a 20% test set
sgd_xTrain, sgd_xTest, sgd_yTrain, sgd_yTest = train_test_split(input, output, test_size = 0.2, random_state = 0)

# Create a SGDRegressor
regressor = SGDRegressor(max_iter = 545, alpha = 0.01, random_state = 0, penalty = 'l2')

# Train the regressor on training data
regressor.fit(sgd_xTrain, sgd_yTrain)

# Make predictions on the both training and test data
sgd_yTrainPredict = regressor.predict(sgd_xTrain)
sgd_yTestPredict = regressor.predict(sgd_xTest)

print("<=============>")
print("  SGD Metrics")
print("<=============>")

# Display evaluation metrics for training data
print("---------------")
print(" Training Data -")
print("---------------")
print(" > MSE:          ", mean_squared_error(sgd_yTrain, sgd_yTrainPredict))
print(" > MAE:          ", mean_absolute_error(sgd_yTrain, sgd_yTrainPredict))
print(" > R^2:          ", r2_score(sgd_yTrain, sgd_yTrainPredict))

# Display evaluation metrics for test data
print("---------------")
print(" Test Data -")
print("---------------")
print(" > MSE:          ", mean_squared_error(sgd_yTest, sgd_yTestPredict))
print(" > MAE:          ", mean_absolute_error(sgd_yTest, sgd_yTestPredict))
print(" > R^2:          ", r2_score(sgd_yTest, sgd_yTestPredict))

# Display solution for SGD
print("---------------")
print(" > Solution (w): ", np.concatenate((regressor.intercept_.reshape(1,), regressor.coef_)))