#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it_begin = this->arr_spell.begin();
	std::map<std::string, ASpell *>::iterator it_end = this->arr_spell.end();

	if (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}

	this->arr_spell.clear();
}

void SpellBook::learnSpell(ASpell *aspell_ptr)
{
	if (aspell_ptr)
		arr_spell.insert(std::pair<std::string, ASpell *>(aspell_ptr->getName(), aspell_ptr->clone()));
}

void SpellBook::forgetSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = arr_spell.find(name);
	if (it != arr_spell.end())
		delete it->second;
	arr_spell.erase(name);
}

ASpell *SpellBook::createSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = arr_spell.find(name);
	if (it != arr_spell.end())
		return arr_spell[name];
	return NULL;
}
