/* largeint.h : interface of the LargeInt class
   multiple precision integer arithmetic
   Copyright (C) 1994 John K. Gotwals
   -------------------------------------------- */
class LargeInt {
friend LargeInt divRem(const LargeInt& u, const LargeInt& v, LargeInt* r);
friend char* evalFrac(const LargeInt& u, const LargeInt& v, int precision,
	char* dest, int lim);

public:
	LargeInt();
	LargeInt(int num);
	LargeInt(unsigned num);
	LargeInt(const char* str);
	LargeInt(const LargeInt& lint);
	~LargeInt() {delete [] adr;}
	int lintLen() {return len;}
	int operator==(const LargeInt& lint) const;
	int operator==(int num) const;
	int operator<(const LargeInt& lint) const;
	int operator<(int num) const;
	const LargeInt& operator=(const LargeInt& lint);
	const LargeInt& operator=(int num);
	const LargeInt& operator=(unsigned num);
	const LargeInt& operator=(const char* str);
	LargeInt operator+(const LargeInt& lint) const;
	LargeInt operator-(const LargeInt& lint) const;
	LargeInt operator*(const LargeInt& lint) const;
	LargeInt operator/(const LargeInt& lint) const;
	LargeInt operator%(const LargeInt& lint) const;
	LargeInt operator-() const; // unary minus
	void operator*=(int num);
	void powerTwo(int power);
	char* binToDec(char* dest, int lim) const;
	void decToBin(const char* str);
	void lintDump() const;

private:
	int* adr;	// address of most significant digit
	int len;	// number of radix-2^32 digits
	int	sign;	// 1 ==> +; 0 ==> zero; -1 ==> -
	LargeInt(int digits, int fill);
	void normalize();
};

/* manifest constants and other misc items
   --------------------------------------- */
const LargeInt tenTo9  = 1000000000u;
const int intTenTo9    = 1000000000u;
	// change both to 10^18 for 64-bit machine
const LargeInt zero    = 0;
const LargeInt one     = 1;
const LargeInt two     = 2;
const int numBitsStar3 = sizeof(int) * 8 * 3;
const int PackFactor   = numBitsStar3 / 10;
	// log of 2 to base 10 is approx. 3/10

/* int version of memcmp()
   ----------------------- */
inline int memcmpInt(const int* u, const int* v,
  		int n) {
   while (n--) {
      if (*u != *v)
         return ((unsigned)*u < (unsigned)*v)? -1 : 1;
      u++;
      v++;
   }
   return 0;
}

/* LargeInt function prototypes
   ---------------------------- */
LargeInt sqrt(const LargeInt& lint);
