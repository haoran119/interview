# 面试总结之MISC(操作系统, 网络, 软件开发, 测试, 工具, 系统设计, MISC)

## 操作系统

* 解释堆和栈的区别。
* 分配在堆的内存与分配在堆栈的内存有什么不同
  * 分配在堆的内存要手动去释放
* [大厂面试爱问的「调度算法」，20 张图一举拿下 (qq.com)](https://mp.weixin.qq.com/s/v49BrZhe5BMWjDJn-5FWRg)
* [我和面试官之间关于操作系统的一场对弈！ (qq.com)](https://mp.weixin.qq.com/s/viTFTqsO1TZZgHk6r26LZg)
* User Level thread v.s. Kernel Level thread
  * [User-level threads and Kernel-level threads](https://www.tutorialspoint.com/user-level-threads-and-kernel-level-threads)
    * The user-level threads are implemented by users and the kernel is not aware of the existence of these threads. It handles them as if they were single-threaded processes. User-level threads are small and much faster than kernel level threads. They are represented by a program counter(PC), stack, registers and a small process control block. Also, there is no kernel involvement in synchronization for user-level threads.
    * Kernel-level threads are handled by the operating system directly and the thread management is done by the kernel. The context information for the process as well as the process threads is all managed by the kernel. Because of this, kernel-level threads are slower than user-level threads.
  * [Implement Threads in User Space - GeeksforGeeks](https://www.geeksforgeeks.org/implement-threads-in-user-space/)
    * In an operating system, there are a number of programs, and both the operating system and the user share the hardware and software resources of the computer system. In order to ensure that an incorrect program doesn’t harm the other programs or the operating system, it distinguishes between the user-defined code and the operating-system code. 
    * The approach is, only the task that is executing on behalf of the operating system is provided with hardware support, known as the kernel mode, while the task executing on behalf of a user application is not, known as a user mode.
      * Kernel mode is a privileged mode, where the process has access to all the resources, such as hardware, kernel data, OS kernel code.
      * The basic difference is that, in kernel mode, the kernel can access the hardware directly, but this is not the case with the user mode. However, when a user application requests a service from the operating system, the system must make a transition from user to kernel mode. 
    * A better way to understand the concept is by looking at the following diagram. 
    * ![image](https://user-images.githubusercontent.com/34557994/205421835-1f77f8bc-2b3d-46a8-8c42-72a0113d2abf.png)
    * A thread is an execution unit, which is part of a process. It shares the process’s resources. It is scheduled by the scheduler. There are two ways to implement a thread, they’re either in user space or in the Kernel.
    * Threads can be implemented in user space, without the support of the kernel. The following things happen if we  implement a thread in user space –
      * The corresponding code and the data structures used are stored in the user space.
      * If an API is invoked, it results in a local system call in user space, rather than a system call.
      * The threads are managed entirely by the run-time system, without the kernel knowing anything about it.
  * [What's difference between User Level thread and Kernel Level thread ?](https://www.geeksforgeeks.org/difference-between-user-level-thread-and-kernel-level-thread/#:~:text=User%20threads%20are%20implemented%20by,by%20Operating%20System%20(OS).)

| No.	| Parameters	| User Level Thread	| Kernel Level Thread |
| - | - | - | - |
| 1	| Implemented by	| User threads are implemented by users.	| Kernel threads are implemented by Operating System (OS). |
| 2	| Recognize	| Operating System doesn’t recognize user level threads.	| Kernel threads are recognized by Operating System.
| 3	| Implementation	| Implementation of User threads is easy.	| Implementation of Kernel thread is complicated.
| 4	| Context switch time	| Context switch time is less.	| Context switch time is more.
| 5	| Hardware support	| Context switch requires no hardware support.	| Hardware support is needed.
| 6	| Blocking operation	| If one user level thread performs blocking operation then entire process will be blocked.	| If one kernel thread perform blocking operation then another thread can continue execution.
| 7	| Multithreading	| Multithread applications cannot take advantage of multiprocessing.	| Kernels can be multithreaded.
| 8	| Creation and Management	| User level threads can be created and managed more quickly. | Kernel level threads take more time to create and manage. 
| 9	| Operating System	| Any operating system can support user-level threads.	| Kernel level threads are operating system-specific.
| 10	| Thread Management	| The thread library contains the code for thread creation, message passing, thread scheduling, data transfer and thread destroying	| The application code does not contain thread management code. It is merely an API to the kernel mode. The Windows operating system makes use of this feature.
| 11	| Example	| Example: Java thread, POSIX threads.	| Example: Window Solaris.
| 12	| Advantages	| User Level Threads are simple and quick to create. / Can run on any operating system / They perform better than kernel threads since they don’t need to make system calls to create threads. / In user level threads, switching between threads does not need kernel mode privileges. | Scheduling of multiple threads that belong to same process on different processors is possible in kernel level threads. / Multithreading can be there for kernel routines. / When a thread at the kernel level is halted, the kernel can schedule another thread for the same process.
| 13.	| Disadvantages	| Multithreaded applications on user-level threads cannot benefit from multiprocessing. / If a single user-level thread performs a blocking operation, the entire process is halted. | Transferring control within a process from one thread to another necessitates a mode switch to kernel mode. / Kernel level threads takes more time to create and manage than user level threads.

### 多线程

* [学习笔记之多线程 - 浩然119 - 博客园 (cnblogs.com)](https://www.cnblogs.com/pegasus923/p/5554565.html)
* [用三个线程按顺序循环打印ABC三个字母 - 浩然119 - 博客园 (cnblogs.com)](https://www.cnblogs.com/pegasus923/p/8575543.html)
* 线程与进程的区别
* 多线程中栈与堆是公有的还是私有的
  * 在多线程环境下，每个线程拥有一个栈和一个程序计数器。栈和程序计数器用来保存线程的执行历史和线程的执行状态，是线程私有的资源。
  * 其他的资源（比如堆、地址空间、全局变量）是由同一个进程内的多个线程共享
* [mutex - C++ Reference (cplusplus.com)](http://www.cplusplus.com/reference/mutex/mutex/?kw=mutex)
* [condition_variable - C++ Reference (cplusplus.com)](http://www.cplusplus.com/reference/condition_variable/condition_variable/)
* semophore
* deadlock
  * 在引入锁的同时，我们遇到了一个新的问题：死锁(Deadlock)。死锁是指两个或多个线程／进程之间相互阻塞，以至于任何一个都不能继续运行，因此也不能解锁其他线程／进程。例如，线程A占有lock A，并且尝试获取lock B；而线程2占有lock B，尝试获取lock A。此时，两者相互阻塞，都无法继续运行。
  * 总结产生死锁的四个条件(只有当四个条件同时满足时才会产生死锁)：
    * Mutual Exclusion – Only one process may use a resource at a time
    * Hold-and-Wait – Process holds resource while waiting for another
    * No Preemption – Can’t take a resource away from a process
    * Circular Wait – The waiting processes form a cycle
  * 如何处理死锁问题：
    * 忽略该问题。例如鸵鸟算法，该算法可以应用在极少发生死锁的的情况下。为什么叫鸵鸟算法呢，因为传说中鸵鸟看到危险就把头埋在地底下，可能鸵鸟觉得看不到危险也就没危险了吧。跟掩耳盗铃有点像。
    * 检测死锁并且恢复。
    * 仔细地对资源进行动态分配，以避免死锁。
    * 通过破除死锁四个必要条件之一，来防止死锁产生。
* [记一次腾讯面试：进程之间究竟有哪些通信方式？如何通信？ ---- 告别死记硬背_帅地-CSDN博客](https://blog.csdn.net/m0_37907797/article/details/103188294)
* [4 个场景详解大厂面试中的死锁问题 (qq.com)](https://mp.weixin.qq.com/s/t49aLTN9w-1qNg5_EKpNzA)
* [2 万字长文详解 10 大多线程面试题｜原力计划 (qq.com)](https://mp.weixin.qq.com/s/hq5GbYBe98YsBDNA3u2s5Q)
  * [2020大厂必问面试题(Java多线程)_ZZZhonngger的博客-CSDN博客_大厂多线程面试题](https://blog.csdn.net/weixin_43395911/article/details/104660403)
* [面试问我，创建多少个线程合适？我该怎么说 (qq.com)](https://mp.weixin.qq.com/s/otLfgYhjh17kOm6zxAhpiw)
* [一文看懂进程和线程调度 (qq.com)](https://mp.weixin.qq.com/s/pKdQu74Sl3PIaKyDlIEExg)
* [线程间到底共享了哪些进程资源？ (qq.com)](https://mp.weixin.qq.com/s/L7-CypKf25bLVzIeStB-sA)
* [Linux系统僵尸进程详解](https://mp.weixin.qq.com/s/pSUkTib5PcInYl-LGXweGw)

## 网络 

* [网络协议_百度百科 (baidu.com)](https://baike.baidu.com/item/%E7%BD%91%E7%BB%9C%E5%8D%8F%E8%AE%AE/328636?fr=aladdin)
* [网络协议常见面试题集锦 (qq.com)](https://mp.weixin.qq.com/s/_yEqNFbxsIhS_45WKTy9_w)
* TCP/IP
  * [动画讲解TCP](https://mp.weixin.qq.com/s/hBufa_4wwkPxuxcIf6s6hg)
  * [动画讲解 TCP 四次分手过程](https://mp.weixin.qq.com/s/osQceF7Pg1SDMZDAXIniXg)
* 是否了解应用层通信，通信协议HTTP
* 你一定要知道，关于https的五大误区
  * https://mp.weixin.qq.com/s/bncfDp_Mg54qLL_JBYE20g
  * http://www.d1net.com/security/news/552826.html
* UDP/IP
* socket
  * [socket（计算机专业术语）_百度百科](https://baike.baidu.com/item/socket/281150?fr=aladdin)
* [TCP/IP、Http、Socket的区别_百度经验](http://jingyan.baidu.com/article/08b6a591e07ecc14a80922f1.html)
* [面试环节：在浏览器输入 URL 回车之后发生了什么？](https://mp.weixin.qq.com/s/xPdm2MqP38pSIE0X3sQrdQ)
  * https://4ark.me/post/b6c7c0a2.html
* [面试官问我：一个 TCP 连接可以发多少个 HTTP 请求？](https://mp.weixin.qq.com/s/TagCMAXyjspnEIP2E1Hmqw)
  * https://zhuanlan.zhihu.com/p/61423830
* [面试官问我：三次握手与四次挥手是怎么完成的？](https://mp.weixin.qq.com/s?__biz=MzUyNjQxNjYyMg==&mid=2247486377&idx=1&sn=05f19f7854f9e2524219e742e69fee51&chksm=fa0e6428cd79ed3e3b1a9c0f2f2ce9e73c13b4fc2586e7bf96da01e0e1cbb1ac30e4b276e900&mpshare=1&scene=24&srcid=&sharer_sharetime=1567832363410&sharer_shareid=5ed4a849fa42d9599a974fa8eb45e8fa&key=5a37b8e9f2933463a19e893ed135defb0616b130a6c0c3d7bf51b08d053292a643da98040780c4703bc795bfaf4ec690f22ed56aaaae3974bdb5de4130272d9bd0e2abfb7a79732df47daff037a5ce27&ascene=14&uin=MTMzMzc3MjY4MQ%3D%3D&devicetype=Windows+10&version=62060833&lang=en&pass_ticket=tT3maEfznKd3xtVT4L8%2Bl%2B2KKdhrJZ3ERaWEoIpqIMB2I2ssKo%2BTfx0v80L7rMTL)
* [面试 | 你真的了解 HTTP 头部么？](https://mp.weixin.qq.com/s/Mcbfg1uLwk7pUo8tE48VGA)
* [看完这篇HTTP，跟面试官扯皮就没问题了 (qq.com)](https://mp.weixin.qq.com/s/F3RoMypV62sjNKNfNJuzug)
* [HTTP Methods GET vs POST vs PUT](https://www.w3schools.com/tags/ref_httpmethods.asp#:~:text=The%20PUT%20Method&text=The%20difference%20between%20POST%20and,the%20same%20resource%20multiple%20times.)
  * The PUT Method
    * PUT is used to send data to a server to create/update a resource.
    * The difference between POST and PUT is that PUT requests are idempotent. That is, calling the same PUT request multiple times will always produce the same result. In contrast, calling a POST request repeatedly have side effects of creating the same resource multiple times.
  * Compare GET vs. POST

-|GET|POST
-|-|-
BACK button/Reload|Harmless|Data will be re-submitted (the browser should alert the user that the data are about to be re-submitted)
Bookmarked|Can be bookmarked|Cannot be bookmarked
Cached|Can be cached|Not cached
Encoding type|application/x-www-form-urlencoded|application/x-www-form-urlencoded or multipart/form-data. Use multipart encoding for binary data
History|Parameters remain in browser history|Parameters are not saved in browser history
Restrictions on data length|Yes, when sending data, the GET method adds the data to the URL; and the length of a URL is limited (maximum URL length is 2048 characters)|No restrictions
Restrictions on data type|Only ASCII characters allowed|No restrictions. Binary data is also allowed
Security|GET is less secure compared to POST because data sent is part of the URL. Never use GET when sending passwords or other sensitive information!	|POST is a little safer than GET because the parameters are not stored in browser history or in web server logs
Visibility|Data is visible to everyone in the URL|Data is not displayed in the URL

* [What's DNS ?](https://www.cloudflare.com/learning/dns/what-is-dns/)
  * The Domain Name System (DNS) is the phonebook of the Internet. Humans access information online through domain names, like nytimes.com or espn.com. Web browsers interact through Internet Protocol (IP) addresses. DNS translates domain names to IP addresses so browsers can load Internet resources.
  * [What is DNS? – Introduction to DNS - AWS](https://aws.amazon.com/route53/what-is-dns/?nc1=h_ls)
* [Cookie、Session、Token那点事儿](https://mp.weixin.qq.com/s/b8h6_3CMlwsE8PtkrPr9FA)
  * https://www.jianshu.com/p/bd1be47a16c1
* [一文彻底搞懂cookie和session](https://mp.weixin.qq.com/s/5b4h8-N-3HpQz4pL9Dn6Sw)
  * https://juejin.im/post/5b7c1f4d6fb9a019f221ca14
* [吊打面试官之消息队列基础 (qq.com)](https://mp.weixin.qq.com/s/Tta36pxSIGDvnW_Rb-FkQA)
* [面试官：你连 RESTful 都不知道我怎么敢要你？| 原力计划 (qq.com)](https://mp.weixin.qq.com/s/AzKyyvCQbdoASG5KMKrokg)
* [面试官：说说你对 RESTful 的理解？](https://mp.weixin.qq.com/s/wtynZ5kw-48tq8PIkBw6Rw)

## 软件开发

* C# v.s. C++
* Scripting language v.s. Compiling language
* 动态/静态链接库区别
  * 动态链接库：在运行时加载
  * 静态链接库：在编译时直接联到可执行文件中
  * 动态链接库和静态链接库的区别
    * http://blog.csdn.net/gamecreating/article/details/5504152
    * http://blog.sina.com.cn/s/blog_61ba4898010153zu.html
* [敏捷软件开发 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E6%95%8F%E6%8D%B7%E8%BD%AF%E4%BB%B6%E5%BC%80%E5%8F%91)
* Scrum
  * [Scrum - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/Scrum)
    * Scrum是一种敏捷软件开发的方法学，用于迭代式增量软件开发过程。Scrum在英语是橄榄球运动中列阵争球的意思。
    * 虽然Scrum是为管理软件开发项目而开发的，它同样可以用于运行软件维护团队，或者作为计划管理方法。Scrum之间的合作称为“Scrum of Scrums”。
* Test-driven development （TDD）
  * [测试驱动开发 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E6%B5%8B%E8%AF%95%E9%A9%B1%E5%8A%A8%E5%BC%80%E5%8F%91)
    * 测试驱动开发（英语：Test-driven development，缩写为TDD）是一种软件开发过程中的应用方法，由极限编程中倡导，以其倡导先写测试程序，然后编码实现其功能得名。测试驱动开发始于20世纪90年代。测试驱动开发的目的是取得快速反馈并使用“illustrate the main line”方法来构建程序。
    * 测试驱动开发是戴两顶帽子思考的开发方式：先戴上实现功能的帽子，在测试的辅助下，快速实现其功能；再戴上重构的帽子，在测试的保护下，通过去除冗余的代码，提高代码质量。测试驱动着整个开发过程：首先，驱动代码的设计和功能的实现；其后，驱动代码的再设计和重构。
* Behavior-driven development（BDD）
  * [行为驱动开发 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E8%A1%8C%E4%B8%BA%E9%A9%B1%E5%8A%A8%E5%BC%80%E5%8F%91)
    * 行为驱动开发（英语：Behavior-driven development，缩写BDD）是一种敏捷软件开发的技术，它鼓励软件项目中的开发者、QA和非技术人员或商业参与者之间的协作。BDD最初是由Dan North在2003年命名[1]，它包括验收测试和客户测试驱动等的极限编程的实践，作为对测试驱动开发的回应。在过去数年里，它得到了很大的发展[2]。
    * 2009年，在伦敦发表的“敏捷规格，BDD和极限测试交流”[3]中，Dan North对BDD给出了如下定义：
    * BDD是第二代的、由外及内的、基于拉(pull)的、多方利益相关者的(stakeholder)、多种可扩展的、高自动化的敏捷方法。它描述了一个交互循环，可以具有带有良好定义的输出（即工作中交付的结果）：已测试过的软件。
    * BDD的重点是通过与利益相关者的讨论取得对预期的软件行为的清醒认识。它通过用自然语言书写非程序员可读的测试用例扩展了测试驱动开发方法。行为驱动开发人员使用混合了领域中统一的语言的母语语言来描述他们的代码的目的。这让开发者得以把精力集中在代码应该怎么写，而不是技术细节上，而且也最大程度的减少了将代码编写者的技术语言与商业客户、用户、利益相关者、项目管理者等的领域语言之间来回翻译的代价。
* Continuous integration（CI）
  * [Continuous integration - Wikipedia](https://en.wikipedia.org/wiki/Continuous_integration)
  * [持续集成 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E6%8C%81%E7%BA%8C%E6%95%B4%E5%90%88)
    * 持续集成（英语：Continuous integration，缩写CI）是一种软件工程流程，是将所有软件工程师对于软件的工作副本持续集成到共用主线（mainline）的一种举措。该名称最早由[1]葛来迪·布区（Grady Booch）在他的布区方法[2]中提出，不过他并没有提到要每天集成数次。之后该举措成为极限编程（extreme programming）的一部分时，其中建议每天应集成超过一次，甚至达到数十次。[3]在测试驱动开发（TDD）的作法中，通常还会搭配自动单元测试。持续集成的提出主要是为解决软件进行系统集成时面临的各项问题，极限编程称这些问题为集成地狱（integration hell）。
  * [持续集成_百度百科](https://baike.baidu.com/item/%E6%8C%81%E7%BB%AD%E9%9B%86%E6%88%90)
    * 持续集成是一种软件开发实践，即团队开发成员经常集成他们的工作，通过每个成员每天至少集成一次，也就意味着每天可能会发生多次集成。每次集成都通过自动化的构建（包括编译，发布，自动化测试）来验证，从而尽早地发现集成错误。
* Continuous delivery / Continuous deployment（CD）
  * [Continuous delivery - Wikipedia](https://en.wikipedia.org/wiki/Continuous_delivery)
  * [持续交付 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E6%8C%81%E7%BA%8C%E4%BA%A4%E4%BB%98)
    * 持续交付（英语：Continuous delivery，缩写为 CD），是一种软件工程手法，让软件产品的产出过程在一个短周期内完成，以保证软件可以稳定、持续的保持在随时可以释出的状况。它的目标在于让软件的建置、测试与释出变得更快以及更频繁。这种方式可以减少软件开发的成本与时间，减少风险。
  * [持续交付_百度百科](https://baike.baidu.com/item/%E6%8C%81%E7%BB%AD%E4%BA%A4%E4%BB%98/9803571?fr=aladdin)
* DevOps（Development和Operations的组合词）
  * [DevOps - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/DevOps)
    * DevOps（Development和Operations的组合词）是一种重视“软件开发人员（Dev）”和“IT运维技术人员（Ops）”之间沟通合作的文化、运动或惯例。透过自动化“软件交付”和“架构变更”的流程，来使得构建、测试、发布软件能够更加地快捷、频繁和可靠。
* 系统发展生命周期（SDLC）
  * [系统发展生命周期 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E7%B3%BB%E7%BB%9F%E5%8F%91%E5%B1%95%E7%94%9F%E5%91%BD%E5%91%A8%E6%9C%9F)
    * 系统发展生命周期（SDLC），也称软件生命周期，是系统工程、信息系统和软件工程中的术语，用于描述一个信息系统从规划、创建、测试到最终完成部署的全过程[1]。
* 软件即服务（Software as a Service，i.e. SaaS）
  * [软件即服务 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E8%BD%AF%E4%BB%B6%E5%8D%B3%E6%9C%8D%E5%8A%A1)
* 奇异递归模板模式（curiously recurring template pattern，CRTP）
  * [奇异递归模板模式 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E5%A5%87%E5%BC%82%E9%80%92%E5%BD%92%E6%A8%A1%E6%9D%BF%E6%A8%A1%E5%BC%8F)
    * 奇异递归模板模式（curiously recurring template pattern，CRTP）是C++模板编程时的一种惯用法（idiom）：把派生类作为基类的模板参数。[1]更一般地被称作F-bound polymorphism，是一类F 界量化。
* MEAN Stack
  * MongoDB, Angularjs, Nodejs, React, Golang
* LAMP Stack
  * Linux, Apache, MySQL, PHP/Python, Javascript, Angularjs
* Full Stack Java
  * Java, J2EE, Spring MVC Framework, Bootstrap, Javascript, Angularjs

## 测试 

* 如何测试一个水杯，记得考虑异常测试
* 常用的测试工具，测试方法 
* 程序crash如何定位检测
* 内存泄露定位 / 监测／防止
  * [内存泄漏_百度百科](https://baike.baidu.com/item/%E5%86%85%E5%AD%98%E6%B3%84%E6%BC%8F/6181425?fr=aladdin)
  * [内存泄漏以及常见的解决方法 - na_he的专栏 - CSDN博客](http://blog.csdn.net/na_he/article/details/7429171)
  * [C/C++内存泄漏及检测 - 吴秦 - 博客园](http://www.cnblogs.com/skynet/archive/2011/02/20/1959162.html)
  * [Memory debugger - Wikipedia](https://en.wikipedia.org/wiki/Memory_debugger)
    * A memory debugger also known as a runtime debugger[1] is a debugger for finding software memory problems such as memory leaks and buffer overflows. These are due to bugs related to the allocation and deallocation of dynamic memory. Programs written in languages that have garbage collection, such as managed code, might also need memory debuggers, e.g. for memory leaks due to "living" references in collections.
  * [Valgrind - Wikipedia](https://en.wikipedia.org/wiki/Valgrind#Memcheck)
    * Valgrind /ˈvælɡrɪnd/ is a programming tool for memory debugging, memory leak detection, and profiling.
    * Valgrind was originally designed to be a freememory debugging tool for Linux on x86, but has since evolved to become a generic framework for creating dynamic analysis tools such as checkers and profilers.
* GDB
  * [gdb_百度百科](http://baike.baidu.com/link?url=qzDVNAB5igtON9p7hw4Ybwu5hELcvElenqb9X-hINKukyB-6lG0Al-VJ2Vxjm7PwFBJmiZVwZCYJ2V-alB_WLa)

## 工具

* Confluence
  * [Confluence (software) - Wikipedia](https://en.wikipedia.org/wiki/Confluence_(software))
    * Confluence is a team collaboration software. Written in Java and mainly used in corporate environments, it is developed and marketed by Atlassian. Confluence is sold as either on-premises software or as software as a service.
* Cucumber
  * [Cucumber (software) - Wikipedia](https://en.wikipedia.org/wiki/Cucumber_(software))
    * Cucumber is a software tool used by computer programmers for testing other software. It runs automated acceptance tests written in a behavior-driven development (BDD) style. Central to the Cucumber BDD approach is its plain language parser called Gherkin. It allows expected software behaviors to be specified in a logical language that customers can understand. As such, Cucumber allows the execution of feature documentation written in business-facing text. Capybara, which is a part of the Cucumber testing framework, is an example of a web based test automation software.
    * [Cucumber is written in the Ruby programming language. and was originally used exclusively for Ruby testing as a complement to the RSpec BDD framework. Cucumber now supports a variety of different programming languages through various implementations. For example, Cuke4php and Cuke4Lua are software bridges that enable testing of PHP and Lua projects, respectively. Other implementations may simply leverage the Gherkin parser while implementing the rest of the testing framework in the target language.
  * [Introduction to Cucumber](https://www.guru99.com/introduction-to-cucumber.html)
  * [从头写一个Cucumber测试(一) Selenium Test – Bu・log](https://yaowenjie.github.io/%E7%BC%96%E7%A8%8B%E7%9B%B8%E5%85%B3/cucumber-test)
  * [从头写一个Cucumber测试(二) Cucumber Test – Bu・log](https://yaowenjie.github.io/%E7%BC%96%E7%A8%8B%E7%9B%B8%E5%85%B3/cucumber-test-part-2)
* git
  * [git - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/Git)
    * git是一个分布式版本控制软件，最初由林纳斯·托瓦兹（Linus Torvalds）创作，于2005年以GPL发布。最初目的是为更好地管理Linux内核开发而设计。应注意的是，这与GNU Interactive Tools[6]（一个类似Norton Commander界面的文件管理器）有所不同。
    * git最初的开发动力来自于BitKeeper和Monotone[7][8]。git最初只是作为一个可以被其他前端（比如Cogito或Stgit[9]）包装的后端而开发的，但后来git内核已经成熟到可以独立地用作版本控制[10]。很多著名的软件都使用git进行版本控制[11]，其中包括Linux内核、X.Org服务器和OLPC内核等项目的开发流程[12]。
* JIRA
  * [JIRA - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/JIRA)
    * JIRA 是一个缺陷跟踪管理系统，为针对缺陷管理、任务追踪和项目管理的商业性应用软件，开发者是澳大利亚的Atlassian。JIRA这个名字并不是一个缩写，而是截取自“Gojira”，日文的哥斯拉发音。 
* JMeter
  * [Apache JMeter - Wikipedia](https://en.wikipedia.org/wiki/Apache_JMeter)
    * Apache JMeter is an Apacheproject that can be used as a load testing tool for analyzing and measuring the performance of a variety of services, with a focus on web applications.
    * JMeter can be used as a unit-test tool for JDBC database connections,[1] FTP,[2] LDAP,[3] Webservices,[4] JMS,[5] HTTP,[6] generic TCP connections and OS native processes.[citation needed] One can also configure JMeter as a monitor,[7] although this is typically considered[by whom?]ad hoc rather than advanced monitoring. It can be used for some functional testing as well.[8]
    * JMeter supports variable parameterization, assertions (response validation), per-thread cookies, configuration variables and a variety of reports.
    * JMeter architecture is based on plugins. Most of its "out of the box" features are implemented with plugins. Off-site developers can easily extend JMeter with custom plugins.
  * [Jmeter_百度百科](https://baike.baidu.com/item/Jmeter)
    * Apache JMeter是Apache组织开发的基于Java的压力测试工具。用于对软件做压力测试，它最初被设计用于Web应用测试，但后来扩展到其他测试领域。 它可以用于测试静态和动态资源，例如静态文件、Java 小服务程序、CGI 脚本、Java 对象、数据库、FTP 服务器， 等等。JMeter 可以用于对服务器、网络或对象模拟巨大的负载，来自不同压力类别下测试它们的强度和分析整体性能。另外，JMeter能够对应用程序做功能/回归测试，通过创建带有断言的脚本来验证你的程序返回了你期望的结果。为了最大限度的灵活性，JMeter允许使用正则表达式创建断言。
    * Apache jmeter 可以用于对静态的和动态的资源（文件，Servlet，Perl脚本，java 对象，数据库和查询，FTP服务器等等）的性能进行测试。它可以用于对服务器、网络或对象模拟繁重的负载来测试它们的强度或分析不同压力类型下的整体性能。你可以使用它做性能的图形分析或在大并发负载测试你的服务器/脚本/对象。
* LoadUI
  * [LoadUI - Wikipedia](https://en.wikipedia.org/wiki/LoadUI)
    * LoadUI is a load testing software, targeted mainly at web services. LoadUI runs on Windows, Linux and Mac OS. LoadUI allows users to test the speed and scalability of APIs, preview API performance behaviors before releasing to production environments and shift performance insights to the left.
* OpenGL
  * [OpenGL - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/OpenGL)
    * OpenGL（英语：Open Graphics Library，译名：开放图形库或者“开放式图形库”）是用于渲染2D、3D矢量图形的跨语言、跨平台的应用程序编程接口（API）。这个接口由近350个不同的函数调用组成，用来从简单的图形比特绘制复杂的三维景象。而另一种程序接口系统是仅用于Microsoft Windows上的Direct3D。OpenGL常用于CAD、虚拟实境、科学可视化程序和电子游戏开发。
* Selenium
  * [Selenium (software) - Wikipedia](https://en.wikipedia.org/wiki/Selenium_(software))
    * Selenium is a portable software-testingframework for web applications. Selenium provides a playback (formerly also recording) tool for authoring tests without the need to learn a test scripting language (Selenium IDE). It also provides a test domain-specific language (Selenese) to write tests in a number of popular programming languages, including C#, Groovy, Java, Perl, PHP, Python, Ruby and Scala. The tests can then run against most modern web browsers. Selenium deploys on Windows, Linux, and macOS platforms. It is open-source software, released under the Apache 2.0 license: web developers can download and use it without charge.
* SoapUI
  * [SoapUI - Wikipedia](https://en.wikipedia.org/wiki/SoapUI)
    * SoapUI is an open-source web service testing application for service-oriented architectures (SOA) and representational state transfers (REST). Its functionality covers web service inspection, invoking, development, simulation and mocking, functional testing, load and compliance testing. A commercial version, SoapUI Pro, which mainly focuses on features designed to enhance productivity, was also developed by Eviware software. In 2011, SmartBear Software acquired Eviware.
    * SoapUI was initially released to SourceForge in September 2005. It is free software, licensed under the terms of the European Union Public License. Since the initial release, SoapUI has been downloaded more than 2,000,000 times. It is built entirely on the Java platform, and uses Swing for the user interface. This means that SoapUI is cross-platform. Today, SoapUI also supports IDEA, Eclipse, and NetBeans.
    * SoapUI can test SOAP and REST web services, JMS, AMF, as well as make any HTTP(S) and JDBC calls.
* Swing
  * [Swing (Java) - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/Swing_(Java))
    * Swing是一个为Java设计的GUI工具包。Swing是Java基础类的一部分。Swing包括了图形用户界面（GUI）组件如：文本框，文本域，按钮，分隔窗格和表。
    * Swing提供许多比AWT更好的屏幕显示元素。它们用纯Java写成，所以同Java本身一样可以跨平台运行，这一点不像AWT。它们是JFC的一部分。它们支持可更换的面板和主题（各种操作系统默认的特有主题），然而不是真的使用原生平台提供的设备，而是仅仅在表面上模仿它们。这意味着你可以在任意平台上使用Java支持的任意面板。轻量级组件的缺点则是执行速度较慢，优点就是可以在所有平台上采用统一的行为。
* [程序员必备的工具软件有哪些？](https://mp.weixin.qq.com/s/0JXEb_QHqKDQ755sX3R6GQ)

## [系统设计](https://github.com/haoran119/learning-notes/tree/main/%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0%E4%B9%8BCoding-Design-Tool#design)

* 设计模式
    * [设计模式（即使代码编制真正工程化）_百度百科](http://baike.baidu.com/link?url=QoxZgqaX0LcWjUC9bYsOC8jLwWf3HpljeCuDoqxL4MYIWnWqzdtWlIhyVhe6npPk8zL-pcoQP5oq4HImZKspt9Da3R7d3cEkrsVgwqVmAKu)
* 单体如何避免多个instance？
    * 构造时指向一块内存保证惟一性。static
* [System Design - OpenGenus IQ: Computing Expertise & Legacy](https://iq.opengenus.org/tag/system-design/)
    * [How to design a System? (Cheatsheet)](https://iq.opengenus.org/how-to-design-system/)
    * [System Design of Bank Management System](https://iq.opengenus.org/system-design-of-bank-management-system/)
    * [System Design of Facebook Messenger](https://iq.opengenus.org/system-design-of-facebook-messenger/)
* [System Design for Beginners Course - YouTube](https://www.youtube.com/watch?v=m8Icp_Cid5o&list=LL&index=3)
* [System Design Course for Beginners - YouTube](https://www.youtube.com/watch?v=MbjObHmDbZo)
* [个人吐血整理的系统设计资料大全 - 九章算法](https://mp.weixin.qq.com/s/4kv57_rBVWemkh5t33WGMw)
* [如何设计爬虫系统 | 系统设计高频题解题思路分析](https://mp.weixin.qq.com/s/X6e9zXRFDRN05RrD11XUGg)
* [系统设计资料大全](https://mp.weixin.qq.com/s/jl0lQlSv6tOtmI3EMvrZQw)
* [面试官绝杀：系统是如何支撑高并发的？](https://mp.weixin.qq.com/s/fHSKIgJVTdoPVu7hFAZXSw)
* [每秒千万级实时数据处理系统是如何设计的？](https://mp.weixin.qq.com/s/BwDvqt2yLEq8BHnQUGS8gw)
* [字节三面：如何设计一个高性能短链系统？](https://mp.weixin.qq.com/s/Fzg34Q6PH2-Q8SzH_uaxng)
    * 什么是短链？为什么要用短链？
    * 短链跳转的基本原理
    * 生成短链的两种方法
        * 方法 1：哈希算法
            * 如何让短链更短
                * 将 10 进制的哈希值，转化成更高进制的哈希值，这样哈希值就变短了。
            * 如何解决哈希冲突
            * 如何优化性能
                * 给短链字段建立唯一索引
                * 布隆过滤器
        * 方法二：ID 生成器
            * 相同的原始网址可能会对应不同的短链
            * 如何实现高性能的 ID 生成器

### [System Design Tutorial - GeeksforGeeks](https://www.geeksforgeeks.org/system-design-tutorial/)

* [Getting Started with System Design - GeeksforGeeks](https://www.geeksforgeeks.org/getting-started-with-system-design/)
    * Approaching a Design Problem
        * Breaking Down the Problem
        * Communicating your Ideas
        * Assumptions that make sense
    * Reliability in System Design –
        * A system is Reliable when it can meet the end-user requirement. When you are designing a system you should have planned to implement a set of features and services in your system. If your system can serve all those features without wearing out then your System can be considered to be Reliable.
        * A Fault Tolerant system can be one that can continue to be functioning reliably even in the presence of faults. Faults are the errors that arise in a particular component of the system. An occurrence of fault doesn’t guarantee Failure of the System.
        * Failure is the state when the system is not able to perform as expected. It is no longer able to provide certain services to the end-users.
    * Availability in System Design –
        * Availability is a characteristic of a System which aims to ensure an agreed level of Operational Performance, also known as uptime. It is essential for a system to ensure high availability in order to serve the user’s requests.
        * There are various principles you should follow in order to ensure the availability of your system :
            * Your System should not have a Single Point of Failure. Basically, your system should not be dependent on a single service in order to process all of its requests. Because when that service fails then your entire system can be jeopardized and end up becoming unavailable.
            * Detecting the Failure and resolving it at that point.
    * Scalability in System Design –
        * Scalability refers to the ability of the System to cope up with the increasing load. 
        * In order to ensure scalability you should be able to compute the load that your system will experience. There are various factors that describe the Load on the System:
            * Number of requests coming to your system for getting processed per day
            * Number of Database calls made from your system
            * Amount of Cache Hit or Miss requests to your system
            * Users currently active on your system
* [Database Sharding - System Design Interview Concept - GeeksforGeeks](https://www.geeksforgeeks.org/database-sharding-a-system-design-concept/)
* [How to Crack System Design Round in Interviews? - GeeksforGeeks](https://www.geeksforgeeks.org/how-to-crack-system-design-round-in-interviews/)
* [Top 10 System Design Interview Questions and Answers - GeeksforGeeks](https://www.geeksforgeeks.org/top-10-system-design-interview-questions-and-answers/)
* [Design Twitter - A System Design Interview Question - GeeksforGeeks](https://www.geeksforgeeks.org/design-twitter-a-system-design-interview-question/)

## MISC

* [一起刷题学习 Git/SQL/正则表达式 (qq.com)](https://mp.weixin.qq.com/s/31gpcQkKvy7sMUvEoVyHQw)
* [What is the difference between SSD and HDD ?](https://www.avast.com/c-ssd-vs-hdd#:~:text=SSD%20vs%20HDD%3A%20What%27s%20the,less%20energy%2C%20and%20more%20durable.)
    * HDDs are traditional storage devices with spinning platters that read and write data. SSDs use newer technology that stores data on instantly accessible memory chips. SSDs are faster, quieter, smaller, consume less energy, and more durable. HDDs are cheaper, have more storage capacity, and offer easier data recovery if damaged.
    * The main difference between a solid state drive (SSD) and a hard disk drive (HDD) is how data is stored and accessed. HDDs use mechanical spinning disks and a moving read/write head to access data, while SSDs use memory chips. If price isn’t an issue, SSDs are a better option — especially since modern SSDs are just about as reliable as HDDs.
![image](https://user-images.githubusercontent.com/34557994/205414966-3b429837-cfed-44c0-8ce6-dff647773427.png)

# END
