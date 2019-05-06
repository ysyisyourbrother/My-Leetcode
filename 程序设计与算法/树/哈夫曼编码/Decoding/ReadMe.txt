接哈夫曼编码的文本（如果没有尝试过编码请看上一个ReadMe文本）
使用方法：
1.打开decoding.cpp文件，同样先更改main函数中的4个读写文件的地址
   因为译码必须基于编码建立的哈弗曼树，所以译码包含了编码的所有操作。
2.运行cpp文件，进行哈夫曼编码，编码是基于huffmanCoding inputfile的内容，编码结果会输出到输出文件上
   （具体见coding文件）
3.用户可以把huffmanCoding outputfile.txt的编码输出的乱码复制到译码输入文件huffmanDeCoding inputfile
   进行测试。复制完后再次运行cpp文件,查看huffmanDeCoding outputfile.txt文件，可以发现和huffmanCoding inputfile.txt
  文件内容相同，可知译码和编码进行正确。
4.用户可以自己修改编码的输入文件内容来重新建立不同的哈弗曼树，只需要修改编码输入文件的内容然后重新执行
  cpp文件即可。
注意：译码是基于编码，所以译码的输入不能随便输入，一定要基于编码建立的哈弗曼树才会有正确的结果，否则会有
意想不到的错误发生。