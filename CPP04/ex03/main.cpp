#include "Character.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void	test1()
{
	std::cout << "\n==========| TEST 1 |==========\n\n";

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
}

void	test2()
{
	std::cout << "\n==========| TEST 2 |==========\n";

	std::cout << "\nMateriaSource :\n\n";
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	MateriaSource* copy = new MateriaSource(*src);
	//MateriaSource* copy = new MateriaSource();
	//*copy = *src;
	copy->learnMateria(new Cure());

	std::cout << "\nsrc ("<< src <<") :\n";
	AMateria *m1 = src->createMateria("cure");

	std::cout << "\ncopy ("<< copy <<") :\n";
	AMateria *m2 = copy->createMateria("ice");

	delete src;
	std::cout << "\nDeleted src and still can use copy because its a deep copy:\n";
	AMateria *m3 = copy->createMateria("ice");

	std::cout << "\nEvery materia has diferent addresses:\n";
	std::cout << "m1 (" << m1 << ")\n";
	std::cout << "m2 (" << m2 << ")\n";
	std::cout << "m3 (" << m3 << ")\n";
	delete copy;

	std::cout << "\nCharacters (using AMaterias from above) :\n\n";
	Character* quim = new Character("Quim");
	Character* barreiros = new Character("Barreiros");
	Cure* cure = new Cure();

	quim->equip(m2);
	quim->equip(cure);
	barreiros->equip(m3);

	*barreiros = *quim;

	std::cout << "\nBarreiros now has Quim's name and Quim's AMaterias but they use different \
addresses:\n\n";

	barreiros->use(0, *quim);
	barreiros->use(1, *quim);

	std::cout << "Quim (" << quim << ")\n";
	std::cout << "Barreiros (" << barreiros << ")\n";

	delete quim;
	delete barreiros;

	std::cout << "\nThis test wont have leaks even though we didn't delete m3\n" <<\
		"This is because when using the \"=\" operator on Barreiros all Materias were deleted\n";
}

void	test3()
{
	std::cout << "\n==========| TEST 3 |==========\n\n";
	Character* vasco = new Character("Vasco");
	Character* gama = new Character("Gama");
	Ice *ice1 = new Ice();
	Ice *ice2 = new Ice();
	Cure *cure1 = new Cure();
	Cure *cure2 = new Cure();
	Cure *cure3 = new Cure();

	vasco->equip(ice1);
	vasco->equip(ice2);
	vasco->equip(cure1);
	vasco->equip(cure2);
	vasco->equip(cure3);
	vasco->unequip(1);
	vasco->unequip(3);

	gama->use(0, *vasco);
	gama->equip(ice2);
	gama->equip(cure2);
	gama->use(0, *vasco);
	(void)gama;

	delete vasco;
	delete gama;
	delete cure3;
}

int main()
{
	test1();
	test2();
	test3();
}
