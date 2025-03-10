/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:00 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/03 19:33:32 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    ClapTrap clap("John ClapTrap");

    ScavTrap scav("Bob ScavTrap");

    ClapTrap* clapPtr;

    clapPtr = &clap;
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");

    clapPtr = &scav;
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");

    scav.guardGate(); 

    return 0;
}
