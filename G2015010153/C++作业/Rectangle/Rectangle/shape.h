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
		// д�������д����������
		virtual ~Shape() {}
		// why shap* p = new rectange(); delete p;
		// �ᵼ�� rectange�ڴ�й¶

	friend class Rectangle;
	};

}

#endif