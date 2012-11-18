#include <gp_Alloc.h>
#include <gp_Math.h>

static gpUByte gp_allocated_memory[gp_MAX_MEM];
static gpUByte* after_last_allocated_index = gp_allocated_memory;

static gpUByte* nearestFreeSpace(gpInt);
static gpUByte* freeSpaceInRange(gpInt, gpUByte*, gpUByte*);

gpVoid gpAlloc_free(gpVoid* ptr)
{
	$fun;
	gpUByte* start_ptr = ((gpUByte*) ptr) - sizeof(gpInt) + 1;
	gpInt size = *start_ptr;

	$assert (start_ptr >= gp_allocated_memory, GP_MEMVIOL);
	$assert (start_ptr + size <= gp_allocated_memory + gp_MAX_MEM, GP_MEMVIOL);

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

	gpUByte* freeSpace = nearestFreeSpace(size + sizeof(gpInt));
	if(freeSpace == null)
	{

#ifdef DEBUG
	gp_errno = GP_NOMEM;
#endif
		return null;
	}
	*((gpInt*)freeSpace) = size;
	after_last_allocated_index = freeSpace + size + sizeof(gpInt);
	return freeSpace + sizeof(gpInt) - 1;
}

static gpUByte* nearestFreeSpace(gpInt size)
{
	gpInt* rightBound = gp_allocated_memory + gp_MAX_MEM - 1;
	gpInt* freeSpace = freeSpaceInRange(size, after_last_allocated_index, rightBound) $c;

	if(freeSpace != null)
	{
		return freeSpace;
	}

	return freeSpaceInRange(size, gp_allocated_memory, after_last_allocated_index);
}


static gpUByte* freeSpaceInRange(gpInt size, gpUByte* start, gpUByte* end)
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
