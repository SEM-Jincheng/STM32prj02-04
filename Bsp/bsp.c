#include "includes.h"

void BSPInit(void)
{
	LEDInit();
	KEYInit();
	EXTIKeyInit();
	BEEPInit();
}