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