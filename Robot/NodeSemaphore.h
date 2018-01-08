#ifndef NODESEMAPHORE_H
#define NODESEMAPHORE_H

#pragma once
class NodeSemaphore
{
private:
	int Value;
public:
	NodeSemaphore(int InitialValue);
	NodeSemaphore();
	~NodeSemaphore();
	void Wait();
	void Signal();
};

#endif
