#include <iostream>
#include <cassert>
#include <cstdint>
#include <sstream>
#include <cstring>
#pragma once

enum class Error {
    NoError,
    CorruptedArchive
};

class Serializer {
	
   	std::ostream& out_;

	public:
	    explicit Serializer(std::ostream& out) : out_(out) {}
	
	    template <class T>
	    Error save(T& object) {
	        return object.serialize(*this);
	    }
		
	    template <class... ArgsT>
	    Error operator()(ArgsT... args) {
	        return process(args...);
	    }
	
	private:
		Error err;
    	static constexpr char Separator = ' ';
    	
	    template<class T>
	    Error process(T val) {
	        return print(val);
	    }

	    template<class T, class ...Args>
	    Error process(T val, Args ...args) {
	    	err = print(val);
	        if (err == Error::NoError) {
	            return process(args...);
			}
	        else
	            return Error::CorruptedArchive;
	    }
	    
	    Error print(bool a) {
	    	if (a) out_ << "true" << Separator;
	    	else out_ << "false" << Separator;
	    	return Error::NoError;
		}
		
		Error print(uint64_t a) {
			out_ << a << Separator;
			return Error::NoError;
		}
};


class Deserializer {
	
   	std::istream& in_;

	public:
	    explicit Deserializer(std::istream& in) : in_(in) {}
	
	    template <class T>
	    Error load(T& object) {
	        return object.serialize(*this);
	    }
	
	    template <class... Args>
	    Error operator()(Args&... args) {
	        return process(args...);
	    }
	
	private:
		static constexpr char Separator = ' ';
	    Error err;
	    
	    template<class T>
	    Error process(T& val) {
	    	return read_from_stream(val);
	    }
	    
	    template<class T, class ...Args>
	    Error process(T& val, Args& ...args) {
	 		err = read_from_stream(val);
	 	    if (err == Error::NoError)
	            return process(args...);
	        else
	            return Error::CorruptedArchive;
	    }
	    
	    Error read_from_stream(bool& a) {
			std::string text;
		    in_ >> text;
		    if (text == "true")
		        a = true;
		    else if (text == "false")
		    	a = false;
		    else
		        return Error::CorruptedArchive;
		    return Error::NoError;
		}
		
		Error read_from_stream(uint64_t& a) {
			std::string text;
		    in_ >> text;
		
		    if (is_number(text)) 
		    	a = std::stoi(text);
		    else
		        return Error::CorruptedArchive;
		    return Error::NoError;
		}
		
		bool is_number(const std::string& s) {
		    return (strspn( s.c_str(), "0123456789" ) == s.size());
		}
   
};

