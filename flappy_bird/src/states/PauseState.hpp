/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author (student) : José Agelvis

*/

#pragma once

#include <memory>

#include <SFML/Graphics.hpp>
#include <src/states/BaseState.hpp>
class StateMachine;
class World;
class Bird;

class PauseState : public BaseState
{
public:
    PauseState(StateMachine *sm) noexcept;

    // virtual ~PauseState() {}

    void enter(std::shared_ptr<World> _world = nullptr, std::shared_ptr<Bird> _bird = nullptr, int _score = 0) noexcept override;

    // void exit() noexcept {}

    void handle_inputs(const sf::Event &event) noexcept override;

    // void update(float dt) noexcept override;

    void render(sf::RenderTarget &target) const noexcept override;

private:
    StateMachine *state_machine;
    std::shared_ptr<Bird> bird;
    std::shared_ptr<World> world;
    int score;
};
