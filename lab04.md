# 文本压缩及其类型
>我们每天都活在许许多多的数据中，这些数据所占用的空间是不可思议的。为了存储和传输数据，减少数据所占空间的大小是很有必要的。完成这项工作的技术成为数据压缩。过去因为存储的局限性，需要数据压缩。现在，虽然存储容量不受限制，但由于要与他人共享数据，网络具有固有的带宽限制，定义了在固定时间从一个地点传输到另一个地点的最大位数或字节数，因此也需要数据压缩。在众多数据中，文本数据占了很大比重。

&nbsp;通信带宽是一种昂贵的资源，许多用户希望尽可能地减少传送的总比特数，即文本压缩。此外，文本压缩也有保密的意义。以下是一些文本压缩的类型：
## 一、关键字编码
&nbsp;人们日常生活中交流所用到的字有很多会被重复使用多次，如果这些字占用更少的空间(即使用更少的字符表示)，数据所占空间就会减小。一种相当直接的文本压缩方法就是**关键字编码**，它用单个字符代替了常见的字。
<br/>例如，假设我们用下图表对几个单词进行编码:
![](images\lab04\1.PNG)

<br/>对下列段落使用此编码:
![](images\lab04\2.PNG)

<br/>得到新的一个段落:
![](images\lab04\3.PNG)

<br/>这个新段落就比以前的段落少了一些字节，大致计算一下压缩率约为90%。
<br/>然而，关键字编码有很多局限性。比如，用来对应原来单词的字符不能出现在原来的文本中，否则编码出来的新段落就会产生歧义。再如例子中的"The"就没有被转为字符"~"，因为在计算机上存储的字母的大小写被看作是不同的字符。
## 二、行程长度编码
&nbsp;在某些情况下，同一个字符可能在一个长序列中反复出现。在日常文档中，这种重复不常出现，但在大的数据流(如DNA序列)中，这种情况会反复出现。于是**行程长度编码**应运而生，它把一系列重复字符替换为他们重复出现的次数。例如，一个由10个C构成的字符串**CCCCCCCCC**如果被以*作为标志字符编码的话可以变成<b>*C9</b>。
<br/>标志字符说明这三个字符(*C9)的序列应该被解码为相应的重复字符串，其他文本则正常处理。因此，下面的字符串
![](images\lab04\4.PNG)

<br/>将被解码为如下的原始文本:
![](images\lab04\5.PNG)

<br/>原始文本有51个字符，编码串包括35个字符，故压缩率约为68%。
<br/>注意，这个例子中有三个重复的c和三个重复的e都备有被编码，因为需要用三个字符对这样的重复序列编码，所以对于长度为2或3的字符串进行编码是"得不偿失的"。
## 三、赫夫曼编码
&nbsp;还有一种文本压缩类型叫做赫夫曼编码，是以一个叫David Huffman博士的名字命名的。它是用变长的二进制串表示字符，使常用的字符具有较短的编码。赫夫曼编码的一个与众不同之处是，使用不同长度的位串表示每个字符。也就是说，一些字符由2位编码表示，一些字符以6位编码表示等等。这种方法与字符集的概念相反，在字符集中，每个字符都由定长的位串表示。