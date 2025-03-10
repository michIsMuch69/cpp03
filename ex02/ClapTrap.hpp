/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:57 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/04 11:34:29 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define COLOR_RED     "\033[1;31m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN    "\033[1;36m"
#define COLOR_RESET   "\033[0m"

class ClapTrap
{
    private :
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        void takeDamage(int amount);
        void beRepaired(int amount);    
        
    public:
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap &);
        virtual ~ClapTrap();
        virtual void attack(const std::string& target);


        ClapTrap & operator=(const ClapTrap &other);

        //getter functions
        const std::string& getName () const;
        const int& getHitPoints() const;
        const int&  getEnergyPoints() const;
        const int& getAttackDamage() const;
        //setter functions
        void setHitPoints(int nb);
        void setEnergyPoints(int nb);
        void setAttackDamage(int nb);
};

#endif