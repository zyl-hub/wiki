# task

机器人握手击掌

# Difficulty

controller design remains very challenging and has been
shown to be a very complex problem

## Reward function

## model free method when higher DoF

# Contribution

## A multi-objective reward function for DRL algorithms

show how to extract parameters from motion

## training method works in combination with DDPG

## Dataset

## adding imitation reward to the policy results in motions that are perceived as more natural

加入模仿奖励可以让机械臂的动作更为自然

# outlines

奖励函数难以设计

reward is based on tracking position and angle references from motion capture data

parametrized reward function为了不同的手部互动而去设计，大多数的参数都是根据捕捉到的动作数据获得，只剩下6个相对容易调节的参数

使用DDPG算法

policy

$$
 a_{t}=\pi\left(s_{t}\right)+\mathcal{N} 
$$

$\mathcal{N}$ is a sample from zero mean Normal distribution

零平均正态分布

Our method is able to learn control policies of hand interactions
using motion capture data of human demonstrations

## Reward function

one reward function for different tasks

consists of two terms

$$
 r\left(s_{t}, a_{t}\right)=r_{F}\left(s_{t}, a_{t}\right)+r_{I}\left(s_{t}, a_{t}\right) 
$$

### $r_{F}\left(s_{t}, a_{t}\right)$ final state reward(correct end configuration)

$$
 r_{F}\left(s_{t}, a_{t}\right)=r_{p}\left(s_{t}\right)+r_{\alpha}\left(s_{t}\right)+r_{c}\left(s_{t}\right)+r_{a}\left(a_{t}\right) 
$$

- $r_{p}\left(s_{t}\right)$ position reward

$$
 r_{p}\left(s_{t}\right)=-\sum_{i=1}^{N_{f}} \omega_{p}^{i} \| p_{g}^{i}-p_{r t}^{i} \mid 
$$

$p_{g}^{i}$ goal position

$p_{r t}^{i}$ current position

- $r_{\alpha}\left(s_{t}\right)$ angle reward

$$
 r_{\alpha}\left(s_{t}\right)=-\sum_{i=1}^{N_{\alpha}} \omega_{\alpha}^{i}\left\|\alpha_{g}^{i}-\alpha_{r t}^{i}\right\| 
$$

$a_{g}^{i}$ goal angle

$a_{r t}^{i}$ current angle

$\omega_{p}^{i}, \omega_{\alpha}^{i}$ determine the importance of the specific goal

- $r_{c}\left(s_{t}\right)$ contact reward

$$
 r_{c}\left(s_{t}\right)=\sum_{i=1}^{N_{c}} \omega_{c}^{i} 1_{c t}^{i} 
$$

function $\mathbb{I}_{c t}^{i}$ outputs 1 when contact sensor is active else 0

$N_c$为传感器的个数

- $r_{a}\left(a_{t}\right)$ penalizes high action input

$$
 r_{a}\left(a_{t}\right)=-\sum_{i=1}^{N_{a}} \omega_{a}^{i}\left\|a^{i}\right\|^{2} 
$$

### $r_{I}\left(s_{t}, a_{t}\right)$ imitation state reward(more natural)

$$
 r_{I}\left(s_{t}, a_{t}\right)=r_{p I}\left(s_{t}\right)+r_{\alpha I}\left(s_{t}\right) 
$$

$$
 r_{p I}\left(s_{t}\right)=-K_{p I} \sum_{i=1}^{N_{f}} \omega_{p}^{i}\left\|p_{g t}^{i}-p_{r}^{i}\right\| 
$$

$$
 r_{\alpha I}\left(s_{t}\right)=-K_{\alpha I} \sum_{i=1}^{N_{\alpha}} \omega_{\alpha}^{i}\left\|\alpha_{g t}^{i}-\alpha_{r}^{i}\right\| 
$$

$$\mathcal{D}=
 \left\{\left(p_{t}^{i}, p_{t}^{j}, \alpha_{t}^{i}, \alpha_{t}^{j}\right)\right\}_{t=1}^{T} 
$$


