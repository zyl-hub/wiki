[[论文索引#Sim-to-Real Reinforcement Learning for Deformable Object Manipulation Sim-to-RealReinforcementLearningforDeformableObjectManipulation md]]

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





