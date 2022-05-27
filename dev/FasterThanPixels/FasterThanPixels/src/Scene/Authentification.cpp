#include "Authentification.h"
#include "../Factory/FTP_SceneManager.h"
#include "../Factory/FTP_GameManager.h"
#include "SFML/Graphics.hpp"
#include <regex>
#include "../Utility/FTP_DAO.h"


Authentification::Authentification(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;

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

	if (inscription) 
	{
		_SceneManager->_GameManager->Windows->draw(Mail.BackgroundTexture);
		_SceneManager->_GameManager->Windows->draw(Mail.textbox);
		_SceneManager->_GameManager->Windows->draw(VerifPassWord.BackgroundTexture);
		_SceneManager->_GameManager->Windows->draw(VerifPassWord.textbox);

		_SceneManager->_GameManager->Windows->draw(Apply.ButtonSprite);
		_SceneManager->_GameManager->Windows->draw(Back.ButtonSprite);
	}
	else
	{
		_SceneManager->_GameManager->Windows->draw(Login.ButtonSprite);
		_SceneManager->_GameManager->Windows->draw(Register.ButtonSprite);
	}



}


void Authentification::Begin_Play()
{
	inscription = false;
	Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MenuBackground"));
	Background.setOrigin(Background.getGlobalBounds().width / 2.f, Background.getGlobalBounds().height / 2.f);
	Background.setPosition(_SceneManager->_GameManager->View.getCenter());

#pragma region Boutons
	Login.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("LoginButton"));
	Login.ButtonSprite.setOrigin(Login.ButtonSprite.getGlobalBounds().width / 2.f, Login.ButtonSprite.getGlobalBounds().height / 2.f);
	Login.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Login.ButtonSprite.move(sf::Vector2(200.f, 400.f));
	Login.ButtonSprite.setScale(sf::Vector2f(_SceneManager->_GameManager->View.getSize().x / _SceneManager->_GameManager->Windows->getSize().x, _SceneManager->_GameManager->View.getSize().y / _SceneManager->_GameManager->Windows->getSize().y));

	Register.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("RegisterButton"));
	Register.ButtonSprite.setOrigin(Register.ButtonSprite.getGlobalBounds().width / 2.f, Register.ButtonSprite.getGlobalBounds().height / 2.f);
	Register.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Register.ButtonSprite.move(sf::Vector2(-300.f, 400.f));

	Apply.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("ApplyButton"));
	Apply.ButtonSprite.setOrigin(Apply.ButtonSprite.getGlobalBounds().width / 2.f, Apply.ButtonSprite.getGlobalBounds().height / 2.f);
	Apply.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Apply.ButtonSprite.move(sf::Vector2(-0.f, 400.f));

	Back.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackButton"));
	Back.ButtonSprite.setOrigin(Register.ButtonSprite.getGlobalBounds().width / 2.f, Register.ButtonSprite.getGlobalBounds().height / 2.f);
	Back.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Back.ButtonSprite.move(sf::Vector2(300.f, 400.f));

	ButtonBackground.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackgroundButtonIdentification"));
	ButtonBackground.setOrigin(Register.ButtonSprite.getGlobalBounds().width / 2.f, Register.ButtonSprite.getGlobalBounds().height / 2.f);
	ButtonBackground.setPosition(_SceneManager->_GameManager->View.getCenter());
	ButtonBackground.move(sf::Vector2(-500.f, 370.f));
#pragma endregion

#pragma region Titre
	Title.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MenuTitre"));
	Title.setOrigin(Title.getGlobalBounds().width / 2.f, Title.getGlobalBounds().height / 2.f);
	Title.setPosition(_SceneManager->_GameManager->View.getCenter());
	Title.move(sf::Vector2(0.f, -450.f));
#pragma endregion

#pragma region Input
	UserName.hasLimit = true;
	UserName.limit = 16;
	UserName.isCrypted = false; 
	UserName.SetSelected(false);
	UserName.BackgroundTexture.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("InputBackground"));
	UserName.textbox.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	UserName.textbox.setCharacterSize(20);
	UserName.textbox.setOrigin(UserName.textbox.getGlobalBounds().width / 2.f, UserName.textbox.getGlobalBounds().height / 2.f);
	UserName.textbox.setPosition(_SceneManager->_GameManager->View.getCenter());
	UserName.BackgroundTexture.setOrigin(UserName.BackgroundTexture.getGlobalBounds().width / 2.f, UserName.BackgroundTexture.getGlobalBounds().height / 2.f);
	UserName.textbox.setString("Username");
	UserName.SetPosition("Username", sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 400.f, _SceneManager->_GameManager->View.getCenter().y + 200.f));

	Mail.hasLimit = false;
	Mail.isCrypted = false;
	Mail.SetSelected(false);
	Mail.BackgroundTexture.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("InputBackground"));
	Mail.textbox.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Mail.textbox.setCharacterSize(20);
	Mail.textbox.setOrigin(Mail.textbox.getGlobalBounds().width / 2.f, Mail.textbox.getGlobalBounds().height / 2.f);
	Mail.BackgroundTexture.setOrigin(Mail.BackgroundTexture.getGlobalBounds().width / 2.f, Mail.BackgroundTexture.getGlobalBounds().height / 2.f);
	Mail.textbox.setString("Adresse Mail");
	Mail.SetPosition("Adresse Mail", sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x, _SceneManager->_GameManager->View.getCenter().y + -200.f));

	PassWord.hasLimit = true;
	PassWord.limit = 10;
	PassWord.isCrypted = true;
	PassWord.SetSelected(false);
	PassWord.BackgroundTexture.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("InputBackground"));
	PassWord.textbox.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	PassWord.textbox.setCharacterSize(20);
	PassWord.textbox.setOrigin(PassWord.textbox.getGlobalBounds().width / 2.f, PassWord.textbox.getGlobalBounds().height / 2.f);
	PassWord.BackgroundTexture.setOrigin(PassWord.BackgroundTexture.getGlobalBounds().width / 2.f, PassWord.BackgroundTexture.getGlobalBounds().height / 2.f);
	PassWord.textbox.setString("Password");
	PassWord.SetPosition("Password", sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x + 400.f, _SceneManager->_GameManager->View.getCenter().y + 200.f));

	VerifPassWord.hasLimit = true;
	VerifPassWord.limit = 10;
	VerifPassWord.isCrypted = true;
	VerifPassWord.SetSelected(false);
	VerifPassWord.BackgroundTexture.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("InputBackground"));
	VerifPassWord.textbox.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	VerifPassWord.textbox.setCharacterSize(20);
	VerifPassWord.textbox.setOrigin(VerifPassWord.textbox.getGlobalBounds().width / 2.f, VerifPassWord.textbox.getGlobalBounds().height / 2.f);
	VerifPassWord.BackgroundTexture.setOrigin(VerifPassWord.BackgroundTexture.getGlobalBounds().width / 2.f, VerifPassWord.BackgroundTexture.getGlobalBounds().height / 2.f);
	VerifPassWord.textbox.setString("Password Verification");
	VerifPassWord.SetPosition("Password Verification", sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x, _SceneManager->_GameManager->View.getCenter().y + 100.f));
#pragma endregion

}




void Authentification::S_Input_Mouse(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed) {

#pragma region Boutons
		if (Login.IsSpriteClicked(_SceneManager->_GameManager->Windows) && !inscription) {
			std::cout << "login";

			static_cast<FTP_GameManager*>(_SceneManager->_GameManager)->Dao->db_info.Username = UserName.GetText();

			std::map<std::string,std::string>datatemp = static_cast<FTP_GameManager*>(_SceneManager->_GameManager)->Dao->GetData();
			if (datatemp["Username"]._Equal(UserName.GetText()) && datatemp["Password"]._Equal(PassWord.GetText()))
			{
				_SceneManager->ChangeScene("MainMenu");
			}
		}
		if (Register.IsSpriteClicked(_SceneManager->_GameManager->Windows) && !inscription) {
			std::cout << "register";
			inscription = true;
			ShowRegister();
		}
		if (Apply.IsSpriteClicked(_SceneManager->_GameManager->Windows) && inscription) {
			std::cout << "Registration Applied";
			//std::regex_match(UserName.GetText(), std::regex("\w[A-z]*"))
			//Fonctionne sur les testeurs en ligne, mais pas dans le programme
			if (std::regex_match(Mail.GetText(), std::regex(".*[@].*[\.].*")) && PassWord.GetText()._Equal(VerifPassWord.GetText())){
				static_cast<FTP_GameManager*>(_SceneManager->_GameManager)->Dao->db_info.Username = UserName.GetText();
				std::map<std::string, std::string> data;
				data["Username"] = UserName.GetText();
				data["Mail"] = Mail.GetText();
				data["Password"] = PassWord.GetText();
				data["Level"] = "0";
				data["Interceptor"] = "0";
				data["Bomber"] = "0";
				data["Fighter"] = "0";
				data["Carrier"] = "0";
				data["Turret"] = "0";
				data["Asteroid"] = "0";
				data["Castaway"] = "0";
				data["Mission"] = "0";
				static_cast<FTP_GameManager*>(_SceneManager->_GameManager)->Dao->InsertData(data, static_cast<FTP_GameManager*>(_SceneManager->_GameManager)->Dao->pattern);
			}
			else {
				std::cout << "Registration Failed";
			}
			inscription = false;
		}
		if (Back.IsSpriteClicked(_SceneManager->_GameManager->Windows) && inscription) {
			std::cout << "Back";
			inscription = false;
			ShowLogin();
		}
#pragma endregion

#pragma region Champs

		if (UserName.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			UserName.SetSelected(true);
		}
		if (UserName.isSelected && !UserName.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			UserName.SetSelected(false);

		}
		if (PassWord.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			PassWord.SetSelected(true);
		}
		if (PassWord.isSelected && !PassWord.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			PassWord.SetSelected(false);

		}
		if (Mail.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			Mail.SetSelected(true);
		}
		if (Mail.isSelected && !Mail.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			Mail.SetSelected(false);

		}
		if (VerifPassWord.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			VerifPassWord.SetSelected(true);
		}
		if (VerifPassWord.isSelected && !VerifPassWord.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			VerifPassWord.SetSelected(false);
		}
#pragma endregion
	}

}

void Authentification::S_Input_Text(sf::Event event)
{
	UserName.TypedOn(event);
	PassWord.TypedOn(event);
	Mail.TypedOn(event);
	VerifPassWord.TypedOn(event);

}

void Authentification::ShowLogin()
{
	UserName.SetPosition("Username", sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 400.f, _SceneManager->_GameManager->View.getCenter().y + 200.f));
	PassWord.SetPosition("Password", sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x + 400.f, _SceneManager->_GameManager->View.getCenter().y + 200.f));
 
}

void Authentification::ShowRegister()
{
	UserName.SetPosition("Username", sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x , _SceneManager->_GameManager->View.getCenter().y - 100.f));
	PassWord.SetPosition("Password", sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x , _SceneManager->_GameManager->View.getCenter().y));

	
}

void Authentification::Tick()
{
}
