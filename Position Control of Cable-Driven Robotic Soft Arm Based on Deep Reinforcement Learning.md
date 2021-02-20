# outline

The purpose of this
paper is to combine data-driven modeling with reinforcement learning

directly learned from experience

## 使用MLP对软体机械臂进行建模

$$
 Q_{t}\left(s_{t}, a_{t}\right)=r_{t}+\alpha\left(r_{t}+\gamma \max _{a} Q_{t+1}\left(s_{t+1}, a\right)-Q_{t}\left(s_{t}, a\right)\right) 
$$

Traditional Q learning uses a table to record value functions

in practice, there are often a large number of states, or even a continuous state space，so the traditional Q learning and deep learning are combined


## simulation

DQN来做action选取，MLP负责返回状态并计算出当前行为的奖励值

## real environment experiment

collect image data by camera input into DQN -> motion

# Idea

## state design

