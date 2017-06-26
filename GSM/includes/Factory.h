#pragma once
#include <memory>
#include "DynArr.h"

class IPrototype;

class Factory
{
public:
	Factory();
	~Factory();

	void addPrototype(std::shared_ptr<IPrototype> prototype);

	std::shared_ptr<IPrototype> create(const char* name);

private:
	DynArr<std::shared_ptr<IPrototype>> m_prototypes;
};

