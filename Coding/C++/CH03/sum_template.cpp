//sum_template.cpp

template<typename T> //list_sum
T sum(const list<T>& l){
	T sum = 0;
	for (auto entry = l.first; entry != nullptr; entry = entry->next)
		sum += entry->value;
	return sum;
}

template<typename T> //array_sum
inline T accumulate_array(T* a, T* a_end){
	T sum(0);
	for(; a != a_end; ++a)
		sum += *a;
	return sum;
}

template<typename Iter, typename T> //sum of both array and list
inline T accumulate(Iter it, Iter end, T init){
	for(; it != end; ++it)
		init += *it;
	return init;
}