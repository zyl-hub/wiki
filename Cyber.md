# 主要组成

## 1. 控制计算前方曲率半径的点位

``` c++
startPoint = _speed * 0.445;
```

因为这里会让算曲率半径的点位位置过于靠前

## 2. 计算想要的速度

``` c++
if (c.r<=60)
{
		expectedSpeed = constrain(200,200,c.r*c.r*(-0.046)+c.r*5.3-59.66);
}
else
{
		expectedSpeed = constrain(160,170,c.r*1.4);
}
```

constrain(low,high,input)能够把input限制在low和high之间，函数的input部分需要改进，初步想法是与速度和角度相关联

## 3. 转向的控制

``` c++
if (curSpeedErr > 0)
{
			
		if (abs(*cmdSteer)<0.6)
		{
			*cmdAcc = constrain(0.0,1.0,kp_s * curSpeedErr + ki_s * speedErrSum + offset);
			*cmdBrake = 0;
		}
		else if (abs(*cmdSteer)>0.70)
		{
			*cmdAcc = 0.005 + offset;
			*cmdBrake = 0;
		}
		else
		{
			*cmdAcc = 0.11 + offset;
			*cmdBrake = 0;
		}
}
else if (curSpeedErr < 0)
{
		*cmdBrake = constrain(0.0,0.8,-kp_s *curSpeedErr/5 - offset/3);
		*cmdAcc = 0;
}
```

## 工具函数

`constrain(low, high, input)`限制input在low和high之间

`atan2()`计算求y/x（弧度表示）的arctan值

