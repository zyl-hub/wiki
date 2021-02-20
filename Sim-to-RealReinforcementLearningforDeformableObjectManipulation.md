[[论文索引#Sim-to-Real Reinforcement Learning for Deformable Object Manipulation Sim-to-RealReinforcementLearningforDeformableObjectManipulation md]]

![[Pasted image 20210220211838.png]]

deformable

the large object configuration spaces

the difficulty of accurate object behaviour modelling

the large change in the configuration resulting from manipulation attempts

end-to-end manner, mapping observations directly to actions bypassing explict modelling

# DDPG extension used

## Prioritised Replay

Prioritised replay assigns a priority pi to each transition

## N-Step returns

Loss function changed

$$
 L_{n s t e p}=\left(Q\left(s_{t}, a_{t}\right)-\sum_{i=0}^{N} \gamma^{i} r_{t+i}-\gamma^{N} Q^{*}\left(s_{t+N}, \pi^{*}\left(o_{t+N}\right)\right)\right)^{2} 
$$

It is possible to use both 1-step loss and N-step loss at the same time, in which case the critic loss becomes the sum of the losses weighted by two hyper-parameters nstep and 1step.

## DDPGfD

seeding the training with demonstrations

## Behavioural Cloning

当actor做出的action不如behavioural cloning时直接采用behavioural cloning

## Reset to demonstration

改变起始状态使得任务变得容易些

## TD3

$$
 y=r_{t}+\min _{i=1,2} Q_{i}^{*}\left(s_{t+1}, \pi\left(o_{t+1}\right)+\operatorname{clip}(\mathcal{N}(0, \sigma),-c, c)\right) 
$$

## Asymmetric actor-critic

uses high dimensional (RGB) partial observations as an input to the actor

using low-dimensional environment state (object positions, arm state, etc.) as the input for the critic

ensure the accuracy of critic

# DDPG with all extension

$$
 L_{\text {critic }}(a)=\lambda_{\text {nstep }} L_{\text {nstep }}(a) w_{i}+\lambda_{\text {1step }} L_{1 \text { step }}(a) w_{i}+\lambda_{L 2} L_{\text {reg }}^{Q}\left(\theta^{Q}\right) 
$$
$$
 L_{\text {nstep }}(a)=\left(Q\left(s_{t}, a\right)-\sum_{i=0}^{N} \gamma^{i} r_{t+i}-\gamma^{N} \min _{i=1,2} Q_{i}^{*}\left(s_{t+N}, \pi^{*}\left(o_{t+N}\right)\right)\right)^{2} 
$$
$$
 L_{\text {1step }}(a)=\left(Q\left(s_{t}, a\right)-r_{t}-\min _{i=1,2} Q_{i}^{*}\left(s_{t+1}, \pi^{*}\left(o_{t+1}\right)\right)\right)^{2} 
$$



