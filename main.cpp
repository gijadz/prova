#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <C:/Users/Giada Schicchi/Desktop/Laboratorio/sfml-widgets-master/src/Gui/Gui.hpp>
#include <vector>
//per funzione remove in rimuovi()
#include <algorithm>
//per cronometro/timer
#include <thread>
#include <chrono>
using namespace std;

class Observer{
public:
    virtual void aggiorna(int progressoBarra) = 0;
    virtual ~Observer() = default;
};

class Subject{
    vector<Observer*> observers;
public:
    void aggiungi(Observer* obs){
        observers.push_back(obs);
    }
    void rimuovi(Observer* obs){
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }
    void notificaProgresso(int progressoBarra){
        for(auto& obs : observers){
            obs->aggiorna(progressoBarra);
        }
    }

    void avanzamentoBarra(int numFiles){ //numFile = t0tale numero "barre" da simulare nel caricamento
        for(int i = 1; i <= numFiles; ++i){
            //simula il caricamento di un certo numero di file
            int progresso = (i * 100) / numFiles;
            notificaProgresso(progresso); // Notifica tutti gli osservatori registrati passando la percentuale di avanzamento.
            std::this_thread::sleep_for(std::chrono::milliseconds(700)); //simula il tempo di caricamento
        }
    }
};

//interfaccia
class SFMLProgressBar : public Observer, public sf::Drawable{
private:
    sf::RectangleShape background;
    sf::RectangleShape bar;
    sf::Text text;
    //sf::Font font;
    int progresso;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
        target.draw(background, states);
        target.draw(bar, states);
        target.draw(text, states);
    }

public:
    SFMLProgressBar(float x, float y, float width, float height){
        //Imposto lo sfondo della progress bar
        background.setSize(sf::Vector2f(width, height));
        background.setFillColor(sf::Color(50,50,50));
        background.setPosition(x,y);
        background.setOutlineThickness(2);
        background.setOutlineColor(sf::Color::White);


        //Imposto la progress bar centrata nello sfondo (2 pixel di margine)
        bar.setSize(sf::Vector2f(0,height - 4));
        bar.setFillColor(sf::Color(100, 200, 100));
        bar.setPosition(x + 2, y + 2);
        progresso = 0;
    }
    void aggiorna(int progressoBarra) override{
        progresso = progressoBarra;

        //aggiorna dimensione della barra
        float barWidth = (background.getSize().x-4)*(progresso/100.f);
        bar.setSize(sf::Vector2f(barWidth, bar.getSize().y));

        //aggiorna il testo
        text.setString(to_string(progresso)+"%");
    }
};

int main(){
    //creo finestra sfml
    sf::RenderWindow window(sf::VideoMode(800,600), "Progress Bar");

    //creo progress bar
    SFMLProgressBar progressBar(200,300,400,30);

    Subject sub;
    sub.aggiungi(&progressBar);

    //avvio timer per avanzamento barra
    thread worker([&sub](){
        sub.avanzamentoBarra(13);
    });
    //loop principale della finestra
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(progressBar);
        window.display();
    }
    worker.join();

    return 0;
}
