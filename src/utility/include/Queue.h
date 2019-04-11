//
// Created by xgallom on 4/5/19.
//

#ifndef ESET_FILE_SYSTEM_QUEUE_H
#define ESET_FILE_SYSTEM_QUEUE_H

#include <utility>

template<typename Container>
class Queue {
public:
	inline bool isEmpty() const
	{ return m_index.empty(); }

	inline void reserve(typename Container::size_type size)
	{ m_index.reserve(size); }

	inline void clear()
	{ m_index.clear(); }

	inline void enqueue(typename Container::const_reference value)
	{ m_index.emplace_back(value); }

	inline auto dequeue()
	{
		const auto value = m_index.front();
		erase();

		return value;
	}

	inline auto dequeueAll()
	{ return std::move(m_index); }

	inline void erase()
	{ m_index.erase(m_index.begin()); }

	inline auto begin()
	{ return m_index.begin(); }

	inline auto begin() const
	{ return m_index.begin(); }

	inline auto end()
	{ return m_index.end(); }

	inline auto end() const
	{ return m_index.end(); }

	inline auto front() const
	{ return m_index.front(); }

	inline auto front()
	{ return m_index.front(); }

private:
	Container m_index = {};
};

#endif //ESET_FILE_SYSTEM_QUEUE_H
