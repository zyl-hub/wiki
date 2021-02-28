[[论文索引#Demonstration-Guided Deep Reinforcement Learning of Control Policies for Dexterous Human-Robot Interaction Demonstration-GuidedDeepReinforcementLearningofControlPoliciesforDexterousHuman-RobotInteraction md]]

![[Pasted image 20210220211709.png]]

# task

Make Robot Handshake High five, shake hands like humans

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

The addition of an imitation reward can make the robotic arm move more naturally

# outlines

Reward functions are hard to design

reward is based on tracking position and angle references from motion capture data

The Parametrized reward function is designed for different hand interactions. Most of the parameters are based on the captured motion data, leaving only six parameters that are relatively easy to adjust

The DDPG algorithm is used

policy

$$
 a_{t}=\pi\left(s_{t}\right)+\mathcal{N} 
$$

$\mathcal{N}$ is a sample from zero mean Normal distribution

zero mean normal distribution

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

use ablation study([[术语#ablation study]]) on reward function to show the influence of the different parts of reward function

## reward parameters

Input: $\mathcal{D}, d_{t}^{i j}, \Delta p_{t}^{i j}$

$t_{\min } \leftarrow \arg \min d_{t}^{i j}, \quad j_{\min } \leftarrow \arg \min d_{t}^{i j}$

$p_{s}^{j_{\min }} \leftarrow$ position of a $j_{\min }$ link in simulation

$R_{\mathrm{c}}^{j_{\min }} \leftarrow$ rotation matrix of a $j_{\min }$ link in simulation

$p_{g}^{i} \leftarrow p_{s}^{j_{\min }}+R_{s}^{j_{\min }} \Delta p_{t_{\min }}^{i j_{\min }}, \quad \alpha_{g}^{i} \leftarrow \alpha_{t_{\min }}^{i}$

$p_{g t}^{i} \leftarrow p_{s}^{j_{\min }}+R_{s}^{j_{\min }} \Delta p_{t}^{i_{j} \min }, \quad \alpha_{g t}^{i} \leftarrow \alpha_{t}^{i}$

return $p_{q}^{i}, \alpha_{q}^{i},\left\{\alpha_{q t}^{i} \mid t=1 . . t_{\min }\right\},\left\{p_{q t}^{i} \mid t=1 . . t_{\min }\right\}$

$d_{t}^{i j}$ distance between rigid bodies

relative position $\Delta p_{t}^{i j}$

$$
 \omega_{p}^{i}=K_{p} \frac{d_{\min }}{d_{t_{\min }}^{i j_{\min }}} 
$$

6 weights in the reward function to set

$$
 \left(K_{p}, K_{\alpha}, K_{c}, K_{a}, K_{p I}, K_{\alpha I}\right) 
$$

