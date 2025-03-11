/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:57 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/11 11:26:05 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
        private:
            std::string _name;
            int _hitPoints;
            int _energyPoints;
            int _attackDamage;
        
        public:

            ClapTrap();
            ClapTrap(const std::string& name);
            ClapTrap(const ClapTrap&);
            virtual ~ClapTrap();
            ClapTrap & operator=(const ClapTrap &);
            
            virtual void attack(const std::string& target);
            void takeDamage(int amount);
            void beRepaired(int amount);
            
            const std::string& getName () const;

            //getter functions
            const int& getHitPoints() const;
            const int&  getEnergyPoints() const;
            const int& getAttackDamage() const;
            //setter functions
            void setHitPoints(int nb);
            void setEnergyPoints(int nb);
            void setAttackDamage(int nb);

    };

#endif