#include <Header.h>

namespace str {
	static bool is_braces(const char& s) {
		return
			s == '{' ? true :
			s == '}' ? true :
			false;
	}
	static bool is_comma(const char& s) {
		return	s == ',' ? true : false;
	}
	decltype(auto) is_hyphen{ [] <typename T>(T && s) {
		if constexpr (std::is_same_v<T, char>) {
			return s == '-' ? true : false;
		}
		else {
			return std::forward<T>(s) == "-" ? true : false;
		}
		return true;
	}
	};
	template<typename T>
	static T to_decimal(const std::string& str) {
		if constexpr (std::is_same_v<T, double>) {
			return std::atof(str.data());
		}
		else if constexpr (std::is_same_v<T, int>) {
			return std::atoi(str.data());
		}
	}
	static double string_to_double(const std::string& str) {
		return std::atof((str
			| ranges::views::replace_if(is_comma, '.')
			| ranges::to<std::string>).data());
	}
}