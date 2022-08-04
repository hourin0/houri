#pragma once
#define ARRAY_H

I32 search_array(const UI32 value,const UI32* array,const UI32 len);

UI8 is_sorted(const UI32* array,const UI32 len); 
/*
return 	1 for sorted smaller->greater
	2 for sorted greater->smaller
	0 for unsorted
*/
UI0 bubble_sort(const UI32* array,const UI32 len);
UI0 selection_sort(const UI32* array,const UI32 len);
