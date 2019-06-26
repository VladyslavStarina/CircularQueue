#include "integer_queue.hpp"
#include "test.hpp"
#include <iostream>
#include <cassert>

void Test1(IntegerQueue & _queue)
{
	IntegerQueueCreate(_queue, 10);
	assert(IntegerQueueIsEmpty(_queue));

	IntegerQueueDestroy(_queue);
}

void Test2(IntegerQueue & _queue)
{
	IntegerQueueCreate(_queue, 10);
	assert(IntegerQueueIsEmpty(_queue));

	IntegerQueuePush(_queue, 8);
	assert(IntegerQueueFront(_queue)== 8);

	IntegerQueueDestroy(_queue);
}

void Test3(IntegerQueue & _queue)
{
	IntegerQueueCreate(_queue, 5);
	assert(IntegerQueueIsEmpty(_queue));

	for(int i = 0; i < 5; i++ )
	{
		IntegerQueuePush(_queue, i);
	}
	assert(_queue.m_Size == 10);

	IntegerQueueDestroy(_queue);
}

void Test4(IntegerQueue & _queue)
{
	IntegerQueueCreate(_queue, 5);
	assert(IntegerQueueIsEmpty(_queue));

	for (int i = 0; i < 4; i++)
	{
		IntegerQueuePush(_queue, i);
	}
	assert(IntegerQueueIsFull(_queue));
	
	IntegerQueueClear(_queue);

	assert(IntegerQueueIsEmpty(_queue));
	
	IntegerQueueDestroy(_queue);
}

void Test5(IntegerQueue & _queue)
{
	IntegerQueueCreate(_queue, 5);
	assert(IntegerQueueIsEmpty(_queue));

	for (int i = 0; i < 6; i++)
	{
		IntegerQueuePush(_queue, i);
	}
	assert(_queue.m_Size == 10);

	IntegerQueueDestroy(_queue);
}

void Test6(IntegerQueue & _queue)
{
	IntegerQueueCreate(_queue, 10);
	assert(IntegerQueueIsEmpty(_queue));

	IntegerQueuePush(_queue, 8);
	assert(IntegerQueueFront(_queue) == 8);

	IntegerQueuePop(_queue);

	assert(IntegerQueueIsEmpty(_queue));

	IntegerQueueDestroy(_queue);
}

void Test7(IntegerQueue & _queue)
{
	IntegerQueueCreate(_queue, 5);
	assert(IntegerQueueIsEmpty(_queue));

	for (int i = 0; i < 6; i++)
	{
		IntegerQueuePush(_queue, i);
	}
	assert(_queue.m_Size == 10);

	for (int i = 0; i < 6; i++)
	{
		IntegerQueuePop(_queue);
	}

	assert(IntegerQueueIsEmpty(_queue));
	IntegerQueueDestroy(_queue);
}

void Test8(IntegerQueue & _queue)
{
	IntegerQueueCreate(_queue, 5);
	assert(IntegerQueueIsEmpty(_queue));

	for (int i = 0; i < 4; i++)
	{
		IntegerQueuePush(_queue, i);
	}

	for (int i = 0; i < 2; i++)
	{
		IntegerQueuePop(_queue);
	}
	for (int i = 0; i < 2; i++)
	{
		IntegerQueuePush(_queue, i);
	}
	assert(_queue.m_BackIndex < _queue.m_FrontIndex);
	IntegerQueueDestroy(_queue);
}

void Test9(IntegerQueue & _queue)
{
	IntegerQueueCreate(_queue, 5);
	assert(IntegerQueueIsEmpty(_queue));

	for (int i = 0; i < 4; i++)
	{
		IntegerQueuePush(_queue, i);
	}

	for (int i = 0; i < 3; i++)
	{
		IntegerQueuePop(_queue);
	}
	for (int i = 0; i < 7; i++)
	{
		IntegerQueuePush(_queue, i);
	}

	assert(_queue.m_BackIndex < _queue.m_FrontIndex);
	assert(_queue.m_Size == 10);
	assert(!IntegerQueueIsFull(_queue));

	IntegerQueueDestroy(_queue);
}

void Test10(IntegerQueue & _queue)
{
	IntegerQueueCreate(_queue, 5);
	assert(IntegerQueueIsEmpty(_queue));

	for (int i = 0; i < 4; i++)
	{
		IntegerQueuePush(_queue, i);
	}

	for (int i = 0; i < 2; i++)
	{
		IntegerQueuePop(_queue);
	}
	for (int i = 0; i < 2; i++)
	{
		IntegerQueuePush(_queue, i);
	}
	for (int i = 0; i < 3; i++)
	{
		IntegerQueuePop(_queue);
	}
	for (int i = 0; i < 3; i++)
	{
		IntegerQueuePush(_queue, i);
	}
	assert(_queue.m_BackIndex > _queue.m_FrontIndex);
	IntegerQueueDestroy(_queue);
}


