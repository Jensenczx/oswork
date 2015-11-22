/*second commit: 1.加法运算通过位运算实现 2.物理页号，通过数组索引 3.改正移位运算错误*/
#include <stdio.h>
#include <stdlib.h>

# define PAGE_SIZE 4096

//获得物理页号
unsigned int getPhyPage(unsigned int page)
{
	switch(page)
	{
		case 0:return 32102;
		case 1:return 443217;
		case 2:return 6723;
		case 3:return 8985;
		case 4:return 11238;
		case 5:return 29065;
		case 6:return 234205;
		case 7:return 45812;
		case 8:return 240561;
		case 9:return 300451;
		default:exit(1);
	}
}
//通过位运算实现加法
unsigned int addByByte(unsigned int num1,unsigned int num2)
{
	int tmp;
	do{
		int tmp = num1^num2;
		num2 = (num1&num2)<<1;
		num1 = tmp;
	}while(num2);
	return tmp;
}
//通过索引获得物理页号
unsigned int getPhyPageByArray(unsigned int page)
{
	int pageIndex[]={32102,443217,6723,8985,11238,29065,234205,45812,240561,300451};
	return pageIndex[page];
}
//通过函数计算获取物理页号
unsigned int getPhyAddrByFormula(unsigned int logicAddr)
{
	unsigned int page = logicAddr/PAGE_SIZE;
	unsigned int offset = logicAddr%PAGE_SIZE;
	return getPhyPageByArray(page)+offset;
}
//通过蛮力比对法获取物理地址
unsigned int getPhyAddrByRude(unsigned int logicAddr)
{
	return addByByte((getPhyPageByArray(logicAddr>>12)<<12),((logicAddr<<20)>>20));
}

int main()
{
	unsigned int logicAddr = 90008;
	printf("%d",getPhyAddrByFormula(logicAddr));
	printf("%d",getPhyAddrByRude(logicAddr));
}
