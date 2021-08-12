// Copyright (c) 2021 Futureblur. All rights reserved.

#include <iostream>

#define LOG(x) std::cout << x << std::endl
#define ADD_INPUT std::cout << "> "

static void clear();

static void start();

static void run(long base);

int main()
{
    LOG("Welcome! This is a tiny program which simulates the collatz-conjecture. ");
    LOG("For more information, please visit: https://simple.wikipedia.org/wiki/Collatz_conjecture\n\n");
    LOG("Please enter any integer greater than 0 to start.\n");
    start();
}

static void clear()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static void start()
{
    ADD_INPUT;

    long base;
    std::cin >> base;

    if (!std::cin)
    {
        LOG("This is not a valid integer. Please try again.");
        clear();
        start();
        return;
    }

    if (base <= 0.0)
    {
        LOG("The number must be greater than 0.");
        clear();
        start();
        return;
    }

    run(base);
}

static void run(long base)
{
    LOG("Running simulation with integer " << base << ".");

    uint32_t iterations = 0;
    while (base != 1)
    {
        iterations++;

        if (base % 2 == 0)
        {
            //Even
            base /= 2;
        }
        else
        {
            //Odd
            base = base * 3 + 1;
        }

        LOG(base);
    }

    LOG("Simulation finished.");
    LOG("Total iterations: " << iterations);
    LOG("Enter another number to retry.");
    start();
}