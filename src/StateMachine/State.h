#pragma once
class State
{
public:
	virtual ~State() = default;
	virtual void Start() = 0;
	virtual void HandleInput() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Stop() = 0;
};

