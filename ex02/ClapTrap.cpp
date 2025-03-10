/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:54 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/04 11:34:16 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this=other;

    return ;
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
        std::cout << _name << " has no energy or hit points to attack!" << std::endl;
}

void ClapTrap::takeDamage(int amount)
{
    if (amount < 0) return;
        _hitPoints -= amount;
    if (_hitPoints < 0) _hitPoints = 0;
            std::cout << _name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << _name << " has been repaired by " << amount 
                  << " hit points! Energy left: " << _energyPoints << std::endl;
    }
    else
        std::cout << _name << " cannot be repaired due to lack of energy or hit points!" << std::endl;
}


ClapTrap & ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
	return (*this);
}

const std::string& ClapTrap::getName () const { return (this->_name) ; }
const int& ClapTrap::getHitPoints() const { return (this->_hitPoints) ; } 
const int&  ClapTrap::getEnergyPoints() const { return (this->_energyPoints) ; }
const int& ClapTrap::getAttackDamage() const { return (this->_attackDamage) ; }

void ClapTrap::setHitPoints(int nb) { this->_hitPoints = nb ;}
void ClapTrap::setEnergyPoints(int nb) { this->_energyPoints = nb ;}
void ClapTrap::setAttackDamage(int nb) { this->_attackDamage = nb ;}