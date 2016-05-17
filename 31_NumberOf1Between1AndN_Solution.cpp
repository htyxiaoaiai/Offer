题目描述

求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

long NumberOf1Between1AndN_Solution (long long int n){
	//1的个数
	long long int count = 0;
	//当前位
	long long int Factor = 1;
	//低位数字
	long long int LowerNum = 0;
	//当前位数字
	long long int CurrNum = 0;
	//高位数字
	long long int HigherNum = 0;
	if(n <= 0){
		return 0;
	}
	while(n / Factor != 0){
		//低位数字
		LowerNum = n - (n / Factor) * Factor;
		//当前位数字
		CurrNum = (n / Factor) % 10;
		//高位数字
		HigherNum = n / (Factor * 10);
		//如果为0,出现1的次数由高位决定
		if(CurrNum == 0){
			//等于高位数字 * 当前位数
			count += HigherNum * Factor;
		}
		//如果为1,出现1的次数由高位和低位决定
		else if(CurrNum == 1){
			//高位数字 * 当前位数 + 低位数字 + 1
			count += HigherNum * Factor + LowerNum + 1;
		}
		//如果大于1,出现1的次数由高位决定
		else{
			//（高位数字+1）* 当前位数
			count += (HigherNum + 1) * Factor;
		}
		//前移一位
		Factor *= 10;
	}
	return count;
}
