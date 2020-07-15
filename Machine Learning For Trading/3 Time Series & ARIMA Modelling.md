# Time Series
What is TS?
Concepts, Modelling

## What is TS?
series of data indexed in time order

Stationary: the statistical structure of the series is independent of time
mean/sd dont change over time
Looking at plots, summary statistics, statistical tests(expected stationarity, **augmented Dickey-Fuller test**, p-value)

stationize: removing trends, seasonal effect, cyclical(one-year horizon at least), take differenced data

Why stationarity matters?
1 a model that mean and sd will be used(consistent mean/sd over time)

## AT - Auto Regressive
Aoto Correlation: a corelation of a variable with itself at different time periods
(Regression: Pearson Correlation of two variables)

first series: excluding last five points, X
second series: excluding first five points, Y
5-day autocorrelation, 125-5 pairs
how to choose the value of lag? ACF chart. 7 days: 30%

Auto Regression: no direction.
AR process: a process autoregression occurs

lag scatter plot: Original <-against-> (t-k)
observe dispersion

## MA - Moving Average
predict with past few data points

AT: previous y values as input
MA: previous error terms as input

## ARIMA
参考：https://www.jianshu.com/p/91a931d8d92f
I: integrated
ARIMA(p, d, q)
p: AR, how many prior terms?    ACF test
q: MA, how many prior error terms?
d: how many differences do we need to make data stationary?
we are predicting the DIFFERENCE of data between periods, rather than the data itself

you can also add seasonality, ...

selecting model parameter: context driven
1. plotting residual: do not observe a pattern in residual error terms, stop iterating. (residual在时间序列上不相关，是stationary)
2. Ljung-Box Test

# Regression vs ARIMA
Stationary: mean and sd dont change over time
Regression: Model y ~ x
ARIMA: y ~ previous values of y

## in common: 
require stationarity!
linear. No exponential
Correlation of response & dependent variables: estimation, evaluation

## different:
no natural ordering to the observations in linear regression: not time series / ARIMA: time series, natural ordering
linear regression: two different variables

## parameter selection
1. data. 
   Most difficult. Too much data.
   frequency, columns, ...
   tradeoff between: timeliness and relevance
   training / testing divide
   prediction goal

2. d
   0, working with levels; 1, workinbg with differences
3. p & q
   2 & 3: software do this! 

4. form of ARIMA
   fractional estimation / seasonality

   part art and part science: traditional, oversimplify; complex, may overcomplicate

5. estimation method
   maximum likelihood / moments / non-parametric / simulation...
   defer software, but some art
   try starting with different starting points, might be local minimum...
   
6. the best model
   run multiple form of model with different estimation parameters
   differnet software
   best quality of fit!


## sensitivity of trading strategies
mean-reverting strategy

what is the mean? choose only bull market?
how does it typically deviate from the mean, how long does it take to get back? how long you should hold trade?

high p: market has high memory
low p: past has low impact

model decisions -> parameters -> trading strategies -> trading

## Statsmodel package in python
### step 1: stationary test
```python 
# resample, & difference
df_week = df.resample('w').mean()[['close']]
df_week['weekly_ret'] = np.log(df_week['close']).diff()
udiff = df_week.drop(['close'], axis = 1)

from statsmodels.tsa.stattools import adfuller
# you can try plotting rolling mean/rolling std
rolmean = udiff.rolling(20).mean()
rolstd = udiff.rolling(20).std()

dftest = sm.tsa.adfuller(udiff.weekly_ret, autolag='AIC')
dfoutput = pd.Series(dftest[0:4], index=['Test Statistic', 'p-value', '#Lags Used', 'Number of Observations Used'])
for key, value in dftest[4].items():
    dfoutput['Critical Value ({0})'.format(key)] = value
print(dfoutput)

# p-vallue < 0.05: stationary
```

### step 2: ACF & PACF, choose p
```python
from statsmodels.graphics.tsaplots import plot_acf
fig, ax = plt.subplots(figsize=(12,5))
plot_acf(udiff.values, lags=10, ax=ax)
plt.show()

from statsmodels.graphics.tsaplots import plot_pacf

fig, ax = plt.subplots(figsize=(12,5))
plot_pacf(udiff.values, lags=10, ax=ax)
plt.show()
```

### step 3: ARIMA model
```python
from statsmodels.tsa.arima_model import ARMA
# Notice that you have to use udiff - the differenced data rather than the original data. 
ar1 = ARMA(tuple(udiff.values), (3, 1)).fit()
print(ar1.summary())

plt.figure(figsize = (12,8))
plt.plot(udiff.values, color = 'blue') # original fluctuations

preds = ar1.fittedvalues # prediction
plt.plot(preds, color = 'red')
plt.show()

```

### step 4: forecast of the future
```python
steps = 2
forecast = ar1.forecast(steps = steps)[0]
```