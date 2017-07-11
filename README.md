Data-Structure(资料/数据结构)
===
### Teaching materials

`FUNDAMENTALS OF DATA STRUCTURES IN C(数据结构基础C语言版)` **Second Edition**

Writen by Ellis Horowitz, Sartaj Sahni, Susan Anderson-Freed
Translated by 朱仲涛 

### Programming Homework Code

+ The factorial function n! has value 1 when n < 1 and value n*(n-1)! when n > 1. Write both a recursive and an iterative C function to compute n!.
**------Example------** 
**Input** : 5
**Output** : Recursive : 120  Iterative : 120
如果输入-1，直接结束程式

![](https://i.imgur.com/GP9JGZw.png)

+ If S is a set of n elements, the power set of S is the set of all possible subsets of S.For example, if S={a,b,c}, then powerset(S)={{},{a},{b},{c},{a,b},{a,c},{b,c},{a,b,c}}.Write a recursive function to compute powerset(S).
**------Example------** 
**Input** : abc
**Output** : {},{a},{b},{c},{a b},{a c},{b c},{a b c}

![](https://i.imgur.com/rTK8UQ1.png)

+ A generalized band matrix D~n,a,b~ is an n*n matrix in which all the nonzero terms lie in a band made up of a-1 diagnals below the main diagnal, the main diagonal, and b-1 bands above the main diagnal.
Obtain a sequential representation of of the band D~n,a,b~ in the one dimensional array e. For this representation, write a C function value(n,a,b,i,j,e) that determines the value of element d~ij~ in the matrix D~n,a,b~ is represented in the array e.
**Attention** : 程式input要求以档案的方式输入
**------Example------**
**Input** : Please input the file name : Sample_input.txt
a:3
b:3
**Output** : 
e[0] = 9  d(2,0)
e[1] = 7  d(3,1)
e[2] = 8  d(1,0)
e[3] = 3  d(2,1)
e[4] = 6  d(3,2)
e[5] = 6  d(0,0)
e[6] = 0  d(1,1)
e[7] = 2  d(2,2)
e[8] = 8  d(3,3)
e[9] = 7  d(0,1)
e[10] = 4  d(1,2)
e[11] = 9  d(2,3)
e[12] = 8  d(0,2)
e[13] = 4  d(1,3)
**Sample_input.txt** : 
4
6 7 8 0
8 0 4 4
9 3 2 9
0 7 6 8

![](https://i.imgur.com/FG1TONV.png)

+ Random walk problem in a room of size n*m. moves are represented by (ibug + imove[k], jbug + jmove[k]), where -1<k<8, and i,jbug represent the initial position.
Write a program to perform the specified simulation experiment. Your program MUST:
1、handle all values of n and m, 2<n<41, 1<m<21;
2、perform the experiment for (1)n=15,m=15,starting point(10,10), and (2)n=39,m=19,starting point(1,1);
3、have an iteration limit, that is , a maximum number of squares that the bug may enter during the experiment. This ensures that your program will terminate. A maximum of 50,000 is appropriate for this exercise.
**------Example------**
**Input** : 能任意输入阵列 n * m的值以及inital bug postion
范围限制 2<n<41, 1<m<21
N : 2
M : 2
Initial bug position X : 0
Initial bug position Y : 0
**Output** : 
1、The total number of legal moves that the cockroach makes
2、The final count array
**Attention** : 请以阵列的方式输出到txt档案显示答案，并且阵列必须对齐

![](https://i.imgur.com/dVd4dQV.png)

+ 走迷宫问题 
**Attention** : 0 represents Forbidden and 1 represents Smooth. And the input must be a txt file.S is the start position and D is the terminal.
**------Example------**
**Input** :  
s0010
11010
01011
0110d
**Output** : 
s**10
11*10
01*11
011*d
Total 6 steps

![](https://i.imgur.com/AuFvdzP.png)

+ Implement circular queue and non-circular queue of size 4.
**------Example------**
**Input** :
Insert(1)delete(2): 1
Insert number : 1
**Output** : 
Front = -1, Rear = 0
Queue : [1][][][]

**Circular Queue :**

![](https://i.imgur.com/G5687ga.png)

**Non-circular Queue :**

![](https://i.imgur.com/mhQ2WLR.png)

+ Implement matrix multiplication.
**------Example------**
**Input** :
row = 2, col = 3 for the first matrix
row = 3, col = 2 for the second matrix
the values for the first matrix : 1 2 3 4 5 6
the values for the second matrix : 6 5 4 3 2 1
**Output** :
20 14
56 41

![](https://i.imgur.com/CqcCWl7.png)

+ Implement matrix transpose.
**------Example------**
**Input** : 
1 2 3
4 5 6
7 8 9
**Output** :
1 4 7
2 5 8
3 6 9

![](https://i.imgur.com/auXOyPs.png)

+ Write a C function that changes the priority of an arbitrary element in a max heap. The resulting heap must satisfy the max heap definition. What is the computing time of your function?
**Attention** : Read file as input to build Max Heap Tree.
**Input** : 
(in.txt) 7, 16, 49, 82, 5, 31, 6, 2, 44
**Output** : 
Create Max Heap:
Max Heap:
82
49 31
44 5 16 6
2 7
Change priority?(Y/N) : Y
Choice priority : 16
Change priority to : 38
Max Heap : 
82
49 38
44 5 31 6
2 7
Speed time : 0.00123sec
Change priority?(Y/N) : N
Press any key to continue...

![](https://i.imgur.com/AtZZ0x0.png)

+ Write a C function that deletes an arbitrary element from a max heap(the deleted element may be anywhere in the heap). The resulting heap must satisfy the max heap definition. What is the computing time of your function?
**Attention** : Read file as input to build Max Heap Tree.
**------Example------**
**Input** :
(in.txt) 7, 16, 49, 82, 5, 31, 6, 2, 44
**Output** :
Create Max Heap:
Max Heap:
82
49 31
44 5 16 6
2 7
Delete priority?(Y/N) : Y
Choice element : 31
Max Heap : 
82
49 16
44 5 7 6
2
Speed time : 0.00123sec
Change priority?(Y/N) : N
Press any key to continue...

![](https://i.imgur.com/ONgJAU0.png)

+ Write a C program that allows the user to input an AOE network. The program should calculate and output the early(i) and late(i) times and the degree of criticality for each activity. If the project is not feasible, it should indicate this. If the project is feasible it should print out the critical activities in an appropriate format.
**------Example------**
**Input** :
9
0 6 4 5 0 0 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 0 2 0 0 0
0 0 0 0 0 0 9 7 0
0 0 0 0 0 0 0 4 0
0 0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0 4
0 0 0 0 0 0 0 0 0
**Output** :
activity, early_time(e), late_time(l), slack(l-e)
a~1~, 0, 0, 0
a~2~, 0, 2, 2
a~3~, 0, 3, 3
a~4~, 6, 6, 0
a~5~, 4, 6, 2
a~6~, 5, 8, 3
a~7~, 7, 7, 0
a~8~, 7, 7, 0
a~9~, 7, 10, 3
a~10~, 16, 16, 0
a~11~, 14, 14, 0

![](https://i.imgur.com/00eoAlx.png)

### Keywords

###### Tags: `Iterative` `Recursive` `Set` `Band-Matrix` `Random Walk` `Stack` `Queue` `Transpose` `Graph` `Tree` `Heap` `AOE Network`
