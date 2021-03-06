/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
Filename: dlist.hpp
-----------------------------------------------------------------*/

template <typename T>
node<T>* dlist<T>::_createNode(T& d) {

	node<T>* n = new(node<T>)(d);

	return n;
}

template <typename T>
void dlist<T>::append(T& d) {

	_num_obj_added++;
	node<T>* temp = _createNode(d);

	node<T>* f = _first;
	node<T>* prev = nullptr;
	node<T>* end = nullptr;

	//Case for empty list
	if (!_first) {

		_first = temp;
		_first->_ptr = nullptr;
		_last = temp;
	}
	else {

		//Get the last but 1 node
		prev = (node<T>*)((uintptr_t)_last->_ptr ^ (uintptr_t) nullptr);
		_last->_ptr = (node<T>*)((uintptr_t) prev ^ (uintptr_t) temp);
		temp->_ptr = _last;
		_last = temp;

	}
}

template <typename T>
void dlist<T>::display() {

	node<T>* i = _first;
	node<T>* prev = nullptr;
	node<T>* next = (node<T>*)((uintptr_t)prev ^ (uintptr_t)i);
	while (next) {

		cout << _i << endl;
	}

}

template <typename T>
T& dlist<T>::get_data(int index) {

	node<T>* f = _first;
	node<T>* prev = nullptr;

	node<T>* next = (node<T>*)((uintptr_t)prev ^ (uintptr_t)f->_ptr);
	while (next && index) {

		node<T>* temp = prev;
		prev = f;
		f = next;
		next = (node<T>*)((uintptr_t)prev ^ (uintptr_t)f->_ptr);
		index--;
	}

	return f->_data;

}

template <typename T>
void dlist<T>::deleteNode(node<T>* t) {
	_num_obj_freed++;
	if (_ptr_to_func_to_del_obj) {

		_ptr_to_func_to_del_obj(t->_data);
	}

	delete(t);

}

//EOF

