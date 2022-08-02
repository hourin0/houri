#pragma once

#define true 1
#define false 0

typedef UI8 B;

B flip(B val);


B flip(B val) {
	if (val==true)
		return false;
	else
		return true;

}
