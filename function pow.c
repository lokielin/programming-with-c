//剑指offer：数值的整数次方
/*note: 
1. 0的-double次方；
2. 怎么表示0
3. -double次方；
4. 16次方是8次方的平方，递归
*/
bool g_InvalidInput = false;
double Power(double base,int exponent)
{
	unsigned int absExponent = (unsigned int)(exponent);
	double result;
	g_InvalidInput = false;
	if(equal(base,0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	if(exponent < 0)
		absExponent = (unsigned int)(-exponent);		
	result = PowerWithUnsignedExponent(base,absExponent);
	if(exponent < 0)
		return (1.0/result);
	return result;
}
double PowerWithUnsignedExponent(double base, int exponent);
{
	double result;
	if(exponent == 1)
		return base;
	if(exponent == 0)
		return 1;
	result = PowerWithUnsignedExponent(base,exponent>>1);
	result *= result;
	if(exponent &0x01 == 1)
		result *= base;
	return result;
}
boot equal(double num1,double num2)
{
	if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else 
		return false;
}
