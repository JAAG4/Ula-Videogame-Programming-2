/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author (student) : José Agelvis

*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PauseState.hpp>
#include <src/Bird.hpp>
#include <src/World.hpp>
PauseState::PauseState(StateMachine *sm) noexcept
    : BaseState{sm}
{
}

void PauseState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, int _score) noexcept
{
    world = _world;
    // world->reset(true);
    bird = _bird;
    score = _score;
}

void PauseState::handle_inputs(const sf::Event &event) noexcept
{
    if (event.key.code == sf::Keyboard::P)
    {
        state_machine->change_state("playing", world, bird, score);
    }
}

void PauseState::render(sf::RenderTarget &target) const noexcept
{
    world->render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Paused", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, "Press P to Unpause", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    bird->render(target);
    render_text(target, 20, 10, "Score: " + std::to_string(score), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);
}