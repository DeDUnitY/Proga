#include <SFML/Graphics.hpp>

class AnimatedText
{
private:
    std::string _text;
    int _pos = 0;
    double _DurPerSec;
    std::string _new_text;
public:
    AnimatedText(const std::string& text, int duration)
    {
        _text = text;
        _DurPerSec = (duration * 1000) / text.size();
    }

    std::string Get()
    {
        std::string temp;
        if (_pos == _text.size())
        {
            return _text;
        }
        _new_text = _text.substr(0, _pos);
        _pos += 1;
        return _new_text;
    }
    double GetDuration()
    {
        return _DurPerSec;
    }

};

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Lab 1");
    AnimatedText message("Hello world!", 2);
    std::string temp = message.Get();

    sf::Font font;
    font.loadFromFile("font.ttf");

    sf::Text text(temp, font, 50);
    text.setFillColor(sf::Color::Cyan);


    sf::Clock timer;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) 
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
        }

        window.clear();

        if (timer.getElapsedTime().asMilliseconds() >= message.GetDuration())
        {
            timer.restart();
            text.setString(message.Get());
        }
        window.draw(text);
        window.display();

        sf::sleep(sf::milliseconds(int(1000 / 60)));

    }

    return 0;
}