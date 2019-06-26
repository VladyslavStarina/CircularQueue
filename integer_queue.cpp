#include "integer_queue.hpp"
#include <iostream>
#include <cassert>

void IntegerQueueCreate(IntegerQueue & _queue, int size)
{
	_queue.m_Size = size;
	_queue.m_pData = new int[_queue.m_Size];
	_queue.m_BackIndex = 0;
	_queue.m_FrontIndex = 0;
}

void IntegerQueueDestroy(IntegerQueue & _queue)
{
	delete[] _queue.m_pData;
}

void IntegerQueueClear(IntegerQueue & _queue)
{
	_queue.m_BackIndex = 0;
	_queue.m_FrontIndex = 0;
}

bool IntegerQueueIsEmpty(IntegerQueue & _queue)
{
	return identifyOrder(_queue) == 0;
}

bool IntegerQueueIsFull(IntegerQueue & _queue)
{
	return (identifyOrder(_queue) == (_queue.m_Size - 1));
}

void IntegerQueuePush(IntegerQueue & _queue, int _value)
{
	IntegerQueueGrow(_queue);
	_queue.m_pData[_queue.m_BackIndex] = _value;
	_queue.m_BackIndex = IntegerQueueNextIndex(_queue, _queue.m_BackIndex);
}

void IntegerQueuePop(IntegerQueue & _queue)
{
	assert(!IntegerQueueIsEmpty(_queue));
	_queue.m_FrontIndex = IntegerQueueNextIndex(_queue, _queue.m_FrontIndex);
}

int IntegerQueueFront(const IntegerQueue & _queue)
{
	return _queue.m_pData[_queue.m_FrontIndex];
}

void IntegerQueueGrow(IntegerQueue & _queue)
{
	if(IntegerQueueIsFull(_queue))
	{	
		int newSize = _queue.m_Size * 2;
		int *newData = new int[newSize];

		IntegerQueueMidGrow(_queue, newData);
		IntegerQueueBackGrow(_queue, newData);	

		delete[] _queue.m_pData;

		_queue.m_pData = newData;
		_queue.m_Size = newSize;
	}
}

void IntegerQueueMidGrow(IntegerQueue & _queue, int *& newData)
{
	if (_queue.m_FrontIndex > _queue.m_BackIndex)
	{
		for (int i = _queue.m_FrontIndex; i < _queue.m_Size; i++)
		{
			newData[_queue.m_Size + i] = _queue.m_pData[i];
		}

		for (int i = 0; i < _queue.m_BackIndex; i++)
		{
			newData[i] = _queue.m_pData[i];
		}

		_queue.m_FrontIndex += _queue.m_Size;
	}
}

void IntegerQueueBackGrow(IntegerQueue & _queue, int *& newData)
{
	if (_queue.m_FrontIndex < _queue.m_BackIndex)
	{
		memcpy(newData, _queue.m_pData, sizeof(int)*_queue.m_Size);
	}
}

int IntegerQueueNextIndex(IntegerQueue & _queue, int _index)
{
	int index = _index + 1;
	if (index == _queue.m_Size)
	{
		index = 0;
	}

	return index;
}

int identifyOrder(IntegerQueue & _queue)
{
	return (_queue.m_FrontIndex <= _queue.m_BackIndex) ?
		_queue.m_BackIndex - _queue.m_FrontIndex :
		_queue.m_BackIndex + _queue.m_Size - _queue.m_FrontIndex;
}
