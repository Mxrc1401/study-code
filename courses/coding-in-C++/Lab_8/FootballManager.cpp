#include "FootballManager.hpp"

#include <iostream>

constexpr int MIN_PROFESSIONAL_AGE = 16;
constexpr int DEFAULT_TRAINING_INTENSITY = 70;

Player::Player(const std::string &name, int age)
    : name(name),
      age(age)
{
}

std::string Player::get_name() const
{
    return name;
}

int Player::get_age() const
{
    return age;
}

void Player::train(int intensity)
{
    if (intensity < 0 || intensity > 100)
    {
        std::cout << "Invalid intensity. Use a value between 0 and 100.\n";
        return;
    }

    std::cout << get_name() << " trains with intensity " << intensity << ".\n";
}

InjuredPlayer::InjuredPlayer(const std::string &name, int age)
    : Player(name, age)
{
}

void InjuredPlayer::train(int intensity)
{
    // LSP-compliant: cap intensity instead of rejecting it.
    int safe_intensity = std::max(0, std::min(intensity, 30));
    std::cout << get_name() << " performs recovery training with intensity " << safe_intensity << ".\n";
}

void FilePlayerRepository::save(const Player &player)
{
    // In a real application this would write to disk; kept minimal here.
    std::cout << "Saving " << player.get_name() << " to player_file.txt.\n";
}

void EmailNotifier::send(const Player &player, const std::string &message)
{
    std::cout << "Sending email to " << player.get_name() << ": " << message << "\n";
}

// -------------------- Strategy implementations -------------------
void OffensiveStrategy::apply() const
{
    std::cout << "Strategy: offensive pressing.\n";
}

void DefensiveStrategy::apply() const
{
    std::cout << "Strategy: compact defense.\n";
}

void BalancedStrategy::apply() const
{
    std::cout << "Strategy: balanced default strategy.\n";
}

// -------------------- FootballManager implementation --------------
FootballManager::FootballManager()
{
    // Default: FootballManager owns concrete implementations.
    owned_repository = std::make_unique<FilePlayerRepository>();
    owned_notifier = std::make_unique<EmailNotifier>();

    repository = owned_repository.get();
    notifier = owned_notifier.get();
}

FootballManager::FootballManager(IPlayerRepository *repo, INotifier *notifier)
{
    // Use externally provided implementations (caller owns them).
    this->repository = repo;
    this->notifier = notifier;
}

std::unique_ptr<Strategy> FootballManager::create_strategy(const std::string &strategy) const
{
    if (strategy == "offensive")
        return std::make_unique<OffensiveStrategy>();
    if (strategy == "defensive")
        return std::make_unique<DefensiveStrategy>();
    return std::make_unique<BalancedStrategy>();
}

void FootballManager::prepare_player(Player &player, const std::string &strategy)
{
    if (player.get_age() < MIN_PROFESSIONAL_AGE)
    {
        std::cout << player.get_name() << " is too young for the professional team.\n";
        return;
    }

    // select and apply a strategy (Strategy pattern improves OCP)
    auto strat = create_strategy(strategy);
    strat->apply();

    train_player(player, DEFAULT_TRAINING_INTENSITY);
    save_player(player);
    notify_player(player, "Training preparation completed.");
}

void FootballManager::train_player(Player &player, int intensity)
{
    player.train(intensity);
}

void FootballManager::save_player(const Player &player)
{
    if (repository)
        repository->save(player);
}

void FootballManager::notify_player(const Player &player, const std::string &message)
{
    if (notifier)
        notifier->send(player, message);
}

int main()
{
    Player player("Alex Striker", 24);
    InjuredPlayer injured_player("Ben Defender", 29);

    FootballManager manager; // uses default FilePlayerRepository + EmailNotifier

    manager.prepare_player(player, "offensive");
    std::cout << "\n";
    manager.prepare_player(injured_player, "defensive");

    return 0;
}
