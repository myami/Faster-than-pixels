#include "Authentification.h"
#include "../Factory/FTP_SceneManager.h"


Authentification::Authentification(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;

}



void Authentification::S_Update()
{
	// sql
}

void Authentification::S_Render()
{
	
	_SceneManager->_GameManager->Windows->draw(Background);
	_SceneManager->_GameManager->Windows->draw(ButtonBackground);
	_SceneManager->_GameManager->Windows->draw(Title);

	_SceneManager->_GameManager->Windows->draw(UserName.BackgroundTexture);
	_SceneManager->_GameManager->Windows->draw(UserName.textbox);
	_SceneManager->_GameManager->Windows->draw(PassWord.BackgroundTexture);
	_SceneManager->_GameManager->Windows->draw(PassWord.textbox);

	_SceneManager->_GameManager->Windows->draw(Login.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Register.ButtonSprite);



}


void Authentification::S_Begin_Play()
{
	Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MenuBackground"));
	Background.setOrigin(Background.getGlobalBounds().width / 2.f, Background.getGlobalBounds().height / 2.f);
	Background.setPosition(_SceneManager->_GameManager->View.getCenter());

	Login.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("LoginButton"));
	Login.ButtonSprite.setOrigin(Login.ButtonSprite.getGlobalBounds().width / 2.f, Login.ButtonSprite.getGlobalBounds().height / 2.f);
	Login.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Login.ButtonSprite.move(sf::Vector2(200.f, 400.f));
	Login.ButtonSprite.setScale(sf::Vector2f(_SceneManager->_GameManager->View.getSize().x / _SceneManager->_GameManager->Windows->getSize().x, _SceneManager->_GameManager->View.getSize().y / _SceneManager->_GameManager->Windows->getSize().y));

	Register.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("RegisterButton"));
	Register.ButtonSprite.setOrigin(Register.ButtonSprite.getGlobalBounds().width / 2.f, Register.ButtonSprite.getGlobalBounds().height / 2.f);
	Register.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Register.ButtonSprite.move(sf::Vector2(-200.f, 400.f));

	ButtonBackground.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackgroundButtonIdentification"));
	ButtonBackground.setOrigin(Register.ButtonSprite.getGlobalBounds().width / 2.f, Register.ButtonSprite.getGlobalBounds().height / 2.f);
	ButtonBackground.setPosition(_SceneManager->_GameManager->View.getCenter());
	ButtonBackground.move(sf::Vector2(-500.f, 370.f));

	Title.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MenuTitre"));
	Title.setOrigin(Title.getGlobalBounds().width / 2.f, Title.getGlobalBounds().height / 2.f);
	Title.setPosition(_SceneManager->_GameManager->View.getCenter());
	Title.move(sf::Vector2(0.f, -450.f));

	UserName.hasLimit = true;
	UserName.limit = 10;
	UserName.isCrypted = false; 
	UserName.SetSelected(false);
	UserName.BackgroundTexture.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("InputBackground"));
	UserName.textbox.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	UserName.textbox.setCharacterSize(20);
	UserName.textbox.setOrigin(UserName.textbox.getGlobalBounds().width / 2.f, UserName.textbox.getGlobalBounds().height / 2.f);
	UserName.textbox.setPosition(_SceneManager->_GameManager->View.getCenter());
	UserName.textbox.move(sf::Vector2(-50.f, -8.f)); // bonne position relatif 
	UserName.BackgroundTexture.setOrigin(UserName.BackgroundTexture.getGlobalBounds().width / 2.f, UserName.BackgroundTexture.getGlobalBounds().height / 2.f);
	UserName.BackgroundTexture.setPosition(_SceneManager->_GameManager->View.getCenter());
	UserName.textbox.setString("Username");
	UserName.BackgroundTexture.move(sf::Vector2(-400.f, 200.f));
	UserName.textbox.move(sf::Vector2(-400.f, 200.f));


	PassWord.hasLimit = true;
	PassWord.limit = 10;
	PassWord.isCrypted = true;
	PassWord.SetSelected(false);
	PassWord.BackgroundTexture.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("InputBackground"));
	PassWord.textbox.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	PassWord.textbox.setCharacterSize(20);
	PassWord.textbox.setOrigin(UserName.textbox.getGlobalBounds().width / 2.f, UserName.textbox.getGlobalBounds().height / 2.f);
	PassWord.textbox.setPosition(_SceneManager->_GameManager->View.getCenter());
	PassWord.textbox.move(sf::Vector2(-50.f, -8.f)); // bonne position relatif 
	PassWord.BackgroundTexture.setOrigin(UserName.BackgroundTexture.getGlobalBounds().width / 2.f, UserName.BackgroundTexture.getGlobalBounds().height / 2.f);
	PassWord.BackgroundTexture.setPosition(_SceneManager->_GameManager->View.getCenter());
	PassWord.textbox.setString("Password");
	PassWord.BackgroundTexture.move(sf::Vector2(400.f, 200.f));
	PassWord.textbox.move(sf::Vector2(400.f, 200.f));





}




void Authentification::S_Input_Mouse(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed) {

		if (Login.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "login";
			_SceneManager->ChangeScene("MainMenu");

		}
		if (Register.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "register";
		}

		if (UserName.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			UserName.SetSelected(true);
		}
		if (UserName.isSelected && !UserName.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			UserName.SetSelected(false);

		}
		
	}


	
}

void Authentification::S_Input_Text(sf::Event event)
{
	UserName.TypedOn(event);
}
