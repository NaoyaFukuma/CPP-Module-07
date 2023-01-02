/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:18:18 by nfukuma           #+#    #+#             */
/*   Updated: 2023/01/02 21:49:20 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
  private:
	T *arrPtr_;
	unsigned int size_;
	void checkIndex(unsigned int i) const;

  public:
	typedef unsigned int iterator;
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	~Array();

	bool empty() const;
	unsigned int size() const;
	iterator begin() const;
	iterator end() const;
	T &front();
	const T &front() const;
	T &back();
	const T &back() const;


	Array &operator=(const Array &rhs);
	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &arr)
{
	unsigned int size = arr.size();
	for (unsigned int i = 0; i < size; ++i)
		out << arr[i] << " ";
	return (out);
}

template <typename T>
Array<T>::Array()
	: arrPtr_(nullptr), size_(0)
{
	std::cout << "arrPtr address" << arrPtr_ << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
	: size_(n)
{
	try
	{
		this->arrPtr_ = new T[size_];
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
}

template <typename T>
Array<T>::Array(const Array &src)
	: size_(src.size())
{
	try
	{
		this->arrPtr_ = new T[size_];
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
	for (unsigned int i = 0; i < this->size_; ++i)
	{
		this->arrPtr_[i] = src.arrPtr_[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] arrPtr_;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
	if (this != &rhs)
	{
		if (this->size_ != rhs.size())
		{
			delete[] this->arrPtr_;
			this->size_ = rhs.size();
			try
			{
				this->arrPtr_ = new T[this->size_];
			}
			catch(const std::bad_alloc& e)
			{
				std::cerr << e.what() << '\n';
				std::exit(EXIT_FAILURE);
			}
		}
		for (unsigned int i = 0; i < size_; ++i)
			this->arrPtr_[i] = rhs.arrPtr_[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	this->checkIndex(i);
	return (this->arrPtr_[i]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	this->checkIndex(i);
	return (this->arrPtr_[i]);
}

template <typename T>
void Array<T>::checkIndex(unsigned int i) const
{
	if (i >= this->size())
	{
		std::cerr << "Error : Index is out of range.\nThe index you have tried to access. >>> [" << i << "]" << std::endl;
		std::cerr << "Accessible indexes were 0 to " << this->size() - 1 << "." << std::endl;
		throw std::exception();
	}
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->size_);
}

template <typename T>
bool Array<T>::empty() const
{
	return (this->size_ == 0);
}

template <typename T>
typename Array<T>::iterator Array<T>::begin() const
{
	return (0);
}

template <typename T>
typename Array<T>::iterator Array<T>::end() const
{
	return (this->size_);
}

template <typename T>
T &Array<T>::front()
{
	if (Array<T>::empty())
	{
		std::cerr << "Error : empty." << std::endl;
		throw std::exception();
	}
	return (this->arrPtr_[0]);
}

template <typename T>
const T &Array<T>::front() const
{
	if (Array<T>::empty())
	{
		std::cerr << "Error : empty." << std::endl;
		throw std::exception();
	}
	return (this->arrPtr_[0]);
}

template <typename T>
T &Array<T>::back()
{
	if (Array<T>::empty())
	{
		std::cerr << "Error : empty." << std::endl;
		throw std::exception();
	}
	return (this->arrPtr_[this->size_ - 1]);
}

template <typename T>
const T &Array<T>::back() const
{
	if (Array<T>::empty())
	{
		std::cerr << "Error : empty." << std::endl;
		throw std::exception();
	}
	return (this->arrPtr_[this->size_]);
}

#endif
