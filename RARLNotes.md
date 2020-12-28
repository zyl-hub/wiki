# [Back to Index](~/wiki/index.md)

# What I need to do to make a RARL demo

- [ ] Adversarial agents for modeling disturbances

- [ ] adversary with super-powers

# Outline of the paper

## MDP game settings

MDP game $(S;A1;A2;P; r; γ; s0)$

represent step as $(s_t, a_{t}^1, a_{t}^2, r_{t}^1, r_{t}^2, s_{t + 1})$

reward function

$R^{1}=E_{80 \sim \rho, a^{1} \sim \mu(s), a^{2} \sim \nu(s)}\left[\sum_{t=0}^{T-1} r^{1}\left(s, a^{1}, a^{2}\right)\right]$

$R^{1 *}=\min_{\nu} \max_{\mu} R^{1}(\mu, \nu)=\max_{\mu} \min_{\nu} R^{1}(\mu, \nu)$

## Other

Adversary learn to sample worst-trajectories for protagonist

parametered by the magnitude fo force available to the adversary

the adversary cannot be too strong(with super power make the target not available) or too weak(traditional).

# overall algorithm

1. Input env, stochastic policies u and v

2. Init theta_u and theta_v for two policy network

3. iteration

Note that a2=-a1
``` python
for i in iteration
    for j in Nu
        si, ai1, ai2, ri1, ri2 = roll(env, ui, vi_prev, nTrajectory)
        update policy u parameter theta_u
    theta_v = theta_v_prev
    for j in Nv
        si, ai1, ai2, ri1, ri2 = roll(env, ui, vi, nTrajectory)
        update policy v parameter theta_v
return theta_u, theta_v
```


