# DDPG

noisy policy

$$
 a_{t}=\pi\left(o_{t}\right)+N(0, \sigma) 
$$

estimate Q by minimising the Bellman loss

$$
 L_{\text {critic }}=\left(Q\left(s_{t}, a_{t}\right)-r_{t}-Q^{*}\left(s_{t+1}, \pi^{*}\left(o_{t+1}\right)\right)\right)^{2} 
$$

minimize the loss to update critic parameters $\theta^{Q}$

$$
 L\left(\theta^{Q}\right)=\mathbb{E}_{\mathcal{M}, a_{t}}\left[\left(Q\left(s_{t}, a_{t} ; \theta^{Q}\right)-y_{t}\right)^{2}\right] 
$$
$$
 y_{t}=r\left(s_{t}, a_{t}\right)+\gamma Q\left(s_{t+1}, a_{t+1} ; \theta^{Q}\right) 
$$



compute the gradients update the actor parameters $\theta^{\pi}$

$$
 \nabla_{\theta^{\pi}} J=\mathbb{E}_{\mathcal{M}}\left[\nabla_{\theta^{\pi}} Q\left(s_{t}, a_{t} ; \theta^{Q}\right) \mid s_{t}, a_{t}=\pi\left(s_{t} ; \theta^{\pi}\right)\right] 
$$

apply it to actor neural network


# techniques to stabilize convergence properties

- a replay buffer

Sampling from a replay buffer stabilises training by removing temporal correlations and therefore reduces the changes in the distributions the networks are trying to learn

- batch normalization
- target networks
