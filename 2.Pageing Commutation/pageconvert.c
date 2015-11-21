#include <stdio.h>
# define PAGE_SIZE 4096

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

unsigned int getPhyAddrByFormula(unsigned int logicAddr)
{
	unsigned int page = logicAddr/4096;
	unsigned int offset = logicAddr%4096;
	return getPhyPage(page)+offset;
}

unsigned int getPhyAddrByRude(unsigned int logicAddr)
{
	return getPhyPage(logicAddr>>12)<<12+logicAddr<<19>>19;
}

int main()
{
	unsigned int logicAddr = 90008;
	printf("%d",getPhyAddrByFormula(logicAddr));
	printf("%d",getPhyAddrByRude(logicAddr));
}