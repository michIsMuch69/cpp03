/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:00 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/11 11:45:46 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

void testClapTrap()
{
    
    ClapTrap ct("Clap");
    std::cout << RED << "Début de la simulation pour ClapTrap " << ct.getName() << "...\n" << std::endl;
    
    while (ct.getEnergyPoints() > 0 && ct.getHitPoints() > 0)
    {
        ct.attack("Roger");
        ct.takeDamage(3);
        ct.beRepaired(5);
    
        if (ct.getEnergyPoints() == 0)
        {
            std::cout << ct.getName() << " n'a plus de points d'énergie." << std::endl;
            break;
        }
    }
    
    std::cout << "\nSimulation terminée. État final de ClapTrap " << ct.getName() << " :" << std::endl;
    std::cout << "Points de vie : " << YELLOW << ct.getHitPoints() << RESET << ", Points d'énergie : " << YELLOW <<ct.getEnergyPoints()  << RESET << std::endl << std::endl;
    return ;
}

void testScavTrap()
{
    std::cout << GREEN;
    ScavTrap st("Scav");
    
    std::cout <<  "Début de la simulation pour ScavTrap " << st.getName() << "...\n" << std::endl;
    
    st.guardGate();
    while (st.getEnergyPoints() > 0 && st.getHitPoints() > 0)
    {
        st.attack("Roger");
        st.takeDamage(10);
        st.beRepaired(7);
    
        if (st.getEnergyPoints() == 0)
        {
            std::cout << st.getName() << " n'a plus de points d'énergie." << std::endl;
            break;
        }
    }
    
    std::cout << "\nSimulation terminée. État final de ScavTrap " << st.getName() << " :" << std::endl;
    std::cout << "Points de vie : " << YELLOW << st.getHitPoints() << RESET << ", Points d'énergie : " << YELLOW <<st.getEnergyPoints()  << RESET << std::endl << std::endl;
    
    
    
    return ;
}

int main(void)
{
    
    testClapTrap();
    std::cout << RESET;
    testScavTrap(); 
    std::cout << RESET;
        
    
}

