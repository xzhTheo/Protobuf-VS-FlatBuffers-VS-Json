# 不同序列化方法工程搭建与对比

## Introduction
fbs、protobuffer、json

## Table of Contents
1. [Section 1](#section-1)
2. [Section 2](#section-2)
3. [Section 3](#section-3)
4. [Conclusion](#conclusion)

## flatbuffer
### 下载源码构建项目

git clone https://github.com/google/flatbuffers.git
cd flatbuffers
mkdir build && cd build
cmake .. -G "Unix Makefiles"
make -j $(nproc)
sudo make install
打开权限
chmod a+x flatc
flatc --version

### 创建和编译Schema
定义一个.fbs文件
table Person {
  name: string;
  age: int;
}
编译
flatc --cpp example.fbs、
FlatBuffers 支持跨多个文件定义命名空间，以及在单个文件中定义多个结构体。这增加了组织大型项目的灵活性。使用 flatc 编译多个 .fbs 文件时，可以一次性指定多个文件以解决相互依赖的问题：

flatc --cpp players.fbs enemies.fbs game_stats.fbs
## Section 2
### Subsection 2.1
Introduce the second main point. Provide relevant information and examples.

### Subsection 2.2
Further elaborate on the second main point with supporting details.

## Section 3
### Subsection 3.1
Discuss the third main point. Use visuals or code snippets to enhance understanding.

### Subsection 3.2
Conclude the third main point with additional insights or examples.

## Conclusion
Summarize the key points discussed in the article. Provide final thoughts or recommendations for further reading.

## References
- [Reference 1](#)
- [Reference 2](#)
- [Reference 3](#)

## About the Author
Provide a brief bio of the author, including relevant credentials and experience.
