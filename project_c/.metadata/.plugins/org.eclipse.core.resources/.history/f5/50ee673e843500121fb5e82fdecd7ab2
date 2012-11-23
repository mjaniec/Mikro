#ifndef gp_Alloc_c
#define gp_Alloc_c
#include "..\..\Include\Alloc\gp_Alloc.h"

gpUByte _gpAlloc_allocated_memory[_gpAlloc_MAX_MEM];
gpUByte* _gpAlloc_after_last_allocated_index = _gpAlloc_allocated_memory;

gpUByte* _gpAlloc_nearestFreeSpace(gpInt);
gpUByte* _gpAlloc_freeSpaceInRange(gpInt, gpUByte*, gpUByte*);

gpVoid gpAlloc_free(gpVoid* ptr)
{
	$fun;
	gpUByte* start_ptr = ((gpUByte*) ptr) - sizeof(gpInt) + 1;
	gpInt size = *start_ptr;

	$assert (start_ptr >= _gpAlloc_allocated_memory, GP_MEMVIOL);
	$assert (start_ptr + size <= _gpAlloc_allocated_memory + _gpAlloc_MAX_MEM, GP_MEMVIOL);

	for(gpUByte* i = start_ptr; i < start_ptr + size + sizeof(gpInt); i++)
	{
		*i = 0;
	}
}

gpVoid* gpAlloc_alloc(gpInt size)
{
	$fun;

	if(size < 0)
	{

#ifdef DEBUG
	gp_errno = GP_EARG;
#endif

		return null;
	}

	gpUByte* freeSpace = _gpAlloc_nearestFreeSpace(size + sizeof(gpInt));
	if(freeSpace == null)
	{

#ifdef DEBUG
	gp_errno = GP_NOMEM;
#endif
		return null;
	}
	*((gpInt*)freeSpace) = size;
	_gpAlloc_after_last_allocated_index = freeSpace + size + sizeof(gpInt);
	return freeSpace + sizeof(gpInt) - 1;
}

gpUByte* _gpAlloc_nearestFreeSpace(gpInt size)
{
	gpUByte* rightBound = _gpAlloc_allocated_memory + _gpAlloc_MAX_MEM - 1;
	gpUByte* freeSpace = _gpAlloc_freeSpaceInRange(size, _gpAlloc_after_last_allocated_index, rightBound) $c;

	if(freeSpace != null)
	{
		return freeSpace;
	}

	return _gpAlloc_freeSpaceInRange(size, _gpAlloc_allocated_memory, _gpAlloc_after_last_allocated_index);
}


gpUByte* _gpAlloc_freeSpaceInRange(gpInt size, gpUByte* start, gpUByte* end)
{
	while(start + size - 1 <= end)
	{
		gpInt startValue = *start;
		if(startValue != 0)
		{
			start += startValue;
		}
		else
		{
			gpUByte* tmp = start;

			while(tmp <= start + size && *tmp == 0)
			{
				tmp++;
			}

			if(tmp == start + size + 1)
			{
				return start;
			}

			start = tmp;
		}
	}

	return null;
}
#endif
