//vector_template.cpp
template<typename T>
class vector{
	public: 
		explicit vector(int size)
		: my_size(size), data(new T[my_size])
		{ }

		vector(const vector& that)
		: my_size(that.my_size), data(new T[my_size])
		{
			std::copy(&that.data[0],&data[0])
		}

		int size() const{ return my_size ;}

		const T& operator[](int i) const{
			check_index(i);
			return data[i];
		}

		//...

	private:
		int my_size;
		std::unique_ptr<T[]> data;
};