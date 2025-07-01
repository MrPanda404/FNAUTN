#include "Room.h"

std::array<RoomData, 10> Room::rooms = {};
bool Room::setedUp = false;

void Room::SetupRooms()
{
	if (setedUp) return;
	setedUp = true;

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
	rooms.at(ID).spotOccupied.at(spot - 1) = state;
	//ID = array position. (Hopefully)
}
