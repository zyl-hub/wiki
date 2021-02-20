Algorithm

```
for episode do
	reset start position and target position
	While not terminal do
    state, reward, terminal = ENV.observe
	action = DQN.chooseAction(state)
	ENV.executeAction(action)
	stateNext, reward, terminal = ENV.observe
 	DQN.store(state, action, reward, stateNext)
	DQN.learn
	End while
	End for
```