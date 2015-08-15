## 题目
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

## 交作业

[Rectangel － ideone](http://ideone.com/spAROD)

## Build & Run

`$ cd src`
<br/>
`$ c++ -Wall Rectangle-demo.cpp -o demo`
<br/>
`./demo`
