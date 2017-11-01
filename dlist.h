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

	node(T& data) : _data(data), _ptr(nullptr) {}

	~node() {

		_ptr = 0;

	}

	//Cannot copy or equate node object
	node(const node& n) = delete;
	node operator=(const node& n) = delete;

	friend class dlist<T>;
	//friend class dlist_iterator<T>;


private:

	T _data;
	//node<T>* _next;
	node<T>* _ptr;

};

#if 0
template <typename T>
class dlist_iterator {

public:

	dlist_iterator(node<T>* x = nullptr, dlist<T>& d = false) : _current(x), _prev(nullptr), _obj(d) {};
	~dlist_iterator() {};

	T& operator*() {

		return (_current->_data);

	}

	dlist_iterator<T>& operator++() {

		//_current++;
		node<T>* temp = _prev;
		_prev = _current;
		_current = (node<T>*) ((uintptr_t)_p1 ^ (uintptr_t)_current->_ptr);

		return _current;

	}

	dlist_iterator<T>& operator++(int k) = delete;
	dlist_iterator<T>& operator--(int k) = delete;
	dlist_iterator<T>& operator--() = delete;


private:

	node<T>* _current;
	node<T>* _prev;
	dlist<T> _obj;


};

#endif // 0

template <typename T>
class dlist {

	typedef dlist_iterator<T> iterator;

public:

	dlist(bool display, void(*df) (T& d) = nullptr, int(*cf)(const T& lhs, const T& rhs) = nullptr): _ptr_to_func_to_del_obj(df), _ptr_to_func_to_cmp_obj(cf), 
	_first(nullptr), _last(nullptr), _num_obj_added(0), _num_obj_freed(0), _display(verbose) {

		cout << "In dlist const" << endl;
	}

	~dlist() {

		cout << "In dlist dest" << endl;

		node<T>* f = _first;
		node<T>* prev = nullptr;
		node<T>* next = (node<T>*)((uintptr_t)prev ^ (uintptr_t) f->_ptr);
		while (f) {

			node<T>* t = f;
			//node<T>* p = prev;
			//f = f->_next
			f = (node<T>*)((uintptr_t)prev ^ (uintptr_t)f->_ptr);
			prev = t;
			deleteNode(t);
			//node<T>* temp = prev;
			//prev = f;
			//f = next;
			
		}

		assert(_num_obj_added == _num_obj_freed);

		_first = 0;
		_last = 0;
	}

	void append(T& d);
	void append1(T& d);
	node<T>* _createNode(T& d);
	int size() { return _num_obj_added; };
	void display();
	T& get_data(int index);
	void deleteNode(node<T>* t);

	//Iterator methods
	//iterator begin() { return (iterator)(_first); }
	//iterator end() { return (iterator)(); }

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

