# 1.题目名称

Linux系统下实现一个C语言的词法分析器

#### 注意：

本题难度相对较大，有隐藏福利。

# 2.题目背景

> ## 关于Linux：
>
> **Linux 是一个操作系统最底层的核心及其提供的核心工具**，而常说的Linux系统指的是**Linux distribution(Linux 发布商套件)**，即**Linux Kernel + Softwares + Tools + 可完全安装程序**组成的相当完整的操作系统。而对于Linux的发行版该选哪个，我的建议是Ubuntu，因为不仅仅在于其操作友好，上手容易，界面美观，而且具有丰富的生态环境，甚至于连大名鼎鼎的机器人操作系统ROS（[ROS.org | Powering the world's robots](http://link.zhihu.com/?target=http%3A//www.ros.org/)）也是基于Ubuntu开发的。
>
> 国内高校的教学，往往忽视了Linux的重要性，一味的使用IDE，不利于计算机思维的提升。Linux下的编程开发，不仅能够弥补这一缺陷，并且随着深入Linux的世界，能够进一步学习到线程进程操作系统内核等等知识，为进一步的提升打下坚实的基础。
>
> ## 关于词法分析器：
>
> 编译器是将汇编或高级计算机语言翻译为二进制机器语言代码的计算机程序。编译器将源程序（source language） 编写的程序作为输入，翻译产生目标语言（target language ）机器代码的等价程序。通常地，源程序为高级语言（high-level language ），像C或C + +、汉语语言程序等，而目标则是机器语言的目标代码 （object code，有时也称作机器代码（machine code ）），也就是可以在计算机硬件中运行的机器代码软件程序。
>
> 编译原理关注的是编译器方面的产生原理和技术问题，旨在介绍编译程序构造的一般原理和基本方法。内容包括语言和文法、词法分析、语法分析、语法制导翻译、中间代码生成、存储管理、代码优化和目标代码生成。
>
> 了解一些编译器的相关知识，能够让同学们从编译器的角度去思考问题，这比起从语言本身的层面思考要更深一层，能够明白一些编程语言的特性产生的原因。所谓触类旁通是也，能够帮助同学们走出某些误区，甚至于更为快速的学会一门语言。

# 3.题目内容

本期题目要求在linux系统下实现一个C语言的词法分析器。

首先安装git（Ubuntu系统下使用命令`sudo apt-get install git`），然后clone仓库到本地：

```
git clone https://github.com/starwarein/Step4-2.git
```

在本地的Step4-2目录下，有示例程序 **Lexical_Analyzer.c** ，以及简单的目标程序文件**Test.c**，样例结果如下：

![hSwZr.png](https://s1.ax2x.com/2018/02/04/hSwZr.png)

## 本题要求：

重写或者修改示例程序 **Lexical_Analyzer.c** ，使其能够分析**aim.c**程序，为了简单起便，提交时不要求完全分析成功该程序，只要在原示例程序的基础上有所更改即可，当然，如果完全分析成功甚至能够分析本身（**Lexical_Analyzer.c** ），就是满分。

### 系统要求

Linux

PS:如果实在是懒，Ubuntu可以用学长写好的[脚本](https://github.com/starFalll/Ubuntu_Init)配置环境

# 4.参考资料

- [词法分析](http://pandolia.net/tinyc/ch7_lexical_basic.html)
- [Linux入门](http://www.blogof33.com/post/4/)

# 5.提交要求：

## 加分提交:

使用git提交，提pull request即可。

格式要求：不要修改Step4-2目录下的其他文件，新建一个文件夹，命名为自己的姓名，将自己修改后的程序（**程序名为Lexical_Analyzer_你的名字的拼音.c**）放入该文件夹即可。

## 普通提交：

1.所有文件放在一个文件夹里面

2.所有文本文件（包括C源代码）均使用utf-8编码格式

3.文件里面包含自己的思路，Markdown格式（可选）

4.文件夹命名为：**嵌入式工作室第四期第二题-姓名.zip**

5.邮箱地址：fyxformal@163.com

6.**请严格遵守以上提交格式要求!!!**

# 截止日期
2018年3月5号23点59分



