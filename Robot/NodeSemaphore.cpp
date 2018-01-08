#include "NodeSemaphore.h"


NodeSemaphore::NodeSemaphore(int InitialValue)
{
	Value = InitialValue;
}

NodeSemaphore::NodeSemaphore()
{
	
}


NodeSemaphore::~NodeSemaphore()
{
}

void NodeSemaphore::Wait()
{

	// Once here we decrement the state
	Value--;
}

void NodeSemaphore::Signal()
{
	// State increment
	Value++;
}
