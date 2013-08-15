/*double pow(doubel base, int exponent)*/

bool g_InvalidInput = false;
double power(double base, int exponent){
	g_InvalidInput = false;
	//0 as demoninator
	//double value maybe has different value
	if(equal(base, 0.0) || exponent < 0){
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = exponent;
	//exponent = -2^32, maybe more than int range(-2^32, 2^32-1)
	//so use unsigned int
	if(absExponent < 0)
		absExponent = -exponent;
	double result = powerPositive(base, absExponent);
	if(absExponent != exponent)
		result = 1/result;
	return result;
}
double powerPositive(double base, unsigned int absExponent){
	//special case
	if(absExponent == 0){
		return 1;
	}
	double result;
	if(absEponent & 1 == 1){
		result = base;
	}
	double recurResult = powerPositive(base, absExponent>>1);
	result *= recurResult * recurResult;
	return result;
}
bool equal(double value1, double  value2){
	if( value1 - value2 > 0.0000001 || value2 - value1< 0.0000001 ){
		return true;
	}
	return false;
}
