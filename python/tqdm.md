# usage

``` python
from tqdm import tqdm
objname = tqdm(total=len)
for i in range(len):
    objname.update(1)
objname.close()
```
