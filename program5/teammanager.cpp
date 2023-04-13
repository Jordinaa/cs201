#include "teammanager.h"

TeamManager::TeamManager(const std::vector<BasketballPlayer> &ncaaPlayers, const std::vector<ProBasketballPlayer> &proPlayers)
    : ncaaPlayers(ncaaPlayers), proPlayers(proPlayers) {}

// Helper method to filter pro players based on position
std::vector<ProBasketballPlayer> TeamManager::filterProPlayersByPosition(const std::string &position) {
    std::vector<ProBasketballPlayer> filteredPlayers;
    for (const auto &player : proPlayers) {
        if (player.getPosition() == position) {
            filteredPlayers.push_back(player);
        }
    }
    return filteredPlayers;
}

bool compareNcaaPlayers(const BasketballPlayer &a, const BasketballPlayer &b) {
    if (a.getValue() != b.getValue()) {
        return a.getValue() > b.getValue();
    }
    return a.getEffRating() > b.getEffRating();
}

bool compareProPlayers(const ProBasketballPlayer &a, const ProBasketballPlayer &b) {
    if (a.getValue() != b.getValue()) {
        return a.getValue() > b.getValue();
    }
    return a.getEffRating() > b.getEffRating();
}

void TeamManager::createAllNcaaTeam() {
    // Sort NCAA players by player value and efficiency rating
    std::sort(ncaaPlayers.begin(), ncaaPlayers.end(), compareNcaaPlayers);

    // Select the top 12 players
    for (int i = 0; i < 12; ++i) {
        allNcaaTeam.push_back(ncaaPlayers[i]);
    }

    // Print All NCAA Team Roster
    std::cout << "All NCAA Team Roster:" << std::endl;
    for (const auto &player : allNcaaTeam) {
        std::cout << player.getPlayerName() << " (" << player.getPlayerType() << ")" << std::endl;
    }
}

void TeamManager::createMixedTeam() {
    // Select top 2 players from each position in the pro player list
    for (const auto &position : {"C", "F", "G"}) {
        auto filteredPlayers = filterProPlayersByPosition(position);
        std::sort(filteredPlayers.begin(), filteredPlayers.end(), compareProPlayers);
        for (int i = 0; i < 2; ++i) {
            mixedTeam.push_back(filteredPlayers[i]);
        }
    }

    // Sort NCAA players by player value and efficiency rating
    std::sort(ncaaPlayers.begin(), ncaaPlayers.end(), compareNcaaPlayers);

    // Select the top 6 NCAA players
    for (int i = 0; i < 6; ++i) {
        mixedTeam.push_back(ncaaPlayers[i]);
    }

    // Print Mixed Team Roster
    std::cout << "Mixed Team Roster:" << std::endl;
    for (const auto &player : mixedTeam) {
        std::cout << player.getPlayerName() << " (" << player.getPlayerType() << ")" << std::endl;
    }
}

void TeamManager::createAllProTeam() {
    // Initialize team budget
    int teamBudget = 98000000;

    // Select best center, 2 forwards, and 2 guards
    for (const auto &position : {"C", "F", "G"}) {
        int numPlayersToAdd = position == "C" ? 1 : 2;
        auto filteredPlayers = filterProPlayersByPosition(position);
        std::sort(filteredPlayers.begin(), filteredPlayers.end(), compareProPlayers);
        for (int i = 0; i < numPlayersToAdd; ++i) {
            allProTeam.push_back(filteredPlayers[i]);
            teamBudget -= filteredPlayers[i].getContractValue();
        }
    }

    // Add remaining players while maintaining the budget and following the specified conditions
    std::vector<std::pair<std::string, int>> positionAndMaxValue = {{"C", 8}, {"F", 8}, {"G", 8}, {"G", 6}, {"F", 5}};
    for (const auto &posAndVal : positionAndMaxValue) {
        auto position = posAndVal.first;
        auto maxValue = posAndVal.second;
        auto filteredPlayers = filterProPlayersByPosition(position);
        std::sort(filteredPlayers.begin(), filteredPlayers.end(), compareProPlayers);

        for (const auto &player : filteredPlayers) {
            if (player.getValue() <= maxValue && teamBudget >= player.getContractValue()) {
                allProTeam.push_back(player);
                teamBudget -= player.getContractValue();
                break;
            }
        }
    }

    // Print All Pro Team Roster and the total cost
    std::cout << "All Pro Team Roster:" << std::endl;
    int totalCost = 0;
    for (const auto &player : allProTeam) {
        totalCost += player.getContractValue();
        std::cout << player.getPlayerName() << " (" << player.getPlayerType() << ", $" << player.getContractValue() << ")" << std::endl;
    }
    std::cout << "Total cost for funding this team: $" << totalCost << std::endl;
}

