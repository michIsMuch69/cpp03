/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:00 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/03 19:39:10 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"


int main()
{
    ClapTrap clap("John ClapTrap");

    FragTrap scav("Bob FragTrap");

    ClapTrap* clapPtr;

    clapPtr = &clap;
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");

    clapPtr = &scav;
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");
    clapPtr->attack("target");

    scav.highFiveGuys(); 

    return 0;
}
