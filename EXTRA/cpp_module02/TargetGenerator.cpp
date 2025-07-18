#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it_begin = this->arr_target.begin();
	std::map<std::string, ATarget *>::iterator it_end = this->arr_target.end();

	if (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}

	this->arr_target.clear();
}

void TargetGenerator::learnTargetType(ATarget *target_ptr)
{
	if (target_ptr)
		arr_target.insert(std::pair<std::string, ATarget *>(target_ptr->getType(), target_ptr->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &name)
{
	arr_target.erase(name);
}

ATarget *TargetGenerator::createTarget(std::string const &name)
{
	std::map<std::string, ATarget *>::iterator it = arr_target.find(name);
	if (it != arr_target.end())
		return arr_target[name];
	return NULL;
}
