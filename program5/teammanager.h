#pragma once

#include "player.h"
#include "proplayer.h"
#include "collegeplayer.h"

#include <vector>

class TeamManager {
public:
    TeamManager();

    void addPlayer(BasketballPlayer* player);
    void createAllNCAATeam();
    void createMixedTeam();
    void createAllProTeam();

private:
    std::vector<BasketballPlayer*> players;
};
