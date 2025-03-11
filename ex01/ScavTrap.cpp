/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:54:59 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/11 11:18:43 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    return ;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    
    setHitPoints(100);   
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " created with " << getHitPoints() << " hit points," << getEnergyPoints() << " energy points, and " << getAttackDamage() << " attack damage!" << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " has been destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap assignment operator called" << std::endl;
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (getEnergyPoints() > 0 && getHitPoints() > 0)
    {
        std::cout << "ScavTrap " << getName() << " attacks " << target 
                  << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
        std::cout << "Energy left: " << getEnergyPoints() << std::endl;
    }
    else
        std::cout << getName() << " has no energy or hit points to attack!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " is now in Guard Gate mode!" << std::endl;
}
