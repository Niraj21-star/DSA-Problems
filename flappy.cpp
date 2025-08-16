#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GRAVITY 0.5f
#define JUMP_STRENGTH -10.0f
#define PIPE_SPEED 5.0f
#define PIPE_WIDTH 50.0f
#define PIPE_GAP 150.0f

struct Pipe {
    sf::RectangleShape topPipe;
    sf::RectangleShape bottomPipe;
    float x;
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    // Create the window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird");
    window.setFramerateLimit(60);

    // Initialize bird
    sf::RectangleShape bird(sf::Vector2f(30.0f, 30.0f));
    bird.setFillColor(sf::Color::Yellow);
    bird.setPosition(100.0f, SCREEN_HEIGHT / 2.0f);
    float birdVelocity = 0.0f;

    // Initialize pipes
    std::vector<Pipe> pipes;
    float pipeSpawnTimer = 0;

    // Score
    int score = 0;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1; // Ensure the font file is available in the same directory
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);

    bool isGameOver = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (!isGameOver && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                birdVelocity = JUMP_STRENGTH;
            }
        }

        if (!isGameOver) {
            // Bird physics
            birdVelocity += GRAVITY;
            bird.move(0, birdVelocity);

            // Spawn pipes
            pipeSpawnTimer += 1.0f;
            if (pipeSpawnTimer >= 90) {
                pipeSpawnTimer = 0;
                float topPipeHeight = rand() % (SCREEN_HEIGHT / 2);
                float bottomPipeHeight = SCREEN_HEIGHT - topPipeHeight - PIPE_GAP;

                Pipe pipe;
                pipe.topPipe.setSize(sf::Vector2f(PIPE_WIDTH, topPipeHeight));
                pipe.topPipe.setFillColor(sf::Color::Green);
                pipe.topPipe.setPosition(SCREEN_WIDTH, 0);

                pipe.bottomPipe.setSize(sf::Vector2f(PIPE_WIDTH, bottomPipeHeight));
                pipe.bottomPipe.setFillColor(sf::Color::Green);
                pipe.bottomPipe.setPosition(SCREEN_WIDTH, SCREEN_HEIGHT - bottomPipeHeight);

                pipe.x = SCREEN_WIDTH;

                pipes.push_back(pipe);
            }

            // Move pipes
            for (auto &pipe : pipes) {
                pipe.x -= PIPE_SPEED;
                pipe.topPipe.setPosition(pipe.x, 0);
                pipe.bottomPipe.setPosition(pipe.x, SCREEN_HEIGHT - pipe.bottomPipe.getSize().y);
            }

            // Remove off-screen pipes
            pipes.erase(
                std::remove_if(pipes.begin(), pipes.end(),
                               [](Pipe &p) { return p.x + PIPE_WIDTH < 0; }),
                pipes.end());

            // Check for collisions
            for (const auto &pipe : pipes) {
                if (bird.getGlobalBounds().intersects(pipe.topPipe.getGlobalBounds()) ||
                    bird.getGlobalBounds().intersects(pipe.bottomPipe.getGlobalBounds()) ||
                    bird.getPosition().y < 0 || bird.getPosition().y + bird.getSize().y > SCREEN_HEIGHT) {
                    isGameOver = true;
                }
            }

            // Update score
            for (const auto &pipe : pipes) {
                if (pipe.x + PIPE_WIDTH < bird.getPosition().x && !isGameOver) {
                    score++;
                }
            }
        }

        // Render
        window.clear();

        // Draw bird
        window.draw(bird);

        // Draw pipes
        for (const auto &pipe : pipes) {
            window.draw(pipe.topPipe);
            window.draw(pipe.bottomPipe);
        }

        // Draw score
        scoreText.setString("Score: " + std::to_string(score));
        scoreText.setPosition(10, 10);
        window.draw(scoreText);

        window.display();
    }

    return 0;
}

