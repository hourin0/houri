#include <typedefs.h>


I32 search_array(const UI32 value,const UI32* array,const UI32 len) {
	UI32 i;
	for (i=0;i<len;i++)
		if (array[i]==value)
			return i; //return index if found
	return -1; //return -1 if not found
}

UI8 is_sorted(const UI32* array,const UI32 len) {
	UI8 state=1;
	for (UI32 i=0;i<len-1;i++)
		if (array[i]>array[i+1]) {
			state=2;
			break;
		}
	if (state==2) {
		for (UI32 i=0;i<len-1;i++)
			if (array[i]<array[i+1]) {
				state=0;
				break;
			}
	}
	return state;
}

UI0 bubble_sort(const UI32* array,const UI32 len) {


}
