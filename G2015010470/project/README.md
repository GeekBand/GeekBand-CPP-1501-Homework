## 简介

这是我在极课班学习C++期间做的一个小项目。使用[Qt](http://www.qt.io/developers/)完成了一个简单的8x8[西洋跳棋](https://en.wikipedia.org/wiki/Draughts)人机对弈游戏。因为我对棋类运动比较感兴趣，所以做了这样一个简单的程序。原本打算使用机器学习算法完成这样一个功能，即随着人机对弈次数的增加，机器的对弈水平会越来越好，但是由于没有规划好时间，这一功能没有完成。在这个项目中我也尝试使用了几个在极客班中学到的设计模式，例如单例模式、策略模式、中介者模式等。总之，通过这个项目我感到学习到了很多内容。

## 编译运行

<pre><code>mkdir build
cd build
qmake ../SelfLearningCheckers.pro
make
</code></pre>

## 程序截图
![game shot](https://github.com/crest55/GeekBand-CPP-1501-Homework/blob/master/G2015010470/project/checkers.png)