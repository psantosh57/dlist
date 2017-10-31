/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
Filename: dlist.h
-----------------------------------------------------------------*/
#ifndef dlist_h
#define dlist_h

#include "../util/util.h"

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
template <typename T>
class node ;

template <typename T>
class dlist ;

template <typename T>
class dlist_iterator ;

template <typename T>
class node {

public:

	node(T& data) : _data(data), _next(nullptr), _ptr(nullptr) {

		cout << "In node const" << endl;

	}

	~node() {

		cout << "In node dest" << endl;

		_next = 0;

	}

	//Cannot copy or equate node object
	node(const node& n) = delete;
	node operator=(const node& n) = delete;

	friend class dlist<T>;
	friend class dlist_iterator<T>;


private:

	T _data;
	node<T>* _next;
	node<T>* _ptr;

};

template <typename T>
class dlist {

public:

	dlist(bool display, void(*df) (T& d) = nullptr, int(*cf)(const T& lhs, const T& rhs) = nullptr): _ptr_to_func_to_del_obj(df), _ptr_to_func_to_cmp_obj(cf), 
	_first(nullptr), _last(nullptr), _num_obj_added(0), _num_obj_freed(0), _display(verbose) {

		cout << "In dlist const" << endl;
	}

	~dlist() {

		cout << "In dlist dest" << endl;

		_first = 0;
		_last = 0;
	}

	void append(T& d);
	void append1(T& d);
	node<T>* _createNode(T& d);
	int size() { return _num_obj_added; };
	void display();
	T& get_data(int index);

private:

	node<T>* _first;
	node<T>* _last;
	void(*_ptr_to_func_to_del_obj) (T& d);
	int(*_ptr_to_func_to_cmp_obj) (const T& lhs, const T& rhs);
	int _num_obj_added;
	int _num_obj_freed;
	bool _display;

};


#include "dlist.hpp"
#endif

//EOF

