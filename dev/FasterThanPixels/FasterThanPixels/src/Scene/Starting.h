#pragma once
// cinematique
#include "Engine.h"
class FTP_SceneManager;
/*! \class Starting
* \brief classe enfant de Scene, represente la scene de lancement, il y a des splashcreen pour montrer le nom du jeux et le groupe qui l'a fait
*
*/
class Starting : public Engine::BlankScene {
public:
	Starting(std::string name, FTP_SceneManager* refs);
	void Tick() override; // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_ActionTrigger(std::string ActionName) override;
	void Begin_Play() override;

	sf::Clock clock;  /*!< horloge pour la duree des images et de la scene */
	bool pass = false;  /*!< Si le joueur passe la cinematique */
	sf::Text text;  /*!< texte de la cinematique */
	sf::Sprite logo;  /*!< logo ratatoskr */
};