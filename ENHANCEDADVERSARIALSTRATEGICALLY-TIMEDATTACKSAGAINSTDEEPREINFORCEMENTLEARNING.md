[[论文索引#ENHANCED ADVERSARIAL STRATEGICALLY-TIMED ATTACKS AGAINST DEEP REINFORCEMENT LEARNING ENHANCEDADVERSARIALSTRATEGICALLY-TIMEDATTACKSAGAINSTDEEPREINFORCEMENTLEARNING md]]

![[Pasted image 20210220211259.png]]

[[MDP#model free]]

# Difficulty

delay, pixel-wise, pulsed-signals from attackers

# main Ideas

# work

robustness analysis when attacked by potential noises incurred from real world scenarios

# outlines

white-box attacks: model parameter

black-box attacks

噪声状态观测的表示为状态加噪声

$$
noisy\_s_{t}=s_{t}+noise(t)
$$

## Noisy Observation from the RealWorld

### Pulsed Zero-out Attacks

脉冲的使得$noisy\_s_{t}=0$的噪音

定期让画面全黑

### Gaussian Average on Sensor Fusion

a noisy sensor fusion system by Gaussian filter

定期使用高斯模糊

$noisy\_s_{t}$

### Adversarial Noise Patterns

fast gradient sign method to generade adversarial patterns against the prediction loss of a well-trained DQN

$$
 \operatorname{noise}(t)=\epsilon \operatorname{sign}\left(\nabla_{x} J(\theta, x, y)\right) 
$$

取出梯度的符号并乘参数作为噪声



## Enhanced White-Box Strategically-Timed Attack by Online Learning

设想的场景为对于开放源码的强化学习算法的攻击

### Weighted-Majority Potential Energy Function

$$
 \begin{aligned} c\left(s_{t}, \mathbf{w}_{t}, a_{t}^{\min }, a_{t}^{\max }\right) &=\frac{\mathbf{w}_{t}^{T} \exp \left(-\mathbf{Q}\left(s_{t}, a_{t}^{\max }\right)\right)}{\sum_{a_{t}^{(k)}} \mathbf{w}_{t}^{T} \exp \left(-\mathbf{Q}\left(s_{t}, a_{t}^{(k)}\right)\right)} \\ &-\frac{\mathbf{w}_{t}^{T} \exp \left(-\mathbf{Q}\left(s_{t}, a_{t}^{\min }\right)\right)}{\sum_{a_{t}^{(k)}} \mathbf{w}_{t}^{T} \exp \left(-\mathbf{Q}\left(s_{t}, a_{t}^{(k)}\right)\right)} \end{aligned} 
$$

$c\left(s_{t}, \mathbf{w}_{t}, a_{t}^{\max }, a_{t}^{\min }\right)$ greater than a pre-specified constant threshold $\beta$ -> attack the states by adding pulses to make the user have random observations

### Black-Box Strategically-Timed Attack by Adversarial Evolutionary Strategy

parameter exploring policy gradients adversarial-strategic agent

这种攻击可以使对抗环境下的算法性能明显下降
