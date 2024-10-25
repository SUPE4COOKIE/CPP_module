#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	subject_main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

int	custom_main(void)
{
	ICharacter	*Salut = new Character("Salut");
	ICharacter	*Coucou = new Character("Coucou");

	IMateriaSource	*source = new MateriaSource();
	Ice		*item1 = new Ice();
	Cure	*item2 = new Cure();

	source->learnMateria(item1);
	source->learnMateria(item2);

	Salut->equip(source->createMateria("cure"));
	Salut->equip(source->createMateria("ice"));
	for (int i = 0; i < 5; i++)
		Salut->equip(source->createMateria("cure"));

	Coucou->equip(source->createMateria("cure"));
	Coucou->equip(source->createMateria("ice"));

	Salut->use(0, *Coucou);
	Salut->use(1, *Coucou);
	
	Coucou->use(0, *Salut);
	Coucou->use(3, *Salut);
	Coucou->use(99, *Salut);

	Salut->unequip(0);
	Coucou->unequip(0);

	Coucou->unequip(99);


	delete (source);
	delete (Salut);
	delete (Coucou);

	return (0);
}

int	main(void)
{
	subject_main();
	std::cout << "\n---------------------------\n" << std::endl;
	custom_main();

	return (0);
}
