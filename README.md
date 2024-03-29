# CPlusPlus_Algorithm_DemoFiles

## Algorithm Websites   
  * [DSA](https://www.tutorialspoint.com/data_structures_algorithms/index.htm)
  * [BSC ALgorithm Introduction](http://btechsmartclass.com/data_structures/introduction-to-algorithms.html)
  * [LUOGU](https://www.luogu.com.cn/)
  * [Data Structure Visualization - Home](https://www.cs.usfca.edu/~galles/visualization/)
  * [Data Structure Visualization - Data Structures](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html)
  * [Data Structure Visualization - Source Code](https://www.cs.usfca.edu/~galles/visualization/source.html)
  * [Cornel University - arXiv](https://arxiv.org/)
  * [Cornel University - arXiv - Algorithms](https://arxiv.org/list/cs.DS/recent)

## Alliance algorithm
  * [Application of the “Alliance Algorithm” to Energy Constrained Gait Optimization](https://link.springer.com/chapter/10.1007/978-3-642-32060-6_40)

## Ant colony
  * [Multi-robot Task Allocation Based on Ant Colony Algorithm](http://www.jcomputers.us/vol7/jcp0709-10.pdf)

## Coding Stuff
  * [Gray Code](https://en.wikipedia.org/wiki/Gray_code)

## Computational Geometry
  * [Computational Geometry - From theory to practice, From linear objects to curved objects](https://tel.archives-ouvertes.fr/tel-00175997/file/english.pdf)
  * [Computational Geometry](http://www.cs.virginia.edu/~robins/cs6161/slides/Algorithms%20-%20slide%20set%204%20v116%20-%2004%20Computational_Geometry.pdf)
  * [COMPUTATIONAL GEOMETRY INTRODUCTION](https://cw.fel.cvut.cz/b181/_media/courses/cg/lectures/01-intro.pdf)
  * [CGAL](https://www.cgal.org/)
  * [Find center of circle](https://math.stackexchange.com/questions/2308430/find-center-of-a-circle-using-2-points-and-arc)
  * [calculate coodinate of point on circle](https://math.stackexchange.com/questions/332743/calculating-the-coordinates-of-a-point-on-a-circles-circumference-from-the-radiu)
  * [BresenHam栅格算法](https://www.cnblogs.com/zjiaxing/p/5543386.html)
  * [点到线段的最短距离](https://www.cnblogs.com/flyinggod/p/9359534.html)
  * [判断线段相交](https://zhuanlan.zhihu.com/p/37360022)
  * [计算两线段距离](https://www.dazhuanlan.com/ofyang/topics/1090816)
  
## Discrete Search
  * [Discrete Search Problem](https://zhuanlan.zhihu.com/p/89626842)
   
## Dynamic Programming:
  * 动态规划与分治法相似，都是通过组合子问题的解来求解原问题，"programming"指的是一种表格法，并非计算机程序
  * 分治方法将问题划分为互不相交的子问题，递归求解子问题，再将他们的解组合起来，求出原问题的解
  * 而动态规划应用于子问题重叠的情况，利用表格法避免重复求解，常用于最优化问题，分为四步：
    * 刻画一个最优解的结构特征
    * 递归地定义最优解的值
    * 计算最优解的值，通常采用自底向上的方法
    * 利用计算出的信息构造一个最优解
  * 动态规划方法是付出额外的内存空间来节省计算时间，是典型的时空权衡的例子，而时间上的节省可能是非常大的，可能将指数时间的解转换为多项式时间的解
  * 两种实现方法:
    * 带备忘录的自顶向下法(top-down with memoization method)
    * 自底向上法(bottom-up method)
  * 最优子结构
    * 无权最短路径：找到一条由u到v的边数最少的路径，该路径必然是简单路径，该问题具有最有子结构，可以使用动态规划算法求解
    * 无权最长路径：找到一条由u到v的边数最多的路径，该路径需要加上简单路径的要求，该问题是NP问题
  * 重叠子问题
  * 重构最优解
  * 备忘
  * [Dynamic Programming](https://en.wikipedia.org/wiki/Dynamic_programming)
  * [Bellman Equation](https://en.wikipedia.org/wiki/Bellman_equation)
  * [Checker Borad Problem](https://en.wikipedia.org/wiki/Dynamic_programming#Checkerboard)
  * [Egg Dropping Puzzle](https://en.wikipedia.org/wiki/Dynamic_programming#Egg_dropping_puzzle)
  * [Tower of Hanoi Puzzle](https://en.wikipedia.org/wiki/Dynamic_programming#Tower_of_Hanoi_puzzle)
  * [Sequence Alignment](https://en.wikipedia.org/wiki/Dynamic_programming#Sequence_alignment)
  * [A type of balanced 0-1 matrix](https://en.wikipedia.org/wiki/Dynamic_programming#A_type_of_balanced_0%E2%80%931_matrix)
  * [A tutorial on Dynamic Programming](https://mat.gsia.cmu.edu/classes/dynamic/dynamic.html)
  * [Another tutorial on Dynamic Programming](https://web.archive.org/web/20080626183359/http://www.avatar.se/lectures/molbioinfo2001/dynprog/dynamic.html)
  * [A Gentle Introduction toDynamic Programming and the Viterbi Algorithm](https://www.cambridge.org/resources/0521882672/7934_kaeslin_dynpro_new.pdf)
  * [A Simple Introduction to DynamicProgramming in Macroeconomic Models](https://researchspace.auckland.ac.nz/bitstream/handle/2292/190/230.pdf)
  * [Video Lectures](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-introduction-to-algorithms-sma-5503-fall-2005/video-lectures/)
  * [Dynamic Programming: from novice to advanced](https://www.topcoder.com/community/data-science/data-science-tutorials/dynamic-programming-from-novice-to-advanced/)
  * [OR/MS Games: 1. A Neglected Educational Resource](https://pubsonline.informs.org/doi/pdf/10.1287/ited.2.3.86)
  * [OR/MS Games: 2. Towers of Hanoi](https://pubsonline.informs.org/doi/pdf/10.1287/ited.3.1.45)
  * [OR/MS Games: 3. Counterfeit Coin Problem](https://pubsonline.informs.org/doi/pdf/10.1287/ited.3.2.32)
  * [OR/MS Games: 4. The Joy of Egg-Dropping in Braunschweig and Hong Kong](https://pubsonline.informs.org/doi/pdf/10.1287/ited.4.1.48)
  * [扔鸡蛋问题详解](https://blog.csdn.net/joylnwang/article/details/6769160)
  * [8 Queens Problem](https://zhuanlan.zhihu.com/p/99209213)
  
## Interesting Blogs
  * [Implementing strcmp, strlen, and strstr using SSE 4.2 instructions](https://www.strchr.com/strcmp_and_strlen_using_sse_4.2)
  * [Table-driven approach](https://www.strchr.com/table-driven)
  * [recommanded books](https://www.strchr.com/links)
  
## Simulated annealing
  * [Simulated annealing for multi-robot hierarchical task allocation with flexible constraints and objective functions](https://www.semanticscholar.org/paper/Simulated-annealing-for-multi-robot-hierarchical-Mosteo-Montano/07e560f85142bcb35394823675d06e67e346a57f)
  * [MTSP Implementations and solution modeling 1](https://www.bilibili.com/read/cv6934454?from=search)
  * [MTSP Implementations and solution modeling 2](https://www.bilibili.com/read/cv6944280?from=search)
  * [MTSP Implementations and solution modeling 3](https://www.bilibili.com/read/cv6952033)
  * [Simulated Annealing - Solving the Travelling Salesman Problem (TSP)](https://www.codeproject.com/Articles/26758/Simulated-Annealing-Solving-the-Travelling-Salesma)
  * [Travelling Salesman using simulated annealing C++](https://deerishi.github.io/tsp-using-simulated-annealing-c-)

## Sort Algorithm In Place
  * in place: bubble sort, insert sort, selection sort, shell sort, quick sort
  * not in place: merge sort, radix sort, counting sort, heap sort, bucket sort
  
## Sort Algorithms Stability
  * stable: bubble sort, insert sort, merge sort, radix sort, counting sort, bucket sort
  * unstable: selection sort, shell sort, quick sort, heap sort
  
## Special Sort Algorithms O(n)
  * counting sort
  * radix sort
  * bucket sort
    
## TSP Problem
  * [Naive and Dynamic programming](https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/)
  * [动态规划](https://blog.csdn.net/qq_39559641/article/details/101209534)
  * [dynamic programming introduction](https://people.eecs.berkeley.edu/~vazirani/algorithms/chap6.pdf)
  * [Greedy approach?](https://www.geeksforgeeks.org/travelling-salesman-problem-greedy-approach/?ref=rp)
  * [Backtracking](https://www.geeksforgeeks.org/travelling-salesman-problem-implementation-using-backtracking/?ref=lbp)
  
