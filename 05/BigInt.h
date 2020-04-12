#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#pragma once

class BigInt {
	char* number;
	bool minus;

    BigInt sum(const BigInt& num1, const BigInt& num2);
    BigInt subtract(const BigInt& num1, const BigInt& num2);
    bool isSmaller(const char* str1, const char* str2); 
		
	public:	
		BigInt();		
		BigInt(int i);		
		BigInt(const char* i);		
		~BigInt();
		
		char i2c(int x);
		int c2i(char x);
		
		BigInt& operator=(int i);
		BigInt& operator=(const BigInt& i);
		
		BigInt operator-();
		BigInt operator+(const BigInt& i);
		BigInt operator-(const BigInt& i);
		BigInt operator+(const int i);
		BigInt operator-(const int i);
			
		bool operator==(const BigInt& i);
		bool operator!=(const BigInt& i);
	    bool operator<(const BigInt& i);
	    bool operator<=(const BigInt& i);
	    bool operator>(const BigInt& i);
	    bool operator>=(const BigInt& i);
	    
	    friend std::ostream& operator<< (std::ostream& os, const BigInt& dt);
};
