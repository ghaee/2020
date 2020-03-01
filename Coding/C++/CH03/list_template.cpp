//sum of the indices of
//list_template.cpp

template<typename T>
struct list_entry
{
	list_entry(const T& value) : value(value),next(0){ }
	T 	value;
	list_entry<T>* next;
};

template<typename T>
struct list_iterator
{
	using value_type = T;

	list_iterator(list_entry<T>* entry) :entry(entry){ }

	T& operator*() {return entry->value;}

	const T& operator*() const{
		return entry->value;
	}

	list_iterator<T>& operator++(){
		entry = entry->next; return *this;
	}

	bool operator!=(const list_iterator<T>& other) const{
		return entry != other.entry;
	}

	list_entry<T>* entry;
};

template<typename T>
struct list
{
	list(): first(0), last(nullptr){ }
	~list(){
		while(first){
			list_entry<T>* tmp = first->next;
			delete first;
			first = tmp;
		}
	}

	void append(const T& x){
		last = (first? last->next : first) = new list_entry<T>(x);
	}
	list_entry<T> *first,*last;
	list_iterator<T> begin() {return list_iterator<T>(first);}
	list_iterator<T> end() {return list_iterator<T>(0);}
};
