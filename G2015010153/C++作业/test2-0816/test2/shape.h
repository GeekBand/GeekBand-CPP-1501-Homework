#ifndef _SHAPE_H_
#define _SHAPE_H_

namespace Geekband
{
	class Shape
	{
		int no;

	public:
		Shape(int no = 0) { this->no = no; }

		void setNo(int no) { this->no = no; }
		int getNo() const { return this->no; }

		virtual double getArea() const = 0;
		virtual ~Shape() {}
	};

}

#endif