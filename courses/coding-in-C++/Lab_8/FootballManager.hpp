#ifndef FOOTBALL_MANAGER_HPP
#define FOOTBALL_MANAGER_HPP

#include <string>
#include <memory>
#include <algorithm>

class Player
{
private:
    std::string name;
    int age;

public:
    Player(const std::string &name, int age);
    virtual ~Player() = default;

    std::string get_name() const;
    int get_age() const;

    // Train a player with given intensity (0..100). Subclasses should
    // preserve the contract: accept intensity and perform a training action.
    virtual void train(int intensity);
};

class InjuredPlayer : public Player
{
public:
    InjuredPlayer(const std::string &name, int age);

    // LSP fix: instead of rejecting intensities > 30, we cap the
    // intensity to a safe maximum and perform recovery training. This
    // preserves substitutability when used through a `Player` reference.
    void train(int intensity) override;
};

/*
 * Notes about SOLID violations (answers requested by the lab):
 * - Single Responsibility Principle: `FootballManager` previously
 *   handled strategy selection, training orchestration, persistence and
 *   notifications — multiple responsibilities.
 * - Open/Closed Principle: `select_strategy` used branching (if/else)
 *   which forces modification to add new strategies.
 * - Interface Segregation Principle: `ClubService` (original) grouped
 *   unrelated operations; clients may depend on methods they don't use.
 * - Liskov Substitution Principle: `InjuredPlayer::train` originally
 *   rejected certain intensities with an error message. Substituting an
 *   `InjuredPlayer` for a `Player` could break callers expecting a
 *   working `train` method.
 * - Dependency Inversion Principle: `FootballManager` depended on
 *   concrete `FilePlayerRepository` and `EmailNotifier` instead of
 *   abstractions.
 */

// -------------------- Abstractions (Dependency Inversion) ---------
class IPlayerRepository
{
public:
    virtual ~IPlayerRepository() = default;
    virtual void save(const Player &player) = 0;
};

class INotifier
{
public:
    virtual ~INotifier() = default;
    virtual void send(const Player &player, const std::string &message) = 0;
};

// -------------------- Concrete implementations ---------------------
class FilePlayerRepository : public IPlayerRepository
{
public:
    void save(const Player &player) override;
};

class EmailNotifier : public INotifier
{
public:
    void send(const Player &player, const std::string &message) override;
};

// -------------------- Strategy Pattern (improves OCP) -------------
class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual void apply() const = 0;
};

class OffensiveStrategy : public Strategy
{
public:
    void apply() const override;
};

class DefensiveStrategy : public Strategy
{
public:
    void apply() const override;
};

class BalancedStrategy : public Strategy
{
public:
    void apply() const override;
};

// -------------------- FootballManager (uses abstractions) ---------
class FootballManager
{
private:
    // Owned implementations (when default-constructed)
    std::unique_ptr<IPlayerRepository> owned_repository;
    std::unique_ptr<INotifier> owned_notifier;

    // Non-owning pointers used for operations (may point to owned_*)
    IPlayerRepository *repository = nullptr;
    INotifier *notifier = nullptr;

    // Map selection to a strategy object; keeps selection decoupled.
    std::unique_ptr<Strategy> create_strategy(const std::string &strategy) const;

public:
    // Default constructor: owns concrete implementations
    FootballManager();

    // Dependency-injection constructor: caller manages lifetime
    FootballManager(IPlayerRepository *repo, INotifier *notifier);

    void prepare_player(Player &player, const std::string &strategy);

    void train_player(Player &player, int intensity);
    void save_player(const Player &player);
    void notify_player(const Player &player, const std::string &message);
};

#endif
