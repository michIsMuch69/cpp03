/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:54 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/12 08:59:21 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
{
    return ;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " created with " << _hitPoints << " hit points, " << _energyPoints << " energy points, and " <<  _attackDamage << " attack damage!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this=other;
    return ;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called for " << _name << std::endl;    
}

ClapTrap & ClapTrap::operator=(ClapTrap const &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
        std::cout << "Energy left: " << _energyPoints << std::endl;
    }
    else
    {
        std::cout << _name << " has no energy or hit points to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
    {
        _hitPoints -= amount;
        if (_hitPoints < 0)
            _hitPoints = 0;
        std::cout << _name << " took " << amount << " damage. Hit points left: " << _hitPoints << std::endl;
    }
    else
    {
        std::cout << _name << " has no hit points left!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << _name << " got repaired, regaining " << amount << " hit points. Hit points: " << _hitPoints << std::endl;
        std::cout << "Energy left: " << _energyPoints << std::endl;
    }
    else
        std::cout << _name << " cannot be repaired due to lack of energy or hit points!" << std::endl;
}

const int& ClapTrap::getEnergyPoints() const
{
    return _energyPoints;
}

const int& ClapTrap::getHitPoints() const
{
    return _hitPoints;
}

const std::string& ClapTrap::getName() const
{
    return _name;
}
