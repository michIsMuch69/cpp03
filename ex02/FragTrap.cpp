/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:54:59 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/03 20:12:27 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    setHitPoints(100);   
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
    std::cout << "FragTrap copy constructor called for " << getName() << "!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " has been destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other) 
    {
        ClapTrap::operator=(other); 
        std::cout << "FragTrap assignment operator called for " << getName() << "!" << std::endl;
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (getEnergyPoints() > 0 && getHitPoints() > 0)
    {
        std::cout << "FragTrap " << getName() << " attacks " << target 
                  << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);
        std::cout << "Energy left: " << getEnergyPoints() << std::endl;
    }
    else
        std::cout << getName() << " has no energy or hit points to attack!" << std::endl;
}

void FragTrap::highFiveGuys(void)
{
    std::cout << getName() << " is requesting a high five!" << std::endl;
}

