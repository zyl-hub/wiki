# MDP

$$
 \mathcal{M}=\left\{\mathcal{S}, \mathcal{A}, \mathcal{R}, \mathcal{T}, \rho_{0}, \gamma\right\} 
$$

$\mathcal{S}$ a set of states

$\mathcal{A}$ a set of actions

$\mathcal{R}$ reward function

$\mathcal{T}$ transition dynamics

$\gamma$ discount factor

## model free

Model-free does not require knowledge of transition dynamics requires only sampling from distribution

learn a policy $\pi$ maximizes the expected return from the start distribton

$$
 J=\mathbb{E}_{\mathcal{M}}\left[R_{1}\right] 
$$

## Q-function

the action-value or Q-function

describes the expected return under a policy $\pi$ when taking action $a_t$ from $s_t$

$$
 Q\left(s_{t}, a_{t}\right)=\mathbb{E}_{\mathcal{M}}\left[R_{t} \mid s_{t}, a_{t}\right] 
$$

