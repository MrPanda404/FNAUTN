#include "MenuState.h"
#include "NightState.h"

void ApplyParallax(const sf::Vector2f& mousePos, sf::Sprite& sprite, float parallax);
sf::Vector2f CenterMouse(sf::Vector2i mousePos, sf::Vector2u windowSize);

MenuState::MenuState(GameDataRef data)
    : creditsSprite(creditsTex),
    settingsSprite(settingTex)
{
    this->data = data;
}

void MenuState::Start()
{
    SetupSprites();
    SetupButtons();
    menuView = Menu;
}

void MenuState::HandleInput()
{
    while (const std::optional<sf::Event> event = data->window.pollEvent()) 
    {
        mousePos = data->window.mapPixelToCoords(sf::Mouse::getPosition(data->window));


        if (event->is<sf::Event::Closed>()) {
            data->window.close();
        }


        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (sf::Keyboard::Key::Escape == keyPressed->code) {
                data->window.close();
            }
        }

        if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (sf::Mouse::Button::Left == mousePressed->button) {
                switch (menuView) {
                case Menu:
                    for (auto& btn : menuButtons) {
                        if (btn.GetShape().getGlobalBounds().contains(mousePos)) {
                            btn.OnClick();
                        }
                    }
                    break;
                case Settings:
                case Credits:
                    if (backButton.GetShape().getGlobalBounds().contains(mousePos)) {
                        backButton.OnClick();
                    }
                    break;
                default:
                    break;
                }
            }
        }

        if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
            this->mouseMoved = true;
        }
    }
}

void MenuState::Update()
{
    if (mouseMoved) {
        auto centeredMouse = CenterMouse(sf::Mouse::getPosition(data->window), data->window.getSize());
        ApplyParallax(centeredMouse, bgSprites.at("MenuArtBG"), 100);
        ApplyParallax(centeredMouse, bgSprites.at("MenuArtSmoke"), 50);
        mouseMoved = false;
    }
}

void MenuState::Render()
{
	data->window.clear();

    Game::DrawOnWindow(bgSprites, drawOrderBG, data->window);

    switch (menuView) {
        case Menu:
            Game::DrawOnWindow(menuSprites, drawOrder, data->window);
            Game::DrawOnWindow(menuButtons, data->window);
            break;
        case Settings:
        case Credits:

            if (menuView == Settings) {
                data->window.draw(settingsSprite);
            }
            else {
                data->window.draw(this->creditsSprite);
            }

            data->window.draw(backButton.GetShape());
            break;
        default:
            break;
    }

	data->window.display();
}

void MenuState::Stop()
{
}

void MenuState::SetupSprites() 
{
    drawOrderBG = {
        "MenuArtBG", "MenuArtSmoke"
    };

    for (const auto& name : drawOrderBG) {
        textures[name].setSmooth(true);
    }

    AssetManager::LoadTextureGroup(textures, bgSprites, drawOrderBG, "textures");

    drawOrder = {
        "MenuArtText", "MenuArtCont", "MenuArtNoche6", "MenuArtNocheCustom"
    };

    AssetManager::LoadTextureGroup(textures, menuSprites, drawOrder, "textures");

    AssetManager::LoadTexture(creditsTex, "CreditsArt", "textures");

    AssetManager::LoadTexture(settingTex, "SettingsArt", "textures");

    creditsSprite.setTexture(creditsTex, true);
    settingsSprite.setTexture(settingTex, true);

    AssetManager::CenterSprites(bgSprites);

    bgSprites.at("MenuArtBG").setScale({ 1.05f,1.05f });
    bgSprites.at("MenuArtSmoke").setScale({ 1.05f,1.05f });


}

void MenuState::SetupButtons()
{
    menuButtons = {
        Button("NewGameBtn", { 80, 304 },{ 288, 64 }), //0
        Button("ContinueBtn", { 80, 416 }, { 224, 64 }), //1
        Button("Night6Btn", { 80, 512 },{ 208, 64 }), //2
        Button("CustomNightBtn", { 80, 608 },{ 320, 64}), //3
        Button("ExitBtn", { 46, 768 },{ 192, 80 }), //4
        Button("SettingsButton", { 352, 768 },{ 304, 96 }), //5
        Button("CreditsButton", { 1408, 112 },{ 160, 64 }), //6
    };

    menuButtons.at(0).SetFunction([this]() {
        data->machine.AddState((StateRef)new NightState(data), false);
        });
    menuButtons.at(1).SetFunction([]() {});
    menuButtons.at(2).SetFunction([]() {});
    menuButtons.at(3).SetFunction([]() {});

    menuButtons.at(4).SetFunction([this]() {
        data->window.close();
    });

    menuButtons.at(5).SetFunction([this]{
        this->menuView = Settings;
        });
    menuButtons.at(6).SetFunction([this]{
        this->menuView = Credits;
        });


    backButton = Button("BackButton", { 32,800 }, { 176,80 });
    backButton.SetFunction([this] {
        this->menuView = Menu;
        });
}

void ApplyParallax(const sf::Vector2f& mousePos, sf::Sprite& sprite, float parallax) 
{
    sf::FloatRect floatRect = sprite.getLocalBounds();

    float offsetX = floatRect.size.x / (parallax * 4.f);
    float offsetY = floatRect.size.y / (parallax * 4.f);
    float centerX = (floatRect.size.x / 2.f);
    float centerY = (floatRect.size.y / 2.f);

    sf::Vector2f newPosition({
        -mousePos.x / parallax + centerX + offsetX,
        -mousePos.y / parallax + centerY + offsetY,
        });

    //std::cout << "Sprite " << parallax << " Vector: " << newPosition.x << ", " << newPosition.y << std::endl;
    //std::cout << "MousePos " << mousePos.x << ", " << mousePos.y << std::endl;

    sprite.setPosition(newPosition);
}

sf::Vector2f CenterMouse(sf::Vector2i mousePos, sf::Vector2u windowSize)
{
    return sf::Vector2f({mousePos.x - windowSize.x / 2.f, mousePos.y - windowSize.y / 2.f});
}

