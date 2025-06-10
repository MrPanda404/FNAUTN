#include "StateMachine.h"


void StateMachine::AddState(StateRef newState, bool isReplacing)
{
	this->isAdding = true;
	this->isReplacing = isReplacing;

	this->newState = std::move(newState);
}

void StateMachine::RemoveState()
{
	this->isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
	if (isRemoving && !states.empty())
	{
		states.pop();

		isRemoving = false;
	}

	if (isAdding) {
		if (!states.empty() && isReplacing) {
			states.pop();
		}
		states.push(std::move(newState));
		states.top()->Start();
		isAdding = false;
	}
}

StateRef& StateMachine::GetActiveState()
{
	return this->states.top();
}
