#include "Room.h"
#include "Random.h"
#include <iostream>

std::array<RoomData, 10> Room::rooms = {};
bool Room::initialized = false;

void Room::SetupRooms()
{
	if (initialized) return;
	initialized = true;

	rooms = {
		RoomData(0, 7, std::vector<bool>(7, false), {1, 6, 7}),//1a
		RoomData(1, 5, std::vector<bool>(5, false), {0, 2, 3, 4, 5}),//2a
		RoomData(2, 2, std::vector<bool>(2, false), {1}),//3
		RoomData(3, 3, std::vector<bool>(3, false), {1}),//4
		RoomData(4, 5, std::vector<bool>(5, false), {1}),//5
		RoomData(5, 2, std::vector<bool>(2, false), {1}),//6
		RoomData(6, 3, std::vector<bool>(3, false), {0}),//7
		RoomData(7, 4, std::vector<bool>(4, false), {0}),//1b
		RoomData(8, 3, std::vector<bool>(3, false), {7}),//2b
		RoomData(9, 3, std::vector<bool>(3, false), {8}) //8
	};
}

void Room::SetOccupied(int ID, int spot, bool state)
{
	if (spot <= 0) return;
	rooms.at(ID).spotOccupied.at(spot - 1) = state;
	//ID = array position. (Hopefully)
}

int Room::GetRandomAdyacent(int ID)
{
	return rooms.at(ID).adyacentRoomsIDs.at(Random::GetInt(0,rooms.at(ID).adyacentRoomsIDs.size() -1));
}

int Room::GetValidRandomAdyacent(int ID, std::vector<int>& roomsFilter)
{
	int newRoom = ID;
	do
	{
		newRoom = GetRandomAdyacent(ID);
	} while (std::find(roomsFilter.begin(), roomsFilter.end(), newRoom) != roomsFilter.end());

	return newRoom;
}

int Room::GetSpots(int ID)
{
	return rooms.at(ID).spots;
}

int Room::GetValidRandomSpot(int ID, sf::Vector2i& currentSpot, std::vector<sf::Vector2i>& spotsFilter)
{
	int newSpot = currentSpot.y;
	bool filter = false;

	do
	{
		newSpot = Random::GetInt(1, Room::GetSpots(ID));
		filter = std::find(spotsFilter.begin(), spotsFilter.end(), sf::Vector2i(ID, newSpot)) != spotsFilter.end() ||
				sf::Vector2i(ID, newSpot) == currentSpot;
		if (filter) {
			std::cout << "Filtrado 1: " << (std::find(spotsFilter.begin(), spotsFilter.end(), sf::Vector2i(ID, newSpot)) != spotsFilter.end() ? true : false) << std::endl;
			std::cout << "Filtrado 2: " << (sf::Vector2i(ID, newSpot) == currentSpot ? true : false) << std::endl;
		}
	} while (filter);

	return newSpot;
}

bool Room::CheckOccupied(int ID, int spot)
{
	if (spot <= 0) return true;
	return rooms.at(ID).spotOccupied.at(spot - 1);
}
