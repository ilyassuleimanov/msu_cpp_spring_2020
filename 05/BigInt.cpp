#include "BigInt.h"

BigInt::BigInt() {
	minus = false;
	number = nullptr;
}

BigInt::BigInt(int i) {
	minus = i >= 0 ? false : true;
	char* tmp = new char[11];
	sprintf(tmp, "%d", i > 0 ? i : -i);
	number = tmp;
	number[strlen(number)] = '\0';
}

BigInt::BigInt(const char* i) {
	if (i[0] == '-') {
		minus = true;
		number = new char[strlen(i)];
		std::copy(i + 1, i + strlen(i), number);
		number[strlen(i)] = '\0';
	}
	else {
		minus = false;
		number = new char[strlen(i) + 1];
		std::copy(i, i + strlen(i), number);
		number[strlen(i)] = '\0';
	}
}


BigInt::~BigInt() {
	delete[] number;
}

int BigInt::c2i(char x) {
   return x - '0';
}

char BigInt::i2c(int x) {
	return x + '0';
}

bool BigInt::isSmaller(const char* str1, const char* str2) { // comparing modules 
    int n1 = strlen(str1), n2 = strlen(str2); 
  
    if (n1 < n2) 
        return true; 
    else if (n1 > n2)
        return false; 
  	else {
  		for (int i=0; i<n1; i++) { 
	        if (str1[i] < str2[i]) 
	            return true; 
	        else if (str1[i] > str2[i]) 
	            return false; 
	    } 
	  }
    return false; 
} 

BigInt BigInt::subtract(const BigInt& num1, const BigInt& num2) {
    char* str1 = num1.number;
    char* str2 = num2.number;
    if (isSmaller(str1, str2)) {
    	auto tmp = str1;
    	str1 = str2;
    	str2 = tmp;
	}
  	char* str = new char[strlen(str1) * 20]; 
    int n1 = strlen(str1), n2 = strlen(str2); 
    int diff = n1 - n2; 
    int carry = 0; 
    int j = 0;
    for (int i=n2-1; i> -1; --i) { 
        int sub = ((str1[i+diff]-'0') - 
                   (str2[i]-'0') - 
                   carry); 
        if (sub < 0) { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0;   
        str[j] = sub + '0';
		++j; 
    } 
  	int i;
    for (i=n1-n2-1; i>-1; i--) { 
        if (str1[i]=='0' && carry) { 
            str[j] = '9'; 
            ++j;
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) { 
            str[j] = sub+'0';
			}
            ++j;
        carry = 0;  
    } 
  	++i;

    for (i = 0; i < strlen(str) / 2; i++) {
        char t = str[i];
        str[i] = str[strlen(str) - i - 1]; 
        str[strlen(str) - i - 1] = t;
    } 
  	BigInt tmp(str);
    return tmp; 
} 

bool BigInt::operator!=(const BigInt& num) {
	return !(*this == num);
}

bool BigInt::operator<=(const BigInt& num) {
	bool tmp, tmp1;
	if (this->minus && !num.minus)
		return true;
	if (!this->minus && num.minus)
		return false;
	else
		tmp = isSmaller(this->number, num.number);
	if (tmp)
		return tmp;
	else
		tmp1 = isSmaller(num.number, this->number);
	if (!tmp1)
		return true;
	return false;
}

bool BigInt::operator>(const BigInt& num) {
	if (!this->minus && num.minus)
		return true;
	if (this->minus && !num.minus)
		return false;
	else
		return isSmaller(num.number, this->number);
}

bool BigInt::operator>=(const BigInt& num) {
	bool tmp, tmp1;
	if (!this->minus && num.minus)
		return true;
	if (this->minus && !num.minus)
		return false;
	else
		tmp = isSmaller(num.number, this->number);
	if (tmp)
		return tmp;
	else
		tmp1 = isSmaller(this->number, num.number);
	if (!tmp1)
		return true;
	return false;
}

bool BigInt::operator<(const BigInt& num) {
	if (this->minus && !num.minus)
		return true;
	if (!this->minus && num.minus)
		return false;
	else
		return isSmaller(this->number, num.number);
}

BigInt BigInt::sum(const BigInt& num1, const BigInt& num2) {
    int i, wa=strlen(num1.number), wb=strlen(num2.number), width, sum, carry = 0;
    width = wa > wb ? wa : wb; 
    char* answer = new char[width + 2];
    for(i=0; i<width; i++){
        int ca, cb;
		if (i < strlen(num1.number)) {
        ca = c2i(num1.number[strlen(num1.number) - i - 1]);	
		}
		else ca = 0;
        if (i < strlen(num2.number)) {
        	cb = c2i(num2.number[strlen(num2.number) - i - 1]);
		}
		else cb = 0;
        sum = ca + cb + carry;
        carry = 0;
        if(sum > 9){ 
            carry = 1;
            sum-=10;
        }
        answer[i] = sum+48;
    }   
    if(carry) 
		answer[i] = carry+48;
	++i;
    answer[i]= '\0';
    for (i = 0; i < strlen(answer) / 2; ++i) {
        char t = answer[i];
        answer[i] = answer[strlen(answer) - i - 1]; 
        answer[strlen(answer) - i - 1] = t;
    }   
    BigInt temp = answer;
    return temp;
}

BigInt BigInt::operator- () {
    BigInt tmp (this->number);
    tmp.minus = !tmp.minus;
    return tmp;
}

BigInt& BigInt::operator=(const BigInt& i) {
	if (this == &i)
        return *this;
	minus = i.minus;
	delete[] number;
	char* tmp = new char[strlen(i.number) + 1];
	number = tmp;
	std::copy(i.number, i.number + strlen(i.number), number);
	number[strlen(i.number)] = '\0';
	number = tmp;
	return *this;
}

BigInt& BigInt::operator=(int i) {
	minus = i >= 0 ? false : true;
	char* tmp = new char[11];
	sprintf(tmp, "%d", i > 0 ? i : -i);
	number = tmp;
	number[strlen(number)] = '\0';
}

BigInt BigInt::operator-(const int num) {
	BigInt tmp(num);
	return *this - tmp;
}

BigInt BigInt::operator+(int num) {
	BigInt tmp(num);
	return *this + tmp;
}

BigInt BigInt::operator+(const BigInt& num){

	if (minus && num.minus) {
        return -sum(*this, num);
    }

    if (minus && !num.minus) {
        if (isSmaller(number, num.number)) {
        	return subtract(num, *this);
		}
		else {
			return -subtract(*this, num);
		}
    }

    if (!minus && num.minus) {
        if (isSmaller(number, num.number)) {
        	return -subtract(num, *this);
		}
		else {
			return subtract(*this, num);
		}
    }

    else {
        return sum(*this, num);
    }
}

bool BigInt::operator==(const BigInt& i) {
	if (this == &i) {
		return true;
	}
	if (minus != i.minus)
		return false;
	if (strlen(number) != strlen(i.number))
		return false;
	for (size_t j = 0; j != strlen(number); ++j) {
		if (number[j] != i.number[j])
			return false;
	}
	return true;
}

BigInt BigInt::operator- (const BigInt& num) {
    if (*this == num) {
    	BigInt tmp(0);
    	return tmp;
	}
    if (minus && num.minus) {
        if (isSmaller(number, num.number)) {
        	return subtract(num, *this);
		}
		else {
			return -subtract(*this, num);
		}
    }

    if (minus && !num.minus) {
		return -sum(*this, num);
    }

    if (!minus && num.minus) {
        return sum(*this, num);
    }

    else {
        if (isSmaller(number, num.number)) {
        	return -subtract(num, *this);
		}
		else {
			return subtract(*this, num);
		}
    }
}


std::ostream& operator<<(std::ostream& os, const BigInt& dt)
{
	if (dt.minus) {
		os << "-";
	}
	if (dt.number[0] == '0') 
		std::cout << '0';
	else
	    os << dt.number;
    return os;
}
