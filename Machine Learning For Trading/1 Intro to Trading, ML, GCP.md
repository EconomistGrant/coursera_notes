# Intro to Trading
## Trading vs Investing
buy side: investing/advising, asset managers, PE, MF, insurance, HF,...
sell siede: bank/brokers dealers, sell investment to the buy side, market-making

Portfolio Mangers: strategic allocation of assets (into different categories), somewhat short term tactical allocation(choose asset)
HF: positive return independently, hedge risks, absolute alpha.
Portfolio manager, portfolio reblancing

Traders: market behavior, inefficiencies, no fundamental

Buy-side quant methods: prediction models, regression, arbitrage, ML
Sell-side quant methods: execution strategies, reduce the market impact cost of large orders, capture spreads

## Quant Universe
Quant Trading
Algorithmic Trading: a type of quant trading, pre-specified machine executable instructions to determine size/timing of trades
High Frequency Trading: subset of algo trading, rapid execution, millisecond, liquidity, latency

## Strategies:
set of rules, minimal intervention 
forecast: value of a instrument or a spread(Mean Reversion)

Correlation: returns from two price series are related
Cointegration: difference between the means of two price series is stationary

Momemtum chasing vs Mean Reversion
momentum: both underreation and overreaction, extra return for taking risk

HF trading: platform, behaviours, micro infrastructures, game theory models

example: investment fund wants to purchase, stealth execution to mask was not perfect, other players detect, jump ahead
spoofing "fake" orders

## Ad & DisAd
takes the emotion out. Rules and execute.
Unamiguous path
Mathematically optimal

risky, blow up all the time, computer gliche
competitive, market is about 80% already
optimal for assumptions only
No guarantee of profit with risk there
market change, regimes, correlations, volatility

## Arbitrage
basis for all strategies
### Exchange arbitrage
different price of same product. Riskless.
If bid > ask...time window, HF
### Statistical arbitrage
carry arbitrage (pay in spot market and short for future, while the carry cost is lower than spread)
Stat Arb: Mean Reversion. Buy more or lock in loss?
Pairs Trading: buy A short B. Tends to move together, exposure is limited. Fairy risky to pair stocks! consider bonds.
### Index arbitrage
ETF, mirror SP 500, Nasdaq 100
$5 trillion assets
index components, weight, compare with ETF offer, arbitrage

## Stat Arb opportunities and challenges
unbelievable number of instruments/pairs
challenges: trading clearing and exchange fees, risk-based charges, short sale assets, paying for liquidity (sell at bid, buy at ask? 50% of the spread)
need for real-time data, order book, tick by tick, expensive
liquidity: how much transaction made? bid-ask spread?
timeframe: external influences, affect correlations

when you trade a spread, you also change its market: 
price and liquidity change in response to your trade
competitors notice your pattern

## Backtesting
split-data backtesing model
sliding-window backtesting model
weaknesses/biases that can affect

Training data -> testing data -> paper trade

simulatiion designed to measure the performance of your trading and risk management

### sliding window
whole data -> adjoining pairs od training/testing windows

---|training window|testing window|-------  ->keep sliding
use more data (almost all) to both train and test
### construction
filter out strategies dont meet your performance criteria, Sharpe ratio, Sortino
### traps
correlations vary/reverse given enough time
low-quality data
slippage: last ask/bid and your actual buy/sell

overfitting bias
future data bias
survivorship bias: you don't include companies that go out of the market/merged
drawdown tolerance bias: 
if you have a long term strategy, it is upward-trending, good sharpe, but drastic drawdown happens within 3 months maybe
momemtum stragies. Actually your funder will end your investment

### backtesters 
development backtesters: preliminary models, quick test, inflated performance
implmentation backtesters: simulate all environment
data interface with historic/live data; quant strategy to generate signal; portfolio managers that creates orders, keep track; order execution handler

bid: 竞标价，买家愿意出的最高价
ask: 卖家愿意出的最低价

realistically, expect to sell at bid

## Intro to AI and ML
AI is a discipline, physics
ML ls a specific way of solving AI problems, Newton's laws of mechanics

ML development
deep learning: so popular
- incorporate many improvements brought by earlier methods like decision trees and random forests

optimize models using loss functions/performance metrics

mitigate problems that arise in machine learning, like loss of generalization, overfitting

create repeatable train/test datasets

