#ifndef __GP_VECTOR_C
#define __GP_VECTOR_C
#include "../../Include/Base/gp.h"


gpVoid	gpVector_init(gpVector*self){
	$fun;
	self->size=0;
	self->capacity=8;
	self->data=gpAlloc_alloc(sizeof(gpVoid*)*self->capacity)$r;
}

gpVoid  gpVector_destroy(gpVector*self){
	$fun;
	for(int i=0; i<self->size; ++i){
		gpAlloc_free(self->data[i])$r;
	}
	gpAlloc_free(self->data)$r;
}

gpInt	gpVector_getSize(gpVector*self){
	$fun;
	return self->size;
}
gpVoid* gpVector_at(gpVector*self,gpInt index){
	$fun;
	$assert0 (0<=index && index<self->size, GP_EINDEX);
	return self->data[index];
}
gpVoid	gpVector_clean(gpVector *self){
	$fun;
	for(int i=0; i<self->size; ++i){
		gpAlloc_free(self->data[i])$r;
	}
	gpAlloc_free(self->data)$r;

	self->size=0;
	self->capacity=8;
	self->data=gpAlloc_alloc(sizeof(gpVoid*)*self->capacity)$r;
}

gpVoid _gpVector_Resize(gpVector *self, int newCapacity){
	$fun;
	gpVoid**newData=gpAlloc_alloc(sizeof(gpVoid*)*newCapacity)$r;
	for(int i=0; i<self->size; ++i)
		newData[i]=self->data[i];
	gpAlloc_free(self->data)$r;
	self->data=newData;
	self->capacity=newCapacity;
}

gpVoid  gpVector_pushBack(gpVector *self, gpVoid*what, gpInt size){
	$fun;
	$assert(what!=null,GP_ENULLPTR);
	$assert(size>0,GP_EARG);
	if(self->size==self->capacity)_gpVector_Resize(self,self->capacity*2)$r;
	self->data[self->size]=gpAlloc_alloc(size)$r;
	gpAlloc_copy(what,self->data[self->size],size)$r;
	self->size++;
}

gpVoid gpVector_popBack(gpVector *self, gpVoid*where, gpInt size){
	$fun;
	$assert(where!=null,GP_ENULLPTR);
	$assert(self->size>0,GP_EINDEX);
	$assert(size>0,GP_EARG);
	self->size--;
	gpAlloc_copy(self->data[self->size],where,size)$r;
	gpAlloc_free(self->data[self->size])$r;

}

#endif
