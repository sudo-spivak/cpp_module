#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _hitPoints = 100;
    _maxHP = 100;
    _energyPoints = 50;
    _maxEP = 50;
    _level = 1;
    _meleeAttackDmg = 20;
    _rangedAttackDmg = 15;
    _armorReduction = 3;
    _name = "ScavTrap";
    _challenges[0] = &ScavTrap::_riddle1;
    _challenges[1] = &ScavTrap::_riddle2;
    _challenges[2] = &ScavTrap::_riddle3;
    _challenges[3] = &ScavTrap::_riddle4;
    _challenges[4] = &ScavTrap::_riddle5;
    std::cout << "\033[1;33m" << _name << ": Look out everybody! Things are about to get awesome! (Default constructor)\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name)
{
    _hitPoints = 100;
    _maxHP = 100;
    _energyPoints = 50;
    _maxEP = 50;
    _level = 1;
    _meleeAttackDmg = 20;
    _rangedAttackDmg = 15;
    _armorReduction = 3;
    _name = name;
    _challenges[0] = &ScavTrap::_riddle1;
    _challenges[1] = &ScavTrap::_riddle2;
    _challenges[2] = &ScavTrap::_riddle3;
    _challenges[3] = &ScavTrap::_riddle4;
    _challenges[4] = &ScavTrap::_riddle5;
    std::cout << "\033[1;33m" << _name << " : Glitching weirdness is a term of endearment, right? (Parametric constructor)\033[0m" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &a)
{
    _hitPoints = a._hitPoints;
    _maxHP = a._maxHP;
    _energyPoints = a._energyPoints;
    _maxEP = a._maxEP;
    _level = a._level;
    _meleeAttackDmg = a._meleeAttackDmg;
    _rangedAttackDmg = a._rangedAttackDmg;
    _armorReduction = a._armorReduction;
    _name = a._name;
    std::cout <<  "\033[1;33m" << _name << ": Recompiling my combat code! (Assignation operator)\033[0m" << std::endl;
    return (*this);
}

ScavTrap::ScavTrap(ScavTrap const &a)
{
    *this = a;
    _challenges[0] = &ScavTrap::_riddle1;
    _challenges[1] = &ScavTrap::_riddle2;
    _challenges[2] = &ScavTrap::_riddle3;
    _challenges[3] = &ScavTrap::_riddle4;
    _challenges[4] = &ScavTrap::_riddle5;
    std::cout <<  "\033[1;33m" << _name << ": This time it'll be awesome, I promise! (Copy constructor)\033[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[1;31m" << _name << ": No fair! I wasn't ready. (Destructor)\033[0m" << std::endl;
}

void    ScavTrap::rangedAttack(std::string const &target)
{
    std::cout << "\033[1;31m" << _name << " attacks " << target << " at range, causing ";
    std::cout << _rangedAttackDmg << " points of damage!\033[0m" << std::endl;
}

void    ScavTrap::meleeAttack(std::string const &target)
{
    std::cout << "\033[1;31m" << _name << " attacks " << target << " at melee, causing ";
    std::cout << _meleeAttackDmg << " points of damage!\033[0m" << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount)
{
    std::cout << "\033[1;31m(" << _hitPoints << " - " << amount << ") " << _name << ": ";
    if (amount <= _armorReduction)
        std::cout << "Block! Try once more!";
    else
    {
        if (amount > _hitPoints + _armorReduction)
            _hitPoints = 0;
        else
            _hitPoints += _armorReduction - amount;
        std::cout << "Why do I even feel pain?!";
    }
    std::cout << "(now is " << _hitPoints << ")\033[0m" << std::endl;
    if (_hitPoints == 0)
    {
        this->~ScavTrap();
    }
}

void    ScavTrap::beRepaired(unsigned int amount)
{
    std::cout << "\033[1;32m(" << _hitPoints << " + " << amount << ") " << _name << ": ";
    _hitPoints += amount;
    if (_hitPoints > _maxHP)
    {
        _hitPoints = _maxHP;
    }
    std::cout << "Healsies! (now is " << _hitPoints << ")\033[0m" << std::endl;
}

void	ScavTrap::_riddle1()
{
    std::string temp;

    std::cout << "Clean, but not water," << std::endl;
    std::cout << "White, but not snow," << std::endl;
    std::cout << "weet, but not ice-cream," << std::endl;
    std::cout << "What is it?" << std::endl;
    std::cout << "Your answer: ";
    std::cin >> temp;
    if (temp == "sugar")
        std::cout << "Nice!" << std::endl;
    else
        std::cout << "That was a close one!" << std::endl;
}

void	ScavTrap::_riddle2()
{
    std::string temp;

    std::cout << "I am always hungry," << std::endl;
    std::cout << "I must always be fed," << std::endl;
    std::cout << "The finger I touch," << std::endl;
    std::cout << "Will soon turn red" << std::endl;
    std::cout << "Your answer: ";
    std::cin >> temp;
    if (temp == "fire")
        std::cout << "Nice!" << std::endl;
    else
        std::cout << "That was a close one!" << std::endl;
}

void	ScavTrap::_riddle3()
{
    std::string temp;

    std::cout << "I’m lighther than a feather, yet the strongest man can’t hold me for more than 5 minutes." << std::endl;
    std::cout << "Your answer: ";
    std::cin >> temp;
    if (temp == "breathe")
        std::cout << "Nice!" << std::endl;
    else
        std::cout << "That was a close one!" << std::endl;
}

void	ScavTrap::_riddle4()
{
    std::string temp;

    std::cout << "If you have me, you want to share me. If you share me, you haven’t got me. What am I?" << std::endl;
    std::cout << "Your answer: ";
    std::cin >> temp;
    if (temp == "secret")
        std::cout << "Nice!" << std::endl;
    else
        std::cout << "That was a close one!" << std::endl;
}

void	ScavTrap::_riddle5()
{
    std::string temp;

    std::cout << "What do you fill with empty hands?" << std::endl;
    std::cout << "Your answer: ";
    std::cin >> temp;
    if (temp == "glove")
        std::cout << "Nice!" << std::endl;
    else
        std::cout << "That was a close one!" << std::endl;
}

void    ScavTrap::challengeNewcomer(std::string const &target)
{
    std::cout << "Loading combat packages!" << "\033[1;35m" << std::endl;

    std::cout << _name << " challenges " << target << "!" << std::endl;

    (this->*_challenges[std::rand() % 5])();

    std::cout << "\033[0m";
}
