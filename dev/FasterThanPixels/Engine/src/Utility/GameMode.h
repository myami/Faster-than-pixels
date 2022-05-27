#pragma once
namespace Engine {
	/*! \class GameMode
	* \brief classe parentes des modes de jeux
	*/
	class GameMode {
		/*!
		*  @def OnGameModeStart
		*
		*  Function appeler au lancement du mode de jeux.Generalement utiliser pour initialiser le gamemode
		*/
		virtual void OnGameModeStart() = 0;
		/*!
		*  @def OnGameModeUpdate
		*
		*  Function appeler a chaque gameloop pour mettre a jour le contenu du mode de jeu par rapport a l'avancement du joueur
		*/
		virtual void OnGameModeUpdate() = 0;
		/*!
		*  @def OnGameModeEnd
		*
		*  Function appeler a la fin du mode de jeux. Generalement pour lancer un autre gamemode ou la fin de partie et sauvegarder les stats du joueur pendant se gamemode
		*/
		virtual void OnGameModeEnd() = 0;
	};
}