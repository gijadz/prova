//
// Created by Giada Schicchi on 10/07/2025.
//

#ifndef PROVA_OBSERVER_H
#define PROVA_OBSERVER_H

#pragma once

class Observer {
public:
    virtual void aggiorna(int progressoBarra) = 0;
    virtual ~Observer() = default;
};

#endif //PROVA_OBSERVER_H


