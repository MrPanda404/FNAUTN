#pragma once
#include <vector>
#include <array>
#include <SFML/System/Vector2.hpp>

struct RoomData {
	int ID = 0;
	int spots = 0;
	std::vector<bool> spotOccupied;
	std::vector<int> adyacentRoomsIDs;

	RoomData() = default;

	RoomData(int id, int numSpots, std::vector<bool> occupied, std::vector<int> adyacents)
		: ID(id), spots(numSpots), spotOccupied(std::move(occupied)), adyacentRoomsIDs(adyacents) {}
};

//room =      {1a, 2a, 3, 4, 5, 6, 7, 1b, 2b, 8}

//roomID =    {0,  1,  2, 3, 4, 5, 6,  7,  8, 9}
//roomspots = {7,  5,  2, 3, 5, 2, 3,  4,  3, 3}
//adycrooms = {4,  4,  1, 1, 1, 1, 1,  1,  1, 1}

class Room
{
public:
	Room() = default;
	~Room() = default;

	static void SetupRooms();
	static void SetOccupied(int ID, int spot, bool state);
	static int GetRandomAdyacent(int ID);
	static int GetValidRandomAdyacent(int ID, std::vector<int>& roomsFilter);
	static int GetSpots(int ID);
	static int GetValidRandomSpot(int ID, sf::Vector2i& currentSpot, std::vector<sf::Vector2i>& spotsFilter);
	static bool CheckOccupied(int ID, int spot);

private:
	static std::array<RoomData, 10> rooms;
	static bool initialized;
};

