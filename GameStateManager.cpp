// 
// 
// 

#include "GameStateManager.h"




GameStateManagerClass::GameStateManagerClass() : current(&GameStateWaitingLoveTouch)
{
	
}

void GameStateManagerClass::Entry()
{
	if (this->current == nullptr) { return; }

	this->current = &GameStateWaitingLoveTouch;
	this->current->Entry();
}

IState * GameStateManagerClass::Do()
{
	if (this->current == nullptr) { return; }

	IState *next = this->current->Do();
	if (this->current != next) {
		this->current->Exit();
		next->Entry();
		this->current = next;
	}
	
	return this;
}

void GameStateManagerClass::Exit()
{
	if (this->current == nullptr) { return; }
	this->current->Exit();
}


GameStateManagerClass GameStateManager;



