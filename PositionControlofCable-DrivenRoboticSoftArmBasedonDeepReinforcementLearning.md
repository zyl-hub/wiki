[[论文索引#Position Control of Cable-Driven Robotic Soft Arm Based on Deep Reinforcement Learning PositionControlofCable-DrivenRoboticSoftArmBasedonDeepReinforcementLearning md]]

![[Pasted image 20210220211758.png]]

# outline

The purpose of this
paper is to combine data-driven modeling with reinforcement learning

directly learned from experience

## The soft manipulator is modeled using MLP

$$
 Q_{t}\left(s_{t}, a_{t}\right)=r_{t}+\alpha\left(r_{t}+\gamma \max _{a} Q_{t+1}\left(s_{t+1}, a\right)-Q_{t}\left(s_{t}, a\right)\right) 
$$

Traditional Q learning uses a table to record value functions

in practice, there are often a large number of states, or even a continuous state space，so the traditional Q learning and deep learning are combined


## simulation

The DQN does the action selection, and the MLP returns the status and calculates the reward value for the current action

## real environment experiment

collect image data by camera input into DQN -> motion

# Idea

## state design

The location of several control points is used to stand for the model

## reward design

![[Pasted image 20210220134306.png]]

Use distance to judge the reward