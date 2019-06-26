#ifndef _INTEGER_QUEUE_HPP_
#define _INTEGER_QUEUE_HPP_

struct IntegerQueue
{
	int * m_pData;
	int m_Size;
	int m_FrontIndex;
	int m_BackIndex;
};

void IntegerQueueCreate(IntegerQueue & _queue, int size);

void IntegerQueueDestroy(IntegerQueue & _queue);

void IntegerQueueClear(IntegerQueue & _queue);

bool IntegerQueueIsEmpty(IntegerQueue & _queue);

bool IntegerQueueIsFull(IntegerQueue & _queue);

void IntegerQueuePush(IntegerQueue & _queue, int _value);

void IntegerQueuePop(IntegerQueue & _queue);

int IntegerQueueFront(const IntegerQueue & _queue);

void IntegerQueueGrow(IntegerQueue & _queue);

void IntegerQueueMidGrow(IntegerQueue & _queue, int *& newData);

void IntegerQueueBackGrow(IntegerQueue & _queue, int *& newData);

int IntegerQueueNextIndex(IntegerQueue & _queue, int _index);

int identifyOrder(IntegerQueue & _queue);

#endif 
