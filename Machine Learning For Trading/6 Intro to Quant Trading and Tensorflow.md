# Agenda
Tensorflow, trading strategies (momentum & pair trading), ML for application for applications for trading
pait trading: hedgs out market risks
momentum: predictions ot persistence or reversal

open source library for algo definition and back-testing
algo immediately used in finance + GCP
ML algo, neural networks, deap neural networks, python and tensorflow

# Entries, Exists, Endogenous, Exogenous
common components, no matter how complex
types of entries and exists

algo traing: objective, metrics, pre-planned risk management
being objective upfront

## entry
endogenous entry rule: based purely on the securitiy you trading
exogenous: based on other data sources as well

endo: "buy apple if the volume exceeds the previous day's volume and close lower"
exo: "buy apple if microddoft falls 5%" "buy apple if unemployment rate decreases" "buy apple if profits exceed analyst expectations"

endo: some structure in the data makes sense to predict, extrapolation
exo: based on fundamental, macro, or even other securites, data synthesis. Extra variables will give better prediction, ML!

endo: technical analysis
exo: quantitative trading groups, statistical arb groups, strategists

## exist
1. profit-exist
   "make 25 basis points"
   cover market costs, bid-ask spread, commissions, exchange fees
   meets required return on trading capital
2. stop-loss
   market moves against you, incorrect prediction, "close position if down 150 bps"
3. time-out
   hold position intraday


## stop loss
time outs are optional
stop loss: mandatory! set by trader or risk management, reduce rrisk
expected changes in market conditions, unexpected changes
### static stop loss
based on where you enter the trade
considerr market noise trigger vs. increased risks
tight: a lot of small losses
loose: exposure to large losses
### dynamic stop loss
2.5% below highest realized price (drawback)
"increase the original stop-loss by 50% of the unrealized profit"
4 parameter model: entry, profit-exist, stop-loss, time-out

short at 160, stop-loss at 164.8, profit target 152
154-164, end of the week 154, stop-loss = 154 * (1.03) = 

# Estimator API
Production-ready ML models the easy way
train on large datasets that do not fit in memory
monitor training metrics in tensorboard


tf.estimator, high-level API for production-ready models, wrap all things up
quick model, checkpointing, out-of-memory datasets, train/eval/monitor, distuibuted training, hyper-paramter tuning on ML-Engine, ...

tf.estimator.Estimator.
DNNLinearCombinedClassifier, workhouse of machine learning

# Tensorflow Estimator: Predicting real estate house value
"features": square footage

```python
# transfer data into column
tf.feature_column.
tf.feature_column.numeric_column("sq_footage")
tf.feature_column.categorical_column_with_vocabulary_list("type", ["house", "apt"])

# training, feed in data
def train_input_fn():
    features = {"sq_footage": [1000,     2000,    3000,    1000,  2000,  3000],
                "type":       ["house", "house", "house", "apt", "apt", "apt"]}
    labels =                  [ 500,     1000,    1500,    700,   1300,  1900]
    return features, lables
model.train(train_input_fn, steps = 100)

# prediction
def predict_input_fn():
    features = {"sq_footage" : [1500, 1800],
                "type" :       ["house", "apt"]}
    return features

predictions = model.predict(predict_input_fn)
```

model = tf.estimator.DNNRegressor(featcols, hidden_units[3,2]) 
dense neural networks

train, validation, test, ...

# Tensorflow: Basics
```python
a = tf.constant([5, 3, 8])
b = tf.constant([3, -1, 2])
c = tf.add(a,b)
print(c)
```