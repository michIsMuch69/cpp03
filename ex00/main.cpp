/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:00 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/03 15:49:21 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap ct("Joe");

    std::cout << "Starting simulation for ClapTrap " << ct.getName() << "...\n" << std::endl;

    while (ct.getEnergyPoints() > 0 && ct.getHitPoints() > 0)
    {
        ct.attack("Roger");
        ct.takeDamage(3);
        ct.beRepaired(5);

        if (ct.getEnergyPoints() == 0)
        {
            std::cout << ct.getName() << " has no energy points left." << std::endl;
            break;
        }
    }

    std::cout << "\nSimulation ended. Final state of ClapTrap " << ct.getName() << ":" << std::endl;
    std::cout << "Hit points: " << ct.getHitPoints() << ", Energy points: " << ct.getEnergyPoints() << std::endl;

    return 0;
}
