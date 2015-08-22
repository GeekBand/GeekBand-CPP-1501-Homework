//
//  Rectangle.h
//  Rect
//


#ifndef __Rect__Rectangle__
#define __Rect__Rectangle__

#include <stdio.h>




#include <iostream>

class Shape {
private:
    int no;
public:
    Shape(int n = 0) : no(n) {}
    void setNo(int n){
        this->no = n;
    }
    int getNo() const{
        return no;
    }
//    ~Shape(){
//        std::cout<<"~Shape:"<<getNo()<<")\n";
//    }
};
class Point {
private:
    int x;
    int y;
public:
    Point(int x = 0,int y = 0):x(x),y(y){}
    void set(int x,int y){
        this->x = x;
        this->y = y;
    }
    void set(const Point& p){
        set(p.x,p.y);
    }
    int getX() const{
        return x;
    }
    int getY() const{
        return y;
    }
};
class Rectangle: public Shape
{
private:
    int width;
    int height;
    Point * leftUp;
public:
    Rectangle(int x = 0, int y = 0,int width = 0, int height = 0, int no = 0):width(width),height(height),Shape(no) {
        this->leftUp = new Point(x,y);
    }
    Rectangle(const Rectangle& other):Shape() {
        set(other);
    }
    Rectangle& operator=(const Rectangle& other){
        set(other);
        return *this;
    }
    ~Rectangle(){
        if (leftUp!=nullptr) {
            delete leftUp;
            leftUp = nullptr;
        }
//        std::cout<<"~Rectangle:"<<getNo()<<")\n";
    }
    void set(const Rectangle& other){
        
        setNo((other).getNo());
        this->width = other.width;
        this->height = other.height;
        this->leftUp->set(*(other.leftUp));
    }
    
    void set(int x = 0, int y = 0,int width = 0, int height = 0){
        this->width = width;
        this->height = height;
        if(this->leftUp!=nullptr){
            this->leftUp->set(x,y);
        }else{
            this->leftUp = new Point(x,y);
        }
    }
    int getX() const{
        return this->leftUp->getX();
    }
    int getY() const{
        return this->leftUp->getY();
    }
    int getWidth() const{
        return this->width;
    }
    int getHeight() const{
        return this->height;
    }
    void print(){
        std::cout<<"[Rectangle:("<<getNo()<<")"<<"("<<getX()<<","<<getY()<<","<<getWidth()<<","<<getHeight()<<")]\n";
    }
    static void testRectangle(){
        
        Rectangle r = Rectangle();
        r.setNo(1);
        r.print();
        
        
        Rectangle* r2 = new Rectangle();
        r2->setNo(2);
        r2->print();
        
        Rectangle* r3 = new Rectangle(1,2,3,4,3);
        r3->print();
        
        std::cout<<"---r4---\n";
        Rectangle r4;
        r4.print();
        
        std::cout<<"---r5---\n";
        Rectangle r5;
        r5 = *r3;
        r5.print();
        std::cout<<"---r6---\n";
        
        Rectangle r6;
        r6.set(r5);
        r6.print();
        
        std::cout<<"---r7-1-\n";
        Rectangle r7;
        r7 = r5;
        r7.print();
        std::cout<<"---r7-2-\n";
        r7 = *r3 = r;
        r.print();
        r3->print();
        r7.print();
        
        delete r3;
        delete r2;
        
        
    }

};


/**
 ---testRectangle---
 
 
 [Rectangle:(1)(0,0,0,0)]
 [Rectangle:(2)(0,0,0,0)]
 [Rectangle:(3)(1,2,3,4)]
 ---r4---
 [Rectangle:(0)(0,0,0,0)]
 ---r5---
 [Rectangle:(3)(1,2,3,4)]
 ---r6---
 [Rectangle:(3)(1,2,3,4)]
 ---r7-1-
 [Rectangle:(3)(1,2,3,4)]
 ---r7-2-
 [Rectangle:(1)(0,0,0,0)]
 [Rectangle:(1)(0,0,0,0)]
 [Rectangle:(1)(0,0,0,0)]
 */


#endif /* defined(__Rect__Rectangle__) */
