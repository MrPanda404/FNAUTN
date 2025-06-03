#include "StateMachine.h"

void StateMachine::addState(StateRef newState, bool isReplacing)
{
	this->isAdding = true;
	this->isReplacing = isReplacing;

	this->newState = std::move(newState);
}

void StateMachine::removeState()
{
	this->isRemoving = true;
}

void StateMachine::processStateChanges()
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

StateRef& StateMachine::getActiveState()
{
	return this->states.top();
}
