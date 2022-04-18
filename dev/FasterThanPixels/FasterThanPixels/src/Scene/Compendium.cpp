#include "Compendium.h"
#include "../Factory/FTP_SceneManager.h"

Compendium::Compendium(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;

}


void Compendium::S_Render()
{
	_SceneManager->_GameManager->Windows->draw(Background);
	_SceneManager->_GameManager->Windows->draw(Title);
	_SceneManager->_GameManager->Windows->draw(MenuTitle);

	_SceneManager->_GameManager->Windows->draw(Ennemis.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Bonus.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Objectifs.ButtonSprite);

	_SceneManager->_GameManager->Windows->draw(Back.ButtonSprite);

	switch(FS){
		case FirstState::Ennemis:

			_SceneManager->_GameManager->Windows->draw(Inter.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(Bomber.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(Chasseur.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(Carrier.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(Tour.ButtonSprite);

			switch (SS){
				
				case SecondState::First:
				//DISPLAY FIRST ROW INFORMATIONS
					_SceneManager->_GameManager->Windows->draw(ci_Inter.m_Titre);
					_SceneManager->_GameManager->Windows->draw(ci_Inter.m_Image);
					_SceneManager->_GameManager->Windows->draw(ci_Inter.m_Damage);
					_SceneManager->_GameManager->Windows->draw(ci_Inter.m_Shield);
					_SceneManager->_GameManager->Windows->draw(ci_Inter.m_Life);
					_SceneManager->_GameManager->Windows->draw(ci_Inter.m_Description);
					break;
				case SecondState::Second:
					_SceneManager->_GameManager->Windows->draw(ci_Bomber.m_Titre);
					_SceneManager->_GameManager->Windows->draw(ci_Bomber.m_Image);
					_SceneManager->_GameManager->Windows->draw(ci_Bomber.m_Damage);
					_SceneManager->_GameManager->Windows->draw(ci_Bomber.m_Shield);
					_SceneManager->_GameManager->Windows->draw(ci_Bomber.m_Life);
					_SceneManager->_GameManager->Windows->draw(ci_Bomber.m_Description);
					break;
				case SecondState::Third:
					_SceneManager->_GameManager->Windows->draw(ci_Chasseur.m_Titre);
					_SceneManager->_GameManager->Windows->draw(ci_Chasseur.m_Image);
					_SceneManager->_GameManager->Windows->draw(ci_Chasseur.m_Damage);
					_SceneManager->_GameManager->Windows->draw(ci_Chasseur.m_Shield);
					_SceneManager->_GameManager->Windows->draw(ci_Chasseur.m_Life);
					_SceneManager->_GameManager->Windows->draw(ci_Chasseur.m_Description);
					break;
				case SecondState::Fourth:
					_SceneManager->_GameManager->Windows->draw(ci_Carrier.m_Titre);
					_SceneManager->_GameManager->Windows->draw(ci_Carrier.m_Image);
					_SceneManager->_GameManager->Windows->draw(ci_Carrier.m_Damage);
					_SceneManager->_GameManager->Windows->draw(ci_Carrier.m_Shield);
					_SceneManager->_GameManager->Windows->draw(ci_Carrier.m_Life);
					_SceneManager->_GameManager->Windows->draw(ci_Carrier.m_Description);
					break;
				case SecondState::Fifth: 
					_SceneManager->_GameManager->Windows->draw(ci_Tour.m_Titre);
					_SceneManager->_GameManager->Windows->draw(ci_Tour.m_Image);
					_SceneManager->_GameManager->Windows->draw(ci_Tour.m_Damage);
					_SceneManager->_GameManager->Windows->draw(ci_Tour.m_Shield);
					_SceneManager->_GameManager->Windows->draw(ci_Tour.m_Life);
					_SceneManager->_GameManager->Windows->draw(ci_Tour.m_Description);
					break;
			}

			break;
		case FirstState::Bonus:

			_SceneManager->_GameManager->Windows->draw(Mines.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(Reparations.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(Missiles.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(Surcadencage.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(Perforation.ButtonSprite);

			switch (SS) {

			case SecondState::First:
				_SceneManager->_GameManager->Windows->draw(ci_Mines.m_Titre);
				_SceneManager->_GameManager->Windows->draw(ci_Mines.m_Image);
				_SceneManager->_GameManager->Windows->draw(ci_Mines.m_Damage);
				_SceneManager->_GameManager->Windows->draw(ci_Mines.m_Shield);
				_SceneManager->_GameManager->Windows->draw(ci_Mines.m_Life);
				_SceneManager->_GameManager->Windows->draw(ci_Mines.m_Description);
				break;
			case SecondState::Second:
				_SceneManager->_GameManager->Windows->draw(ci_Reparations.m_Titre);
				_SceneManager->_GameManager->Windows->draw(ci_Reparations.m_Image);
				_SceneManager->_GameManager->Windows->draw(ci_Reparations.m_Description);
				break;
			case SecondState::Third:
				_SceneManager->_GameManager->Windows->draw(ci_Missiles.m_Titre);
				_SceneManager->_GameManager->Windows->draw(ci_Missiles.m_Image);
				_SceneManager->_GameManager->Windows->draw(ci_Missiles.m_Damage);
				_SceneManager->_GameManager->Windows->draw(ci_Missiles.m_Description);
				break;
			case SecondState::Fourth:
				_SceneManager->_GameManager->Windows->draw(ci_Surcadencage.m_Titre);
				_SceneManager->_GameManager->Windows->draw(ci_Surcadencage.m_Image);
				_SceneManager->_GameManager->Windows->draw(ci_Surcadencage.m_Description);
				break;
			case SecondState::Fifth:
				_SceneManager->_GameManager->Windows->draw(ci_Perforation.m_Titre);
				_SceneManager->_GameManager->Windows->draw(ci_Perforation.m_Image);
				_SceneManager->_GameManager->Windows->draw(ci_Perforation.m_Description);
				break;
			}
			break;
		case FirstState::Objectifs:

			_SceneManager->_GameManager->Windows->draw(ElimVIP.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(DernierSurvivant.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(DefenseZone.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(AssautZone.ButtonSprite);
			_SceneManager->_GameManager->Windows->draw(Sauvetage.ButtonSprite);
			switch (SS) {

			case SecondState::First:
				_SceneManager->_GameManager->Windows->draw(ci_ElimVIP.m_Titre);
				_SceneManager->_GameManager->Windows->draw(ci_ElimVIP.m_Image);
				_SceneManager->_GameManager->Windows->draw(ci_ElimVIP.m_Description);
				break;
			case SecondState::Second:
				_SceneManager->_GameManager->Windows->draw(ci_DernierSurvivant.m_Titre);
				_SceneManager->_GameManager->Windows->draw(ci_DernierSurvivant.m_Image);
				_SceneManager->_GameManager->Windows->draw(ci_DernierSurvivant.m_Description);
				break;
			case SecondState::Third:
				_SceneManager->_GameManager->Windows->draw(ci_DefenseZone.m_Titre);
				_SceneManager->_GameManager->Windows->draw(ci_DefenseZone.m_Image);
				_SceneManager->_GameManager->Windows->draw(ci_DefenseZone.m_Description);
				break;
			case SecondState::Fourth:
				_SceneManager->_GameManager->Windows->draw(ci_AssautZone.m_Titre);
				_SceneManager->_GameManager->Windows->draw(ci_AssautZone.m_Image);
				_SceneManager->_GameManager->Windows->draw(ci_AssautZone.m_Description);
				break;
			case SecondState::Fifth:
				_SceneManager->_GameManager->Windows->draw(ci_Sauvetage.m_Titre);
				_SceneManager->_GameManager->Windows->draw(ci_Sauvetage.m_Image);
				_SceneManager->_GameManager->Windows->draw(ci_Sauvetage.m_Description);
				break;
			}
			break;
	
	}
	
}



void Compendium::S_ActionTrigger(std::string ActionName)
{
}

void Compendium::S_Begin_Play()
{

	FS = FirstState::Empty;

#pragma region Background
	Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("CompendiumCategoriesBackground"));
	Background.setOrigin(Background.getGlobalBounds().width / 2.f, Background.getGlobalBounds().height / 2.f);
	Background.setPosition(_SceneManager->_GameManager->View.getCenter());
	Background.setScale(1, 4);
#pragma endregion

#pragma region Title
	Title.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MenuTitre"));
	Title.setOrigin(Title.getGlobalBounds().width / 2.f, Title.getGlobalBounds().height / 2.f);
	Title.setPosition(_SceneManager->_GameManager->View.getCenter());
	Title.move(sf::Vector2(0.f, -450.f));
#pragma endregion

#pragma region MenuTitleTxt
	MenuTitle.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MenuTitle.setString("Compendium");
	MenuTitle.setCharacterSize(32);
	MenuTitle.setFillColor(sf::Color::White);
	MenuTitle.setOrigin(MenuTitle.getGlobalBounds().width / 2.f, MenuTitle.getGlobalBounds().height / 2.f);
	MenuTitle.setPosition(_SceneManager->_GameManager->View.getCenter());
	MenuTitle.move(sf::Vector2(0.f, -325.f));
#pragma endregion

	Ennemis.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonEnnemis"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 500.f, _SceneManager->_GameManager->View.getCenter().y - 100.f));
	Bonus.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonBonus"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 500.f, _SceneManager->_GameManager->View.getCenter().y - 50.f));
	Objectifs.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonObjectifs"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 500.f, _SceneManager->_GameManager->View.getCenter().y));

#pragma region EnnemisSubLevel
	Inter.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonInter"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y - 100.f));
	Bomber.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonBomber"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y - 50.f));
	Chasseur.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonChasseur"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y));
	Carrier.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonCarrier"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y + 50.f));
	Tour.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonTour"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y + 100.f));
#pragma endregion

#pragma region BonusSubLevel
	Mines.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonMines"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y - 100.f));
	Reparations.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonReparations"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y - 50.f));
	Missiles.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonMissiles"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y));
	Surcadencage.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonSurcadencage"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y + 50.f));
	Perforation.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonPerforation"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y + 100.f));
#pragma endregion

#pragma region ObjectifSubLevel
	ElimVIP.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonElimVIP"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y - 100.f));
	DernierSurvivant.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonDernierSurvivant"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y - 50.f));
	DefenseZone.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonDefenseZone"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y));
	AssautZone.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonAssautZone"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y + 50.f));
	Sauvetage.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("ButtonSauvetage"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 250.f, _SceneManager->_GameManager->View.getCenter().y + 100.f));
#pragma endregion

#pragma region CompendiumContent

	ci_Inter.InitCompendiumInfo(true, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Intercepteur", _SceneManager->_GameManager->G_AssetManager->GetTexture("Interceptor100"),"1","1","1","Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_Bomber.InitCompendiumInfo(true, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Bombardier", _SceneManager->_GameManager->G_AssetManager->GetTexture("Bomber100"),"1","1","1","Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_Chasseur.InitCompendiumInfo(true, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Chasseur", _SceneManager->_GameManager->G_AssetManager->GetTexture("Chasseur100"),"1","1","1","Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_Carrier.InitCompendiumInfo(true, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Porte-Vaisseau", _SceneManager->_GameManager->G_AssetManager->GetTexture("Carrier100"),"1","1","1","Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_Tour.InitCompendiumInfo(true, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Tour", _SceneManager->_GameManager->G_AssetManager->GetTexture("Tour100"),"1","1","1","Placeholder", _SceneManager->_GameManager->View.getCenter());

	ci_Mines.InitCompendiumInfo(true, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Mines", _SceneManager->_GameManager->G_AssetManager->GetTexture("MineIcon"), "2", "0", "1", "Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_Reparations.InitCompendiumInfo(false, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Reparations", _SceneManager->_GameManager->G_AssetManager->GetTexture("RepairIcon"), "", "", "", "Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_Missiles.InitCompendiumInfo(false, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Missiles", _SceneManager->_GameManager->G_AssetManager->GetTexture("MissilesIcon"), "3", "", "", "Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_Surcadencage.InitCompendiumInfo(false, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Surcadencage", _SceneManager->_GameManager->G_AssetManager->GetTexture("CadenceIcon"), "", "", "", "Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_Perforation.InitCompendiumInfo(false, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Perforation", _SceneManager->_GameManager->G_AssetManager->GetTexture("PerforingIcon"), "", "", "", "Placeholder", _SceneManager->_GameManager->View.getCenter());

	ci_ElimVIP.InitCompendiumInfo(false, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Elimination de VIP", _SceneManager->_GameManager->G_AssetManager->GetTexture("Player100"), "", "", "", "Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_DernierSurvivant.InitCompendiumInfo(false, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Dernier Survivant", _SceneManager->_GameManager->G_AssetManager->GetTexture("Player100"), "", "", "", "Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_DefenseZone.InitCompendiumInfo(false, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Defense de Zone", _SceneManager->_GameManager->G_AssetManager->GetTexture("Player100"), "", "", "", "Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_AssautZone.InitCompendiumInfo(false, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Assaut de Zone", _SceneManager->_GameManager->G_AssetManager->GetTexture("Player100"), "", "", "", "Placeholder", _SceneManager->_GameManager->View.getCenter());
	ci_Sauvetage.InitCompendiumInfo(false, _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 15, "Sauvetage", _SceneManager->_GameManager->G_AssetManager->GetTexture("Player100"), "", "", "", "Placeholder", _SceneManager->_GameManager->View.getCenter());


#pragma endregion

	Back.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackButton"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x, _SceneManager->_GameManager->View.getCenter().y + 400.f));
}



void Compendium::S_Input_Mouse(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (Ennemis.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "Ennemis";
			FS = FirstState::Ennemis;
			SS = SecondState::Empty;
		}
		else if (Bonus.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "Bonus";
			FS = FirstState::Bonus;
			SS = SecondState::Empty;
		}
		else if (Objectifs.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "Objectifs";
			FS = FirstState::Objectifs;
			SS = SecondState::Empty;
		}
		else if (Inter.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Ennemis){
			std::cout << "Ennemis";
			SS = SecondState::First;
		}
		else if (Bomber.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Ennemis) {
			std::cout << "Ennemis";
			SS = SecondState::Second;
		}
		else if (Chasseur.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Ennemis) {
			std::cout << "Ennemis";
			SS = SecondState::Third;
		}
		else if (Carrier.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Ennemis) {
			std::cout << "Ennemis";
			SS = SecondState::Fourth;
		}
		else if (Tour.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Ennemis) {
			std::cout << "Ennemis";
			SS = SecondState::Fifth;
		}
		else if (Mines.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Bonus) {
			std::cout << "Bonus";
			SS = SecondState::First;
		}
		else if (Reparations.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Bonus) {
			std::cout << "Bonus";
			SS = SecondState::Second;
		}
		else if (Missiles.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Bonus) {
			std::cout << "Bonus";
			SS = SecondState::Third;
		}
		else if (Surcadencage.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Bonus) {
			std::cout << "Bonus";
			SS = SecondState::Fourth;
		}
		else if (Perforation.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Bonus) {
			std::cout << "Bonus";
			SS = SecondState::Fifth;
		}
		else if (ElimVIP.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Objectifs) {
			std::cout << "Objectifs";
			SS = SecondState::First;
		}
		else if (DernierSurvivant.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Objectifs) {
			std::cout << "Objectifs";
			SS = SecondState::Second;
		}
		else if (DefenseZone.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Objectifs) {
			std::cout << "Objectifs";
			SS = SecondState::Third;
		}
		else if (AssautZone.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Objectifs) {
			std::cout << "Objectifs";
			SS = SecondState::Fourth;
		}
		else if (Sauvetage.IsSpriteClicked(_SceneManager->_GameManager->Windows) && FS == FirstState::Objectifs) {
			std::cout << "Objectifs";
			SS = SecondState::Fifth;
		}
		else if (Back.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "Back";
			_SceneManager->ChangeScene("MainMenu");
		}

	}
}

void Compendium::S_Input_Text(sf::Event event)
{
}
