#pragma once
#ifndef __DYNAMIC_STACK_H__
#define __DYNAMIC_STACK_H__


// Templated Stack class!
template<typename variable_type>
class DynamicStack
{
public:
	DynamicStack()
	{
		top = nullptr;
	}

	// Pushes a variable to the top of the stack.
	void Push(variable_type value)
	{
		top = new StackNode(value, top);
	}

	// "Pop"s or deletes the top variable in the stack
	variable_type Pop()
	{
		variable_type temp_value = top->value;
		StackNode* temp_node = top;
		top = top->next;
		delete temp_node;
		temp_node = nullptr;
		return temp_value;
	}

	// If top is null our stack is also empty.
	bool IsEmpty()
	{
		return (top == nullptr);
	}
private:
	// Node class that stores the next variabel + value, like a linked list!
	class StackNode
	{
		friend class DynamicStack;
		variable_type value;
		StackNode* next;

		// Constructor
		StackNode(variable_type value, StackNode* next = nullptr)
		{
			this->value = value;
			this->next = next;
		}
	};

	// Top variable in the stack.
	StackNode* top;
};

#endif //!__DYNAMIC_STACK_H__