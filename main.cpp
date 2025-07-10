#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <C:/Users/Giada Schicchi/Desktop/Laboratorio/sfml-widgets-master/src/Gui/Gui.hpp>
#include "Subject.h"
#include "SFMLProgressBar.h"
#include <thread>

using namespace std;



int main(){
    //creo finestra sfml
    sf::RenderWindow window(sf::VideoMode(800,600), "Progress Bar");

    //creo progress bar
    SFMLProgressBar progressBar(200,300,400,30);

    Subject sub;
    sub.aggiungi(&progressBar);

    //avvio timer per avanzamento barra
    thread worker([&sub](){
        sub.avanzamentoBarra(11);
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

//google test avanzamento barra, e aggiorna
//spostare Observer, Subject e SFMLProgressBar in nei loro header e source
//mandare email di conferma dopo aver caricato la repository su github