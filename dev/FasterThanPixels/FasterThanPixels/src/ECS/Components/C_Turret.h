#pragma once
#include "Engine.h"
/*! \class C_Turret
* \brief classe representant le component Turret, Si l'entite a ce component, cela veux dire qu'il a des tourelles
*
*/
class C_Turret : public Engine::BlankComponent {
public:
	int AmountOfTurret;  /*!< Nombre de tourelle */
	std::vector<Engine::Vector2D> TurretPosition;  /*!< Position des tourelles */
	std::vector<Engine::Vector2D> TurretRotation;  /*!< Rotation des tourelles */
	float TurretDamage;  /*!< Degats des tourelles */
	float TurretShootingSpeed;  /*!< Cadence de tir des tourelles */
	float TurretTimeToRotate;  /*!< Duree pour la tourelle de tourner */
	void RotateTurret(int TurrentIndex, Engine::Entity Target);

};