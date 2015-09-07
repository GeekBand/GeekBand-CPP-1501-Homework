#ifndef __SHAPE__
#define __SHAPE__

namespace Geekband
{

	class Shape;

	class Shape
	{
		int no;
	public:
		Shape(int no) { this->no = no; }
		// 写基类必须写虚析构函数
		virtual ~Shape() {}
		// why shap* p = new rectange(); delete p;
		// 会导致 rectange内存泄露

	friend class Rectangle;
	};

}

#endif