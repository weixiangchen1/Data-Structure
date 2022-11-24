
@[TOC](文章目录)
#  堆的概念及结构
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;如果有一个关键码的集合K = { k0，k1 ，k2 ，…，kn-1 }，把它的所有元素按完全二叉树的顺序存储方式存储在一个一维数组中，并满足：ki <= k2*i+1且ki <= k2i+2(ki >= k2i+1且 ki >= k2i+2) i = 0，1，2…，则称为小堆(或大堆)。将根节点最大的堆叫做最大堆或大根堆，根节点最小的堆叫做最小堆或小根堆。

堆的性质：
+ 堆中的某个节点的值总是不大于或者不小于其父节点的值；
+ 堆总是一棵完全二叉树。
![在这里插入图片描述](https://img-blog.csdnimg.cn/cc8060fcafee49ada769ee7ae287acdb.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
# 堆的实现
## 堆向下调整算法
现在我们给出一个数组，逻辑上看做一颗完全二叉树。我们通过从根节点开始的向下调整算法可以把它调整成一个小堆。向下调整算法有一个前提：左右子树必须是一个堆，才能调整。

```
int array[] = {27, 15, 19, 18, 28, 34, 65, 49, 25, 37};
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/0547f4b8c841400b8be7a658f8abe7b0.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
## 堆的创建
下面我们给出一个数组，这个数组逻辑上可以看做一颗完全二叉树，但是还不是一个堆，现在我们通过算法，把它构建成一个堆。根节点左右子树不是堆，我们怎么调整呢？
**从倒数的第一个非叶子节点的子树开始调整，一直调整到根节点的树，就可以调整成堆。**

```
int a[] = {1, 5, 3, 8, 7, 6};
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/bf53e2e24e8c4dc18c5c4495b33c867e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
## 建堆时间复杂度
因为堆是完全二叉树，而满二叉树也是完全二叉树，此处为了简化使用满二叉树来证明(时间复杂度本来看的就是近似值，多几个节点不影响最终结果)：
![在这里插入图片描述](https://img-blog.csdnimg.cn/bceb5d857f3146e0a05adba8b8539a1c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
##  堆的插入
先将要插入的数插到尾上，再用向上调整算法，直到满足堆的性质。
![在这里插入图片描述](https://img-blog.csdnimg.cn/8d686afd43834034be14481689051537.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
## 堆的删除
堆的删除就是删除堆顶的数据，先将堆顶的数据和堆尾的数据交换，删除堆尾也就是原来堆顶的数据，再将堆顶向下调整。
![在这里插入图片描述](https://img-blog.csdnimg.cn/93e443565b784daba22528dc9a8e9d4e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
## 堆的代码实现

```c
typedef int HPDataType;
typedef struct Heap
{
	int* a;
	int size;
	int capacity;
}Heap;
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->size = hp->capacity = 0;
}


void AdjustUp(int*a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			HPDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(int* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)// 左孩子存在则继续循环
	{
		if (child + 1 < n &&  a[child + 1] > a[child])
		{
			++child;
		}// 比较左孩子和右孩子

		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	return hp->a[0];
}

bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}

int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = realloc(hp->a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newCapacity;
	}

	hp->a[hp->size] = x;
	hp->size++;

	AdjustUp(hp->a, hp->size - 1);
}

void HeapPop(Heap* hp)// 最后一个元素和第一个元素交换，第一个元素向下调整
{
	assert(hp);
	assert(!HeapEmpty(hp));

	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}
```
## 堆排序
堆排序利用堆的思想进行排序，总共分成两个步骤：

 1、**建堆**
+ 升序：建大堆（每个根节点都大于等于孩子节点）
+ 降序：建小堆（每个根节点都小于等于孩子节点）


2、**利用堆删除思想来进行排序**
建堆和堆删除中都用到了向下调整，因此掌握了向下调整，就可以完成堆排序。
![在这里插入图片描述](https://img-blog.csdnimg.cn/be699e1b275a4ecdac7d6f1aaf474234.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)

```c
void HeapSort(int* a, int n)
{
	assert(a);
	//先将完全二叉树建成堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//利用堆删除的思想进行排序
	for (int i = n - 1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
	
}
```
<br>

# Topk问题
**TOP-K问题：即求数据结合中前K个最大的元素或者最小的元素，一般情况下数据量都比较大。**
比如：专业前10名、世界500强、富豪榜、游戏中前100的活跃玩家等。

那么该如何解决Topk问题呢？

**思路1**：

排降序，前k个数据就是最大的数据。时间复杂度O(N*logN)。

**思路二**

将所有数插入大堆，然后再HeapPop K次，每次取堆顶的数据。
时间复杂度O(N + K*logN)。

**思路三**

1.先用前k个数建成k个数的小堆。
2.剩下n-k个数，依次跟堆顶的数据进行比较，如果比堆顶的数据大，就进堆进行向下调整。
3.最后堆里的k个数就是最大的k个数。
时间复杂度O(K + (N-K)*logK) ≈ O(N*logK)。

```c
void PrintTopK(int* a, int n, int k)
{
	assert(a);
	Heap hp;
	HeapInit(&hp);
	// 1. 建堆--用a中前k个元素建堆
	for (int i = 0; i < k; ++i)
	{
		HeapPush(&hp, a[i]);
	}
	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	for (int i = k; i < n; i++)
	{
		if (a[i] > hp.a[0])
		{
			hp.a[0] = a[i];
			AdjustDown(hp.a, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", hp.a[i]);
	}
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}

```

