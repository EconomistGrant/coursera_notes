# Deep Learning
non-linear activation function!
NN combine layers of perceptrons, making them more powerful but harder to train

layers, output of a layer as an input

input -> weighted sum -> activation function -> output
tensorflow playground

## activation function
linear: f(x) = x
compress layers into a single layer...

sigmoid: 1/(1+e^{-x}), (0,1), cumulative function of logistic, quantile: inverse of logic
hyperbolic tangent, tanh = 2/(1+e^(-2x)) - 1, (-1, 1)

slope very small, train slowly / saturation: high or low input resulting into asymptote plateaus

ReLU activation function, f(X) = 0 for x < 0
                                 x for x > 0

ELU (exponential linear unit) f(x) = a(e^x - 1) for x<0
                                     x for x > 0
computationally expensive

## History of ML
Support Vector Machines (SVMs), 90s
Random Forests, 00s
DNN, 10s

DNN: 11 million trained parameters...
dropout layers, data augmentation, noise -> better generalization

google production ML systems: informed by lots of past experience with a variety of ML models
Sibyl: recommendation system, linear model
Vizier: parameter tuning
google brain

large amount of data + available computational power + available infrastructure + tasks we care about

# Model Generalization
## Overfitting and Underfitting
more complex model, RMSE = 0, well...
not productionalize

a polynomial with 100 order, a neural network with 100 nodes...
memorize dataset

test on new dataset that it hasn't seen before...

consistent performance on cross validation
How to prevent: split data into training and validation

## Validation and Training Data Splits
Linear Regression or Neural Network?

use the last non-overfit model for prediction
lower loss on the validation set

Cloud ML Engine: Bayesian short search thru hyperparameter space

three parts of data: training, validation, test
since you use validation to stop training.
test: use once and only once, report to your boss

if not good on test: you can't change parameters. You should use new ML model or more data

waste of data: cross-validation/boot-straping, split data several times
trained more, more times

lots of data: held-out test dataset
don't: cross validation

# GCP
batch and streaming data pipelines? 

# Notebooks
self-desciptive, shareable, executable

MarkDown|Code|Output

## AI Platform Notebooks
editable, run in the cloud
machine configuration
version control