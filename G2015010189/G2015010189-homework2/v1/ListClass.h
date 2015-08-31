#pragma once
//#define ListNodePointer(T) ListNode<T>* 
template <typename T> struct ListNode
{
//member
	T data;
	ListNode<T>* succ;
	ListNode<T>* pred;
// 构造函数等
	ListNode(){}
	ListNode(T e, ListNode<T>* p = nullptr, ListNode<T>* s = nullptr): data(e), pred(p), succ(s){}
};
 template <typename T> class List
 {
 private:
	 int _size;
	 ListNode<T>* ListHeader;
	 ListNode<T>* trailer;
 public:
	 void init();
	 int clear();
	 List(){ init(); }
	 ~List();
	 ListNode<T>* first() const{ return ListHeader->succ; }
	 ListNode<T>* last() const{ return trailer->pred; }
	 ListNode<T>* operator[](int r)const;
	 ListNode<T>* insertElement(T const& e);
	 T removeElement(ListNode<T>* p);
	 int get_size(){ return _size; }
 };

 template <typename T> void List<T>::init()
 {
	 ListHeader = new ListNode<T>(0);
	 trailer = new ListNode<T>(0);
	 ListHeader->succ = trailer;
	 ListHeader->pred = nullptr;
	 trailer->pred = ListHeader;
	 trailer->succ  = nullptr;
	 _size = 0;
 }

 template <typename T> ListNode<T>* List<T>::operator[](int r)const
 {
	 ListNode<T>* p = first();
	 while(0<r--) 
		 p = p->succ;
	 return p;
 }

 template <typename T> ListNode<T>* List<T>::insertElement(T const& e)
 {
	 ListNode<T>* x = new ListNode<T>(e);
	 x->pred =  trailer->pred;
	 trailer->pred->succ = x;
	 trailer->pred = x;
	 x->succ = trailer;
	 _size++;
	 return x;
 }

 template <typename T>T List<T>::removeElement(ListNode<T>* p)
 {
	 T e = p->data;
	 p->pred->succ = p->succ;
	 p->succ->pred = p->pred;
	 delete p;
	 _size--;
     return e;
 }


 template <typename T> int List<T>::clear()
 {
	 int oldSize = _size;
	 while(_size > 0) removeElement(trailer->pred);
	 return oldSize;
 }

 template <typename T> List<T>::~List()
 {
	 if(trailer->data !=  ListHeader->data)
	 {
	 clear();
	 }
	 if(ListHeader->pred  != ListHeader->succ)
	 {
	 delete ListHeader;
	 ListHeader = nullptr;
	 }
	 if(trailer->pred !=  trailer->succ)
	 {
	 delete trailer;
	 trailer = nullptr;
	 }
	 
	 _size = 0;
 }
