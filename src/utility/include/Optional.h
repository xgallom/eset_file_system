//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_OPTIONAL_H
#define ESET_FILE_SYSTEM_OPTIONAL_H

#include <utility>

template<typename T>
class Optional {
public:
	constexpr Optional() = default;

	explicit constexpr Optional(const T &a_value) :
			m_valid(true),
			m_value(a_value)
	{}

	explicit constexpr Optional(T &&a_value) :
			m_valid(true),
			m_value(std::move(a_value))
	{}

	constexpr const T &operator()() const
	{ return m_value; }

	constexpr T &operator()()
	{ return m_value; }

	void set(const T &a_value)
	{
		m_value = a_value;
		m_valid = true;
	}

	explicit constexpr operator bool() const
	{ return m_valid; }

private:
	bool m_valid = false;
	T m_value = {};
};

template<typename T>
Optional<T> optional(const T &value)
{
	return Optional<T>(value);
}

#endif //ESET_FILE_SYSTEM_OPTIONAL_H
