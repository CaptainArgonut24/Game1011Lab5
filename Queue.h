#pragma once
#ifndef __DYNAMIC_QUEUE_H__
#define __DYNAMIC_QUEUE_H__


template<typename variable_type>
class DynamicQueue
{
public:
	// Constructor!
	DynamicQueue()
	{
		front = rear = nullptr;
	}

	// Custom Destructor!
	~DynamicQueue()
	{
		Clear();
	}

	// Puts another variable in the queue and sets the rear to the new variable.
	void Enqueue(variable_type value)
	{
		if (IsEmpty())
		{
			front = new QueueNode(value);
			rear = front;
		} else {
			rear->next = new QueueNode(value);
			rear = rear->next;
		}
	}

	// Removes the front variable in the queue and sets the front to the next variable down the list.
	variable_type Dequeue()
	{
		variable_type value = front->value;
		QueueNode* temp = front;
		front = front->next;
		delete temp;
		temp = nullptr;
		return value;
	}

	bool IsEmpty()
	{
		return (front == nullptr);
	}

	void Clear()
	{
		while (!IsEmpty())
		{
			Dequeue();
		}
	}
private:
	class QueueNode
	{
		friend class DynamicQueue;
		variable_type value;
		QueueNode* next;

		// Node class used in the queue.
		QueueNode(variable_type value, QueueNode* next = nullptr)
		{
			this->value = value;
			this->next = next;
		}
	};


	// Nodes used to track the front and rear of the queue.
	QueueNode* front;
	QueueNode* rear;
};

#endif //!__DYNAMIC_QUEUE_H__