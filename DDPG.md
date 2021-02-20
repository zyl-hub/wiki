# DDPG

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
- batch normalization
- target networks
