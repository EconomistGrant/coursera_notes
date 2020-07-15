# Supervised Learning
model, labled examples of what it should learn
labels/correct answers, prediction problem
unsupervised: look at data, how they can seperated into different groups, description problem

predictors: to what we dont know but want to know

## regression and classfication
seaborne python package
row: example with *features* and *label*

regression: predict the tip amount
classification: predict the sex of the customer

lables? supervised or unsupervised
continuous quantity? regression or classification

### regression
mathematical functions of different combinations of features to predict the continuous values of the label
minimize: mean squared error

### classification
linear classfication: decision boundary between different class
non-linear boundary
minimize: cross-entropy (linear penalty but gradually going to exponential)

tips: high, medium low -> classification problem!

## data warehouse
a source of structured data training examples

## Linear Regression: history
1877, computations were done by hand
y = w0x0 + w1x1 + ... = Xw
loss function: mean square error
w = [(X^T X ) ^ (-1)] X^T y
gradient descent, searching for the global minimum
learning rate! step size. Coverge.

## ML: history
40s: preceptron, neural network
inactivation function

inputs (dendites) - weights -> weighted sum - unit step function (compare with threshold, activation?) -> output (axon)

there are simple functions that it cannot learn: XOR

## Lab intro: BigQuery
predict apple price

how to import data from GCS
how to add features
How to build tensorflow model
How to evaluate results
### QWIKLABS

# Forecast
What is Forecasting
Terminology
Choosing the model
BQML

## What is forecasting
(past and present) data -> mathematics in multidimensional spaces -> results

qualitative/quantitative
quant: causal, regression using variables | Time Series, MA, simply past data

a row: instance/observation
feature | lable column

## Model selection
Right Answer? -> Supervised?  --> forecast -> Linear Regression
                              --> Classify --> Binary -> Logistic
                                           --> Multi-Class -> Logistic Multi-class
                              --> Recommend -> Matrix Factorization
Unsupervised -> Clustering

## BQML
takes days to months to create an ML model

BigQuery Ml: easily build machien learning using SQL command
huge data in BQML
adjust hyperparameters

How to import data?
How to add features?
How to build model?
How to evaluate?