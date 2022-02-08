#pragma once
#include "../ECS/Entity.h"
#include <map>
#include <string>
namespace Engine {

	class EntityManager {
		std::vector<std::shared_ptr<Engine::Entity>> M_EntityVector; // liste de toutes les entity
		std::map<std::string, std::vector<std::shared_ptr<Engine::Entity>>> M_EntityMap; // listes des entity par tag
		size_t M_TotalEntity; // le nombre total de entity qu on fait apparaitre
		std::vector<std::shared_ptr<Engine::Entity>> M_EntityToChange; // liste de toutes les entite qui doivent etre changer a chaque debut de frame
	public:
		void GenerateEntity(); // Genere toutes les entite vide dans le vector par rapport au nombre total
		void Update(); // Appelle au debut du gameloop pour mettre a jour les etats des entite avant n importe quel calcul pour les modifier dans vector et rajouter dans map
		void RemoveEntity(); // enleve l entity du map, et enleve toutes sont contenu dans le vector et le rend utilisable a une autre entite
	};
}