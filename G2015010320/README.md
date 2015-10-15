## 第一次作业
### 题目
为下面的 Rectangle 类实现构造函数,拷贝构造函数,赋值操作符,析构函数。

```
class Shape 
{  
  int no; 
};

class Point 
{
  int x;
  int y; 
};

class Rectangle: public Shape {
  int width;
  int height;
  Point * leftUp;
public:
  Rectangle(int width, int height, int x, int y); 
  Rectangle(const Rectangle& other);
  Rectangle& operator=(const Rectangle& other); 
  ~Rectangle();
};

```

### 交作业

[Rectangle － ideone](http://ideone.com/spAROD)

### Build & Run

`$ cd src/001`
<br/>
`$ c++ -Wall Rectangle-demo.cpp -o demo`
<br/>
`$ ./demo`

----
## 第二次作业
### 题目
为下面的 Rectangle 和 Circle 类重写 getArea 虚函数。然后创建一个数组。 使用一个循环,生成 10 个 Rectangle、10 个 Circle,根据循环遍历顺序为它 们设置 no 编号,位置、长、宽、半径等其他信息取随机 1~10 之间的整数值, 然后将它们加入到创建好的数组中。最后,将这个长度为 20 的数组中所有面 积小于 50 的形状删除。将剩下的形状组成一个新的数组返回。
<p/>
**注意:** 

1. 补齐任务所需的其他函数。
2. 考虑正确的内存管理。
3. 使用原生数 组,不使用 vector 等容器。

```
class Shape
{
  int no;
  public:
  virtual int getArea()=0;
};

class Point {
  int x;
  int y; 
};

class Rectangle: public Shape
{
  int width;
  int height;
  Point leftUp; 
};

class Circle: public Shape
{
  Point center; 
  int radius;
};
```

### 交作业
[Shape － ideone](http://ideone.com/oIubwe)

### Build & Run
`$ cd src/002` <br/>
`$ c++ -Wall client.cpp -o client` <br/>
`$ ./client`


----
## 第三次作业
### 题目
考虑一个文件分割器的设计。MainForm 为界面类,收集用户输入的文件路径, 和分割数量。 <br/>
FileSplitter 为实现文件分割的类型,其中 Split()实现文件分割 算法。

1. 要求为 Split()支持多种文件分割算法(至少 3 种), 在 MainForm 中灵活切换多种算法。
2. 在 Split()分割过程中,实现对进度条的实时通知, 即对 progressBar 的赋值。 
3. 使用松耦合面向对象设计方法和思想,无需编写 具体算法实现,可使用伪码表示设计。
<p/>

```
class MainForm: public Form {
  TextBox* txtFilePath; 
  TextBox* txtFileNumber; 
  ProgressBar* progressBar;

public:
  void Button1_Click() {
  } 
};

class FileSplitter {
  string filePath; 
  int fileNumber;
public:
  void Split() {
  } 
};

```

### 交作业
[Split － ideone](http://ideone.com/bjltxZ)

### Build & Run
`$ cd src/003` <br/>
`$ c++ -Wall main.cpp -o main` <br/>
`$ ./main`

