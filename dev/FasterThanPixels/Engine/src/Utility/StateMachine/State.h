#pragma once
#include <string>
#include "StateParent.h"
namespace Engine {
	class StateParent;
	/*! \struct FSM_Param
	* \brief struct qui reprensente les parametres de l'etat
	*
	*/
	struct FSM_Param {
		bool isterminal;
		std::string NextScene;
		bool StopState;
		std::string StateName;
	};
	/*! \class FSM_State
	* \brief classe enfant de StateParent pour les scenes
	*
	*/
	class FSM_State : public StateParent
	{
	public:
		FSM_Param param; /*!< Parametre du state */
	};
}
