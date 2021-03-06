#include "GameModeSelection.h"
#include "../Factory/FTP_SceneManager.h"

GameModeSelection::GameModeSelection(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;
}

void GameModeSelection::S_Render()
{
	_SceneManager->_GameManager->Windows->draw(Background);
	_SceneManager->_GameManager->Windows->draw(Title);
	_SceneManager->_GameManager->Windows->draw(Borders);
	_SceneManager->_GameManager->Windows->draw(ModesSelection);
	_SceneManager->_GameManager->Windows->draw(Easy.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Medium.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Hard.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Training.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(FastAction.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Multiplayer.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(StartGame.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Back.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Seed.BackgroundTexture);
	_SceneManager->_GameManager->Windows->draw(Seed.textbox);
	_SceneManager->_GameManager->Windows->draw(MenuTitle);
	_SceneManager->_GameManager->Windows->draw(Borders);
	_SceneManager->_GameManager->Windows->draw(DifficultySelection);
}

void GameModeSelection::Begin_Play()
{
#pragma region Background
	Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MenuBackground"));
	Background.setOrigin(Background.getGlobalBounds().width / 2.f, Background.getGlobalBounds().height / 2.f);
	Background.setPosition(_SceneManager->_GameManager->View.getCenter());
#pragma endregion

#pragma region Title
	Title.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MenuTitre"));
	Title.setOrigin(Title.getGlobalBounds().width / 2.f, Title.getGlobalBounds().height / 2.f);
	Title.setPosition(_SceneManager->_GameManager->View.getCenter());
	Title.move(sf::Vector2(0.f, -450.f));
#pragma endregion

#pragma region EasyBtn
	Easy.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonEasy"));
	Easy.ButtonSprite.setOrigin(Easy.ButtonSprite.getGlobalBounds().width / 2.f, Easy.ButtonSprite.getGlobalBounds().height / 2.f);
	Easy.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Easy.ButtonSprite.move(sf::Vector2(-225.f, -250.f));
#pragma endregion

#pragma region MediumBtn
	Medium.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonMedium"));
	Medium.ButtonSprite.setOrigin(Medium.ButtonSprite.getGlobalBounds().width / 2.f, Medium.ButtonSprite.getGlobalBounds().height / 2.f);
	Medium.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Medium.ButtonSprite.move(sf::Vector2(0.f, -250.f));
#pragma endregion

#pragma region HardBtn
	Hard.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonHard"));
	Hard.ButtonSprite.setOrigin(Medium.ButtonSprite.getGlobalBounds().width / 2.f, Medium.ButtonSprite.getGlobalBounds().height / 2.f);
	Hard.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Hard.ButtonSprite.move(sf::Vector2(225.f, -250.f));
#pragma endregion

#pragma region TrainingBtn
	Training.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("TrainingButton"));
	Training.ButtonSprite.setOrigin(Training.ButtonSprite.getGlobalBounds().width / 2.f, Training.ButtonSprite.getGlobalBounds().height / 2.f);
	Training.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Training.ButtonSprite.move(sf::Vector2(-275.f, 150.f));
#pragma endregion

#pragma region FastActionBtn
	FastAction.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("FastActionButton"));
	FastAction.ButtonSprite.setOrigin(FastAction.ButtonSprite.getGlobalBounds().width / 2.f, FastAction.ButtonSprite.getGlobalBounds().height / 2.f);
	FastAction.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	FastAction.ButtonSprite.move(sf::Vector2(0.f, 150.f));
#pragma endregion

#pragma region MultiplayerBtn
	Multiplayer.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MultiplayerButton"));
	Multiplayer.ButtonSprite.setOrigin(Multiplayer.ButtonSprite.getGlobalBounds().width / 2.f, Multiplayer.ButtonSprite.getGlobalBounds().height / 2.f);
	Multiplayer.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Multiplayer.ButtonSprite.move(sf::Vector2(275.f, 150.f));
#pragma endregion

#pragma region StartGameBtn
	StartGame.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("PlayButton"));
	StartGame.ButtonSprite.setOrigin(StartGame.ButtonSprite.getGlobalBounds().width / 2.f, StartGame.ButtonSprite.getGlobalBounds().height / 2.f);
	StartGame.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	StartGame.ButtonSprite.move(sf::Vector2(200.f, 475.f));
#pragma endregion

#pragma region BackBtn
	Back.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackButton"));
	Back.ButtonSprite.setOrigin(Back.ButtonSprite.getGlobalBounds().width / 2.f, Back.ButtonSprite.getGlobalBounds().height / 2.f);
	Back.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Back.ButtonSprite.move(sf::Vector2(-200.f, 475.f));
#pragma endregion

#pragma region SeedTxt
	Seed.hasLimit = true;
	Seed.limit = 15;
	Seed.isCrypted = false;
	Seed.SetSelected(false);
	Seed.BackgroundTexture.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("InputBackground"));
	Seed.textbox.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Seed.textbox.setCharacterSize(20);
	Seed.textbox.setOrigin(Seed.textbox.getGlobalBounds().width / 2.f, Seed.textbox.getGlobalBounds().height / 2.f);
	Seed.textbox.setPosition(_SceneManager->_GameManager->View.getCenter());
	Seed.textbox.move(sf::Vector2(-50.f, -8.f)); // bonne position relatif
	Seed.BackgroundTexture.setOrigin(Seed.BackgroundTexture.getGlobalBounds().width / 2.f, Seed.BackgroundTexture.getGlobalBounds().height / 2.f);
	Seed.BackgroundTexture.setPosition(_SceneManager->_GameManager->View.getCenter());
	Seed.textbox.setString("Entrez la seed ici");
	Seed.BackgroundTexture.move(sf::Vector2(0.f, -150.f));
	Seed.textbox.move(sf::Vector2(0.f - Seed.textbox.getGlobalBounds().width / 3.f, -150.f));

#pragma endregion

#pragma region MenuTitleTxt
	MenuTitle.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MenuTitle.setString("MODE SELECTION");
	MenuTitle.setCharacterSize(32);
	MenuTitle.setFillColor(sf::Color::White);
	//MenuTitle.setStyle(sf::Text::Bold | sf::Text::Underlined);
	MenuTitle.setOrigin(MenuTitle.getGlobalBounds().width / 2.f, MenuTitle.getGlobalBounds().height / 2.f);
	MenuTitle.setPosition(_SceneManager->_GameManager->View.getCenter());
	MenuTitle.move(sf::Vector2(0.f, -325.f));
#pragma endregion

#pragma region DifficultySelection

	DifficultySelection.setSize(sf::Vector2f(150, 5));
	DifficultySelection.setFillColor(sf::Color(52, 106, 232));
	DifficultySelection.setOrigin(DifficultySelection.getGlobalBounds().width / 2.f, DifficultySelection.getGlobalBounds().height / 2.f);
	DifficultySelection.setPosition(_SceneManager->_GameManager->View.getCenter());
	DifficultySelection.move(sf::Vector2(-225.f, -215.f));

#pragma endregion

#pragma region ModesSelection
	ModesSelection.setSize(sf::Vector2f(250, 500));
	ModesSelection.setOutlineColor(sf::Color(52, 106, 232));
	ModesSelection.setOutlineThickness(10.f);
	ModesSelection.setOrigin(ModesSelection.getGlobalBounds().width / 2.f, ModesSelection.getGlobalBounds().height / 2.f);
	ModesSelection.setPosition(_SceneManager->_GameManager->View.getCenter());
	ModesSelection.move(sf::Vector2(-265.f, 160.f));
	ModesSelection.setFillColor(sf::Color::Transparent);

#pragma endregion
}

void GameModeSelection::S_Input_Mouse(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (Easy.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			DifficultySelection.setPosition(_SceneManager->_GameManager->View.getCenter());
			DifficultySelection.move(sf::Vector2(-225.f, -215.f));
			CurrentDifficulty = 0;
		}
		if (Medium.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			DifficultySelection.setPosition(_SceneManager->_GameManager->View.getCenter());
			CurrentDifficulty = 1;
			DifficultySelection.move(sf::Vector2(0.f, -215.f));
		}
		if (Hard.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			CurrentDifficulty = 2;
			DifficultySelection.setPosition(_SceneManager->_GameManager->View.getCenter());
			DifficultySelection.move(sf::Vector2(225.f, -215.f));
		}
		if (Back.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			_SceneManager->ChangeScene("MainMenu");
		}
		if (Training.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			ModesSelection.setPosition(_SceneManager->_GameManager->View.getCenter());
			ModesSelection.move(sf::Vector2(-265.f, 160.f));
			CurrentModes = 0;
		}
		if (FastAction.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			CurrentModes = 1;
			ModesSelection.setPosition(_SceneManager->_GameManager->View.getCenter());
			ModesSelection.move(sf::Vector2(10.f, 160.f));
		}
		if (StartGame.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			_SceneManager->ChangeScene("Game");
		}

		if (Seed.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			Seed.SetSelected(true);
		}
		if (Seed.isSelected && !Seed.IsInputClicked(_SceneManager->_GameManager->Windows)) {
			Seed.SetSelected(false);
		}
	}
}

void GameModeSelection::S_Input_Text(sf::Event event)
{
	Seed.TypedOn(event);
}

void GameModeSelection::Tick()
{
}