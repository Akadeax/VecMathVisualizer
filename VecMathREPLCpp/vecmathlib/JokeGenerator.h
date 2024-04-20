#pragma once
#include "Console.h"
#include "Joke.h"
#include <random>
#include <vector>
class JokeGenerator
{
  public:
    JokeGenerator();
    void printRandomJoke(const Console& consoleHandle);

  private:
    std::vector<Joke> m_Jokes;
    std::default_random_engine m_Generator; // seed the generator
};
