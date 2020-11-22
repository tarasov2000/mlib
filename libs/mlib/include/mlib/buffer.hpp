#ifndef MLIB_BUFFER_HPP
#define MLIB_BUFFER_HPP

#include <ostream>
#include <functional>
#include <mlib/types.hpp>

namespace mlib {

	/*! Class for work with data-sets.
		Size = BUFFER_SIZE.
	*/
	class buffer {
	
		/*! Pointer to dataset. */
		number* m_data;
	public:
	
		/*! Creates data-set. */
		buffer();
		
		/*! Deletes data-set. */
		~buffer();

		/*! Copy data from `b` to this buffer.
			@param b - Other buffer.
			@return Pointer to this buffer.
		*/
		buffer& copy(const buffer& b);

		/*! Copy-constructor. */
		buffer(const buffer& b);
		
		/*! Copy-assigment. */
		buffer& operator=(const buffer& b);
	
		/*! Move-constructor. */
		buffer(buffer&& b) noexcept;
		
		/*! Move-assigment. */
		buffer& operator=(buffer&& b) noexcept;

		/*! Indexer. */
		inline number& operator [](size i) {
			return m_data[i];
		}
		
		/*! Constant indexer. */
		inline number operator [](size i) const {
			return m_data[i];
		}

		/*! Calls `cb` for all numbers on buffer.
			@param cb - Lambda for calling for all numbers on buffer.
			@return Refference on this buffer.
		*/
		buffer& foreach(std::function<number(number)> cb);
		
		/*! Calls `cb` for all numbers on this buffer and src buffer.
			@param src - Buffer for first parameter of lambda function.
			@param cb - Lambda for calling for all numbers on buffer.
			@return Refference on this buffer.
		*/
		buffer& foreach(const buffer& src,
			std::function<number(number, number)> cb);
			
		/*! Calls `cb` for all numbers on buffer.
			@param cb - Lambda for calling for all numbers on buffer.
			@return Refference on this buffer.
		*/
		buffer& fori(std::function<number(size)> cb);
		
		/*! Calls `cb` for all numbers on this buffer and src buffer.
			@param src - Buffer for first parameter of lambda function.
			@param cb - Lambda for calling for all numbers on buffer.
			@return Refference on this buffer.
		*/
		buffer& fori(const buffer& src, std::function<number(number, size)> cb);
		
		/*! Rise all numbers on buffer to `s` step.
			@param s - step.
			@return Refference on this buffer.
		*/
		buffer& pow(unsigned s);
		
		/*! Sum of all elements on buffer.
			@param src - Buffer for first parameter of lambda function.
			@return Sum of elements.
		*/
		number sum();
	};
	
	/*! Operator overloading for output buffer to `std::cout`. */
	std::ostream& operator <<(std::ostream& os, const mlib::buffer& d);
}

#endif /* MLIB_BUFFER_HPP */
