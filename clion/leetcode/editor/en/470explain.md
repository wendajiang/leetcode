## 连接
https://blog.csdn.net/chdhust/article/details/10601167

## 等概率随机函数面试题总结

在面试中也常考等概率随机函数的题目，所以很重要，特此整理下，资料全来自网上。

### 1. 几道热身等概率随机函数题\

首先我们来一道最简单的题目作为引子
1、已知有一个随机函数rand_0_and_1_with_p()，它能以概率p产生0，以概率1 - p产生1，只使用该函数，设计一新的随机函数，要求以等概率产生1和0。
我们知道，运行rand_0_and_1_with_p()函数一次，那么P(0) = p, P(1) = 1 - p。那么如果运行两次的话，P(0 and 1) = p(1 - p),P(1 and 0) = p(1 - p)，这样就出现了等概率，所以我们可以如下实现：

```cpp
int rand_0_and_1_with_equal_prob() {
 int tmp1 = rand_0_and_1_with_p();
 int tmp2 = rand_0_and_1_with_p();
 if (tmp1 == 1 && tmp2 == 0) {
  return 1;
 } else if (tmp1 == 0 && tmp2 == 1) {
  return 0;
 } else {
  return -1; 
 }
}
```

注意到，因为题目只是说等概率生成1和0，并没有要求P(1) = 0.5, P(0) = 0.5，所以上述实现是合理的，并且保证了性能，不过实用性不大。那么如果要求该随机函数只能产生0和1，并且等概率呢？其实只要在上述实现中加个循环即可：
```cpp
int rand_0_and_1_with_equal_prob() {
 while (1) {
  int tmp1 = rand_0_and_1_with_p();
  int tmp2 = rand_0_and_1_with_p();
  if (tmp1 == 1 && tmp2 == 0) {
   return 1;
  } else if (tmp1 == 0 && tmp2 == 1) {
   return 0;
  } 
 }
}
```

ok，现在又有新的要求了。
2、已知有一个随机函数rand_0_and_1_with_p()，它能以概率p产生0，以概率1 - p产生1，只使用该函数，设计一新的随机函数，要求以等概率1/n产生1到n之间的随机数。
其实这个问题可以这么想，我们先用rand_0_and_1_with_p()来实现一个以等概率0.5产生1和0的新函数，见上rand_0_and_1_with_equal_prob()。有了这个函数，我们不妨考虑数字i的二进制，它只有0和1组成，那么我们每次生成一个0或者1，生成log2n次就可以以等概率生成数字i了。代码如下：

```cpp
int rand_0_to_n_minus_1_with_equal_prob(int n) {
 int k = 0;
 while (n) {
  k++;
  n >>= 1;
 }
 do {
  int res = 0;
  for (int i = 0; i < k; ++i) {
   res |= rand_0_and_1_with_equal_prob() << i;
  }
 } while (res >= n);
 return res;
}
```



这里有个细节需要注意，就是运行log2n次rand_0_and_1_with_equal_prob()函数，最终产生的数可能比n大，因为有可能是如下这种情况：n = 101b，而最后产生的数字是111b，则应该舍弃这种情况，如代码中所示。
3、给定函数rand5()，它能等概率随机产生1~5之间的数字，要求据此实现rand7()，使得能等概率产生1~7之间的数字。
这个题目个人感觉非常棒，可以从题2中获得一定的灵感，题2中是将n表示成2进制，那是因为已知的随机函数是产生0和1的，对于该题，一直的随机函数是随机产生1~5的，我们可以很容易的将该函数转化成随机产生0~4，然后再将7表示成5进制的数，则1=015, 2=025, 3=035, 4=045, 5=105, 6=115, 7=125。不过这里我们同样是生成所有两位的五进制数，那么最高是445，即24，然后去掉21,22,23,24剩下的21个数0~20模7正好可以等概率生成0~6，然后加1即可。代码如下：


```cpp
int rand7() {
 do {
  int k = 5 * (rand5() - 1) + rand5() - 1;
 } while (k >= 21);
 return (k % 7) + 1;
}
```

注意上面的代码第3行不能直接写成int k = 5 * (rand5() - 1)。
4、假设已知randn()可以等概率的产生0~n-1的值，现在要求设计一个randm要求等概率产生0~m-1的值。
该题可看成是rand5和rand7的扩展，同样的思路：
如果n >= m，则直接取randn()结果的0~m-1即可；
如果n < m，则可以先判断m可以表示成多少位的n进制数，然后再采用类似上面的算法；
代码如下：


```cpp
int randm(int n, int m) {
 int res = 0;
 if (m <= n) {
  do {
   res = randn();
  } while (res >= m); 
  return res;
 }

 int count = 1;
 int tmp = n - 1;
 while (tmp < m) {
  tmp = tmp * n + n - 1;
  count++;
 }
 int times = (tmp / m) * m;

 do {
  res = randn();
  for (int i = 0; i < count; ++i) {
   res = res * n + randn();
  }
 } while (res >= times);

 return res % m;
}
```


可以写简单的程序验证一下结果即可。

5、如何产生如下概率的随机数？0出1次，1出现2次，2出现3次，n-1出现n次？
我们注意到有如下规律：n - 1 = (n - 1) + 0 = (n - 2) + 1 = (n - 3) + 2 = ... = 2 + (n - 3) = 1 + (n - 2) = 0 + (n - 1)
可以发现，满足a + b = n - i的(a, b)数对的个数为n - i + 1个。所以我们得到如下代码：

```cpp
int Rand(int n) {
 while (1) {
  int tmp1 = rand() % n;
  int tmp2 = rand() % n;
  if (tmp1 + tmp2 < n) {
   return tmp1 + tmp2; 
  }  
 }
}
```




### 2.[随机数范围扩展方法总结](http://blog.csdn.net/hackbuteer1/article/details/7486704)

题目： 已知有个rand7()的函数，返回1到7随机自然数，让利用这个rand7()构造rand10() 随机1~10。 分析：要保证rand10()在整数1-10的均匀分布，可以构造一个1-10\*n的均匀分布的随机整数区间（n为任何正整数）。假设x是这个1-10\*n区间上的一个随机整数，那么x%10+1就是均匀分布在1-10区间上的整数。由于(rand7()-1)\*7+rand7()可以构造出均匀分布在1-49的随机数（原因见下面的说明），可以将41～49这样的随机数剔除掉，得到的数1-40仍然是均匀分布在1-40的，这是因为每个数都可以看成一个独立事件。 下面说明为什么(rand7()-1)\*7+rand7()可以构造出均匀分布在1-49的随机数: 首先rand7()-1得到一个离散整数集合{0，1，2，3，4，5，6}，其中每个整数的出现概率都是1/7。那么(rand7()-1)\*7得到一个离散整数集合A={0，7，14，21，28，35，42}，其中每个整数的出现概率也都是1/7。而rand7()得到的集合B={1，2，3，4，5，6，7}中每个整数出现的概率也是1/7。显然集合A和B中任何两个元素组合可以与1-49之间的一个整数一一对应，也就是说1-49之间的任何一个数，可以唯一确定A和B中两个元素的一种组合方式，反过来也成立。由于A和B中元素可以看成是独立事件，根据独立事件的概率公式P(AB)=P(A)P(B)，得到每个组合的概率是1/7\*1/7=1/49。因此(rand7()-1)\*7+rand7()生成的整数均匀分布在1-49之间，每个数的概率都是1/49。 程序： 



```cpp
int rand_10() 
{ 
  int x = 0; 
  do 
  { 
​    x = 7 * (rand7() - 1) + rand7(); 
  }while(x > 40); 
  return x % 10 + 1; 
} 
```


注：由朋友问为什么用while(x>40)而不用while(x>10）呢？原因是如果用while(x>10）则有40/49的概率需要循环while，很有可能死循环了。
问题描述
已知random3()这个随机数产生器生成[1, 3]范围的随机数，请用random3()构造random5()函数，生成[1, 5]的随机数？
问题分析
如何从[1-3]范围的数构造更大范围的数呢？同时满足这个更大范围的数出现概率是相同的，可以想到的运算包括两种：加法和乘法
考虑下面的表达式：
3 * (random3() – 1) + random3();
可以计算得到上述表达式的范围是[1, 9] 而且数的出现概率是相同的，即1/9
下面考虑如何从[1, 9]范围的数生成[1, 5]的数呢？
可以想到的方法就是 rejection sampling 方法，即生成[1, 9]的随机数，如果数的范围不在[1, 5]内，则重新取样
解决方法



```cpp
int random5() 
{ 
  int val = 0; 
  do 
  { 
​    val = 3 * (random3() - 1) + random3(); 
  }while(val > 5); 
  return val; 
} 
```


归纳总结
将这个问题进一步抽象，已知random_m()随机数生成器的范围是[1, m] 求random_n()生成[1, n]范围的函数，m < n && n <= m *m
一般解法：



```cpp
int random_n() 
{ 
  int val = 0; 
  int t;  //t为n的最大倍数，且满足t<m*m 
  do 
  { 
​    val = m * (random_m() - 1) + random_m(); 
  }while(val > t); 
  return val; 
} 
```