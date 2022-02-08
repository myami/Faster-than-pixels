#pragma once
namespace Engine {
	class Vector2D {
	public:
		float x;
		float y;
		Vector2D();
		Vector2D(float x, float y);
		bool operator == (const Vector2D& other) const;
		Vector2D operator + (const Vector2D& other) const;
		Vector2D operator * (const float& val) const;
		void operator += (const Vector2D& other) ;
		Vector2D operator - (const Vector2D& other) const;
		void operator -= (const Vector2D& other);
	

	};
}