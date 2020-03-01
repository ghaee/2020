#include <random>

std::default_random_engine& global_urang(){
	static std::default_random_engine u{};
	return u;
}

void randomize(){
	static std::random_device rd{};
	global_urang().seed(rd());
}

int pick(int from, int thru){
	static std::uniform_int_distribution<> d{};
	using parm_t = decltype(d)::param_type;
	return d(global_urang(),parm_t{from,thru});
}

double pick(double from, double upto){
	static std::uniform_real_distribution<> d{};
	using parm_t = decltype(d)::param_type;
	return d(global_urang(),parm_t{from,upto});
}