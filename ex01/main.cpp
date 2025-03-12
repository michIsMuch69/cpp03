/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:00 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/12 10:14:20 by jedusser         ###   ########.fr       */
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

    std::cout << "Test copy constructor and assignment operator" << std::endl;

    ClapTrap a("sam");
    ClapTrap b(a);

    std::cout   << "Test copy constructor on ClapTrap" << std::endl
                << GREEN "Original attributes :" << std::endl
                << a.getName() << std::endl
                << a.getHitPoints() << std::endl
                << a.getEnergyPoints() << std::endl
                << a.getAttackDamage()
                << RESET << std::endl;
                
    std::cout   << YELLOW  << "Copy attributes :"
                <<  b.getName() << std::endl
                << b.getHitPoints() << std::endl
                << b.getEnergyPoints() << std::endl
                << b.getAttackDamage()
                << RESET  << std::endl;
    
    a.setAttackDamage(2000);
    std::cout   << "attack damage after change on a " 
                << a.getAttackDamage() << std::endl;
    
    std::cout   << "attack damage after change on b " 
                << b.getAttackDamage() << std::endl;




    ScavTrap original("Joe");
    ScavTrap copy(original);
    ScavTrap assign = copy;

    std::cout << "Test copy constructor on ScavTrap" << std::endl;
    std::cout << copy.getName() << std::endl;
    std::cout << copy.getHitPoints() << std::endl;
    std::cout << copy.getEnergyPoints() << std::endl;
    std::cout << copy.getAttackDamage() << std::endl;

    std::cout << "Test assignment operator on ScavTrap" << std::endl;
    std::cout << assign.getName() << std::endl;
    std::cout << assign.getHitPoints() << std::endl;
    std::cout << assign.getEnergyPoints() << std::endl;
    std::cout << assign.getAttackDamage() << std::endl;
}

