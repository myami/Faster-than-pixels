#pragma once
namespace Engine {
	class Vector2D {
	public:
		float x;  /*!< Position x */
		float y;  /*!< Position y */
			/*!
			*  \brief Vector2D
			*
			*  Constructeur vide
			*/
		Vector2D();
		/*!
		*  \brief Vector2D
		*
		*  Constructeur avec des donnes a initialiser
		* \param x : position x
		* \param y : position y
		*/
		Vector2D(float x, float y);
		/*!
		*  \brief operator ==
		*
		*  Compare 2 vector 
		* \param other : autre vector a comparer
		* \return true si les vecteur sont identique
		*/
		bool operator == (const Vector2D& other) const;
		/*!
		*  \brief operator +
		*
		*  additione 2 vector
		* \param other : autre vector a additioner
		* \return le vecteur additionner
		*/
		Vector2D operator + (const Vector2D& other) const;
		/*!
		*  \brief operator *
		*
		*  multiplie 2 vector
		* \param other : autre vector a multiplier
		* \return le vecteur multiplier
		*/
		Vector2D operator * (const float& val) const;
		/*!
		*  \brief operator +=
		*
		*  additione 2 vector
		* \param other : autre vector a additioner
		* 
		*/
		void operator += (const Vector2D& other) ;
		/*!
		*  \brief operator -
		*
		*  soustrait 2 vector
		* \param other : autre vector a soustraire
		* \return le vecteur soustrait
		*/
		Vector2D operator - (const Vector2D& other) const;
		/*!
		*  \brief operator -=
		*
		*  soustrait 2 vector
		* \param other : autre vector a soustraire
		* 
		*/
		void operator -= (const Vector2D& other);
	
	};
}